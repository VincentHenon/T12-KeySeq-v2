#include "display.hpp"
#include "hardware.hpp"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "hardware/vreg.h"
#include "pico/stdlib.h"
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace t12;

namespace {
constexpr unsigned Top = 8191;
constexpr unsigned Targets = 5;
constexpr unsigned Plus = hw::pin::Plus, Minus = hw::pin::Minus;
int target = 0, page = 0, selected = 0;
bool editing = false, lastPlus = true, lastMinus = true;
uint64_t clickDown = 0;
bool longSent = false;
int coarseMv[Targets]{}, fineMv[Targets]{};
float resultV = 0;

void pwmWrite(float volts) {
  volts = std::clamp(volts, 0.0f, 8.0f);
  const auto slice = pwm_gpio_to_slice_num(hw::pin::Pitch);
  const uint16_t level = uint16_t(std::lround((1.0f - volts / 8.0f) * Top));
  pwm_set_both_levels(slice, level, level);
}

float correction(float volts) {
  const float pos = std::clamp(volts / 2.0f, 0.0f, 4.0f);
  const unsigned i = std::min(3u, unsigned(pos));
  const float f = pos - float(i);
  const float a = (coarseMv[i] + fineMv[i] / 10.0f) / 1000.0f;
  const float b = (coarseMv[i + 1] + fineMv[i + 1] / 10.0f) / 1000.0f;
  return a + (b - a) * f;
}

void drawSlider(Canvas &c, int y, const char *name, int value, int lo, int hi,
                bool active) {
  c.text(0, y, name);
  c.box(35, y, 88, 7, false, true);
  const int x = 36 + (value - lo) * 86 / std::max(1, hi - lo);
  c.box(std::clamp(x, 36, 121), y + 1, 3, 5, true, active);
  char s[24]; std::snprintf(s, sizeof s, "%d", value);
  c.text(0, y + 9, s);
}

void draw() {
  Canvas c; c.clear(); char line[32];
  if (page == 0) {
    c.text(0, 0, "CV CALIBRATION");
    std::snprintf(line, sizeof line, "TARGET: %d V", target * 2); c.text(0, 12, line);
    drawSlider(c, 25, "COARSE", coarseMv[target], -1000, 1000, selected == 0);
    drawSlider(c, 45, "FINE", fineMv[target], -100, 100, selected == 1);
    c.text(0, 58, editing ? "TURN VALUE  CLICK OK" : "CLICK EDIT  HOLD NEXT");
  } else {
    c.text(0, 0, "CV CALIBRATION RESULT");
    std::snprintf(line, sizeof line, "OUTPUT: %.1f V", double(resultV)); c.text(0, 14, line);
    std::snprintf(line, sizeof line, "CORRECTION: %+.3f V", double(correction(resultV))); c.text(0, 27, line);
    c.text(0, 42, "- / +  SELECT 0-8 V OCTAVE");
    c.text(0, 56, "HOLD ENCODER: CALIBRATE");
  }
  display::publish(c);
}

void encoderTurn(int direction) {
  if (page == 1) return;
  if (editing) {
    if (selected == 0) coarseMv[target] = std::clamp(coarseMv[target] + direction * 10, -1000, 1000);
    else fineMv[target] = std::clamp(fineMv[target] + direction, -100, 100);
    // Apply the edited calibration point immediately to both CV outputs.
    pwmWrite(float(target * 2) + correction(float(target * 2)));
  } else selected = (selected + (direction > 0 ? 1 : -1) + 2) % 2;
  draw();
}
}

int main() {
  vreg_set_voltage(VREG_VOLTAGE_1_20); sleep_ms(10); set_sys_clock_khz(200000, true);
  stdio_init_all(); display::launch();
  for (auto p : {hw::pin::EncoderA, hw::pin::EncoderB, hw::pin::Click, Plus, Minus}) {
    gpio_init(p); gpio_set_dir(p, false); gpio_pull_up(p);
  }
  auto cfg = pwm_get_default_config(); pwm_config_set_wrap(&cfg, Top);
  pwm_config_set_clkdiv(&cfg, float(clock_get_hz(clk_sys)) / 200000000.0f);
  auto slice = pwm_gpio_to_slice_num(hw::pin::Pitch); pwm_init(slice, &cfg, false);
  gpio_set_function(hw::pin::Pitch, GPIO_FUNC_PWM); gpio_set_function(hw::pin::Aux, GPIO_FUNC_PWM);
  pwm_set_enabled(slice, true); pwmWrite(0); draw();
  bool a = gpio_get(hw::pin::EncoderA), b = gpio_get(hw::pin::EncoderB); int acc = 0;
  const int8_t q[16] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  uint8_t state = uint8_t((a ? 2 : 0) | (b ? 1 : 0));
  while (true) {
    const uint8_t next = uint8_t((gpio_get(hw::pin::EncoderA) ? 2 : 0) |
                                 (gpio_get(hw::pin::EncoderB) ? 1 : 0));
    if (next != state) { acc += q[(state << 2) | next]; state = next;
      if (std::abs(acc) >= 4) { encoderTurn(acc > 0 ? 1 : -1); acc = 0; }
    }
    const bool click = !gpio_get(hw::pin::Click);
    if (click && !clickDown) { clickDown = time_us_64(); longSent = false; }
    if (click && !longSent && time_us_64() - clickDown > 700000) {
      page = 1 - page; editing = false; longSent = true; resultV = 0; pwmWrite(0); draw();
    }
    if (!click && clickDown) {
      if (!longSent) { editing = !editing; draw(); }
      clickDown = 0;
    }
    const bool plus = gpio_get(Plus), minus = gpio_get(Minus);
    if (lastPlus && !plus) {
      if (page == 0) target = std::min(4, target + 1);
      else resultV = std::min(8.0f, resultV + 1.0f);
      pwmWrite(page == 0 ? float(target * 2) + correction(float(target * 2)) : resultV + correction(resultV)); draw();
    }
    if (lastMinus && !minus) {
      if (page == 0) target = std::max(0, target - 1);
      else resultV = std::max(0.0f, resultV - 1.0f);
      pwmWrite(page == 0 ? float(target * 2) + correction(float(target * 2)) : resultV + correction(resultV)); draw();
    }
    lastPlus = plus; lastMinus = minus; sleep_ms(1);
  }
}
