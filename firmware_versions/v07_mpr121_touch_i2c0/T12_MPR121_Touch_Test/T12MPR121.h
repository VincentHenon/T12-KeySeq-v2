#pragma once

#include <Arduino.h>

namespace T12MPR121 {
bool begin();
bool readTouchStatus(uint16_t &status);
}
