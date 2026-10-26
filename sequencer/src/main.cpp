#include "hardware/clocks.h"
#include "hardware/vreg.h"
#include "pico/stdlib.h"
#include "storage.hpp"
#include "ui.hpp"
#include <cstdio>
using namespace t12;
int main() {
  // Same 200 MHz system clock as the working Arduino diagnostic: 200e6/4096
  // gives a 48.828 kHz PWM carrier. RP2040 is overclocked, as in that test.
  vreg_set_voltage(VREG_VOLTAGE_1_20);
  sleep_ms(10);
  set_sys_clock_khz(200000, true);
  stdio_init_all();
  static Settings settings{};
  static Project project{};
  storage::init();
  storage::loadSettings(settings);
  storage::loadProject(0, project);
  hw::init(settings);
  display::launch();
  static Engine engine(project, settings);
  static Ui ui(project, settings, engine);
  static Canvas canvas;
  canvas.text(0, 8, "T12 SEQUENCER");
  canvas.text(0, 24, "MVP 0.1.2");
  canvas.text(0, 40, "C++ PICO SDK");
  display::publish(canvas);
  sleep_ms(600);
  hw::clearEdges();
  uint64_t nextUi = 0, nextLeds = 0;
  std::printf("T12 Sequencer 0.1.2 / native Pico SDK / storage %s\n",
              storage::available() ? "ready" : "unavailable");
  while (true) {
    uint64_t now = time_us_64();
    hw::Edge edge{};
    while (hw::popEdge(edge)) {
      if (edge.reset)
        engine.reset(edge.time);
      else
        engine.clockEdge(edge.time);
    }
    // An IRQ drained above may be newer than the timestamp at loop entry.
    now = time_us_64();
    if (hw::overflowed()) {
      engine.stop();
      ui.fault("CLOCK OVERFLOW", now);
      hw::clearEdges();
    }
    engine.update(now);
    hw::write(ui.calibrationActive() ? ui.calibrationOutput() : engine.output(),
              settings);
    auto input = hw::poll(now);
    ui.input(input, now);
    // Refresh time after potentially slow flash operations in a UI action.
    now = time_us_64();
    engine.update(now);
    if (ui.settingsSaveDue(now) && !engine.running())
      ui.autoSaveSettings(now);
    hw::write(ui.calibrationActive() ? ui.calibrationOutput() : engine.output(),
              settings);
    if (now >= nextUi) {
      nextUi = now + 50000;
      ui.draw(canvas, now);
      display::publish(canvas);
    }
    if (now >= nextLeds) {
      nextLeds = now + 30000;
      hw::leds(input.keys, ui.selectedKey(), engine.soundingKey(),
               settings.brightness, ui.recording());
    }
    hw::serviceLeds();
    sleep_us(100);
  }
}
