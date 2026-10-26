#pragma once
#include <cstdint>
namespace t12 {
struct Canvas {
  uint8_t data[1024]{};
  void clear();
  void pixel(int x, int y, bool on = true);
  void text(int x, int y, const char *s);
  void box(int x, int y, int w, int h, bool fill = false, bool on = true);
};
namespace display {
void launch();
void publish(const Canvas &);
} // namespace display
} // namespace t12
