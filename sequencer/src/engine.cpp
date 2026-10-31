#include "engine.hpp"
#include <algorithm>
#include <cmath>
namespace t12 {
bool Engine::external(uint64_t now) const {
  return hasClock_ && now - lastExternal_ <=
                          std::max<uint64_t>(2000000, uint64_t(rawPeriod_) * 3);
}
void Engine::gate(uint64_t now, uint64_t duration) {
  // Explicitly cancel the previous gate before starting every new one.
  // This is required by the inverted T12 gate driver: writing HIGH again
  // while the logical gate is already active does not create an edge.
  if (retrigger_ < 15)
    ++retrigger_;
  output_.gate = false;
  output_.gate = true;
  const uint64_t gateDuration = fixedPreviewGate_
      ? duration
      : std::max<uint64_t>(1000, duration * s_.gateLength / 100);
  gateOff_ = now + gateDuration;
}
void Engine::queueGate(uint64_t now, uint64_t duration) {
  // hardware::write() applies PWM CV before Gate in the same update cycle.
  gate(now, duration);
}
void Engine::sound(unsigned key, const Step &st, uint64_t now,
                   uint64_t duration, bool trans, int shift) {
  startNote_ = currentNote_;
  targetNote_ = float(shiftDegrees(keyNote(key, p_, s_, trans), shift, p_, s_));
  glideStarted_ = now;
  glideDuration_ =
      st.glide ? std::clamp<uint64_t>(period_ / 2, 10000, 500000) : 0;
  vibrato_ = st.vibrato;
  noteStarted_ = now;
  sounding_ = int(key);
  if (!glideDuration_)
    currentNote_ = targetNote_;
  // Ratchet uses evenly spaced gates across the full stage. The normal
  // retrigger behaviour stays unchanged for ratchet = 1.
  // TB-303 style slide: change the pitch target but keep the current gate
  // open when the preceding note is still sounding. This avoids a retrigger
  // at the boundary and lets the glide ramp carry the note into the next one.
  if (trans && st.glide && output_.gate && gateOff_ > now) {
    ratchetsRemaining_ = 0;
    ratchetDue_ = ratchetInterval_ = 0;
    return;
  }
  if (trans && st.gate == Step::GateType::Ratchet && st.length > 1) {
    ratchetInterval_ = std::max<uint64_t>(1000, duration / st.length);
    // A ratchet pulse occupies exactly 50% of its subdivided interval,
    // independently of the global gate-length setting.
    ratchetPulse_ = std::max<uint64_t>(1000,
        ratchetInterval_ * 50 / std::max<unsigned>(1, s_.gateLength));
    ratchetsRemaining_ = st.length - 1;
    ratchetDue_ = now + ratchetInterval_;
    queueGate(now, ratchetPulse_);
  } else {
    ratchetsRemaining_ = 0;
    ratchetDue_ = ratchetInterval_ = ratchetPulse_ = 0;
    queueGate(now, duration);
  }
  if (st.gate == Step::GateType::Hold)
    gateOff_ = now + std::max<uint64_t>(1000, duration);
}
void Engine::halfTick(uint64_t now) {
  if (!running_ || !p_.length)
    return;
  const unsigned loopLength = p_.loopLength ? p_.loopLength : p_.length;
  const unsigned loopOffset = p_.loopLength ? p_.loopOffset : 0;
  if (remaining_) {
    --remaining_;
    ++elapsed_;
  }
  if (!remaining_) {
    current_ = next_ % loopLength;
    if (s_.sequenceDirection == 1)
      next_ = current_ ? current_ - 1 : uint8_t(loopLength - 1);
    else if (s_.sequenceDirection == 2)
      next_ = uint8_t((uint32_t(current_) * 17u + 5u) % loopLength);
    else
      next_ = (current_ + 1) % loopLength;
    const unsigned physical = loopOffset + current_;
    activePhysical_ = physical;
    active_ = p_.steps[physical];
    elapsed_ = 0;
    // SKIP is not a timed rest: resolve chained skipped steps immediately at
    // the same clock timestamp until a playable step is found.
    if (active_.gate == Step::GateType::Skip) {
      remaining_ = 0;
      halfTick(now);
      return;
    }
    const unsigned length = std::clamp<unsigned>(active_.length ? active_.length : 1, 1, 8);
    // Ratchet step length is the subdivision count, not a multi-step hold:
    // the complete ratchet must fit inside one clock step.
    const unsigned timingLength =
        (active_.gate == Step::GateType::Ratchet ||
         active_.gate == Step::GateType::Skip) ? 1 : length;
    remaining_ = uint8_t(2 * timingLength);
    const auto gate = active_.gate;
    if (gate == Step::GateType::Rest || active_.time == 0) {
      output_.gate = false;
      gateOff_ = 0;
      vibrato_ = false;
      // Keep the last key indicator during a rest; only the gate closes.
      ratchetsRemaining_ = 0;
      return;
    }
    unsigned key = active_.key;
    if (liveKeys_) {
      for (unsigned n = 0; n < Keys; ++n) {
        unsigned candidate;
        if (s_.arpDirection == 1)
          candidate = (liveCursor_ + Keys - n) % Keys;
        else if (s_.arpDirection == 2)
          candidate = (liveCursor_ + ((liveCursor_ / Keys) & 1 ? Keys - n : n)) % Keys;
        else
          candidate = (liveCursor_ + n) % Keys;
        if (liveKeys_ & (1u << candidate)) {
          key = candidate;
          liveCursor_ = uint8_t((candidate + 1) % Keys);
          break;
        }
      }
    } else if (liveKey_ >= 0) {
      key = unsigned(liveKey_);
    }
    const int variantShift = active_.variant ? variantAccum_[physical] : 0;
    const uint64_t total = uint64_t(remaining_) * period_ / 2;
    const uint64_t eventDuration = gate == Step::GateType::Hold ? total : period_;
    sound(key, active_, now, active_.retrigger ? std::min<uint64_t>(period_, total)
                                               : eventDuration,
          true, shiftAccum_[physical] + variantShift);
    if (gate == Step::GateType::Single && length > 1)
      gateOff_ = now + std::max<uint64_t>(1000, period_ * s_.gateLength / 100);
    shiftAccum_[physical] = int8_t(std::clamp(int(shiftAccum_[physical]) +
                                                   int(active_.shift),
                                               -24, 24));
    if (active_.variant) {
      const int nextVariant = int(variantAccum_[physical]) + int(active_.variantDegree);
      if (active_.variantDegree > 0 && nextVariant > active_.variantMax)
        variantAccum_[physical] = active_.variantMin;
      else if (active_.variantDegree < 0 && nextVariant < active_.variantMin)
        variantAccum_[physical] = active_.variantMax;
      else
        variantAccum_[physical] = int8_t(std::clamp(nextVariant,
                                                     int(active_.variantMin),
                                                     int(active_.variantMax)));
    }
  } else if (active_.gate == Step::GateType::Multi && active_.ratchet == 1 &&
             elapsed_ % 2 == 0) {
    // MULTI repeats the complete step event, not only its gate.  This makes
    // each repetition eligible to advance the per-step variant accumulator.
    const int variantShift = active_.variant ? variantAccum_[activePhysical_] : 0;
    sound(active_.key, active_, now, period_, true,
          shiftAccum_[activePhysical_] + variantShift);
    if (active_.variant) {
      const int nextVariant = int(variantAccum_[activePhysical_]) +
                              int(active_.variantDegree);
      if (active_.variantDegree > 0 && nextVariant > active_.variantMax)
        variantAccum_[activePhysical_] = active_.variantMin;
      else if (active_.variantDegree < 0 && nextVariant < active_.variantMin)
        variantAccum_[activePhysical_] = active_.variantMax;
      else
        variantAccum_[activePhysical_] = int8_t(std::clamp(nextVariant,
          int(active_.variantMin), int(active_.variantMax)));
    }
  } else if (active_.retrigger && active_.ratchet == 1 && active_.time != 0 &&
             elapsed_ % 2 == 0) {
    queueGate(now, period_);
  }
}
void Engine::tick(uint64_t now) {
  if (halfDue_) {
    halfTick(std::min(now, halfDue_));
    halfDue_ = 0;
  }
  if (running_ && !p_.length && liveKey_ >= 0) {
    Step plain{};
    sound(unsigned(liveKey_), plain, now, period_, true);
  } else
    halfTick(now);
  halfDue_ = running_ && p_.length ? now + period_ / 2 : 0;
}
void Engine::clockEdge(uint64_t now) {
  if (clockIgnored_)
    return;
  ++clockEvents_;
  const bool firstExternalEdge = !hasClock_;
  if (hasClock_ && now > lastExternal_) {
    uint64_t p = now - lastExternal_;
    if (p >= 2000 && p <= 10000000)
      rawPeriod_ = uint32_t(p);
  }
  hasClock_ = true;
  lastExternal_ = now;
  if (s_.clock == ClockMode::Internal)
    return;
  // An external Pamela clock is also the transport start. Do not discard
  // its first edge just because the local run flag has not been set yet.
  if (!running_) {
    running_ = true;
    next_ = current_ = remaining_ = elapsed_ = 0;
    halfDue_ = 0;
  }
  // The first external edge is always the phase origin. Do not wait for the
  // second incoming edge when a clock division is selected.
  if (firstExternalEdge) {
    division_ = 0;
    period_ = rawPeriod_ * std::max<uint8_t>(1, s_.division);
    tick(now);
    division_ = (s_.division > 1) ? 1 : 0;
    return;
  }
  if (division_ == 0) {
    // tick() owns halfDue_: it completes at most one interpolated half-step
    // before processing this external clock. Do not process it here as well.
    period_ = rawPeriod_ * s_.division;
    tick(now);
  }
  division_ = (division_ + 1) % s_.division;
}
void Engine::reset(uint64_t now) {
  ++resetEvents_;
  next_ = current_ = remaining_ = elapsed_ = division_ = 0;
  halfDue_ = 0;
  ratchetsRemaining_ = 0;
    ratchetDue_ = ratchetInterval_ = ratchetPulse_ = 0;
  std::fill(shiftAccum_, shiftAccum_ + Steps, int8_t(0));
  std::fill(variantAccum_, variantAccum_ + Steps, int8_t(0));
  output_.gate = false;
  gateOff_ = 0;
  vibrato_ = false;
  sounding_ = -1;
  nextInternal_ = now;
  if (p_.length) {
    current_ = 0;
    next_ = current_;
  }
}
void Engine::start(uint64_t now) {
  running_ = true;
  liveKey_ = -1;
  liveKeys_ = 0;
  liveCursor_ = 0;
  reset(now);
}
void Engine::stop() {
  running_ = false;
  output_.gate = false;
  gateOff_ = halfDue_ = 0;
  ratchetsRemaining_ = 0;
  vibrato_ = false;
  liveKey_ = sounding_ = -1;
  liveKeys_ = 0;
}
void Engine::clockChanged(uint64_t now) {
  division_ = 0;
  nextInternal_ = now;
}
void Engine::preview(unsigned key, uint64_t now, const Step *step) {
  Step plain{};
  const auto &st = step ? *step : plain;
  if (st.time == 0) {
    output_.gate = false;
    gateOff_ = 0;
    vibrato_ = false;
    sounding_ = -1;
    return;
  }
  // Short manual/recording previews must retrigger cleanly when keys are
  // played rapidly; the previous 20 ms minimum held the gate too long.
  const uint8_t queuedBefore = retrigger_;
  // Manual previews use a stable musical response independent of the clock.
  // The normal gate-length percentage is still applied inside gate().
  fixedPreviewGate_ = true;
  sound(key, st, now, 300000, false);
  fixedPreviewGate_ = false;
  // A preview is a new user event even when the previous gate has already
  // expired. Queue a physical edge for every preview; otherwise a rapid
  // sequence can update the OLED/LEDs while the gate output remains high and
  // produces no new trigger edge.
  if (retrigger_ == queuedBefore && retrigger_ < 15)
    ++retrigger_;
}
void Engine::tap(uint64_t now) {
  if (lastTap_ && now - lastTap_ >= 200000 && now - lastTap_ <= 3000000)
    s_.bpm =
        uint16_t(std::clamp<uint64_t>(60000000 / (now - lastTap_), 20, 300));
  lastTap_ = now;
}
void Engine::update(uint64_t now) {
  bool useExt = s_.clock == ClockMode::External ||
                (s_.clock == ClockMode::Auto && external(now));
  if (useExt || useExt != clockWasExternal_)
    nextInternal_ = now;
  clockWasExternal_ = useExt;
  if (running_ && halfDue_ && now >= halfDue_) {
    auto at = halfDue_;
    halfDue_ = 0;
    halfTick(at);
  }
  if (running_ && !useExt && now >= nextInternal_) {
    period_ = uint32_t(60000000u / s_.bpm) * s_.division;
    const auto at = nextInternal_;
    tick(at);
    nextInternal_ = at + period_;
    if (now > nextInternal_ && now - nextInternal_ > uint64_t(period_) * 4)
      nextInternal_ = now + period_;
  }
  float mix =
      glideDuration_
          ? std::clamp(float(now - glideStarted_) / float(glideDuration_), 0.0f,
                       1.0f)
          : 1.0f;
  if (s_.glideShape == GlideShape::Smooth)
    mix = mix * mix * (3 - 2 * mix);
  else if (s_.glideShape == GlideShape::Expo)
    mix = (std::exp(4 * mix) - 1) / (std::exp(4.0f) - 1);
  currentNote_ = startNote_ + (targetNote_ - startNote_) * mix;
  const double phase =
      std::fmod(double(now - noteStarted_) * s_.vibratoHz / 1000000.0, 1.0);
  float sine = vibrato_ ? std::sin(float(phase) * 6.283185307f) : 0;
  output_.pitch = std::clamp((currentNote_ + sine * s_.vibratoCents / 100) / 12,
                             0.0f, 8.0f);
  switch (s_.aux) {
  case AuxMode::Off:
    output_.aux = 0;
    break;
  case AuxMode::Pitch:
    output_.aux = output_.pitch;
    break;
  case AuxMode::Vibrato:
    output_.aux = vibrato_ ? 2.5f + 2.5f * sine : 2.5f;
    break;
  case AuxMode::Position:
    output_.aux = p_.length > 1 ? 5.0f * current_ / (p_.length - 1) : 0;
    break;
  case AuxMode::Capacitance:
    // Normalize the positive baseline-filtered delta with the selected pad's
    // persisted idle/range calibration before converting it to 0..8 V.
    const float delta = std::max(0.0f,
                                 float(touchCapacitance_) - s_.capIdle[touchKey_]);
    const float normalized = std::clamp(delta / s_.capRange[touchKey_], 0.0f, 1.0f);
    output_.aux = normalized * 8.0f;
    break;
  }
  while (ratchetsRemaining_ && now >= ratchetDue_) {
    queueGate(ratchetDue_, ratchetPulse_);
    ratchetDue_ += ratchetInterval_;
    --ratchetsRemaining_;
  }
  if (gateOff_ && now >= gateOff_) {
    output_.gate = false;
    gateOff_ = 0;
  }
}
} // namespace t12
