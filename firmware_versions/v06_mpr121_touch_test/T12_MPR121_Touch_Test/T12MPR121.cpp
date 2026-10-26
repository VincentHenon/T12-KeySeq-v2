#include "T12MPR121.h"

namespace {
constexpr uint8_t REG_TOUCH_STATUS_L = 0x00;
constexpr uint8_t REG_ECR = 0x5E;
constexpr uint8_t REG_SOFT_RESET = 0x80;
}

bool T12MPR121::writeRegister(uint8_t reg, uint8_t value) {
  _wire->beginTransmission(_address);
  _wire->write(reg);
  _wire->write(value);
  return _wire->endTransmission() == 0;
}

bool T12MPR121::readRegisters(uint8_t firstReg, uint8_t *data, size_t length) {
  _wire->beginTransmission(_address);
  _wire->write(firstReg);
  if (_wire->endTransmission(false) != 0) return false;
  const size_t received = _wire->requestFrom(_address, length);
  if (received != length) {
    while (_wire->available()) _wire->read();
    return false;
  }
  for (size_t i = 0; i < length; ++i) data[i] = uint8_t(_wire->read());
  return true;
}

bool T12MPR121::setThresholds(uint8_t touch, uint8_t release) {
  for (uint8_t electrode = 0; electrode < 12; ++electrode) {
    const uint8_t reg = uint8_t(0x41 + electrode * 2);
    if (!writeRegister(reg, touch) || !writeRegister(uint8_t(reg + 1), release)) {
      return false;
    }
  }
  return true;
}

bool T12MPR121::begin(TwoWire &wire, uint8_t address) {
  _wire = &wire;
  _address = address;

  // Match the Doboz v20 MPR121 setup recovered from its firmware. GP0/GP1
  // carry I2C0; GP2 is the MPR121's likely IRQ wire and is deliberately not
  // reconfigured or driven. This test polls the status registers instead.
  if (!writeRegister(REG_ECR, 0x00)) return false;
  if (!writeRegister(REG_SOFT_RESET, 0x63)) return false;
  delay(2);

  const uint8_t config[][2] = {
    {0x5C, 0x10}, {0x5D, 0x20}, {0x7D, 0xC9}, {0x7F, 0xB5},
    {0x7E, 0x83}, {0x7B, 0x0B}, {0x2B, 0x01}, {0x2F, 0x01},
    {0x2C, 0x01}, {0x30, 0x01}, {0x33, 0x01}, {0x2D, 0x00},
    {0x31, 0xFF}, {0x34, 0x00}, {0x2E, 0x00}, {0x32, 0x02},
    {0x35, 0x7F}, {0x5B, 0x00}
  };
  for (const auto &entry : config) {
    if (!writeRegister(entry[0], entry[1])) return false;
  }

  if (!setThresholds(15, 10)) return false;
  if (!writeRegister(REG_ECR, 0x8C)) return false; // 12 electrodes, run mode

  uint8_t ecr = 0;
  if (!readRegisters(REG_ECR, &ecr, 1) || (ecr & 0x0F) != 0x0C) return false;

  // The original firmware tightens thresholds after enabling the electrodes.
  if (!writeRegister(REG_ECR, 0x00)) return false;
  if (!setThresholds(9, 5)) return false;
  if (!writeRegister(REG_ECR, 0x8C)) return false;
  return true;
}

bool T12MPR121::readTouchStatus(uint16_t &status) {
  uint8_t data[2];
  if (!readRegisters(REG_TOUCH_STATUS_L, data, sizeof(data))) return false;
  status = uint16_t(data[0]) | (uint16_t(data[1] & 0x0F) << 8);
  return true;
}
