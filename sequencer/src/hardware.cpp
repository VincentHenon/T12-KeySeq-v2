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
unsigned rgbNext = 12, rgbSm = 0;
uint64_t rgbLatch = 0;
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
uint16_t duty(float v, const Calibration &c) {
  return uint16_t(
      std::lround(std::clamp((c.intercept - std::clamp(v, 0.0f, 8.0f)) / c.span,
                             0.0f, 1.0f) *
                  4095));
}
bool clockHigh() { return gpio_get(pin::Clock); }
bool resetHigh() { return gpio_get(pin::Reset); }
void init(const Settings &s) {
  gpio_init(pin::Gate);
  gpio_put(pin::Gate, 0);
  gpio_set_dir(pin::Gate, GPIO_OUT);
  auto config = pwm_get_default_config();
  pwm_config_set_wrap(&config, 4095);
  // 48.828 kHz independently of system clock (125 MHz needs divider 0.625,
  // therefore main selects the previously tested 200 MHz clock first).
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
  sm_config_set_out_shift(&pc, false, true, 24);
  sm_config_set_fifo_join(&pc, PIO_FIFO_JOIN_TX);
  sm_config_set_clkdiv(&pc, float(clock_get_hz(clk_sys)) / 8000000.0f);
  pio_gpio_init(pio0, pin::Rgb);
  pio_sm_set_consecutive_pindirs(pio0, rgbSm, pin::Rgb, 1, true);
  pio_sm_init(pio0, rgbSm, offset, &pc);
  pio_sm_set_enabled(pio0, rgbSm, true);
  // The T12 Clock conditioning presents the useful Pamela clock transition
  // as a rising edge at GP3. Reset remains an active-low, falling-edge input.
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
    nextTouch = now + (touchOk ? 5000 : 100000);
    uint8_t b[2]{};
    if (rd(0, b, 2)) {
      touchOk = true;
      uint16_t raw = uint16_t(b[0]) | (uint16_t(b[1] & 15) << 8), mapped = 0;
      for (unsigned k = 0; k < 12; ++k)
        if (raw & (1u << electrodes[k]))
          mapped |= 1u << k;
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
  gpio_put(pin::Gate, o.gate);
}
void leds(uint16_t held, int selected, int playing, uint8_t brightness,
          bool recording) {
  if (rgbNext < 12 || time_us_64() < rgbLatch)
    return;
  for (int k = 0; k < 12; ++k) {
    unsigned r = 0, g = 0, b = 4;
    if (k == selected) {
      r = 12;
      g = 12;
      b = 32;
    }
    if (k == playing) {
      // Played note: violet. Recording remains warm pink/red.
      r = recording ? 220 : 150;
      g = recording ? 0 : 8;
      b = recording ? 70 : 255;
    }
    if (held & (1u << k)) {
      // A finger on a pad takes priority over the playback indication.
      r = 255;
      g = 20;
      b = 160;
    }
    r = r * brightness / 255;
    g = g * brightness / 255;
    b = b * brightness / 255;
    // The RGB chain starts at the bottom-left and its three physical rows run
    // left-to-right. Reverse the row order only, so LED k occupies the same
    // panel cell as logical Key k.
    unsigned packet = 8 - 4 * unsigned(k / 4) + unsigned(k % 4);
    colors[packet] = ((g << 16) | (r << 8) | b) << 8;
  }
  rgbNext = 0;
}
void serviceLeds() {
  while (rgbNext < 12 && !pio_sm_is_tx_fifo_full(pio0, rgbSm))
    pio_sm_put(pio0, rgbSm, colors[rgbNext++]);
  // FIFO can still contain 8 words plus one active word (270 us), then reset.
  if (rgbNext == 12) {
    rgbNext = 13;
    rgbLatch = time_us_64() + 600;
  }
}
} // namespace t12::hw
