#line 1 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v05_recovered_gpio_input_test/T12_GPIO_Input_Test/T12_GPIO_Input_Test.ino"
#include <Arduino.h>
#include "hardware/gpio.h"
#include "hardware/spi.h"

// Pin assignments recovered from the T12 v20 UF2 display setup:
// RP2040 SPI0: CS=GP17, SCK=GP18, TX/MOSI=GP19.
// The display control pins are GP16 (D/C) and GP20 (RES).
static constexpr uint8_t OLED_DC = 16;
static constexpr uint8_t OLED_CS = 17;
static constexpr uint8_t OLED_SCK = 18;
static constexpr uint8_t OLED_MOSI = 19;
static constexpr uint8_t OLED_RESET = 20;

// These pins are left as inputs in the diagnostic. Reads are passive: no
// output direction changes and no internal pull resistors are enabled.
static constexpr uint8_t SCAN_PINS[] = {3, 6, 10, 11, 12, 26, 27, 28, 29};
static constexpr size_t SCAN_COUNT = sizeof(SCAN_PINS) / sizeof(SCAN_PINS[0]);
static constexpr uint32_t DEBOUNCE_MS = 8;
static constexpr uint32_t DISPLAY_REFRESH_MS = 80;

static uint8_t framebuffer[128 * 64 / 8];
static bool stableState[SCAN_COUNT];
static bool candidateState[SCAN_COUNT];
static uint32_t candidateSince[SCAN_COUNT];
static int lastChangedIndex = -1;
static bool lastOldState = false;
static bool lastNewState = false;
static uint32_t lastDisplayRefresh = 0;

// Compact 5x7 font. Each byte is a vertical column, least significant bit
// at the top. Unsupported characters are drawn as spaces.
static const uint8_t* glyphFor(char c);
static void drawText(int x, int y, const char *text);
static void spiWriteByte(uint8_t value);
static void oledCommand(uint8_t value);
static void oledData(const uint8_t *data, size_t length);
static void oledInit();
static void oledFlush();
static void formatPinState(char *out, size_t size, size_t index);
static void drawDiagnostic();
static void printInitialStates();
void setup();
void loop();

#line 44 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v05_recovered_gpio_input_test/T12_GPIO_Input_Test/T12_GPIO_Input_Test.ino"
static const uint8_t *glyphFor(char c) {
  static const uint8_t space[5] = {0, 0, 0, 0, 0};
  static const uint8_t digits[10][5] = {
    {0x3E,0x51,0x49,0x45,0x3E}, {0x00,0x42,0x7F,0x40,0x00},
    {0x42,0x61,0x51,0x49,0x46}, {0x21,0x41,0x45,0x4B,0x31},
    {0x18,0x14,0x12,0x7F,0x10}, {0x27,0x45,0x45,0x45,0x39},
    {0x3C,0x4A,0x49,0x49,0x30}, {0x01,0x71,0x09,0x05,0x03},
    {0x36,0x49,0x49,0x49,0x36}, {0x06,0x49,0x49,0x29,0x1E}
  };
  static const uint8_t letters[26][5] = {
    {0x7E,0x11,0x11,0x11,0x7E}, {0x7F,0x49,0x49,0x49,0x36},
    {0x3E,0x41,0x41,0x41,0x22}, {0x7F,0x41,0x41,0x22,0x1C},
    {0x7F,0x49,0x49,0x49,0x41}, {0x7F,0x09,0x09,0x09,0x01},
    {0x3E,0x41,0x49,0x49,0x7A}, {0x7F,0x08,0x08,0x08,0x7F},
    {0x00,0x41,0x7F,0x41,0x00}, {0x20,0x40,0x41,0x3F,0x01},
    {0x7F,0x08,0x14,0x22,0x41}, {0x7F,0x40,0x40,0x40,0x40},
    {0x7F,0x02,0x0C,0x02,0x7F}, {0x7F,0x04,0x08,0x10,0x7F},
    {0x3E,0x41,0x41,0x41,0x3E}, {0x7F,0x09,0x09,0x09,0x06},
    {0x3E,0x41,0x51,0x21,0x5E}, {0x7F,0x09,0x19,0x29,0x46},
    {0x46,0x49,0x49,0x49,0x31}, {0x01,0x01,0x7F,0x01,0x01},
    {0x3F,0x40,0x40,0x40,0x3F}, {0x1F,0x20,0x40,0x20,0x1F},
    {0x3F,0x40,0x38,0x40,0x3F}, {0x63,0x14,0x08,0x14,0x63},
    {0x07,0x08,0x70,0x08,0x07}, {0x61,0x51,0x49,0x45,0x43}
  };
  static const uint8_t colon[5] = {0,0x36,0x36,0,0};
  static const uint8_t equal[5] = {0x14,0x14,0x14,0x14,0x14};
  static const uint8_t dash[5] = {0x08,0x08,0x08,0x08,0x08};
  static const uint8_t greater[5] = {0x00,0x41,0x22,0x14,0x08};
  static const uint8_t dot[5] = {0,0x60,0x60,0,0};
  static const uint8_t slash[5] = {0x20,0x10,0x08,0x04,0x02};

  if (c >= 'a' && c <= 'z') c = char(c - 'a' + 'A');
  if (c >= '0' && c <= '9') return digits[c - '0'];
  if (c >= 'A' && c <= 'Z') return letters[c - 'A'];
  switch (c) {
    case ':': return colon;
    case '=': return equal;
    case '-': return dash;
    case '>': return greater;
    case '.': return dot;
    case '/': return slash;
    default: return space;
  }
}

