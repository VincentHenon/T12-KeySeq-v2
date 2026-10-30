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
  int selectedKeyNote() const { return int(p_.notes[key_ < Keys ? key_ : 0]); }
  const uint8_t *keyNotes() const { return p_.notes; }
  bool showSelectedLed() const {
    return page_ == Page::Keys || page_ == Page::Steps || page_ == Page::Record;
  }
  bool showPlayingLed() const {
    return (page_ == Page::Play || page_ == Page::Record) && engine_.running();
  }
  bool recording() const { return page_ == Page::Record; }
  bool keyEditing() const { return page_ == Page::Keys; }
  void fault(const char *, uint64_t now);
  bool settingsSaveDue(uint64_t now) const {
    return settingsDirty_ && now >= settingsSaveDue_;
  }
  bool projectSaveDue(uint64_t now) const { return dirty_ && now >= projectSaveDue_; }
  void autoSaveSettings(uint64_t now);
  void autoSaveProject(uint64_t now);

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
    CalibrationResult,
    ConfirmRecord,
    ConfirmExitRecord
  };
  Project &p_;
  Project recordBackup_{};
  Settings &s_;
  Engine &engine_;
  Page page_ = Page::Play, return_ = Page::Play;
  unsigned row_ = 0, key_ = 0, step_ = 0, slot_ = 0, custom_ = 0, piano_ = 0,
           namePos_ = 0, calChannel_ = 0, calPoint_ = 0;
  unsigned playParam_ = 0;
  bool editing_ = false, recordFull_ = false, recordAppending_ = false,
       recordReplacePending_ = false,
       wasRunning_ = false,
       recordBackupValid_ = false,
       dirty_ = false, settingsDirty_ = false;
  uint16_t customMask_ = 0xFFF;
  char editedName_[17]{}, message_[22]{};
  uint64_t messageUntil_ = 0;
  uint64_t liveModalUntil_ = 0;
  uint64_t editModalUntil_ = 0;
  char editModalText_[22]{};
  uint64_t settingsSaveDue_ = 0;
  uint64_t projectSaveDue_ = 0;
  uint64_t nextMinusRepeat_ = 0, nextPlusRepeat_ = 0;
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
  void discardRecord(uint64_t now);
  void saveSettings(uint64_t now);
  void settingsChanged(uint64_t now);
  void suspend(uint64_t now);
  void resume(uint64_t now);
  void item(unsigned index, char *out, size_t n) const;

public:
  bool calibrationActive() const { return page_ == Page::Calibration; }
  Output calibrationOutput() const {
    if (page_ != Page::Calibration && page_ != Page::CalibrationResult)
      return {};
    const float volts = page_ == Page::CalibrationResult
                            ? float(calPoint_)
                            : float(calPoint_ * 2);
    return {calChannel_ == 0 ? volts : 0,
            calChannel_ == 1 ? volts : 0, false};
  }
};
} // namespace t12
