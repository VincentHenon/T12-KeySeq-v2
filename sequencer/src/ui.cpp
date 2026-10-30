#include "ui.hpp"
#include "storage.hpp"
#include "t12_bitmaps.h"
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

// Compact 6x7 gate glyphs used in the LIVE and EDIT STEPS grids.  The
// selected step gets an outline from the caller; the glyph itself remains
// readable inside that outline.
void drawGateIcon(Canvas &c, int x, int y, const Step &st, bool selected) {
  const Bitmap1bpp *bitmap = &single;
  if (st.gate == Step::GateType::Ratchet) {
    // Repeated gate (ratchet): diagonal burst.
    bitmap = &ratchet;
  } else if (st.gate == Step::GateType::Skip) {
    bitmap = &skip;
  } else if (st.gate == Step::GateType::Multi) {
    bitmap = &multi;
  } else if (st.gate == Step::GateType::Hold) {
    bitmap = &hold;
  } else if (st.gate == Step::GateType::Rest || st.time == 0) {
    bitmap = &rest;
  } else {
    bitmap = &single;
  }
  if (selected)
    c.box(x, y, 12, 12, true);
  for (unsigned dy = 0; dy < bitmap->height; ++dy)
    for (unsigned dx = 0; dx < bitmap->width; ++dx) {
      const unsigned byteIndex = dy * ((bitmap->width + 7) / 8) + dx / 8;
      // The Figma export stores the black background as 1 bits. On the OLED
      // a set pixel is white, so invert the bitmap when rendering it.
      const bool bit = bitmap->data[byteIndex] & (uint8_t(0x80) >> (dx & 7));
      if (!bit)
        c.pixel(x + int(dx), y + int(dy), !selected);
    }
}
void drawModifierIcons(Canvas &c, int x, int y, const Step &st) {
  auto draw = [&](const Bitmap1bpp &bitmap, int ox, int oy) {
    for (unsigned dy = 0; dy < bitmap.height; ++dy)
      for (unsigned dx = 0; dx < bitmap.width; ++dx) {
        const unsigned byteIndex = dy * ((bitmap.width + 7) / 8) + dx / 8;
        if (!(bitmap.data[byteIndex] & (uint8_t(0x80) >> (dx & 7))))
          c.pixel(x + ox + int(dx), y + oy + int(dy));
      }
  };
  // Both indicators share the lower-right corner; vibrato takes the first
  // two columns and slide the second two columns when both are enabled.
  if (st.vibrato) draw(vibrato, 4, 7);
  if (st.glide) draw(slide, 8, 7);
}
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
    return 6;
  case Page::Parameters:
    return p_.steps[std::min(step_, Steps - 1)].variant
               ? 7 : 4;
  case Page::Scale:
    return 5;
  case Page::Clock:
    return 7;
  case Page::Settings:
    return 12;
  case Page::Storage:
    return Slots + 1;
  case Page::Slot:
    return 5;
  case Page::Calibration:
    return 5;
  case Page::ConfirmRecord:
    return 2;
  case Page::ConfirmExitRecord:
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
  recordBackup_ = p_;
  recordBackupValid_ = true;
  engine_.stop();
  p_.length = 0;
  p_.transpose = 0;
  for (auto &st : p_.steps)
    st = Step{};
  step_ = 0;
  recordFull_ = false;
  recordAppending_ = true;
  recordReplacePending_ = false;
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
  recordBackupValid_ = false;
}
void Ui::discardRecord(uint64_t now) {
  if (recordBackupValid_)
    p_ = recordBackup_;
  recordBackupValid_ = false;
  dirty_ = false;
  enter(Page::Play);
  engine_.stop();
  engine_.reset(now);
  menu();
  fault("RECORDING DISCARDED", now);
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
      enter(Page::ConfirmExitRecord, 0);
      return;
    }
    if (page_ == Page::Calibration) {
      enter(Page::Settings, 1);
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
        if (recordReplacePending_ && p_.length) {
          p_.steps[step_].key = k;
          key_ = k;
          engine_.preview(k, now, &p_.steps[step_]);
          recordReplacePending_ = false;
          recordAppending_ = true;
          dirty_ = true;
        } else if (recordAppending_ && p_.length < Steps) {
          Step st{};
          st.key = k;
          p_.steps[p_.length++] = st;
          step_ = p_.length - 1;
          key_ = k;
          engine_.preview(k, now);
          dirty_ = true;
          if (p_.length == Steps) {
            recordFull_ = true;
            recordAppending_ = false;
            fault("32 STEPS RECORDED", now);
          }
        } else if (p_.length) {
          p_.steps[step_].key = k;
          key_ = k;
          engine_.preview(k, now, &p_.steps[step_]);
          dirty_ = true;
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
      playParam_ = wrap(int(playParam_) + sign, 7);
      liveModalUntil_ = now + 1000000;
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
    case Page::Record:
      if (p_.length) {
        if (recordAppending_)
          recordAppending_ = false;
        recordReplacePending_ = false;
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
    if (row_ == 0) {
      st.gate = Step::GateType(wrap(int(st.gate) + d, 6));
      if (st.gate == Step::GateType::Ratchet && st.ratchet == 1) st.ratchet = 2;
    }
    if (row_ == 1) st.length = uint8_t(std::clamp(int(st.length) + d, 1, 8));
    if (row_ == 2) st.variant = !st.variant;
    if (row_ == 3 && st.variant) st.variantDegree = int8_t(std::clamp(int(st.variantDegree) + d, -24, 24));
    if (row_ == 4 && st.variant) st.variantMin = int8_t(std::clamp(int(st.variantMin) + d, -24, 0));
    if (row_ == 5 && st.variant) st.variantMax = int8_t(std::clamp(int(st.variantMax) + d, 0, 24));
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
    if (row_ == 3)
      s_.vibratoHz = std::clamp(s_.vibratoHz + d * 0.1f, 0.1f, 20.0f);
    if (row_ == 4)
      s_.vibratoCents = std::clamp(s_.vibratoCents + d, 0.0f, 200.0f);
    if (row_ == 5)
      s_.glideShape = GlideShape(wrap(int(s_.glideShape) + d, 3));
    if (row_ == 6)
      s_.brightness = uint8_t(std::clamp(int(s_.brightness) + d * 4, 0, 255));
    if (row_ == 7)
      s_.aux = AuxMode(wrap(int(s_.aux) + d, 5));
    if (row_ == 9)
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
    liveModalUntil_ = now + 1000000;
    break;
  case Page::Keys:
    menu();
    break;
  case Page::Record:
    // In REC, a click fixes the current step as the last step.
    if (p_.length) {
      step_ = std::min(step_, unsigned(p_.length - 1));
      p_.length = uint8_t(step_ + 1);
      recordAppending_ = false;
      recordReplacePending_ = true;
      recordFull_ = false;
      dirty_ = true;
      fault("LAST STEP SET", now);
    }
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
      enter(Page::Play);
      break;
    case 1:
      engine_.stop();
      step_ = std::min(step_, p_.length ? unsigned(p_.length - 1) : 0);
      enter(Page::Steps);
      break;
    case 2:
      engine_.stop();
      enter(Page::Keys);
      break;
    case 3:
      startRecord(now);
      break;
    case 4:
      enter(Page::Storage, slot_);
      break;
    case 5:
      enter(Page::Settings);
      break;
    }
    break;
  case Page::ConfirmRecord:
    // Confirmation is controlled with + (confirm) and - (cancel).
    break;
  case Page::ConfirmExitRecord:
    if (row_ == 0)
      discardRecord(now);
    else {
      endRecord(now);
      menu();
    }
    break;
  case Page::Parameters: {
    auto &st = p_.steps[step_];
    const unsigned ret = st.variant ? 9 : 6;
    // All editable step parameters use the normal turn-then-click flow.
    // Variant degree/min/max are rows 3..5 when Variant is enabled; the
    // previous row mapping treated these rows as legacy glide/vibrato toggles,
    // so their values could never be edited.
    if (row_ <= 2 || (st.variant && row_ >= 3 && row_ <= 5)) editing_ = true;
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
    } else if (return_ == Page::Settings)
      enter(Page::Settings);
    else
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
    else if (row_ == 6) {
      if (return_ == Page::Settings)
        enter(Page::Settings);
      else
        menu();
    }
    break;
  case Page::Settings:
    if (row_ == 0) {
      return_ = Page::Settings;
      enter(Page::Scale);
    } else if (row_ == 1) {
      engine_.stop();
      calPoint_ = 0;
      enter(Page::Calibration, 2);
    } else if (row_ == 2) {
      return_ = Page::Settings;
      enter(Page::Clock);
    } else if (row_ >= 3 && row_ <= 7)
      editing_ = true;
    else if (row_ == 8)
      s_.reverseEncoder ^= 1, settingsChanged(now);
    else if (row_ == 9)
      editing_ = true;
    else if (row_ == 10)
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
      liveModalUntil_ = now + 1000000;
    } else if (page_ == Page::Record) {
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
    if (d > 0 || d < 0) {
      auto &st = p_.steps[step_];
      if (d > 0) st.glide = !st.glide;
      else st.vibrato = !st.vibrato;
      std::snprintf(editModalText_, sizeof editModalText_, "%s %s",
                    d > 0 ? "SLIDE" : "VIBRATO",
                    (d > 0 ? st.glide : st.vibrato) ? "ON" : "OFF");
      editModalUntil_ = now + 1000000;
      dirty_ = true;
      return;
    }
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
    if (d < 0) {
      enter(Page::ConfirmExitRecord, 0);
      return;
    } else if (d > 0) {
      enter(Page::ConfirmRecord, 0);
      return;
    }
    return;
  }
  if (page_ == Page::ConfirmExitRecord) {
    if (d < 0)
      enter(Page::Record);
    else if (d > 0)
      row_ = wrap(int(row_) + 1, 2);
    return;
  }
  if (page_ == Page::ConfirmRecord) {
    if (d > 0) {
      startRecord(now);
      fault("SEQUENCE CLEARED", now);
    } else if (d < 0) {
      enter(Page::Record);
    }
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
    enter(Page::Settings, 1);
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
    const char *items[] = {"LIVE", "STEPS", "KEYS", "REC", "SAVE-LOAD",
                           "SETTINGS"};
    std::snprintf(out, n, "%s", items[index]);
    break;
  }
  case Page::ConfirmRecord:
    std::snprintf(out, n, "%s", index == 0 ? "CLEAR SEQUENCE" : "CANCEL");
    break;
  case Page::ConfirmExitRecord:
    std::snprintf(out, n, "%s", index == 0 ? "EXIT" : "SAVE & EXIT");
    break;
  case Page::Parameters: {
    const auto gateName = [](Step::GateType g) { static const char *n[] = {"SINGLE","MULTI","HOLD","REST","SKIP","RATCHET"}; return n[unsigned(g) % 6]; };
    if (index == 0) std::snprintf(out, n, "GATE: %s", gateName(st.gate));
    if (index == 1) std::snprintf(out, n, st.gate == Step::GateType::Ratchet ? "STEP LENGTH: /%u" : "STEP LENGTH: X%u", st.length);
    if (index == 2) std::snprintf(out, n, "VARIANT: %s", st.variant ? "ON" : "OFF");
    const unsigned base = 3;
    if (index == base && st.variant) std::snprintf(out, n, "VARIANT DEG: %+d", int(st.variantDegree));
    if (index == base + 1 && st.variant) std::snprintf(out, n, "VARIANT MIN: %+d", int(st.variantMin));
    if (index == base + 2 && st.variant) std::snprintf(out, n, "VARIANT MAX: %+d", int(st.variantMax));
    if (index == (st.variant ? base + 3 : base)) std::snprintf(out, n, "RETURN");
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
      std::snprintf(out, n, "SCALES");
    if (index == 1)
      std::snprintf(out, n, "CV CALIBRATION");
    if (index == 2)
      std::snprintf(out, n, "CLOCK");
    if (index == 3)
      std::snprintf(out, n, "VIB RATE: %.1f HZ", double(s_.vibratoHz));
    if (index == 4)
      std::snprintf(out, n, "VIB DEPTH: %.0f CT", double(s_.vibratoCents));
    if (index == 5)
      std::snprintf(out, n, "GLIDE: %s", curveNames[unsigned(s_.glideShape)]);
    if (index == 6)
      std::snprintf(out, n, "LED LEVEL: %u", s_.brightness);
    if (index == 7)
      std::snprintf(out, n, "AUX: %s", auxNames[unsigned(s_.aux)]);
    if (index == 8)
      std::snprintf(out, n, "ENC REVERSE: %s",
                    s_.reverseEncoder ? "ON" : "OFF");
    if (index == 9)
      std::snprintf(out, n, "GATE LENGTH: %u%%", s_.gateLength);
    if (index == 10)
      std::snprintf(out, n, "SAVE SETTINGS");
    if (index == 11)
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
  if (page_ == Page::Menu) {
    static const char *items[] = {"LIVE", "STEPS", "KEYS", "REC",
                                  "SAVE-LOAD", "SETTINGS"};
    const unsigned previous = row_ == 0 ? 5 : row_ - 1;
    const unsigned next = row_ == 5 ? 0 : row_ + 1;
    const int currentWidth = int(std::strlen(items[row_]) * 12);
    const int previousWidth = int(std::strlen(items[previous]) * 6);
    const int nextWidth = int(std::strlen(items[next]) * 6);
    c.textScaled((128 - previousWidth) / 2, 5, items[previous], 1, true);
    c.textScaled(std::max(0, (128 - currentWidth) / 2), 24, items[row_], 2);
    c.textScaled((128 - nextWidth) / 2, 49, items[next], 1, true);
  } else if (rows()) {
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
      title = "CLEAR SEQUENCE?";
      break;
    case Page::ConfirmExitRecord:
      title = "EXIT RECORDING?";
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
    if (page_ == Page::ConfirmRecord)
      c.text(0, 56, "+ CONFIRM CLEAR   - CANCEL");
    else if (page_ == Page::ConfirmExitRecord)
      c.text(0, 56, "CLICK: CONFIRM   - BACK");
    else
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
    if (page_ == Page::Steps || page_ == Page::Play) {
      char pitchHeader[8]{};
      const unsigned current = page_ == Page::Play
                                    ? std::min(engine_.playhead(), Steps - 1)
                                    : std::min(step_, Steps - 1);
      if (current < p_.length)
        noteName(float(keyNote(p_.steps[current].key, p_, s_, false)),
                 pitchHeader, sizeof pitchHeader);
      else
        std::snprintf(pitchHeader, sizeof pitchHeader, "--");
      std::snprintf(line, sizeof line, "%02u/%02u", current + 1,
                    p_.length);
      c.text(0, 0, line);
      if (page_ == Page::Steps) {
        c.text(128 - int(std::strlen(pitchHeader)) * 6, 0, pitchHeader);
      } else {
        c.text(56 - int(std::strlen(pitchHeader)) * 3, 0, pitchHeader);
        if (engine_.running()) {
          c.pixel(116, 1); c.pixel(116, 2); c.pixel(117, 3); c.pixel(118, 4);
          c.pixel(119, 5); c.pixel(120, 6); c.pixel(121, 7);
        } else {
          c.box(117, 1, 7, 7, true);
        }
      }
    } else {
      c.text(0, 0,
             page_ == Page::Record ? "RECORD"
             : engine_.running()   ? "PLAY"
                                   : "STOP");
      std::snprintf(line, sizeof line, "%02u/32 %s", p_.length,
                    dirty_ ? "EDIT" : "");
      c.text(64, 0, line);
    }
    for (unsigned i = 0; i < Steps; ++i) {
      // EDIT STEPS uses four rows of eight larger cells. Other pages retain
      // the compact twelve-column layout.
      int x = (page_ == Page::Steps || page_ == Page::Play) ? int(i % 8) * 16 + 2
                                   : int(i % 12) * 10;
      int y = (page_ == Page::Steps || page_ == Page::Play) ? 9 + int(i / 8) * 14
                                   : 12 + int(i / 12) * 10;
      bool selected = page_ == Page::Steps ? i == step_
                      : engine_.running()  ? i == engine_.playhead()
                                           : i == step_;
      const bool inLoop = p_.loopLength &&
                          i >= p_.loopOffset &&
                          i < unsigned(p_.loopOffset + p_.loopLength);
      if (i < p_.length) {
        const bool showGateIcons = page_ == Page::Play || page_ == Page::Steps;
        if (showGateIcons) {
          drawGateIcon(c, x, y, p_.steps[i],
                       (page_ == Page::Steps || page_ == Page::Play) && selected);
          drawModifierIcons(c, x, y, p_.steps[i]);
        } else {
          c.box(x, y, 6, 7, selected);
          if (p_.steps[i].time == 0)
            c.pixel(x + 2, y + 3, !selected);
        }
      } else
        c.pixel(x + 2, y + 3);
      if ((page_ == Page::Play || page_ == Page::Steps) && inLoop) {
        // Mark the active loop window without covering its gate icon.
        c.pixel(x, y);
        c.pixel(x + 11, y);
        c.pixel(x, y + 11);
        c.pixel(x + 11, y + 11);
      }
    }
    if (page_ == Page::Steps && p_.length) {
      const auto &st = p_.steps[step_];
      (void)st;
    } else if (page_ == Page::Record) {
      if (recordAppending_)
        std::snprintf(line, sizeof line, "NEXT STEP %02u", p_.length + 1);
      else
        std::snprintf(line, sizeof line, "EDIT STEP %02u KEY %02u",
                      step_ + 1, p_.length ? p_.steps[step_].key + 1 : 0);
      c.text(0, 36, line);
      c.text(0, 46, "TURN PREVIEW  CLICK: LAST");
      c.text(0, 56, "- EXIT   + CLEAR");
    }
  }
  if (page_ == Page::Play && now < liveModalUntil_) {
    const char *name = playParam_ == 0 ? "OCTAVE" : playParam_ == 1 ? "DIRECTION"
                       : playParam_ == 2 ? "ARP" : playParam_ == 3 ? "GATE LENGTH"
                       : playParam_ == 4 ? "CLOCK DIV" : playParam_ == 5 ? "LOOP LENGTH"
                                         : "LOOP SHIFT";
    char value[24]{};
    if (playParam_ == 0) std::snprintf(value, sizeof value, "%+d", p_.transpose);
    else if (playParam_ == 1) std::snprintf(value, sizeof value, "%s", seqDirNames[s_.sequenceDirection]);
    else if (playParam_ == 2) std::snprintf(value, sizeof value, "%s", arpDirNames[s_.arpDirection]);
    else if (playParam_ == 3) std::snprintf(value, sizeof value, "%u%%", s_.gateLength);
    else if (playParam_ == 4) std::snprintf(value, sizeof value, "x%u", s_.division);
    else if (playParam_ == 5) std::snprintf(value, sizeof value, "%u", p_.loopLength ? p_.loopLength : p_.length);
    else std::snprintf(value, sizeof value, "%u", p_.loopOffset);
    c.box(6, 15, 116, 38, true, false);
    c.text((128 - int(std::strlen(name)) * 6) / 2, 21, name);
    c.text((128 - int(std::strlen(value)) * 6) / 2, 35, value);
  }
  if (page_ == Page::Steps && now < editModalUntil_) {
    c.box(6, 15, 116, 38, true, false);
    c.text((128 - int(std::strlen(editModalText_)) * 6) / 2, 29, editModalText_);
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
