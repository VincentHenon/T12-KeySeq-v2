#include "display.hpp"
#include "hardware.hpp"
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "hardware/vreg.h"
#include "pico/stdlib.h"
#include <cstdio>
#include <initializer_list>
using namespace t12;
namespace {
unsigned bits = 12, volts = 0;
bool lastPlus = true, lastMinus = true;
volatile int encoderTurns = 0;
uint8_t encoderPrevious = 0, encoderDetent = 0;
int encoderQuarters = 0;

void encoderIrq(unsigned gpio, uint32_t) {
  if (gpio != hw::pin::EncoderA && gpio != hw::pin::EncoderB) return;
  const uint8_t state = uint8_t((gpio_get(hw::pin::EncoderA) ? 2 : 0) |
                                (gpio_get(hw::pin::EncoderB) ? 1 : 0));
  static constexpr int8_t table[16] = {0, -1, 1, 0, 1, 0, 0, -1,
                                        -1, 0, 0, 1, 0, 1, -1, 0};
  if ((encoderPrevious ^ state) == 3) {
    encoderQuarters = 0;  // invalid two-bit transition: contact bounce
  } else {
    encoderQuarters += table[(encoderPrevious << 2) | state];
  }
  encoderPrevious = state;
  if (state == encoderDetent) {
    if (encoderQuarters >= 4) ++encoderTurns;
    if (encoderQuarters <= -4) --encoderTurns;
    encoderQuarters = 0;
  }
}
void configure(){ uint16_t top=(1u<<bits)-1; auto c=pwm_get_default_config(); pwm_config_set_wrap(&c,top); pwm_config_set_clkdiv(&c,1.f); auto s=pwm_gpio_to_slice_num(hw::pin::Pitch); pwm_init(s,&c,false); gpio_set_function(hw::pin::Pitch,GPIO_FUNC_PWM); gpio_set_function(hw::pin::Aux,GPIO_FUNC_PWM); pwm_set_enabled(s,true); }
void output(){ uint16_t top=(1u<<bits)-1; uint16_t d=uint16_t((uint32_t(top)*(8-volts))/8); auto s=pwm_gpio_to_slice_num(hw::pin::Pitch); pwm_set_both_levels(s,d,d); }
void draw(){ Canvas c; c.text(0,0,"PWM CV TEST"); char b[32]; std::snprintf(b,sizeof b,"RES: %u BITS",bits); c.text(0,16,b); std::snprintf(b,sizeof b,"CV: %u V INVERTED",volts); c.text(0,30,b); uint32_t f=200000000u/(1u<<bits); std::snprintf(b,sizeof b,"CARRIER: %u HZ",f); c.text(0,44,b); c.text(0,56,"ENC RES +/- CV"); display::publish(c); }
}
int main() {
  vreg_set_voltage(VREG_VOLTAGE_1_20); sleep_ms(10); set_sys_clock_khz(200000,true);
  stdio_init_all(); display::launch();
  for (auto p : {hw::pin::EncoderA, hw::pin::EncoderB, hw::pin::Plus, hw::pin::Minus}) {
    gpio_init(p); gpio_set_dir(p, false); gpio_pull_up(p);
  }
  encoderPrevious = encoderDetent = uint8_t((gpio_get(hw::pin::EncoderA) ? 2 : 0) |
                                             (gpio_get(hw::pin::EncoderB) ? 1 : 0));
  gpio_set_irq_enabled_with_callback(hw::pin::EncoderA, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &encoderIrq);
  gpio_set_irq_enabled(hw::pin::EncoderB, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
  configure(); output(); draw();
  while (true) {
    if (encoderTurns) {
      const int turn = encoderTurns; encoderTurns = 0;
      const int next = int(bits) + (turn > 0 ? 1 : -1) * (turn > 0 ? turn : -turn) * 2;
      if (next <= 10) bits = 10;
      else if (next <= 12) bits = 12;
      else bits = 14;
      configure(); output(); draw();
    }
    const bool plus = gpio_get(hw::pin::Plus), minus = gpio_get(hw::pin::Minus);
    if (lastPlus && !plus && volts < 8) { volts += 2; output(); draw(); }
    if (lastMinus && !minus && volts > 0) { volts -= 2; output(); draw(); }
    lastPlus = plus; lastMinus = minus; sleep_ms(1);
  }
}
