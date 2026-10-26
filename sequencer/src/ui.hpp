#pragma once
#include "display.hpp"
#include "hardware.hpp"
namespace t12 {
class Ui {
public:
  Ui(Project &p, Settings &s, Engine &e) : p_(p), s_(s), engine_(e) {}
  void input(const hw::Input &, uint64_t now);
  void draw(Canvas &, uint64_t now) const;
  int selectedKey() const { return int(key_); }
  bool recording() const { return page_ == Page::Record; }
  void fault(const char *, uint64_t now);
  bool settingsSaveDue(uint64_t now) const {
    return settingsDirty_ && now >= settingsSaveDue_;
  }
  void autoSaveSettings(uint64_t now);

private:
  enum class Page {
    Play,
    Keys,
    Record,
    Steps,
    Menu,
    Parameters,
    Scale,
    Custom,
    Clock,
    Settings,
    Storage,
    Slot,
    Name,
    Calibration,
    ConfirmRecord
  };
  Project &p_;
  Settings &s_;
  Engine &engine_;
  Page page_ = Page::Play, return_ = Page::Play;
  unsigned row_ = 0, key_ = 0, step_ = 0, slot_ = 0, custom_ = 0, piano_ = 0,
           namePos_ = 0, calChannel_ = 0, calVolt_ = 0;
  bool editing_ = false, recordFull_ = false, wasRunning_ = false,
       dirty_ = false, settingsDirty_ = false;
  uint16_t customMask_ = 0xFFF;
  char editedName_[17]{}, message_[22]{};
  uint64_t messageUntil_ = 0;
  uint64_t settingsSaveDue_ = 0;
  hw::Input latest_{};
  unsigned rows() const;
  void enter(Page, unsigned row = 0);
  void menu();
  void turn(int delta, uint64_t now);
  void click(uint64_t now);
  void octave(int delta, uint64_t now);
  void changeValue(int delta, uint64_t now);
  void startRecord(uint64_t now);
  void endRecord(uint64_t now);
  void saveSettings(uint64_t now);
  void settingsChanged(uint64_t now);
  void suspend(uint64_t now);
  void resume(uint64_t now);
  void item(unsigned index, char *out, size_t n) const;

public:
  bool calibrationActive() const { return page_ == Page::Calibration; }
  Output calibrationOutput() const {
    return {calChannel_ == 0 ? float(calVolt_) : 0,
            calChannel_ == 1 ? float(calVolt_) : 0, false};
  }
};
} // namespace t12
