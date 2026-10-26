#include "engine.hpp"
#include <algorithm>
#include <cmath>
namespace t12 {
bool Engine::external(uint64_t now) const {
  return hasClock_ && now - lastExternal_ <=
                          std::max<uint64_t>(2000000, uint64_t(rawPeriod_) * 3);
}
void Engine::gate(uint64_t now, uint64_t duration) {
  output_.gate = true;
  gateOff_ = now + std::max<uint64_t>(1000, duration / 2);
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
  if (trans && st.ratchet > 1) {
    ratchetInterval_ = std::max<uint64_t>(1000, duration / st.ratchet);
    ratchetsRemaining_ = st.ratchet - 1;
    ratchetDue_ = now + ratchetInterval_;
    queueGate(now, ratchetInterval_);
  } else {
    ratchetsRemaining_ = 0;
    ratchetDue_ = ratchetInterval_ = 0;
    queueGate(now, duration);
  }
}
void Engine::halfTick(uint64_t now) {
  if (!running_ || !p_.length)
    return;
  if (remaining_) {
    --remaining_;
    ++elapsed_;
  }
  if (!remaining_) {
    current_ = next_ % p_.length;
    next_ = (current_ + 1) % p_.length;
    active_ = p_.steps[current_];
    elapsed_ = 0;
    remaining_ = active_.time == -1 ? 1 : 2 * std::max(1, int(active_.time));
    if (active_.time == 0) {
      output_.gate = false;
      gateOff_ = 0;
      vibrato_ = false;
      sounding_ = -1;
      ratchetsRemaining_ = 0;
      return;
    }
    unsigned key = liveKey_ >= 0 ? unsigned(liveKey_) : active_.key;
    sound(key, active_, now,
          active_.retrigger
              ? std::min<uint64_t>(period_, uint64_t(remaining_) * period_ / 2)
              : uint64_t(remaining_) * period_ / 2,
          true, shiftAccum_[current_]);
    shiftAccum_[current_] = int8_t(std::clamp(int(shiftAccum_[current_]) +
                                                   int(active_.shift),
                                               -24, 24));
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
  ++clockEvents_;
  if (hasClock_ && now > lastExternal_) {
    uint64_t p = now - lastExternal_;
    if (p >= 2000 && p <= 10000000)
      rawPeriod_ = uint32_t(p);
  }
  hasClock_ = true;
  lastExternal_ = now;
  if (s_.clock == ClockMode::Internal || !running_)
    return;
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
  ratchetDue_ = ratchetInterval_ = 0;
  std::fill(shiftAccum_, shiftAccum_ + Steps, int8_t(0));
  output_.gate = false;
  gateOff_ = 0;
  vibrato_ = false;
  sounding_ = -1;
  nextInternal_ = now;
}
void Engine::start(uint64_t now) {
  running_ = true;
  reset(now);
}
void Engine::stop() {
  running_ = false;
  output_.gate = false;
  gateOff_ = halfDue_ = 0;
  ratchetsRemaining_ = 0;
  vibrato_ = false;
  liveKey_ = sounding_ = -1;
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
  sound(key, st, now, std::clamp<uint64_t>(period_, 20000, 1000000), false);
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
  }
  while (ratchetsRemaining_ && now >= ratchetDue_) {
    queueGate(ratchetDue_, ratchetInterval_);
    ratchetDue_ += ratchetInterval_;
    --ratchetsRemaining_;
  }
  if (gateOff_ && now >= gateOff_) {
    output_.gate = false;
    gateOff_ = 0;
  }
}
} // namespace t12
