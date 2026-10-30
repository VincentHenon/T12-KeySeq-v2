#include "ui.hpp"
#include "storage.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
namespace t12 {
namespace {
unsigned wrap(int n, unsigned count) {
  return unsigned((n % int(count) + int(count)) % int(count));
}
const char *clockNames[] = {"AUTO", "INTERNAL", "EXTERNAL"};
const char *auxNames[] = {"OFF", "PITCH COPY", "VIBRATO", "POSITION", "CAP SENSE"};
const char *curveNames[] = {"SMOOTH", "LINEAR", "EXPO"};
const char *seqDirNames[] = {"FORWARD", "BACKWARD", "RANDOM"};
const char *arpDirNames[] = {"UP", "DOWN", "UP&DOWN"};
const char *pitches[] = {"C",  "C#", "D",  "D#", "E",  "F",
                         "F#", "G",  "G#", "A",  "A#", "B"};
constexpr char nameChars[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";
} // namespace
void Ui::fault(const char *msg, uint64_t now) {
  std::snprintf(message_, sizeof message_, "%s", msg);
  messageUntil_ = now + 2500000;
}
void Ui::enter(Page p, unsigned row) {
  if (p == Page::Keys || p == Page::Steps || p == Page::Parameters || p == Page::Calibration) {
    engine_.stop();
    engine_.setClockIgnored(true);
  } else if (page_ == Page::Keys || page_ == Page::Steps || page_ == Page::Parameters || page_ == Page::Calibration) {
    engine_.setClockIgnored(false);
  }
  page_ = p;
  row_ = row;
  editing_ = false;
}
unsigned Ui::rows() const {
  switch (page_) {
  case Page::Menu:
    return 10;
  case Page::Parameters:
    return p_.steps[std::min(step_, Steps - 1)].variant ? 10 : 7;
  case Page::Scale:
    return 5;
  case Page::Clock:
    return 7;
  case Page::Settings:
    return 10;
  case Page::Storage:
    return Slots + 1;
  case Page::Slot:
    return 5;
  case Page::Calibration:
    return 5;
  case Page::ConfirmRecord:
    return 2;
  default:
    return 0;
  }
}
void Ui::menu() {
  return_ = page_ == Page::Keys    ? Page::Keys
            : page_ == Page::Steps ? Page::Steps
                                   : Page::Play;
  enter(Page::Menu);
}
void Ui::suspend(uint64_t) {
  wasRunning_ = engine_.running();
  engine_.stop();
  hw::write(engine_.output(), s_);
}
void Ui::resume(uint64_t now) {
  hw::clearEdges();
  if (wasRunning_)
    engine_.start(now);
  wasRunning_ = false;
}
void Ui::saveSettings(uint64_t now) {
  suspend(now);
  bool ok = storage::saveSettings(s_);
  resume(now);
  if (ok)
    settingsDirty_ = false;
  else
    settingsSaveDue_ = now + 10000000; // do not hammer unavailable flash
  fault(ok ? "SETTINGS SAVED" : "SAVE FAILED", now);
}
void Ui::autoSaveSettings(uint64_t now) {
  if (engine_.running())
    return;
  saveSettings(now);
}
void Ui::autoSaveProject(uint64_t now) {
  if (engine_.running() || !dirty_)
    return;
  suspend(now);
  bool ok = storage::saveProject(slot_, p_);
  resume(now);
  if (ok) {
    dirty_ = false;
    fault("SEQUENCE SAVED", now);
  } else {
    projectSaveDue_ = now + 10000000;
    fault("SEQUENCE SAVE FAIL", now);
  }
}
void Ui::settingsChanged(uint64_t now) {
  settingsDirty_ = true;
  // Coalesce a run of encoder ticks into one flash write.  The flash keeps two
  // banks, but this still avoids consuming an erase cycle per UI detent.
  settingsSaveDue_ = now + 1500000;
}
void Ui::startRecord(uint64_t) {
  engine_.stop();
  p_.length = 0;
  p_.transpose = 0;
  for (auto &st : p_.steps)
    st = Step{};
  step_ = 0;
  recordFull_ = false;
  dirty_ = true;
  enter(Page::Record);
}
void Ui::endRecord(uint64_t now) {
  enter(Page::Play);
  engine_.stop();
  engine_.reset(now);
  // Commit a completed recording immediately.  The recorder stops the
  // engine here, so this flash write cannot interfere with clock/gate timing.
  if (p_.length && storage::saveProject(slot_, p_))
    dirty_ = false;
  fault(p_.length ? "SEQUENCE RECORDED" : "EMPTY SEQUENCE", now);
}
void Ui::input(const hw::Input &in, uint64_t now) {
  latest_ = in;
  if (page_ == Page::Keys || page_ == Page::Steps)
    engine_.stop();
  if (in.turn) {
    int delta = s_.reverseEncoder ? -in.turn : in.turn;
    // Calibration values use 0.001 steps. Hold Octave+ while turning to
    // accelerate the adjustment instead of requiring hundreds of detents.
    if (page_ == Page::Calibration && in.plusHeld)
      delta *= 10;
    turn(delta, now);
  }
  if (in.longClick) {
    if (page_ == Page::Keys) {
      enter(Page::Play);
      engine_.stop();
      return;
    }
    if (page_ == Page::Record) {
      endRecord(now);
      return;
    }
    if (page_ == Page::Calibration) {
      enter(Page::Settings, 6);
      engine_.stop();
      return;
    }
    if (page_ == Page::CalibrationResult) {
      enter(Page::Calibration, 2);
      return;
    }
    if (page_ == Page::Name) {
      enter(Page::Slot);
      return;
    }
    menu();
  } else if (in.click)
    click(now);
  if (in.minus) {
    octave(-1, now);
    nextMinusRepeat_ = now + 300000;
  }
  if (in.plus) {
    octave(1, now);
    nextPlusRepeat_ = now + 300000;
  }
  if (in.minusHeld && now >= nextMinusRepeat_) {
    octave(-1, now);
    nextMinusRepeat_ = now + 90000;
  }
  if (in.plusHeld && now >= nextPlusRepeat_) {
    octave(1, now);
    nextPlusRepeat_ = now + 90000;
  }
  if (!in.minusHeld) nextMinusRepeat_ = now + 150000;
  if (!in.plusHeld) nextPlusRepeat_ = now + 150000;
  for (unsigned k = 0; k < Keys; ++k)
    if (in.pressed & (1u << k)) {
      if (page_ == Page::Keys) {
        key_ = k;
        engine_.preview(k, now);
      } else if (page_ == Page::Record) {
        if (p_.length < Steps) {
          Step st{};
          st.key = k;
          p_.steps[p_.length++] = st;
          key_ = k;
          engine_.preview(k, now);
          dirty_ = true;
        }
        if (p_.length == Steps) {
          recordFull_ = true;
          endRecord(now);
          fault("32 STEPS RECORDED", now);
          break;
        }
      } else if (page_ == Page::Steps && p_.length) {
        p_.steps[step_].key = k;
        key_ = k;
        dirty_ = true;
        engine_.preview(k, now, &p_.steps[step_]);
      } else if (page_ == Page::Play && !engine_.running()) {
        key_ = k;
        engine_.liveKey(int(k));
        // Manual keys must retrigger immediately even while the external
        // clock is running; liveKey remains active for subsequent clocked
        // steps, but must not delay the audible gate response.
        engine_.preview(k, now);
      }
    }
  if (page_ == Page::Play) {
    uint16_t cap = 0;
    unsigned capKey = 0;
    for (unsigned k = 0; k < Keys; ++k)
      if (in.keys & (1u << k)) { cap = in.touchCap[k]; capKey = k; break; }
    engine_.setTouchCapacitance(cap, capKey);
    if (engine_.running()) {
      // During playback, held pads override the CV only when the next step
      // is emitted. They never call preview() at touch time.
      engine_.liveKeys(in.keys);
    } else if (!in.keys) {
      engine_.liveKey(-1);
    }
  } else {
    engine_.liveKey(-1);
    engine_.liveKeys(0);
  }
  if (dirty_ && !engine_.running())
    projectSaveDue_ = now + 1500000;
}
void Ui::turn(int delta, uint64_t now) {
  int sign = delta > 0 ? 1 : -1;
  for (int i = 0; i < std::abs(delta); ++i) {
    if (editing_) {
      changeValue(sign, now);
      continue;
    }
    if (page_ == Page::Calibration) {
      row_ = row_ == 2 ? 3 : (row_ == 3 ? 0 : 2);
      continue;
    }
    if (rows()) {
      row_ = wrap(int(row_) + sign, rows());
      continue;
    }
    switch (page_) {
    case Page::Play:
      if (engine_.running())
        playParam_ = wrap(int(playParam_) + sign, 7);
      else
        step_ = p_.length ? wrap(int(step_) + sign, p_.length) : 0;
      break;
    case Page::Keys:
      p_.notes[key_] = uint8_t(moveNote(p_.notes[key_], sign, p_, s_));
      dirty_ = true;
      engine_.preview(key_, now);
      break;
    case Page::Steps:
      if (p_.length) {
        step_ = wrap(int(step_) + sign, p_.length);
        key_ = p_.steps[step_].key;
        engine_.preview(key_, now, &p_.steps[step_]);
      }
      break;
    case Page::Custom:
      piano_ = wrap(int(piano_) + sign, 12);
      break;
    case Page::Name: {
      auto *at = std::strchr(nameChars, editedName_[namePos_]);
      int idx = at ? int(at - nameChars) : 0;
      editedName_[namePos_] =
          nameChars[wrap(idx + sign, sizeof(nameChars) - 1)];
      break;
    }
    default:
      break;
    }
  }
}
void Ui::changeValue(int d, uint64_t now) {
  switch (page_) {
  case Page::Parameters: {
    auto &st = p_.steps[step_];
    if (row_ == 0) st.gate = Step::GateType(wrap(int(st.gate) + d, 5));
    if (row_ == 1) st.length = uint8_t(std::clamp(int(st.length) + d, 1, 8));
    if (row_ == 2) { static const uint8_t values[] = {1,2,3,4,6,8}; int i=0; while (i<5 && values[i]!=st.ratchet) ++i; st.ratchet = values[std::clamp(i+d,0,5)]; }
    if (row_ == 6 && st.variant) st.variantDegree = int8_t(std::clamp(int(st.variantDegree) + d, -24, 24));
    if (row_ == 7 && st.variant) st.variantMin = int8_t(std::clamp(int(st.variantMin) + d, -24, 0));
    if (row_ == 8 && st.variant) st.variantMax = int8_t(std::clamp(int(st.variantMax) + d, 0, 24));
    dirty_ = true;
    break;
  }
  case Page::Scale:
    if (row_ == 0)
      p_.scale = uint8_t(wrap(int(p_.scale) + d, scaleCount()));
    if (row_ == 1)
      p_.root = uint8_t(wrap(int(p_.root) + d, 12));
    dirty_ = true;
    break;
  case Page::Clock:
    if (row_ == 0)
      s_.clock = ClockMode(wrap(int(s_.clock) + d, 3));
    if (row_ == 1)
      s_.bpm = uint16_t(std::clamp(int(s_.bpm) + d, 20, 300));
    if (row_ == 2)
      s_.division = uint8_t(d > 0 ? std::min(16, int(s_.division) * 2)
                                  : std::max(1, int(s_.division) / 2));
    engine_.clockChanged(now);
    settingsChanged(now);
    break;
  case Page::Settings:
    if (row_ == 0)
      s_.vibratoHz = std::clamp(s_.vibratoHz + d * 0.1f, 0.1f, 20.0f);
    if (row_ == 1)
      s_.vibratoCents = std::clamp(s_.vibratoCents + d, 0.0f, 200.0f);
    if (row_ == 2)
      s_.glideShape = GlideShape(wrap(int(s_.glideShape) + d, 3));
    if (row_ == 3)
      s_.brightness = uint8_t(std::clamp(int(s_.brightness) + d * 4, 0, 255));
    if (row_ == 4)
      s_.aux = AuxMode(wrap(int(s_.aux) + d, 5));
    if (row_ == 7)
      s_.gateLength = uint8_t(std::clamp(int(s_.gateLength) + d, 10, 90));
    settingsChanged(now);
    break;
  case Page::Calibration: {
    auto &c = calChannel_ ? s_.auxiliary : s_.pitch;
    if (row_ == 0)
      calChannel_ = 1 - calChannel_;
    if (row_ == 1)
      calPoint_ = unsigned(std::clamp(int(calPoint_) + d, 0, int(CalibrationPoints - 1)));
    if (row_ == 2)
      c.coarseMv[calPoint_] = int16_t(std::clamp(int(c.coarseMv[calPoint_]) + d * 10, -1000, 1000));
    if (row_ == 3)
      c.fineTenthsMv[calPoint_] = int16_t(std::clamp(int(c.fineTenthsMv[calPoint_]) + d, -100, 100));
    settingsChanged(now);
    break;
  }
  default:
    break;
  }
}
void Ui::click(uint64_t now) {
  if (editing_) {
    editing_ = false;
    if (page_ == Page::Calibration) {
      saveSettings(now);
      fault("CALIBRATION SAVED", now);
    }
    return;
  }
  switch (page_) {
  case Page::Play:
    if (engine_.running()) engine_.stop(); else engine_.start(now);
    break;
  case Page::Keys:
    menu();
    break;
  case Page::Record:
    endRecord(now);
    break;
  case Page::Steps:
    if (p_.length)
      enter(Page::Parameters);
    else
      fault("RECORD A SEQUENCE", now);
    break;
  case Page::Menu:
    switch (row_) {
    case 0:
      if (engine_.running())
        engine_.stop();
      else
        engine_.start(now);
      enter(Page::Play);
      break;
    case 1:
      engine_.stop();
      enter(Page::Keys);
      break;
    case 2:
      enter(Page::ConfirmRecord, 1);
      break;
    case 3:
      engine_.stop();
      step_ = std::min(step_, p_.length ? unsigned(p_.length - 1) : 0);
      enter(Page::Steps);
      break;
    case 4:
      enter(Page::Scale);
      break;
    case 5:
      enter(Page::Clock);
      break;
    case 6:
      enter(Page::Settings);
      break;
    case 7:
      enter(Page::Storage, slot_);
      break;
    case 8:
      enter(Page::Play);
      break;
    case 9:
      enter(return_);
      break;
    }
    break;
  case Page::ConfirmRecord:
    if (row_ == 0)
      startRecord(now);
    else
      menu();
    break;
  case Page::Parameters: {
    auto &st = p_.steps[step_];
    const unsigned ret = st.variant ? 9 : 6;
    if (row_ == 0 || row_ == 1 || row_ == 2 || (row_ >= 6 && row_ <= 8 && st.variant)) editing_ = true;
    else if (row_ == 3) { st.glide ^= 1; dirty_ = true; }
    else if (row_ == 4) { st.vibrato ^= 1; dirty_ = true; }
    else if (row_ == 5) { st.variant ^= 1; dirty_ = true; }
    else if (row_ == ret) enter(Page::Steps);
    break;
  }
  case Page::Scale:
    if (row_ < 2)
      editing_ = true;
    else if (row_ == 2) {
      fillKeys(p_, s_);
      dirty_ = true;
      fault("KEYS FILLED", now);
    } else if (row_ == 3) {
      custom_ = p_.scale >= BuiltinScales ? p_.scale - BuiltinScales : 0;
      customMask_ = s_.userScales[custom_];
      piano_ = 0;
      enter(Page::Custom);
    } else
      menu();
    break;
  case Page::Custom:
    if ((customMask_ ^ (1u << piano_)) != 0)
      customMask_ ^= 1u << piano_;
    else
      fault("KEEP AT LEAST 1 NOTE", now);
    break;
  case Page::Clock:
    if (row_ < 3)
      editing_ = true;
    else if (row_ == 3)
      engine_.tap(now), settingsChanged(now);
    else if (row_ == 6)
      menu();
    break;
  case Page::Settings:
    if (row_ < 5)
      editing_ = true;
    else if (row_ == 5)
      s_.reverseEncoder ^= 1, settingsChanged(now);
    else if (row_ == 6) {
      engine_.stop();
      calPoint_ = 0;
      enter(Page::Calibration, 2);
    } else if (row_ == 7)
      editing_ = true;
    else if (row_ == 8)
      saveSettings(now);
    else
      menu();
    break;
  case Page::Calibration:
    if (row_ == 0) {
      calChannel_ = 1 - calChannel_;
      fault(calChannel_ ? "AUXILIARY OUTPUT" : "PITCH OUTPUT", now);
      break;
    }
    if (row_ < 4)
      editing_ = true;
    else {
      enter(Page::CalibrationResult);
    }
    break;
  case Page::CalibrationResult:
    break;
  case Page::Storage:
    if (row_ == Slots)
      menu();
    else {
      slot_ = row_;
      enter(Page::Slot);
    }
    break;
  case Page::Slot:
    if (row_ == 0) {
      std::memcpy(editedName_, p_.name, sizeof editedName_);
      size_t len = std::strlen(editedName_);
      for (size_t i = len; i < 16; ++i)
        editedName_[i] = ' ';
      editedName_[16] = 0;
      namePos_ = 0;
      enter(Page::Name);
    } else if (row_ == 1) {
      Project candidate{};
      if (storage::loadProject(slot_, candidate)) {
        engine_.stop();
        p_ = candidate;
        step_ = key_ = 0;
        dirty_ = false;
        enter(Page::Play);
        fault("SEQUENCE LOADED", now);
      } else
        fault("EMPTY OR INVALID", now);
    } else if (row_ == 2) {
      suspend(now);
      bool ok = storage::clearProject(slot_);
      resume(now);
      fault(ok ? "SLOT CLEARED" : "CLEAR FAILED", now);
    } else if (row_ == 3) {
      suspend(now);
      bool ok = storage::saveProject(slot_, p_);
      bool settingsOk = storage::saveSettings(s_);
      resume(now);
      if (ok)
        dirty_ = false;
      fault(ok && settingsOk ? "SAVED" : "SAVE FAILED", now);
    } else
      enter(Page::Storage, slot_);
    break;
  case Page::Name:
    namePos_ = (namePos_ + 1) % 16;
    break;
  }
}
void Ui::octave(int d, uint64_t now) {
  if (page_ == Page::CalibrationResult) {
    calPoint_ = unsigned(std::clamp(int(calPoint_) + d, 0, 8));
    return;
  }
  if (page_ == Page::Calibration) {
    calPoint_ = unsigned(std::clamp(int(calPoint_) + d, 0, int(CalibrationPoints - 1)));
    return;
  }
  if (page_ == Page::Play) {
    if (engine_.running()) {
      switch (playParam_) {
      case 1: s_.sequenceDirection = uint8_t(wrap(int(s_.sequenceDirection) + d, 3)); settingsChanged(now); break;
      case 2: s_.arpDirection = uint8_t(wrap(int(s_.arpDirection) + d, 3)); settingsChanged(now); break;
      case 3: s_.gateLength = uint8_t(std::clamp(int(s_.gateLength) + d, 10, 90)); settingsChanged(now); break;
      case 4: s_.division = uint8_t(d > 0 ? std::min(8, int(s_.division) * 2) : std::max(1, int(s_.division) / 2)); engine_.clockChanged(now); settingsChanged(now); break;
      case 5: if (p_.length) { p_.loopLength = uint8_t(std::clamp(int(p_.loopLength ? p_.loopLength : p_.length) + d, 1, int(p_.length))); p_.loopOffset = uint8_t(std::min<unsigned>(p_.loopOffset, p_.length - p_.loopLength)); } dirty_ = true; break;
      case 6: if (p_.length) { const unsigned len = p_.loopLength ? p_.loopLength : p_.length; p_.loopOffset = uint8_t(std::clamp(int(p_.loopOffset) + d, 0, int(p_.length - len))); } dirty_ = true; break;
      default: p_.transpose = int8_t(std::clamp(int(p_.transpose) + d, -7, 7)); dirty_ = true; break;
      }
    } else {
      p_.transpose = int8_t(std::clamp(int(p_.transpose) + d, -7, 7));
      dirty_ = true;
    }
    return;
  }
  if (page_ == Page::Keys) {
    p_.notes[key_] = uint8_t(quantize(int(p_.notes[key_]) + 12 * d, p_, s_));
    dirty_ = true;
    engine_.preview(key_, now);
    return;
  }
  if (page_ == Page::Steps) {
    if (!p_.length)
      return;
    if (d < 0) {
      auto &st = p_.steps[step_];
      st.time = st.time == 0 ? 1 : 0;
      dirty_ = true;
    } else
      engine_.preview(p_.steps[step_].key, now, &p_.steps[step_]);
    return;
  }
  if (page_ == Page::Record) {
    if (d < 0 && p_.length < Steps) {
      Step st{};
      st.key = key_;
      st.time = 0;
      p_.steps[p_.length++] = st;
      dirty_ = true;
      if (p_.length == Steps)
        endRecord(now);
    } else if (d > 0 && p_.length)
      --p_.length;
    return;
  }
  if (page_ == Page::Custom) {
    if (d < 0)
      enter(Page::Scale, 3);
    else {
      s_.userScales[custom_] = customMask_;
      p_.scale = BuiltinScales + custom_;
      dirty_ = true;
      saveSettings(now);
      enter(Page::Scale, 3);
    }
    return;
  }
  if (page_ == Page::Name) {
    if (d < 0) {
      enter(Page::Slot);
      return;
    }
    Project candidate = p_;
    std::memcpy(candidate.name, editedName_, sizeof candidate.name);
    for (int i = 15; i >= 0 && candidate.name[i] == ' '; --i)
      candidate.name[i] = 0;
    if (!candidate.name[0])
      std::snprintf(candidate.name, sizeof candidate.name, "UNTITLED");
    suspend(now);
    bool ok = storage::saveProject(slot_, candidate);
    bool settingsOk = storage::saveSettings(s_);
    resume(now);
    if (ok) {
      p_ = candidate;
      dirty_ = false;
    }
    if (settingsOk)
      settingsDirty_ = false;
    enter(Page::Slot);
    fault(ok && settingsOk ? "SAVED" : "SAVE FAILED", now);
    return;
  }
  if (d > 0) {
    click(now);
    return;
  }
  if (editing_) {
    editing_ = false;
    return;
  }
  switch (page_) {
  case Page::Parameters:
    enter(Page::Steps);
    break;
  case Page::Calibration:
    enter(Page::Settings, 6);
    break;
  case Page::Slot:
    enter(Page::Storage, slot_);
    break;
  case Page::Menu:
    enter(return_);
    break;
  default:
    menu();
    break;
  }
}
void Ui::item(unsigned index, char *out, size_t n) const {
  const auto &st = p_.steps[std::min(step_, Steps - 1)];
  switch (page_) {
  case Page::Menu: {
    const char *items[] = {engine_.running() ? "STOP" : "PLAY",
                           "EDIT KEYS",
                           "RECORD NEW",
                           "EDIT STEPS",
                           "SCALES",
                           "CLOCK",
                           "SETTINGS",
                           "SAVE / LOAD",
                           "PERFORMANCE",
                           "RETURN"};
    std::snprintf(out, n, "%s", items[index]);
    break;
  }
  case Page::ConfirmRecord:
    std::snprintf(out, n, "%s", index == 0 ? "ERASE AND RECORD" : "CANCEL");
    break;
  case Page::Parameters: {
    const auto gateName = [](Step::GateType g) { static const char *n[] = {"SINGLE","MULTI","HOLD","REST","SKIP"}; return n[unsigned(g) % 5]; };
    if (index == 0) std::snprintf(out, n, "GATE: %s", gateName(st.gate));
    if (index == 1) std::snprintf(out, n, "STEP LENGTH: X%u", st.length);
    if (index == 2) std::snprintf(out, n, "RATCHET: %s", st.ratchet == 1 ? "OFF" : (st.ratchet == 2 ? "2" : st.ratchet == 3 ? "3" : st.ratchet == 4 ? "4" : st.ratchet == 6 ? "6" : "8"));
    if (index == 3) std::snprintf(out, n, "SLIDE: %s", st.glide ? "ON" : "OFF");
    if (index == 4) std::snprintf(out, n, "VIBRATO: %s", st.vibrato ? "ON" : "OFF");
    if (index == 5) std::snprintf(out, n, "VARIANT: %s", st.variant ? "ON" : "OFF");
    if (index == 6 && st.variant) std::snprintf(out, n, "VARIANT DEG: %+d", int(st.variantDegree));
    if (index == 7 && st.variant) std::snprintf(out, n, "VARIANT MIN: %+d", int(st.variantMin));
    if (index == 8 && st.variant) std::snprintf(out, n, "VARIANT MAX: %+d", int(st.variantMax));
    if (index == (st.variant ? 9 : 6)) std::snprintf(out, n, "RETURN");
    break;
  }
  case Page::Scale:
    if (index == 0)
      std::snprintf(out, n, "%s", scaleName(p_.scale));
    if (index == 1)
      std::snprintf(out, n, "ROOT: %s", pitches[p_.root]);
    if (index == 2)
      std::snprintf(out, n, "FILL 12 KEYS");
    if (index == 3)
      std::snprintf(out, n, "EDIT USER SCALE");
    if (index == 4)
      std::snprintf(out, n, "RETURN");
    break;
  case Page::Clock:
    if (index == 0)
      std::snprintf(out, n, "SOURCE: %s", clockNames[unsigned(s_.clock)]);
    if (index == 1)
      std::snprintf(out, n, "BPM: %u", s_.bpm);
    if (index == 2)
      std::snprintf(out, n, "DIVIDE: %u", s_.division);
    if (index == 3)
      std::snprintf(out, n, "TAP TEMPO: CLICK");
    if (index == 4)
      std::snprintf(out, n, "CLOCK IN: %lu %s",
                    static_cast<unsigned long>(engine_.clockEvents()),
                    hw::clockHigh() ? "HIGH" : "LOW");
    if (index == 5)
      std::snprintf(out, n, "RESET IN: %lu %s",
                    static_cast<unsigned long>(engine_.resetEvents()),
                    hw::resetHigh() ? "HIGH" : "LOW");
    if (index == 6)
      std::snprintf(out, n, "RETURN");
    break;
  case Page::Settings:
    if (index == 0)
      std::snprintf(out, n, "VIB RATE: %.1f HZ", double(s_.vibratoHz));
    if (index == 1)
      std::snprintf(out, n, "VIB DEPTH: %.0f CT", double(s_.vibratoCents));
    if (index == 2)
      std::snprintf(out, n, "GLIDE: %s", curveNames[unsigned(s_.glideShape)]);
    if (index == 3)
      std::snprintf(out, n, "LED LEVEL: %u", s_.brightness);
    if (index == 4)
      std::snprintf(out, n, "AUX: %s", auxNames[unsigned(s_.aux)]);
    if (index == 5)
      std::snprintf(out, n, "ENC REVERSE: %s",
                    s_.reverseEncoder ? "ON" : "OFF");
    if (index == 6)
      std::snprintf(out, n, "CV CALIBRATION");
    if (index == 7)
      std::snprintf(out, n, "GATE LENGTH: %u%%", s_.gateLength);
    if (index == 8)
      std::snprintf(out, n, "SAVE SETTINGS");
    if (index == 9)
      std::snprintf(out, n, "RETURN");
    break;
  case Page::Storage: {
    Project saved{};
    if (index == Slots)
      std::snprintf(out, n, "RETURN");
    else
      std::snprintf(out, n, "%u %s", index + 1,
                    storage::loadProject(index, saved) ? saved.name : "EMPTY");
    break;
  }
  case Page::Slot: {
    const char *actions[] = {"SAVE WITH NAME", "LOAD", "CLEAR SLOT",
                             "QUICK SAVE", "RETURN"};
    std::snprintf(out, n, "%s", actions[index]);
    break;
  }
  case Page::Calibration: {
    auto c = calChannel_ ? s_.auxiliary : s_.pitch;
    if (index == 0)
      std::snprintf(out, n, "OUT: %s", calChannel_ ? "AUX" : "PITCH");
    if (index == 1)
      std::snprintf(out, n, "TARGET: %u V", calPoint_ * 2);
    if (index == 2)
      std::snprintf(out, n, "COARSE: %+d MV", int(c.coarseMv[calPoint_]));
    if (index == 3)
      std::snprintf(out, n, "FINE: %+d.%d MV", int(c.fineTenthsMv[calPoint_] / 10),
                    std::abs(int(c.fineTenthsMv[calPoint_] % 10)));
    if (index == 4)
      std::snprintf(out, n, "SAVE CALIBRATION");
    break;
  }
  default:
    out[0] = 0;
    break;
  }
}
void Ui::draw(Canvas &c, uint64_t now) const {
  c.clear();
  char line[40]{}, note[8]{};
  if (rows()) {
    const char *title = "MENU";
    switch (page_) {
    case Page::Menu:
      title = "T12 SEQUENCER";
      break;
    case Page::Parameters:
      title = "STEP PARAMETERS";
      break;
    case Page::Scale:
      title = "SCALES";
      break;
    case Page::Clock:
      title = "CLOCK";
      break;
    case Page::Settings:
      title = "SETTINGS";
      break;
    case Page::Storage:
      title = "SAVE / LOAD";
      break;
    case Page::Slot:
      title = "SLOT ACTIONS";
      break;
    case Page::Calibration:
      title = "CV CALIBRATION";
      break;
    case Page::ConfirmRecord:
      title = "REPLACE SEQUENCE?";
      break;
    default:
      break;
    }
    c.text(0, 0, title);
    unsigned first = row_ >= 4 ? row_ - 3 : 0;
    for (unsigned i = first; i < std::min(first + 4, rows()); ++i) {
      item(i, line, sizeof line);
      int y = 12 + 10 * int(i - first);
      c.text(0, y, i == row_ ? (editing_ ? "=" : ">") : " ");
      c.text(8, y, line);
    }
    c.text(0, 56, editing_ ? "TURN VALUE  CLICK SAVE" : "- BACK  CLICK SELECT");
  } else if (page_ == Page::CalibrationResult) {
    c.text(0, 0, "CV CALIBRATION RESULT");
    std::snprintf(line, sizeof line, "OUTPUT: %u V", calPoint_);
    c.text(0, 14, line);
    c.text(0, 30, "CORRECTED OUTPUT");
    c.text(0, 44, "- / + SELECT 0-8 V");
    c.text(0, 56, "HOLD ENCODER: CALIBRATE");
  } else if (page_ == Page::Custom) {
    std::snprintf(line, sizeof line, "USER %u  NOTE %s", custom_ + 1,
                  pitches[piano_]);
    c.text(0, 0, line);
    constexpr int white[] = {0, 2, 4, 5, 7, 9, 11}, black[] = {1, 3, 6, 8, 10},
                  bx[] = {13, 31, 67, 85, 103};
    for (int i = 0; i < 7; ++i) {
      int x = i * 18;
      c.box(x, 16, 18, 32);
      if (customMask_ & (1u << white[i]))
        c.box(x + 7, 40, 4, 4, true);
      if (int(piano_) == white[i])
        c.text(x + 6, 49, ">");
    }
    for (int i = 0; i < 5; ++i) {
      c.box(bx[i], 16, 10, 19, true);
      if (customMask_ & (1u << black[i]))
        c.box(bx[i] + 3, 27, 4, 4, true, false);
      if (int(piano_) == black[i])
        c.text(bx[i] + 3, 8, ">");
    }
    c.text(0, 57, "CLICK TOGGLE  + SAVE");
  } else if (page_ == Page::Name) {
    c.text(0, 0, "NAME SEQUENCE");
    c.text(0, 22, editedName_);
    c.box(int(namePos_) * 6, 31, 5, 2, true);
    c.text(0, 40, "CLICK NEXT LETTER");
    c.text(0, 56, "- CANCEL      + SAVE");
  } else if (page_ == Page::Keys) {
    const int current = keyNote(key_, p_, s_, false);
    char previous[8]{}, next[8]{};
    noteName(float(current), note, sizeof note);
    noteName(float(moveNote(current, -1, p_, s_)), previous,
             sizeof previous);
    noteName(float(moveNote(current, 1, p_, s_)), next, sizeof next);

    std::snprintf(line, sizeof line, "KEY %02u", key_ + 1);
    c.text(0, 0, line);
    c.text(94, 0, "EDIT");

    // Carousel: the current selectable note is dominant, while the notes
    // reached by the previous/next encoder detent flank it on both sides.
    const int currentWidth = int(std::strlen(note)) * 18;
    const int nextWidth = int(std::strlen(next)) * 7;
    c.textScaled(2, 27, previous, 1, true);
    c.box(27, 30, 7, 1, true);
    c.textScaled((128 - currentWidth) / 2, 17, note, 3);
    c.box(94, 30, 7, 1, true);
    c.textScaled(126 - nextWidth, 27, next, 1, true);

    c.text(0, 56, "HOLD CLICK: EXIT");
  } else {
    c.text(0, 0,
           page_ == Page::Record  ? "RECORD"
           : page_ == Page::Steps ? "EDIT STEPS"
           : engine_.running()    ? "PLAY"
                                  : "STOP");
    std::snprintf(line, sizeof line, "%02u/32 %s", p_.length,
                  dirty_ ? "EDIT" : "");
    c.text(64, 0, line);
    for (unsigned i = 0; i < Steps; ++i) {
      int x = int(i % 16) * 8, y = 15 + int(i / 16) * 10;
      bool selected = page_ == Page::Steps ? i == step_
                      : engine_.running()  ? i == engine_.playhead()
                                           : i == step_;
      if (i < p_.length) {
        c.box(x, y, 6, 7, selected);
        if (p_.steps[i].time == 0)
          c.pixel(x + 2, y + 3, !selected);
      } else
        c.pixel(x + 2, y + 3);
    }
    if (page_ == Page::Steps && p_.length) {
      const auto &st = p_.steps[step_];
      noteName(float(keyNote(st.key, p_, s_, false)), note, sizeof note);
      std::snprintf(line, sizeof line, "STEP %02u KEY %02u %s", step_ + 1,
                    st.key + 1, note);
      c.text(0, 36, line);
      std::snprintf(line, sizeof line, "T:%d Q:%u G:%u S:%+d", st.time,
                    st.ratchet, st.glide, int(st.shift));
      c.text(0, 46, line);
      c.text(0, 56, "CLICK PARAM  - REST");
    } else if (page_ == Page::Record) {
      std::snprintf(line, sizeof line, "NEXT STEP %02u", p_.length + 1);
      c.text(0, 36, line);
      c.text(0, 46, "- REST       + UNDO");
      c.text(0, 56, "CLICK FINISH");
    } else {
      noteName(engine_.output().pitch * 12, note, sizeof note);
      std::snprintf(line, sizeof line, "%s OCT %d %s", note, p_.transpose,
                    engine_.external(now) ? "EXT" : "INT");
      c.text(0, 36, line);
      const char *param = playParam_ == 0 ? "OCTAVE"
                         : playParam_ == 1 ? seqDirNames[s_.sequenceDirection]
                         : playParam_ == 2 ? arpDirNames[s_.arpDirection]
                         : playParam_ == 3 ? "GATE"
                         : playParam_ == 4 ? "DIVISION"
                         : playParam_ == 5 ? "LOOP LENGTH"
                                           : "LOOP OFFSET";
      if (playParam_ == 3)
        std::snprintf(line, sizeof line, "> %s %u%%", param, s_.gateLength);
      else if (playParam_ == 4)
        std::snprintf(line, sizeof line, "> %s x%u", param, s_.division);
      else if (playParam_ == 5)
        std::snprintf(line, sizeof line, "> %s %u", param, p_.loopLength ? p_.loopLength : p_.length);
      else if (playParam_ == 6)
        std::snprintf(line, sizeof line, "> %s %u", param, p_.loopOffset);
      else
        std::snprintf(line, sizeof line, "> %s", param);
      c.text(0, 46, line);
      c.text(0, 56, "ENC SELECT  +/- CHANGE");
    }
  }
  if (!latest_.touchOk) {
    c.box(0, 55, 128, 9, true, false);
    c.text(0, 56, "MPR121 READ ERROR");
  }
  if (now < messageUntil_) {
    c.box(0, 55, 128, 9, true, false);
    c.text(0, 56, message_);
  }
}
} // namespace t12
