#include "engine.hpp"
#include <cassert>
#include <cmath>
#include <cstdio>
using namespace t12;
constexpr uint64_t T = 1000000;
void near(float a, float b, float tolerance = 0.001f) {
  assert(std::fabs(a - b) < tolerance);
}
void defaults_and_scales() {
  Project p;
  Settings s;
  assert(valid(p) && valid(s));
  for (unsigned scale = 0; scale < scaleCount(); ++scale)
    for (unsigned root = 0; root < 12; ++root) {
      p.scale = scale;
      p.root = root;
      for (int n = 0; n <= MaxNote; ++n) {
        auto q = quantize(n, p, s);
        assert(q >= 0 && q <= MaxNote && allowed(q, p, s));
      }
    }
  p = Project{};
  p.notes[0] = 37;
  p.scale = 1;
  assert(keyNote(0, p, s) == 36);
  assert(p.notes[0] == 37);
  p.scale = 0;
  assert(keyNote(0, p, s) == 37); // adaptation never destroys assignment
  p.scale = 1;
  fillKeys(p, s);
  for (unsigned k = 0; k < Keys; ++k)
    assert(allowed(p.notes[k], p, s));
  s.userScales[0] = 0;
  assert(!valid(s));
  s = Settings{};
  s.pitch.span = NAN;
  assert(!valid(s));
  p.steps[0].key = 12;
  assert(!valid(p));
}
void rest_and_loop() {
  Project p;
  Settings s;
  s.clock = ClockMode::Internal;
  p.length = 3;
  p.steps[0].key = 0;
  p.steps[1].time = 0;
  p.steps[2].key = 4;
  Engine e(p, s);
  e.start(T);
  e.update(T);
  assert(e.playhead() == 0 && e.output().gate);
  near(e.output().pitch, 3);
  e.update(T + 250000);
  assert(!e.output().gate);
  e.update(T + 500000);
  assert(e.playhead() == 1 && !e.output().gate);
  e.update(T + 750000);
  assert(e.playhead() == 1);
  e.update(T + 1000000);
  assert(e.playhead() == 2 && e.output().gate);
  e.update(T + 1250000);
  e.update(T + 1500000);
  assert(e.playhead() == 0);
}
void half_steps() {
  Project p;
  Settings s;
  s.clock = ClockMode::Internal;
  p.length = 3;
  p.steps[0].time = -1;
  p.steps[1].time = -1;
  p.steps[2].time = 1;
  Engine e(p, s);
  e.start(T);
  e.update(T);
  assert(e.playhead() == 0);
  e.update(T + 125000);
  assert(!e.output().gate);
  e.update(T + 250000);
  assert(e.playhead() == 1);
  e.update(T + 500000);
  assert(e.playhead() == 2);
  e.update(T + 750000);
  assert(e.playhead() == 2);
  e.update(T + 1000000);
  assert(e.playhead() == 0);
}
void hold_and_retrigger() {
  for (int retrigger = 0; retrigger < 2; ++retrigger) {
    Project p;
    Settings s;
    s.clock = ClockMode::Internal;
    p.length = 2;
    p.steps[0].time = 3;
    p.steps[0].retrigger = retrigger;
    Engine e(p, s);
    e.start(T);
    e.update(T);
    e.update(T + 250000);
    assert(e.output().gate == !retrigger);
    e.update(T + 500000);
    assert(e.playhead() == 0 && e.output().gate);
    e.update(T + 750000);
    assert(!e.output().gate);
    e.update(T + 1000000);
    assert(e.playhead() == 0 && e.output().gate == bool(retrigger));
    e.update(T + 1250000);
    e.update(T + 1500000);
    assert(e.playhead() == 1);
  }
}
void external_reset_and_early_edges() {
  Project p;
  Settings s;
  s.clock = ClockMode::External;
  p.length = 4;
  Engine e(p, s);
  e.start(T);
  e.update(T + 200000);
  assert(!e.output().gate);
  e.clockEdge(T + 300000);
  assert(e.clockEvents() == 1 && e.resetEvents() == 1); // start() resets once
  e.update(T + 300000);
  assert(e.playhead() == 0);
  // New period is shorter than the initially assumed 500 ms; no lost half.
  e.clockEdge(T + 400000);
  e.update(T + 400000);
  assert(e.playhead() == 1);
  e.clockEdge(T + 500000);
  e.update(T + 500000);
  assert(e.playhead() == 2);
  e.reset(T + 550000);
  assert(!e.output().gate);
  e.clockEdge(T + 600000);
  e.update(T + 600000);
  assert(e.playhead() == 0);
  e.update(T + 900000);
  assert(!e.output().gate); // lost clock never leaves gate stuck
}
void clock_division_and_auto() {
  Project p;
  Settings s;
  s.clock = ClockMode::External;
  s.division = 2;
  p.length = 4;
  Engine e(p, s);
  e.start(T);
  e.clockEdge(T);
  e.update(T);
  assert(e.playhead() == 0);
  e.clockEdge(T + 100000);
  e.update(T + 100000);
  assert(e.playhead() == 0);
  e.clockEdge(T + 200000);
  e.update(T + 200000);
  assert(e.playhead() == 1);
  e.clockEdge(T + 300000);
  e.update(T + 300000);
  assert(e.playhead() == 1);
  e.clockEdge(T + 400000);
  e.update(T + 400000);
  assert(e.playhead() == 2);
  s.clock = ClockMode::Auto;
  s.division = 1;
  e.clockChanged(T + 500000);
  assert(e.external(T + 500000));
  e.update(T + 2500000);
  assert(!e.external(T + 2500000));
  assert(e.output().gate);
}
void modulation_and_preview() {
  Project p;
  Settings s;
  s.clock = ClockMode::Internal;
  s.glideShape = GlideShape::Linear;
  p.length = 2;
  p.notes[1] = 48;
  p.steps[1].key = 1;
  p.steps[1].glide = 1;
  Engine e(p, s);
  e.start(T);
  e.update(T);
  near(e.output().pitch, 3);
  e.update(T + 250000);
  e.update(T + 500000);
  near(e.output().pitch, 3);
  e.update(T + 625000);
  near(e.output().pitch, 3.5);
  e.update(T + 750000);
  near(e.output().pitch, 4);
  e.stop();
  Step vib{};
  vib.vibrato = 1;
  s.vibratoHz = 1;
  s.vibratoCents = 100;
  s.aux = AuxMode::Vibrato;
  e.preview(0, T + 1000000, &vib);
  e.update(T + 1250000);
  near(e.output().pitch, 3 + 1.0f / 12);
  near(e.output().aux, 5);
  Step rest{};
  rest.time = 0;
  e.preview(0, T + 1300000, &rest);
  e.update(T + 1300000);
  assert(!e.output().gate);
  p.transpose = 7;
  e.start(T + 2000000);
  e.update(T + 2000000);
  assert(e.output().pitch <= 8);
}
void ratchet_and_step_shift() {
  Project p;
  Settings s;
  s.clock = ClockMode::Internal;
  p.length = 1;
  p.steps[0].ratchet = 4;
  p.steps[0].shift = 1;
  Engine e(p, s);
  e.start(T);
  e.update(T);                    // first ratchet, C3
  near(e.output().pitch, 3);
  e.update(T + 125000);           // second ratchet inside a 500 ms step
  assert(e.output().gate);
  e.update(T + 250000);           // third
  assert(e.output().gate);
  e.update(T + 500000);           // stage repeats: one scale degree above C3
  near(e.output().pitch, 37.0f / 12);
  e.reset(T + 600000);
  e.update(T + 600000);
  near(e.output().pitch, 3);      // Reset clears the per-step accumulation
}
void empty_live_and_tap() {
  Project p;
  Settings s;
  s.clock = ClockMode::Internal;
  Engine e(p, s);
  e.liveKey(2);
  e.start(T);
  e.liveKey(2);
  e.update(T);
  assert(e.output().gate);
  near(e.output().pitch, 38.0f / 12);
  e.stop();
  assert(!e.output().gate);
  e.tap(T);
  e.tap(T + 1000000);
  assert(s.bpm == 60);
}
int main() {
  defaults_and_scales();
  rest_and_loop();
  half_steps();
  hold_and_retrigger();
  external_reset_and_early_edges();
  clock_division_and_auto();
  modulation_and_preview();
  ratchet_and_step_shift();
  empty_live_and_tap();
  std::puts("8 engine regression groups passed");
}
