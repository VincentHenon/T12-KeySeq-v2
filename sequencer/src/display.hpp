#pragma once
#include <cstdint>
namespace t12 {
struct Canvas {
  uint8_t data[1024]{};
  void clear();
  void pixel(int x, int y, bool on = true);
  void text(int x, int y, const char *s);
  // The built-in glyphs are 5x7 pixels. Scale 1..5 produces 5x7 through
  // 25x35 glyphs; bold adds a one-pixel scaled stroke to the right.
  void textScaled(int x, int y, const char *s, unsigned scale, bool bold = false);
  void box(int x, int y, int w, int h, bool fill = false, bool on = true);
};
namespace display {
void launch();
void publish(const Canvas &);
} // namespace display
} // namespace t12
