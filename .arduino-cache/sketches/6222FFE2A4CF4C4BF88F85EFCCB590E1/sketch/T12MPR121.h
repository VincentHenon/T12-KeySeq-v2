#line 1 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v07_mpr121_touch_i2c0/T12_MPR121_Touch_Test/T12MPR121.h"
#pragma once

#include <Arduino.h>

namespace T12MPR121 {
bool begin();
bool readTouchStatus(uint16_t &status);
}
