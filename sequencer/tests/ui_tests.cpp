#include "storage.hpp"
#include "ui.hpp"
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace t12;
namespace {
Project slots[Slots];
bool occupied[Slots]{};
Settings globals;
bool settingsSaved = false;
bool writtenGate = false;
} // namespace
namespace t12::hw {
void clearEdges() {}
void write(const Output &o, const Settings &) { writtenGate = o.gate; }
bool clockHigh() { return true; }
bool resetHigh() { return true; }
} // namespace t12::hw
namespace t12::storage {
bool loadProject(unsigned n, Project &p) {
  if (n >= Slots || !occupied[n])
    return false;
  p = slots[n];
  return true;
}
bool saveProject(unsigned n, const Project &p) {
  assert(!writtenGate);
  assert(valid(p));
  if (n >= Slots)
    return false;
  slots[n] = p;
  occupied[n] = true;
  return true;
}
bool clearProject(unsigned n) {
  assert(!writtenGate);
  occupied[n] = false;
  return true;
}
bool saveSettings(const Settings &s) {
  assert(!writtenGate);
  assert(valid(s));
  globals = s;
  settingsSaved = true;
  return true;
}
} // namespace t12::storage
struct Fixture {
  Project p;
  Settings s;
  Engine engine;
  Ui ui;
  uint64_t now = 1000000;
  Fixture() : engine(p, s), ui(p, s, engine) { s.reverseEncoder = 0; }
  void send(hw::Input in) {
    now += 20000;
    in.touchOk = true;
    ui.input(in, now);
    engine.update(now);
  }
  void click() {
    hw::Input in{};
    in.click = true;
    send(in);
  }
  void turn(int n) {
    hw::Input in{};
    in.turn = n;
    send(in);
  }
  void menu(unsigned row) {
    hw::Input in{};
    in.longClick = true;
    send(in);
    turn(row);
    click();
  }
  void key(unsigned k) {
    hw::Input in{};
    in.keys = in.pressed = 1u << k;
    send(in);
    send({});
  }
  void plus() {
    hw::Input in{};
    in.plus = true;
    send(in);
  }
  void minus() {
    hw::Input in{};
    in.minus = true;
    send(in);
  }
  void capture(const char *file) {
    Canvas c;
    ui.draw(c, now + 3000000);
    FILE *f = std::fopen(file, "wb");
    assert(f);
    std::fwrite(c.data, 1, 1024, f);
    std::fclose(f);
  }
};
void recording_and_editing() {
  Fixture f;
  f.menu(2);
  f.turn(-1);
  f.click();
  assert(f.ui.recording());
  f.key(3);
  f.key(7);
  f.minus();
  assert(f.p.length == 3 && f.p.steps[2].time == 0);
  f.plus();
  assert(f.p.length == 2);
  f.key(11);
  f.click();
  assert(!f.ui.recording() && f.p.length == 3);
  f.menu(3);
  f.turn(1);
  f.key(5);
  assert(f.p.steps[1].key == 5);
  f.click();
  f.click();
  f.turn(-2);
  f.click();
  assert(f.p.steps[1].time == -1);
  f.turn(1);
  f.click();
  assert(f.p.steps[1].retrigger);
  f.turn(1);
  f.click();
  f.turn(2);
  f.click();
  assert(f.p.steps[1].ratchet == 3);
  f.turn(1);
  f.click();
  assert(f.p.steps[1].glide);
  f.turn(1);
  f.click();
  assert(f.p.steps[1].vibrato);
  f.capture("/private/tmp/t12-parameters.fb");
  f.menu(2);
  f.turn(-1);
  f.click();
  for (unsigned i = 0; i < 32; ++i)
    f.key(i % 12);
  assert(f.p.length == 32 && !f.ui.recording());
  auto last = f.p.steps[31].key;
  f.key(0);
  assert(f.p.steps[31].key == last && f.p.length == 32);
  f.capture("/private/tmp/t12-play.fb");
}
void keys_and_scales() {
  Fixture f;
  f.menu(1);
  f.key(5);
  f.turn(3);
  assert(f.p.notes[5] == 44);
  f.minus();
  assert(f.p.notes[5] == 32);
  f.capture("/private/tmp/t12-keys.fb");
  f.menu(4);
  f.click();
  f.turn(1);
  f.click();
  assert(f.p.scale == 1 && f.p.notes[5] == 32);
  f.turn(3);
  f.click(); // user scale 1 editor
  f.turn(1);
  f.click();
  f.capture("/private/tmp/t12-user-scale.fb");
  f.plus();
  assert(settingsSaved && f.p.scale == BuiltinScales &&
         (globals.userScales[0] & 2));
}
void clock_save_and_load() {
  Fixture f;
  f.menu(5);
  f.turn(1);
  f.click();
  f.turn(10);
  f.click();
  assert(f.s.bpm == 130);
  f.capture("/private/tmp/t12-clock.fb");
  f.menu(0);
  assert(f.engine.running());
  writtenGate = true;
  f.p.length = 1;
  f.p.steps[0].key = 9;
  f.menu(7);
  f.click();
  f.click();
  f.turn(1);
  f.plus(); // save named slot 1
  assert(occupied[0] && slots[0].steps[0].key == 9 && !writtenGate);
  f.p.steps[0].key = 1;
  f.turn(1);
  f.click(); // load saved project
  assert(f.p.steps[0].key == 9 && !f.engine.running());
}
int main() {
  recording_and_editing();
  keys_and_scales();
  clock_save_and_load();
  std::puts("3 UI regression groups passed");
}