static void setPixel(int x, int y, bool on = true) {
  if (x < 0 || x >= 128 || y < 0 || y >= 64) return;
  const size_t index = size_t(x) + size_t(y / 8) * 128;
  const uint8_t mask = uint8_t(1u << (y & 7));
  if (on) framebuffer[index] |= mask;
  else framebuffer[index] &= uint8_t(~mask);
}

static void drawText(int x, int y, const char *text) {
  while (*text) {
    const uint8_t *glyph = glyphFor(*text++);
    for (int col = 0; col < 5; ++col) {
      for (int row = 0; row < 7; ++row) {
        if (glyph[col] & (1u << row)) setPixel(x + col, y + row);
      }
    }
    x += 6;
  }
}

static void spiWriteByte(uint8_t value) {
  spi_write_blocking(spi0, &value, 1);
}

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
    0xAE, 0x32, 0x10, 0x00, 0x40, 0x81, 0xD2, 0xA1, 0xA4, 0xA6,
    0xA8, 0x3F, 0xAD, 0x8B, 0xB0, 0xC8, 0xD3, 0x00, 0xD5, 0x80,
    0xD9, 0xF1, 0xDA, 0x12, 0xDB, 0x40, 0xAF
  };
  for (uint8_t command : initCommands) oledCommand(command);
}

static void oledFlush() {
  // The original controller is driven in page mode, eight pages by 128 cols.
  for (uint8_t page = 0; page < 8; ++page) {
    oledCommand(uint8_t(0xB0 | page));
    oledCommand(0x00);
    oledCommand(0x10);
    oledData(&framebuffer[size_t(page) * 128], 128);
  }
}

static void formatPinState(char *out, size_t size, size_t index) {
  snprintf(out, size, "G%02u=%u", SCAN_PINS[index], stableState[index] ? 1 : 0);
}

static void drawDiagnostic() {
  memset(framebuffer, 0, sizeof(framebuffer));
  drawText(0, 0, "T12 INPUT TEST");
  drawText(0, 8, "TURN CLICK RESET");
  for (size_t i = 0; i < SCAN_COUNT; ++i) {
    char cell[8];
    formatPinState(cell, sizeof(cell), i);
    const int col = int(i % 3);
    const int row = int(i / 3);
    drawText(col * 43, 18 + row * 8, cell);
  }
  if (lastChangedIndex >= 0) {
    char line[24];
    snprintf(line, sizeof(line), "LAST G%02u %u>%u",
             SCAN_PINS[lastChangedIndex], lastOldState ? 1 : 0,
             lastNewState ? 1 : 0);
    drawText(0, 46, line);
  } else {
    drawText(0, 46, "WAITING INPUT");
  }
  drawText(0, 56, "USB CDC ENABLED");
  oledFlush();
}

static void printInitialStates() {
  Serial.println("T12 GPIO input diagnostic");
  Serial.println("Read-only pin scan; no pulls enabled.");
  for (size_t i = 0; i < SCAN_COUNT; ++i) {
    Serial.print("GPIO");
    Serial.print(SCAN_PINS[i]);
    Serial.print('=');
    Serial.println(stableState[i] ? 1 : 0);
  }
  Serial.println("Rotate encoder, click it, and pulse Reset In through its jack.");
}

void setup() {
  Serial.begin(115200);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 2500) delay(10);

  oledInit();

  const uint32_t now = millis();
  for (size_t i = 0; i < SCAN_COUNT; ++i) {
    const bool value = gpio_get(SCAN_PINS[i]);
    stableState[i] = value;
    candidateState[i] = value;
    candidateSince[i] = now;
  }
  printInitialStates();
  drawDiagnostic();
  lastDisplayRefresh = millis();
}

void loop() {
  const uint32_t now = millis();
  bool changed = false;
  for (size_t i = 0; i < SCAN_COUNT; ++i) {
    const bool value = gpio_get(SCAN_PINS[i]);
    if (value != candidateState[i]) {
      candidateState[i] = value;
      candidateSince[i] = now;
    }
    if (candidateState[i] != stableState[i] &&
        now - candidateSince[i] >= DEBOUNCE_MS) {
      const bool oldValue = stableState[i];
      stableState[i] = candidateState[i];
      lastChangedIndex = int(i);
      lastOldState = oldValue;
      lastNewState = stableState[i];
      Serial.print("GPIO");
      Serial.print(SCAN_PINS[i]);
      Serial.print(' ');
      Serial.print(oldValue ? 1 : 0);
      Serial.print(" -> ");
      Serial.println(stableState[i] ? 1 : 0);
      changed = true;
    }
  }

  if (changed && now - lastDisplayRefresh >= DISPLAY_REFRESH_MS) {
    drawDiagnostic();
    lastDisplayRefresh = now;
  }
  delay(1);
}


