#line 1 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test/T12MPR121.cpp"
#include "T12MPR121.h"
#include "hardware/gpio.h"
#include "hardware/i2c.h"

namespace {
constexpr uint8_t MPR_SDA = 0;
constexpr uint8_t MPR_SCL = 1;
constexpr uint8_t MPR_ADDRESS = 0x5A;
constexpr uint8_t REG_TOUCH_STATUS_L = 0x00;
constexpr uint8_t REG_ECR = 0x5E;
constexpr uint8_t REG_SOFT_RESET = 0x80;

bool writeRegister(uint8_t reg, uint8_t value) {
  const uint8_t data[2] = {reg, value};
  return i2c_write_blocking(i2c0, MPR_ADDRESS, data, sizeof(data), false) == sizeof(data);
}

bool readRegisters(uint8_t firstReg, uint8_t *data, size_t length) {
  if (i2c_write_blocking(i2c0, MPR_ADDRESS, &firstReg, 1, true) != 1) return false;
  return i2c_read_blocking(i2c0, MPR_ADDRESS, data, length, false) == int(length);
}

bool setThresholds(uint8_t touch, uint8_t release) {
  for (uint8_t electrode = 0; electrode < 12; ++electrode) {
    const uint8_t reg = uint8_t(0x41 + electrode * 2);
    if (!writeRegister(reg, touch) || !writeRegister(uint8_t(reg + 1), release)) return false;
  }
  return true;
}
}

bool T12MPR121::begin() {
  // Explicit hardware I2C0 pin mux; GP2 (likely active-low IRQ) is not touched.
  gpio_set_function(MPR_SDA, GPIO_FUNC_I2C);
  gpio_set_function(MPR_SCL, GPIO_FUNC_I2C);
  gpio_set_pulls(MPR_SDA, true, false);
  gpio_set_pulls(MPR_SCL, true, false);
  i2c_init(i2c0, 100000);

  if (!writeRegister(REG_ECR, 0x00)) return false;
  if (!writeRegister(REG_SOFT_RESET, 0x63)) return false;
  sleep_ms(2);

  // Register values and threshold sequence match the Doboz v20 firmware.
  const uint8_t config[][2] = {
    {0x5C, 0x10}, {0x5D, 0x20}, {0x7D, 0xC9}, {0x7F, 0xB5},
    {0x7E, 0x83}, {0x7B, 0x0B}, {0x2B, 0x01}, {0x2F, 0x01},
    {0x2C, 0x01}, {0x30, 0x01}, {0x33, 0x01}, {0x2D, 0x00},
    {0x31, 0xFF}, {0x34, 0x00}, {0x2E, 0x00}, {0x32, 0x02},
    {0x35, 0x7F}, {0x5B, 0x00}
  };
  for (const auto &entry : config) if (!writeRegister(entry[0], entry[1])) return false;

  if (!setThresholds(15, 10) || !writeRegister(REG_ECR, 0x8C)) return false;
  uint8_t ecr = 0;
  if (!readRegisters(REG_ECR, &ecr, 1) || (ecr & 0x0F) != 0x0C) return false;

  if (!writeRegister(REG_ECR, 0x00) || !setThresholds(9, 5)) return false;
  return writeRegister(REG_ECR, 0x8C);
}

bool T12MPR121::readTouchStatus(uint16_t &status) {
  uint8_t data[2];
  if (!readRegisters(REG_TOUCH_STATUS_L, data, sizeof(data))) return false;
  status = uint16_t(data[0]) | (uint16_t(data[1] & 0x0F) << 8);
  return true;
}
