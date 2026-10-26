#pragma once
#include "engine.hpp"
#include <cstdint>
namespace t12::hw {
namespace pin {
constexpr unsigned TouchSda = 0, TouchScl = 1, Rgb = 2, Clock = 3, Pitch = 4,
                   Aux = 5, Reset = 6, Gate = 7;
constexpr unsigned Click = 10, EncoderA = 11, EncoderB = 12, DisplayDc = 16,
                   DisplayCs = 17, DisplayClk = 18, DisplayMosi = 19,
                   DisplayReset = 20;
constexpr unsigned LedPlus = 21, LedMinus = 22, Cv = 26, Minus = 27, Plus = 28;
} // namespace pin
struct Input {
  int turn = 0;
  bool click = false, longClick = false, minus = false, plus = false;
  bool minusHeld = false, plusHeld = false, touchOk = false;
  uint16_t keys = 0, pressed = 0, cvRaw = 0;
};
struct Edge {
  uint64_t time;
  bool reset;
};
void init(const Settings &);
Input poll(uint64_t now);
bool popEdge(Edge &);
bool overflowed();
void clearEdges();
void write(const Output &, const Settings &);
void leds(uint16_t held, int selected, int playing, uint8_t brightness,
          bool recording);
void serviceLeds();
uint16_t duty(float volts, const Calibration &);
bool clockHigh();
bool resetHigh();
} // namespace t12::hw
