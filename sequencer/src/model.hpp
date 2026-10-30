#pragma once
#include <cstddef>
#include <cstdint>
namespace t12 {
constexpr unsigned Keys = 12, Steps = 32, UserScales = 4, Slots = 8,
                   CalibrationPoints = 5;
constexpr int MaxNote = 96; // semitones above C0; 8 V maximum
struct Step {
  uint8_t key = 0;
  int8_t time = 1; // -1: half clock, 0: one-clock rest, 1..8 clocks
  uint8_t retrigger = 0, glide = 0, vibrato = 0;
  uint8_t ratchet = 1; // equal gate repeats across this complete step: 1..8
  int8_t shift = 0;    // scale degrees added each time this step returns
  enum class GateType : uint8_t { Single, Multi, Hold, Rest, Skip };
  GateType gate = GateType::Single;
  uint8_t length = 1;  // clock steps occupied by this event
  uint8_t variant = 0;
  int8_t variantDegree = 0;
  int8_t variantMin = -24;
  int8_t variantMax = 24;
};
struct Project {
  char name[17] = "UNTITLED";
  Step steps[Steps]{};
  uint8_t notes[Keys] = {36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};
  uint8_t length = 0, scale = 0, root = 0;
  uint8_t loopLength = 0, loopOffset = 0;
  int8_t transpose = 0; // octaves, playback only
};
enum class ClockMode : uint8_t { Auto, Internal, External };
enum class AuxMode : uint8_t { Off, Pitch, Vibrato, Position, Capacitance };
enum class GlideShape : uint8_t { Smooth, Linear, Expo };
struct Calibration {
  float intercept = 7.787f, span = 8.464f;
  // Jack voltage measured when commanding nominal 0, 2, 4, 6 and 8 V.
  float measured[CalibrationPoints] = {0, 2, 4, 6, 8};
  int16_t coarseMv[CalibrationPoints]{};
  int16_t fineTenthsMv[CalibrationPoints]{};
};
struct Settings {
  uint16_t userScales[UserScales] = {0xAB5, 0x5AD, 0x295, 0xFFF};
  uint16_t bpm = 120;
  uint8_t division = 1, brightness = 32, gateLength = 50;
  uint8_t sequenceDirection = 0, arpDirection = 0;
  uint16_t capIdle[Keys]{};
  uint16_t capRange[Keys] = {256,256,256,256,256,256,256,256,256,256,256,256};
  ClockMode clock = ClockMode::Auto;
  AuxMode aux = AuxMode::Off;
  GlideShape glideShape = GlideShape::Expo;
  uint8_t reverseEncoder = 1;
  float vibratoHz = 8, vibratoCents = 30;
  Calibration pitch{}, auxiliary{7.780f, 8.528f};
};
struct Scale {
  const char *name;
  uint16_t mask;
};
extern const Scale scales[];
extern const unsigned BuiltinScales;
unsigned scaleCount();
const char *scaleName(unsigned index);
uint16_t scaleMask(const Project &, const Settings &);
bool allowed(int note, const Project &, const Settings &);
int quantize(int note, const Project &, const Settings &);
int moveNote(int note, int direction, const Project &, const Settings &);
int keyNote(unsigned key, const Project &, const Settings &,
            bool transpose = true);
int shiftDegrees(int note, int degrees, const Project &, const Settings &);
void fillKeys(Project &, const Settings &);
void noteName(float note, char *out, size_t size);
bool valid(const Project &);
bool valid(const Settings &);
} // namespace t12
