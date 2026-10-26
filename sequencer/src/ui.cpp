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
const char *auxNames[] = {"OFF", "PITCH COPY", "VIBRATO", "POSITION"};
const char *curveNames[] = {"SMOOTH", "LINEAR", "EXPO"};
const char *pitches[] = {"C",  "C#", "D",  "D#", "E",  "F",
                         "F#", "G",  "G#", "A",  "A#", "B"};
constexpr char nameChars[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";
} // namespace
void Ui::fault(const char *msg, uint64_t now) {
  std::snprintf(message_, sizeof message_, "%s", msg);
  messageUntil_ = now + 2500000;
}
void Ui::enter(Page p, unsigned row) {
  page_ = p;
  row_ = row;
  editing_ = false;
}
unsigned Ui::rows() const {
  switch (page_) {
  case Page::Menu:
    return 10;
  case Page::Parameters:
    return 8;
  case Page::Scale:
    return 5;
  case Page::Clock:
    return 7;
  case Page::Settings:
    return 9;
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
  fault(p_.length ? "SEQUENCE RECORDED" : "EMPTY SEQUENCE", now);
}
void Ui::input(const hw::Input &in, uint64_t now) {
  latest_ = in;
  if (in.turn)
    turn(s_.reverseEncoder ? -in.turn : in.turn, now);
  if (in.longClick) {
    if (page_ == Page::Record) {
      endRecord(now);
      return;
    }
    if (page_ == Page::Calibration) {
      enter(Page::Settings, 6);
      engine_.stop();
      return;
    }
    if (page_ == Page::Name) {
      enter(Page::Slot);
      return;
    }
    menu();
  } else if (in.click)
    click(now);
  if (in.minus)
    octave(-1, now);
  if (in.plus)
    octave(1, now);
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
      } else if (page_ == Page::Play) {
        key_ = k;
        engine_.liveKey(int(k));
        if (!engine_.running())
          engine_.preview(k, now);
      }
    }
  if (page_ == Page::Play) {
    if (!in.keys)
      engine_.liveKey(-1);
  } else
    engine_.liveKey(-1);
}
void Ui::turn(int delta, uint64_t now) {
  int sign = delta > 0 ? 1 : -1;
  for (int i = 0; i < std::abs(delta); ++i) {
    if (editing_) {
      changeValue(sign, now);
      continue;
    }
    if (rows()) {
      row_ = wrap(int(row_) + sign, rows());
      continue;
    }
    switch (page_) {
    case Page::Play:
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
  case Page::Parameters:
    if (row_ == 0)
      p_.steps[step_].time =
          int8_t(std::clamp(int(p_.steps[step_].time) + d, -1, 8));
    if (row_ == 2)
      p_.steps[step_].ratchet =
          uint8_t(std::clamp(int(p_.steps[step_].ratchet) + d, 1, 8));
    if (row_ == 5)
      p_.steps[step_].shift =
          int8_t(std::clamp(int(p_.steps[step_].shift) + d, -7, 7));
    if (row_ == 6) {
      p_.length = uint8_t(std::clamp(int(p_.length) + d, 1, int(Steps)));
      step_ = std::min(step_, unsigned(p_.length - 1));
    }
    dirty_ = true;
    break;
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
      s_.aux = AuxMode(wrap(int(s_.aux) + d, 4));
    settingsChanged(now);
    break;
  case Page::Calibration: {
    auto &c = calChannel_ ? s_.auxiliary : s_.pitch;
    if (row_ == 0)
      calChannel_ = 1 - calChannel_;
    if (row_ == 1)
      calVolt_ = unsigned(std::clamp(int(calVolt_) + d, 0, 8));
    if (row_ == 2)
      c.intercept = std::clamp(c.intercept + d * 0.001f, 6.0f, 10.0f);
    if (row_ == 3)
      c.span = std::clamp(c.span + d * 0.001f, 6.0f, 12.0f);
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
    return;
  }
  switch (page_) {
  case Page::Play:
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
  case Page::Parameters:
    switch (row_) {
    case 0:
    case 2:
    case 5:
    case 6:
      editing_ = true;
      break;
    case 1:
      p_.steps[step_].retrigger ^= 1;
      dirty_ = true;
      break;
    case 3:
      p_.steps[step_].glide ^= 1;
      dirty_ = true;
      break;
    case 4:
      p_.steps[step_].vibrato ^= 1;
      dirty_ = true;
      break;
    case 7:
      enter(Page::Steps);
      break;
    }
    break;
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
      calVolt_ = 0;
      enter(Page::Calibration);
    } else if (row_ == 7)
      saveSettings(now);
    else
      menu();
    break;
  case Page::Calibration:
    if (row_ < 4)
      editing_ = true;
    else {
      saveSettings(now);
      enter(Page::Settings, 6);
    }
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
  if (page_ == Page::Play) {
    p_.transpose = int8_t(std::clamp(int(p_.transpose) + d, -7, 7));
    dirty_ = true;
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
  case Page::Parameters:
    if (index == 0) {
      if (st.time == -1)
        std::snprintf(out, n, "TIME: HALF");
      else if (st.time == 0)
        std::snprintf(out, n, "TIME: REST");
      else
        std::snprintf(out, n, "TIME: %d CLOCKS", int(st.time));
    }
    if (index == 1)
      std::snprintf(out, n, "RETRIGGER: %s", st.retrigger ? "ON" : "OFF");
    if (index == 2)
      std::snprintf(out, n, "RATCHET: %u", st.ratchet);
    if (index == 3)
      std::snprintf(out, n, "GLIDE: %s", st.glide ? "ON" : "OFF");
    if (index == 4)
      std::snprintf(out, n, "VIBRATO: %s", st.vibrato ? "ON" : "OFF");
    if (index == 5)
      std::snprintf(out, n, "STEP SHIFT: %+d DEG", int(st.shift));
    if (index == 6)
      std::snprintf(out, n, "LENGTH: %u", p_.length);
    if (index == 7)
      std::snprintf(out, n, "RETURN");
    break;
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
      std::snprintf(out, n, "SAVE SETTINGS");
    if (index == 8)
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
      std::snprintf(out, n, "TARGET: %u V", calVolt_);
    if (index == 2)
      std::snprintf(out, n, "INTERCEPT: %.3f", double(c.intercept));
    if (index == 3)
      std::snprintf(out, n, "SPAN: %.3f", double(c.span));
    if (index == 4)
      std::snprintf(out, n, "SAVE AND RETURN");
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
    c.text(0, 56, editing_ ? "TURN VALUE  CLICK OK" : "- BACK  CLICK SELECT");
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
    c.text(0, 0, "EDIT KEYS");
    noteName(float(keyNote(key_, p_, s_, false)), note, sizeof note);
    std::snprintf(line, sizeof line, "KEY %02u  %s", key_ + 1, note);
    c.text(0, 12, line);
    for (unsigned k = 0; k < Keys; ++k) {
      int x = int(k % 4) * 32, y = 25 + int(k / 4) * 9;
      std::snprintf(line, sizeof line, "%02u", k + 1);
      c.text(x + 7, y, line);
      if (k == key_)
        c.box(x, y - 1, 29, 9);
    }
    c.text(0, 56, "TOUCH KEY  TURN NOTE");
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
      std::snprintf(line, sizeof line, "%u BPM %s", s_.bpm,
                    scaleName(p_.scale));
      c.text(0, 46, line);
      c.text(0, 56, "CLICK MENU  HOLD MENU");
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
