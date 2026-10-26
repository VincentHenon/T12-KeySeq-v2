#include "display.hpp"
#include "hardware.hpp"
#include "hardware/spi.h"
#include "pico/flash.h"
#include "pico/multicore.h"
#include "pico/mutex.h"
#include "pico/stdlib.h"
#include <cstring>
namespace t12 {
namespace display {
namespace {
constexpr auto OLED_DC = hw::pin::DisplayDc, OLED_CS = hw::pin::DisplayCs,
               OLED_SCK = hw::pin::DisplayClk, OLED_MOSI = hw::pin::DisplayMosi,
               OLED_RESET = hw::pin::DisplayReset;
constexpr uint8_t OLED_COLUMN_START = 2;
uint8_t framebuffer[1024]{};
Canvas mailbox{};
mutex_t lock;
bool pending = false;
static void spiWriteByte(uint8_t value) { spi_write_blocking(spi0, &value, 1); }

static void oledCommand(uint8_t value) {
  gpio_put(OLED_DC, 0);
  gpio_put(OLED_CS, 0);
  spiWriteByte(value);
  gpio_put(OLED_CS, 1);
}

static void oledData(const uint8_t *data, size_t length) {
  gpio_put(OLED_DC, 1);
  gpio_put(OLED_CS, 0);
  spi_write_blocking(spi0, data, length);
  gpio_put(OLED_CS, 1);
}

static void oledInit() {
  gpio_init(OLED_DC);
  gpio_set_dir(OLED_DC, GPIO_OUT);
  gpio_put(OLED_DC, 1);
  gpio_init(OLED_CS);
  gpio_set_dir(OLED_CS, GPIO_OUT);
  gpio_put(OLED_CS, 1);
  gpio_init(OLED_RESET);
  gpio_set_dir(OLED_RESET, GPIO_OUT);
  gpio_put(OLED_RESET, 1);
  sleep_ms(2);
  gpio_put(OLED_RESET, 0);
  sleep_ms(10);
  gpio_put(OLED_RESET, 1);
  sleep_ms(10);

  gpio_set_function(OLED_SCK, GPIO_FUNC_SPI);
  gpio_set_function(OLED_MOSI, GPIO_FUNC_SPI);
  spi_init(spi0, 1000000);
  spi_set_format(spi0, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);

  // Command stream extracted from the Doboz T12 v20 UF2 display initializer.
  static const uint8_t initCommands[] = {
      0xAE, 0x32, 0x10, 0x00, 0x40, 0x81, 0xD2, 0xA1, 0xA4,
      0xA6, 0xA8, 0x3F, 0xAD, 0x8B, 0xB0, 0xC8, 0xD3, 0x00,
      0xD5, 0x80, 0xD9, 0xF1, 0xDA, 0x12, 0xDB, 0x40, 0xAF};
  for (uint8_t command : initCommands)
    oledCommand(command);
}

static void oledFlush() {
  // The original controller is driven in page mode, eight pages by 128 cols.
  // Wrap the final two framebuffer columns to the left edge, shifting all
  // other pixels two columns to the right without changing OLED commands.
  uint8_t shiftedPage[128];
  for (uint8_t page = 0; page < 8; ++page) {
    const size_t pageStart = size_t(page) * 128;
    shiftedPage[0] = framebuffer[pageStart + 126];
    shiftedPage[1] = framebuffer[pageStart + 127];
    for (uint8_t column = 2; column < 128; ++column) {
      shiftedPage[column] = framebuffer[pageStart + column - 2];
    }
    oledCommand(uint8_t(0xB0 | page));
    oledCommand(uint8_t(0x00 | (OLED_COLUMN_START & 0x0F)));
    oledCommand(uint8_t(0x10 | (OLED_COLUMN_START >> 4)));
    oledData(shiftedPage, sizeof(shiftedPage));
  }
}

void run() {
  flash_safe_execute_core_init();
  oledInit();
  multicore_fifo_push_blocking(1);
  while (true) {
    bool redraw = false;
    mutex_enter_blocking(&lock);
    if (pending) {
      std::memcpy(framebuffer, mailbox.data, 1024);
      pending = false;
      redraw = true;
    }
    mutex_exit(&lock);
    if (redraw)
      oledFlush();
    sleep_ms(1);
  }
}
} // namespace
void launch() {
  mutex_init(&lock);
  multicore_launch_core1(run);
  multicore_fifo_pop_blocking();
}
void publish(const Canvas &c) {
  mutex_enter_blocking(&lock);
  mailbox = c;
  pending = true;
  mutex_exit(&lock);
}
} // namespace display
} // namespace t12
