#include "model.hpp"
#include <algorithm>
#include <cmath>
#include <cstdio>
namespace t12 {
const Scale scales[] = {
    {"CHROMATIC", 0xFFF},  {"MAJOR", 0xAB5},      {"NAT MINOR", 0x5AD},
    {"DORIAN", 0x6AD},     {"PHRYGIAN", 0x5AB},   {"LYDIAN", 0xAD5},
    {"MIXOLYDIAN", 0x6B5}, {"LOCRIAN", 0x56B},    {"HARM MINOR", 0x9AD},
    {"MELO MINOR", 0xAAD}, {"MAJ PENTA", 0x295},  {"MIN PENTA", 0x4A9},
    {"BLUES", 0x4E9},      {"WHOLE TONE", 0x555}, {"DIMINISHED", 0x6DB}};
const unsigned BuiltinScales = sizeof(scales) / sizeof(scales[0]);
unsigned scaleCount() { return BuiltinScales + UserScales; }
const char *scaleName(unsigned index) {
  static const char *names[] = {"USER 1", "USER 2", "USER 3", "USER 4"};
  return index < BuiltinScales  ? scales[index].name
         : index < scaleCount() ? names[index - BuiltinScales]
                                : "INVALID";
}
uint16_t scaleMask(const Project &p, const Settings &s) {
  return p.scale < BuiltinScales  ? scales[p.scale].mask
         : p.scale < scaleCount() ? s.userScales[p.scale - BuiltinScales]
                                  : 0xFFF;
}
bool allowed(int n, const Project &p, const Settings &s) {
  return (scaleMask(p, s) & (1u << ((n - int(p.root) + 120) % 12))) != 0;
}
int quantize(int n, const Project &p, const Settings &s) {
  n = std::clamp(n, 0, MaxNote);
  for (int d = 0; d <= 12; ++d) {
    if (n - d >= 0 && allowed(n - d, p, s))
      return n - d; // downward tie break
    if (n + d <= MaxNote && allowed(n + d, p, s))
      return n + d;
  }
  return n;
}
int moveNote(int n, int direction, const Project &p, const Settings &s) {
  for (int x = n + direction; x >= 0 && x <= MaxNote; x += direction)
    if (allowed(x, p, s))
      return x;
  return quantize(n, p, s);
}
int keyNote(unsigned k, const Project &p, const Settings &s, bool trans) {
  return std::clamp(quantize(p.notes[k % Keys], p, s) +
                        (trans ? 12 * p.transpose : 0),
                    0, MaxNote);
}
int shiftDegrees(int note, int degrees, const Project &p, const Settings &s) {
  int result = std::clamp(note, 0, MaxNote);
  const int direction = degrees < 0 ? -1 : 1;
  for (int n = 0; n < std::abs(degrees); ++n) {
    const int next = moveNote(result, direction, p, s);
    if (next == result)
      break;
    result = next;
  }
  return result;
}
void fillKeys(Project &p, const Settings &s) {
  int n = quantize(p.notes[0], p, s);
  for (auto &key : p.notes) {
    key = uint8_t(n);
    n = moveNote(n, 1, p, s);
  }
}
void noteName(float n, char *out, size_t size) {
  static const char *names[] = {"C",  "C#", "D",  "D#", "E",  "F",
                                "F#", "G",  "G#", "A",  "A#", "B"};
  int note = std::clamp(int(std::lround(n)), 0, MaxNote);
  std::snprintf(out, size, "%s%d", names[note % 12], note / 12);
}
bool valid(const Project &p) {
  if (p.length > Steps || p.scale >= scaleCount() || p.root > 11 ||
      p.transpose < -7 || p.transpose > 7 || p.name[16])
    return false;
  for (auto n : p.notes)
    if (n > MaxNote)
      return false;
  for (auto st : p.steps)
    if (st.key >= Keys || st.time < -1 || st.time > 8 || st.retrigger > 1 ||
        st.glide > 1 || st.vibrato > 1 || st.ratchet < 1 || st.ratchet > 8 ||
        st.shift < -7 || st.shift > 7 || uint8_t(st.gate) > 5 ||
        st.length < 1 || st.length > 8 || st.variant > 1 ||
        st.variantDegree < -24 || st.variantDegree > 24 ||
        st.variantMin < -24 || st.variantMin > 0 || st.variantMax < 0 ||
        st.variantMax > 24 || st.variantMin > st.variantMax)
      return false;
  if (p.length && ((p.loopLength && p.loopLength > p.length) ||
                   p.loopOffset + (p.loopLength ? p.loopLength : p.length) > p.length))
    return false;
  return true;
}
bool valid(const Settings &s) {
  if (s.bpm < 20 || s.bpm > 300 || !s.division || s.division > 16 ||
      (s.division & (s.division - 1)) || unsigned(s.clock) > 2 ||
      unsigned(s.aux) > 4 || unsigned(s.glideShape) > 2 || s.reverseEncoder > 1 ||
      s.gateLength < 10 || s.gateLength > 90)
    return false;
  if (s.sequenceDirection > 2 || s.arpDirection > 2)
    return false;
  for (unsigned i = 0; i < Keys; ++i)
    if (s.capRange[i] == 0 || s.capRange[i] > 1023 || s.capIdle[i] > 1023)
      return false;
  if (!std::isfinite(s.vibratoHz) || s.vibratoHz < 0.1f || s.vibratoHz > 20 ||
      !std::isfinite(s.vibratoCents) || s.vibratoCents < 0 ||
      s.vibratoCents > 200)
    return false;
  for (auto mask : s.userScales)
    if (!mask || (mask & 0xF000))
      return false;
  for (auto c : {s.pitch, s.auxiliary})
    if (!std::isfinite(c.intercept) || !std::isfinite(c.span) ||
        c.intercept < 6 || c.intercept > 10 || c.span < 6 || c.span > 12)
      return false;
  for (const auto &c : {s.pitch, s.auxiliary}) {
    float previous = -2.0f;
    for (float x : c.measured) {
      if (!std::isfinite(x) || x < -1.0f || x > 10.0f || x <= previous + 0.02f)
        return false;
      previous = x;
    }
    for (unsigned i = 0; i < CalibrationPoints; ++i)
      if (c.coarseMv[i] < -1000 || c.coarseMv[i] > 1000 ||
          c.fineTenthsMv[i] < -100 || c.fineTenthsMv[i] > 100)
        return false;
  }
  return true;
}
} // namespace t12
