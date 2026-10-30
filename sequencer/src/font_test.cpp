#include "display.hpp"
#include "hardware.hpp"
#include "hardware/clocks.h"
#include "hardware/vreg.h"
#include "pico/stdlib.h"
#include <algorithm>
#include <cstdio>

using namespace t12;

namespace {
unsigned scale = 1;
bool bold = false, lastClick = true;
uint8_t encState = 0;
int encAccum = 0;

void draw() {
  Canvas c; c.clear(); char line[32];
  std::snprintf(line, sizeof line, "FONT %u  %s", scale, bold ? "BOLD" : "NORMAL");
  c.text(0, 0, line);
  if (scale == 1) {
    c.textScaled(0, 13, "AaBbCc 0123", 1, bold);
    c.text(0, 25, "SIZE 5x7");
  } else {
    c.textScaled(0, 12, "T12", scale, bold);
    std::snprintf(line, sizeof line, "SIZE %ux%u", 5 * scale, 7 * scale);
    c.text(0, 55, line);
  }
  display::publish(c);
}
}

int main() {
  vreg_set_voltage(VREG_VOLTAGE_1_20); sleep_ms(10);
  set_sys_clock_khz(200000, true); stdio_init_all(); display::launch();
  for (auto p : {hw::pin::EncoderA, hw::pin::EncoderB, hw::pin::Click}) {
    gpio_init(p); gpio_set_dir(p, false); gpio_pull_up(p);
  }
  encState = uint8_t((gpio_get(hw::pin::EncoderA) ? 2 : 0) |
                     (gpio_get(hw::pin::EncoderB) ? 1 : 0));
  draw();
  static const int8_t q[16] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0};
  while (true) {
    const uint8_t next = uint8_t((gpio_get(hw::pin::EncoderA) ? 2 : 0) |
                                 (gpio_get(hw::pin::EncoderB) ? 1 : 0));
    if (next != encState) {
      encAccum += q[(encState << 2) | next]; encState = next;
      if (std::abs(encAccum) >= 4) {
        scale = unsigned(std::clamp(int(scale) + (encAccum > 0 ? 1 : -1), 1, 5));
        encAccum = 0; draw();
      }
    }
    const bool click = !gpio_get(hw::pin::Click);
    if (lastClick && click) { bold = !bold; draw(); }
    lastClick = !click; sleep_ms(1);
  }
}
