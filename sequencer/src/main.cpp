#include "hardware/clocks.h"
#include "hardware/vreg.h"
#include "pico/stdlib.h"
#include "storage.hpp"
#include "usb_protocol.hpp"
#include "ui.hpp"
#include <cstdio>
using namespace t12;
int main() {
  // 200 MHz / 8192 gives the selected 13-bit, 24.414 kHz PWM carrier.
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
  canvas.text(0, 24, "MVP 0.1.99");
  canvas.text(0, 40, "C++ PICO SDK");
  display::publish(canvas);
  sleep_ms(600);
  hw::clearEdges();
  uint64_t nextUi = 0, nextLeds = 0;
  bool ledTransportRunning = engine.running();
  std::printf("T12 Sequencer 0.1.99 / native Pico SDK / storage %s\n",
              storage::available() ? "ready" : "unavailable");
  while (true) {
    usbproto::service(project, settings);
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
    // Advance the clocked engine before handling a manual touch.  A preview
    // must be the final musical event in this loop; otherwise engine.update()
    // can immediately overwrite it while a sequence is running.
    engine.update(now);
    auto input = hw::poll(now);
    ui.input(input, now);
    const bool transportRunning = engine.running();
    if (ledTransportRunning && !transportRunning) {
      // Clear the playhead immediately when transport stops; do not wait for
      // the next scheduled LED refresh.
      hw::leds(0, -1, -1, settings.brightness, false, nullptr, false);
      nextLeds = now + 30000;
    }
    ledTransportRunning = transportRunning;
    while (engine.consumeRetrigger()) {
      auto low = engine.output();
      low.gate = false;
      hw::write(low, settings);
      // The external gate conditioner needs a real low interval.  Writing
      // all queued retriggers low and restoring high only once at the end
      // collapses rapid key events into a single gate.  Complete each pulse
      // separately so every preview/step produces a detectable edge.
      sleep_us(100);
      hw::write(engine.output(), settings);
    }
    // Refresh time after input handling and any potentially slow flash action.
    now = time_us_64();
    if (ui.settingsSaveDue(now) && !engine.running())
      ui.autoSaveSettings(now);
    if (ui.projectSaveDue(now) && !engine.running())
      ui.autoSaveProject(now);
    hw::write(ui.calibrationActive() ? ui.calibrationOutput() : engine.output(),
              settings);
    if (now >= nextUi) {
      nextUi = now + 50000;
      ui.draw(canvas, now);
      display::publish(canvas);
    }
    if (now >= nextLeds) {
      nextLeds = now + 30000;
      // In Play mode a held key controls the live note but must not latch its
      // pad LED. Held-touch highlighting remains useful in recording/editing.
      hw::leds(ui.recording() ? input.keys : 0,
               ui.showSelectedLed() ? ui.selectedKey() : -1,
               ui.showPlayingLed() ? engine.soundingKey() : -1,
               settings.brightness, ui.recording(), input.touchCap,
               ui.keyEditing(), ui.selectedKeyNote(), ui.keyNotes());
    }
    hw::serviceLeds();
    sleep_us(100);
  }
}
