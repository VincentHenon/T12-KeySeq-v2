#line 1 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v06_mpr121_touch_test/T12_MPR121_Touch_Test/T12MPR121.h"
#pragma once

#include <Arduino.h>
#include <Wire.h>

class T12MPR121 {
public:
  bool begin(TwoWire &wire, uint8_t address = 0x5A);
  bool readTouchStatus(uint16_t &status);

private:
  TwoWire *_wire = nullptr;
  uint8_t _address = 0x5A;
  bool writeRegister(uint8_t reg, uint8_t value);
  bool readRegisters(uint8_t firstReg, uint8_t *data, size_t length);
  bool setThresholds(uint8_t touch, uint8_t release);
};
