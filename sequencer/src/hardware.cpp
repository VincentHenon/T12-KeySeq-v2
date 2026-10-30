#include "hardware.hpp"
#include "hardware/adc.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"
#include "hardware/pio.h"
#include "hardware/pwm.h"
#include "hardware/sync.h"
#include "pico/stdlib.h"
#include "rgb.pio.h"
#include <algorithm>
#include <cmath>
namespace t12::hw {
namespace {
// Logical Key 1..12 follows the visible panel grid from top-left to
// bottom-right: 1 2 3 4 / 5 6 7 8 / 9 10 11 12.
constexpr uint8_t electrodes[12] = {10, 6, 5, 0, 9, 7, 4, 2, 11, 8, 3, 1};
// 13-bit PWM: 200 MHz / 8192 = 24.414 kHz carrier.
constexpr uint16_t CvPwmTop = (1u << 13) - 1u;
Edge edges[64]{};
volatile unsigned head = 0, tail = 0;
volatile bool overrun = false;
volatile int turns = 0;
int quarters = 0;
uint8_t previous = 0, detent = 0;
uint64_t lastClock = 0, lastReset = 0;
uint16_t keys = 0;
uint64_t nextTouch = 0;
bool touchOk = false, mprConfigured = false;
uint32_t colors[12]{};
unsigned rgbSm = 0;
struct Button {
  unsigned pin;
  bool raw = false, stable = false, longSent = false;
  uint64_t changed = 0, down = 0;
  bool press = false, release = false, longPress = false;
  void poll(uint64_t now) {
    press = release = longPress = false;
    bool value = !gpio_get(pin);
    if (value != raw) {
      raw = value;
      changed = now;
    }
    if (raw != stable && now - changed >= 15000) {
      stable = raw;
      if (stable) {
        press = true;
        down = now;
        longSent = false;
      } else
        release = !longSent;
    }
    if (stable && !longSent && now - down >= 800000) {
      longSent = true;
      longPress = true;
    }
  }
} click{pin::Click}, minus{pin::Minus}, plus{pin::Plus};
void irq(unsigned gpio, uint32_t) {
  const auto now = time_us_64();
  if (gpio == pin::EncoderA || gpio == pin::EncoderB) {
    auto state = uint8_t((gpio_get(pin::EncoderA) ? 2 : 0) |
                         (gpio_get(pin::EncoderB) ? 1 : 0));
    static constexpr int8_t table[16] = {0,  -1, 1, 0, 1, 0, 0,  -1,
                                         -1, 0,  0, 1, 0, 1, -1, 0};
    if ((previous ^ state) == 3)
      quarters = 0;
    else
      quarters += table[(previous << 2) | state];
    previous = state;
    if (state == detent) {
      if (quarters >= 4)
        turns = turns + 1;
      else if (quarters <= -4)
        turns = turns - 1;
      quarters = 0;
    }
    return;
  }
  auto &last = gpio == pin::Reset ? lastReset : lastClock;
  if (last && now - last < 150)
    return; // reject electrical glitches, retain clock pulses
  last = now;
  unsigned next = (head + 1) % 64;
  if (next == tail) {
    overrun = true;
    return;
  }
  edges[head] = {now, gpio == pin::Reset};
  __dmb();
  head = next;
}
bool wr(uint8_t reg, uint8_t val) {
  uint8_t b[] = {reg, val};
  return i2c_write_timeout_us(i2c0, 0x5A, b, 2, false, 1000) == 2;
}
bool rd(uint8_t reg, uint8_t *b, unsigned n) {
  return i2c_write_timeout_us(i2c0, 0x5A, &reg, 1, true, 1000) == 1 &&
         i2c_read_timeout_us(i2c0, 0x5A, b, n, false, 1000) == int(n);
}
bool thresholds(uint8_t t, uint8_t r) {
  for (unsigned i = 0; i < 12; ++i)
    if (!wr(0x41 + i * 2, t) || !wr(0x42 + i * 2, r))
      return false;
  return true;
}
bool mprInit() {
  gpio_set_function(0, GPIO_FUNC_I2C);
  gpio_set_function(1, GPIO_FUNC_I2C);
  gpio_pull_up(0);
  gpio_pull_up(1);
  i2c_init(i2c0, 100000);
  sleep_ms(10);
  if (!wr(0x5E, 0) || !wr(0x80, 0x63))
    return false;
  sleep_ms(2);
  constexpr uint8_t config[][2] = {
      {0x5C, 0x10}, {0x5D, 0x20}, {0x7D, 0xC9}, {0x7F, 0xB5}, {0x7E, 0x83},
      {0x7B, 0x0B}, {0x2B, 1},    {0x2F, 1},    {0x2C, 1},    {0x30, 1},
      {0x33, 1},    {0x2D, 0},    {0x31, 0xFF}, {0x34, 0},    {0x2E, 0},
      {0x32, 2},    {0x35, 0x7F}, {0x5B, 0}};
  for (auto &e : config)
    if (!wr(e[0], e[1]))
      return false;
  if (!thresholds(15, 10) || !wr(0x5E, 0x8C))
    return false;
  uint8_t ecr = 0;
  if (!rd(0x5E, &ecr, 1) || (ecr & 15) != 12)
    return false;
  return wr(0x5E, 0) && thresholds(9, 5) && wr(0x5E, 0x8C);
}
} // namespace
namespace {
float calibratedCommand(float target, const Calibration &c) {
  constexpr float commands[CalibrationPoints] = {0, 2, 4, 6, 8};
  target = std::clamp(target, 0.0f, 8.0f);
  unsigned segment = CalibrationPoints - 2;
  if (target <= c.measured[0]) {
    segment = 0;
  } else {
    for (unsigned i = 0; i + 1 < CalibrationPoints; ++i) {
      if (target <= c.measured[i + 1]) {
        segment = i;
        break;
      }
    }
  }
  const float span = c.measured[segment + 1] - c.measured[segment];
  if (span < 0.02f) return target;
  const float correctionA = (c.coarseMv[segment] + c.fineTenthsMv[segment] / 10.0f) / 1000.0f;
  const float correctionB = (c.coarseMv[segment + 1] + c.fineTenthsMv[segment + 1] / 10.0f) / 1000.0f;
  const float correction = correctionA +
      (correctionB - correctionA) * (target - c.measured[segment]) / span;
  // Permit a negative internal command to correct a positive jack offset at
  // the 0 V point of the analog output stage.
  return std::clamp(commands[segment] + correction +
                        (target - c.measured[segment]) * 2.0f / span,
                    -2.0f, 8.0f);
}
} // namespace
uint16_t duty(float v, const Calibration &c) {
  const float command = calibratedCommand(v, c);
  return uint16_t(std::lround(std::clamp((c.intercept - command) / c.span,
                             0.0f, 1.0f) * CvPwmTop));
}
bool clockHigh() { return gpio_get(pin::Clock); }
bool resetHigh() { return gpio_get(pin::Reset); }
void init(const Settings &s) {
  gpio_init(pin::Gate);
  // The T12 gate output stage inverts the MCU signal.
  gpio_put(pin::Gate, 1); // closed at startup
  gpio_set_dir(pin::Gate, GPIO_OUT);
  auto config = pwm_get_default_config();
  pwm_config_set_wrap(&config, CvPwmTop);
  // 24.414 kHz at the tested 200 MHz system clock.
  pwm_config_set_clkdiv(&config, float(clock_get_hz(clk_sys)) / 200000000.0f);
  auto slice = pwm_gpio_to_slice_num(pin::Pitch);
  pwm_init(slice, &config, false);
  pwm_set_both_levels(slice, duty(0, s.pitch), duty(0, s.auxiliary));
  gpio_set_function(pin::Pitch, GPIO_FUNC_PWM);
  gpio_set_function(pin::Aux, GPIO_FUNC_PWM);
  pwm_set_enabled(slice, true);
  for (unsigned p : {pin::Click, pin::EncoderA, pin::EncoderB, pin::Minus,
                     pin::Plus, pin::Clock, pin::Reset}) {
    gpio_init(p);
    gpio_set_dir(p, GPIO_IN);
    gpio_pull_up(p);
  }
  for (unsigned p : {pin::LedMinus, pin::LedPlus}) {
    gpio_init(p);
    gpio_put(p, 0);
    gpio_set_dir(p, GPIO_OUT);
  }
  previous = detent = uint8_t((gpio_get(pin::EncoderA) ? 2 : 0) |
                              (gpio_get(pin::EncoderB) ? 1 : 0));
  touchOk = mprConfigured = mprInit();
  adc_init();
  adc_gpio_init(pin::Cv);
  adc_select_input(0);
  auto offset = pio_add_program(pio0, &rgb_program);
  rgbSm = pio_claim_unused_sm(pio0, true);
  auto pc = rgb_program_get_default_config(offset);
  sm_config_set_sideset_pins(&pc, pin::Rgb);
  // The diagnostic firmware confirmed a 24-bit GRB stream at 800 kHz.
  // Keep the pull threshold aligned with the three-byte pixel protocol.
  sm_config_set_out_shift(&pc, false, true, 24);
  sm_config_set_fifo_join(&pc, PIO_FIFO_JOIN_TX);
  sm_config_set_clkdiv(&pc, float(clock_get_hz(clk_sys)) / 8000000.0f);
  pio_gpio_init(pio0, pin::Rgb);
  pio_sm_set_consecutive_pindirs(pio0, rgbSm, pin::Rgb, 1, true);
  pio_sm_init(pio0, rgbSm, offset, &pc);
  pio_sm_set_enabled(pio0, rgbSm, true);
  // Start the sequence on the first rising edge seen by the MCU.  The
  // conditioned clock input is exposed as a normal digital edge here; using
  // only the rising edge prevents the first pulse from being lost while the
  // transport is arming.
  gpio_set_irq_enabled_with_callback(pin::Clock, GPIO_IRQ_EDGE_RISE, true, irq);
  gpio_set_irq_enabled(pin::Reset, GPIO_IRQ_EDGE_FALL, true);
  for (unsigned p : {pin::EncoderA, pin::EncoderB})
    gpio_set_irq_enabled(p, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
}
Input poll(uint64_t now) {
  Input in{};
  auto mask = save_and_disable_interrupts();
  in.turn = turns;
  turns = 0;
  restore_interrupts(mask);
  click.poll(now);
  minus.poll(now);
  plus.poll(now);
  in.click = click.release;
  in.longClick = click.longPress;
  in.minus = minus.press;
  in.plus = plus.press;
  in.minusHeld = minus.stable;
  in.plusHeld = plus.stable;
  gpio_put(pin::LedMinus, minus.stable);
  gpio_put(pin::LedPlus, plus.stable);
  if (mprConfigured && now >= nextTouch) {
      // Keep live recording responsive: the MPR121 is sampled every 1 ms.
      nextTouch = now + (touchOk ? 1000 : 100000);
    uint8_t b[2]{};
    if (rd(0, b, 2)) {
      touchOk = true;
      uint16_t raw = uint16_t(b[0]) | (uint16_t(b[1] & 15) << 8), mapped = 0;
      for (unsigned k = 0; k < 12; ++k)
        if (raw & (1u << electrodes[k]))
          mapped |= 1u << k;
      for (unsigned k = 0; k < 12; ++k) {
        if (!(mapped & (1u << k))) continue;
        const uint8_t electrode = electrodes[k];
        uint8_t filteredBytes[2]{}, baselineByte = 0;
        if (rd(uint8_t(0x04 + electrode * 2), filteredBytes, 2) &&
            rd(uint8_t(0x1E + electrode), &baselineByte, 1)) {
          const uint16_t filtered = uint16_t(filteredBytes[0]) |
                                    (uint16_t(filteredBytes[1] & 0x03) << 8);
          const uint16_t baseline = uint16_t(baselineByte) << 2;
          // Filtered data decreases as finger capacitance increases.
          in.touchCap[k] = baseline > filtered ? baseline - filtered : 0;
        }
      }
      in.pressed = mapped & ~keys;
      keys = mapped;
    } else {
      touchOk = false;
      keys = 0;
    }
  }
  in.touchOk = touchOk;
  in.keys = keys;
  in.cvRaw = adc_read();
  return in;
}
bool popEdge(Edge &e) {
  auto mask = save_and_disable_interrupts();
  bool found = tail != head;
  if (found) {
    e = edges[tail];
    tail = (tail + 1) % 64;
  }
  restore_interrupts(mask);
  return found;
}
bool overflowed() {
  auto mask = save_and_disable_interrupts();
  bool v = overrun;
  overrun = false;
  restore_interrupts(mask);
  return v;
}
void clearEdges() {
  auto mask = save_and_disable_interrupts();
  tail = head;
  overrun = false;
  restore_interrupts(mask);
}
void write(const Output &o, const Settings &s) {
  pwm_set_both_levels(pwm_gpio_to_slice_num(pin::Pitch), duty(o.pitch, s.pitch),
                      duty(o.aux, s.auxiliary));
  gpio_put(pin::Gate, o.gate ? 0 : 1);
}
void leds(uint16_t held, int selected, int playing, uint8_t brightness,
          bool recording, const uint16_t *touchCap, bool orangeSelected,
          int selectedNote, const uint8_t *keyNotes) {
  for (int k = 0; k < 12; ++k) {
    // Unused pixels must be completely dark.  A non-zero blue floor leaves
    // the last playhead visibly latched when transport stops.
    unsigned r = 0, g = 0, b = 0;
    if (orangeSelected) {
      // KEY EDIT: every assigned key is visible at low intensity. The note
      // octave maps from blue/cold to red/warm; the edited key is brighter.
      const int note = (k == selected) ? selectedNote
                                       : (keyNotes ? keyNotes[k] : 36 + k);
      const int oct = std::clamp(note / 12, 0, 8);
      const int hue = 240 - oct * 30;
      const int sector = hue / 60;
      const int f = (hue % 60) * 255 / 60;
      const int q = 255 - f;
      switch (sector) {
      case 0: r = 255; g = f; b = 0; break;
      case 1: r = q; g = 255; b = 0; break;
      case 2: r = 0; g = 255; b = f; break;
      case 3: r = 0; g = q; b = 255; break;
      default: r = 0; g = 0; b = 255; break;
      }
      if (k != selected) { r /= 5; g /= 5; b /= 5; }
    } else if (playing >= 0) {
      // LIVE playback: every key stays visible dimly in blue; the sounding
      // key is overwritten below with the brighter pink playhead color.
      r = 0;
      g = 0;
      b = 255 / 2;
    } else if (k == selected && playing < 0) {
      if (orangeSelected) {
        r = 255;
        g = 72;
        b = 0;
      } else {
        // Browsing a recorded step uses a blue/violet marker. The key editor
        // passes orangeSelected=true for its dedicated orange cursor.
        r = 64;
        g = 8;
        b = 220;
      }
    }
    // A directly touched pad has priority over the sequence playhead.  This
    // prevents a currently sounding sequence key from appearing as a second
    // blinking address when the performer touches another pad.
    if (k == playing && held == 0) {
      // Played note: violet. Recording remains warm pink/red.
      r = recording ? 220 : 150;
      g = recording ? 0 : 8;
      b = recording ? 70 : 255;
    }
    if (held & (1u << k)) {
      // A finger on a pad takes priority over the playback indication.
      if (recording) {
        r = 255;
        g = 0;
        b = 0;
      } else {
        r = 255;
        g = 20;
        b = 160;
      }
      // MPR121 filtered capacitance controls the intensity of the touched
      // pad. Keep a visible floor so a light touch is still identifiable.
      if (touchCap) {
        const unsigned level = 32u +
            (std::min<unsigned>(touchCap[k], 1023u) * 223u) / 1023u;
        r = r * level / 255u;
        g = g * level / 255u;
        b = b * level / 255u;
      }
    }
    r = r * brightness / 255;
    g = g * brightness / 255;
    b = b * brightness / 255;
    // Physical RGB chain mapping confirmed by the diagnostic firmware.
    unsigned packet = 8 - 4 * unsigned(k / 4) + unsigned(k % 4);
    colors[packet] = ((g << 16) | (r << 8) | b) << 8;
  }
  // Use the exact blocking 12-pixel transfer validated by the standalone
  // RGB diagnostic. Keeping the framebuffer immutable until all 12 packets
  // have entered the PIO prevents partial-frame updates and ghost pixels.
  pio_sm_clear_fifos(pio0, rgbSm);
  pio_sm_restart(pio0, rgbSm);
  for (uint32_t color : colors)
    pio_sm_put_blocking(pio0, rgbSm, color);
  // Allow the remaining FIFO words to drain and the SK6812 reset interval
  // to latch the complete frame before another frame can begin.
  sleep_us(800);
}
void serviceLeds() {}
} // namespace t12::hw
