#pragma once
#include "model.hpp"
namespace t12 {
struct Output {
  float pitch = 0, aux = 0;
  bool gate = false;
};
class Engine {
public:
  Engine(Project &p, Settings &s) : p_(p), s_(s) {}
  void update(uint64_t now);
  void clockEdge(uint64_t now);
  void reset(uint64_t now);
  void start(uint64_t now);
  void stop();
  void clockChanged(uint64_t now);
  void preview(unsigned key, uint64_t now, const Step *step = nullptr);
  void liveKey(int key) { liveKey_ = key; }
  void liveKeys(uint16_t keys) { liveKeys_ = keys; }
  void setTouchCapacitance(uint16_t value, unsigned key = 0) {
    touchCapacitance_ = value;
    touchKey_ = key < Keys ? key : 0;
  }
  void setClockIgnored(bool ignored) { clockIgnored_ = ignored; }
  void tap(uint64_t now);
  bool running() const { return running_; }
  bool external(uint64_t now) const;
  uint32_t period() const { return period_; }
  uint32_t clockEvents() const { return clockEvents_; }
  uint32_t resetEvents() const { return resetEvents_; }
  unsigned playhead() const { return current_; }
  int soundingKey() const { return sounding_; }
  const Output &output() const { return output_; }
  bool consumeRetrigger() {
    if (!retrigger_) return false;
    --retrigger_;
    return true;
  }

private:
  Project &p_;
  Settings &s_;
  Output output_{};
  uint8_t retrigger_ = 0;
  bool running_ = false, vibrato_ = false, hasClock_ = false, clockWasExternal_ = false;
  bool fixedPreviewGate_ = false;
  bool clockIgnored_ = false;
  uint8_t next_ = 0, current_ = 0, remaining_ = 0, elapsed_ = 0, division_ = 0;
  int liveKey_ = -1, sounding_ = -1;
  uint16_t liveKeys_ = 0;
  uint8_t liveCursor_ = 0;
  uint16_t touchCapacitance_ = 0;
  unsigned touchKey_ = 0;
  uint32_t period_ = 500000, rawPeriod_ = 500000;
  uint32_t clockEvents_ = 0, resetEvents_ = 0;
  uint64_t lastExternal_ = 0, nextInternal_ = 0, halfDue_ = 0, gateOff_ = 0,
           lastTap_ = 0;
  uint64_t ratchetDue_ = 0, ratchetInterval_ = 0, ratchetPulse_ = 0;
  uint8_t ratchetsRemaining_ = 0;
  int8_t shiftAccum_[Steps]{};
  int8_t variantAccum_[Steps]{};
  uint64_t noteStarted_ = 0, glideStarted_ = 0, glideDuration_ = 0;
  float startNote_ = 0, targetNote_ = 0, currentNote_ = 0;
  Step active_{};
  unsigned activePhysical_ = 0;
  void tick(uint64_t now);
  void halfTick(uint64_t now);
  void sound(unsigned key, const Step &, uint64_t now, uint64_t duration,
             bool trans, int shift = 0);
  void gate(uint64_t now, uint64_t duration);
  void queueGate(uint64_t now, uint64_t duration);
};
} // namespace t12
