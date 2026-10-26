#line 1 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v09_capacitive_touch_screen/T12_Capacitive_Touch_Test/T12_Capacitive_Touch_Test.ino"
#include <Arduino.h>
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"

// Pin assignments recovered from the T12 v20 UF2 display setup:
// RP2040 SPI0: CS=GP17, SCK=GP18, TX/MOSI=GP19.
// The display control pins are GP16 (D/C) and GP20 (RES).
static constexpr uint8_t OLED_DC = 16;
static constexpr uint8_t OLED_CS = 17;
static constexpr uint8_t OLED_SCK = 18;
static constexpr uint8_t OLED_MOSI = 19;
static constexpr uint8_t OLED_RESET = 20;

// Simple capacitive-pad test. OLED code below is copied from v08, which the
// user confirmed displays correctly on this T12.
static constexpr uint8_t MPR_SDA = 0;
static constexpr uint8_t MPR_SCL = 1;
static constexpr uint8_t MPR_ADDRESS = 0x5A;
static constexpr uint8_t MPR_KEY_ELECTRODE[12] = {10, 6, 5, 0, 9, 7, 4, 2, 11, 8, 3, 1};
static constexpr uint32_t TOUCH_POLL_MS = 25;
static constexpr uint32_t DISPLAY_REFRESH_MS = 100;

static uint8_t framebuffer[128 * 64 / 8];
static bool mprReady = false;
static uint16_t electrodeMask = 0;
static uint16_t keyMask = 0;
static uint32_t lastTouchPoll = 0;
static uint32_t lastDisplayRefresh = 0;
static uint32_t lastDrawnKeyState = 0xFFFFFFFFu;

static void drawTouchScreen();
static bool mprBegin();
static bool mprReadTouchStatus(uint16_t &status);
static bool mprWriteRegister(uint8_t reg, uint8_t value);
static bool mprReadRegisters(uint8_t firstReg, uint8_t *data, size_t length);

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

static bool mprWriteRegister(uint8_t reg, uint8_t value) {
  const uint8_t data[2] = {reg, value};
  return i2c_write_blocking(i2c0, MPR_ADDRESS, data, 2, false) == 2;
}

static bool mprReadRegisters(uint8_t firstReg, uint8_t *data, size_t length) {
  if (i2c_write_blocking(i2c0, MPR_ADDRESS, &firstReg, 1, true) != 1) return false;
  return i2c_read_blocking(i2c0, MPR_ADDRESS, data, length, false) == int(length);
}

static bool mprSetThresholds(uint8_t touch, uint8_t release) {
  for (uint8_t electrode = 0; electrode < 12; ++electrode) {
    const uint8_t reg = uint8_t(0x41 + electrode * 2);
    if (!mprWriteRegister(reg, touch) || !mprWriteRegister(uint8_t(reg + 1), release)) return false;
  }
  return true;
}

static bool mprBegin() {
  gpio_set_function(MPR_SDA, GPIO_FUNC_I2C);
  gpio_set_function(MPR_SCL, GPIO_FUNC_I2C);
  gpio_set_pulls(MPR_SDA, true, false);
  gpio_set_pulls(MPR_SCL, true, false);
  i2c_init(i2c0, 100000);
  sleep_ms(10);

  if (!mprWriteRegister(0x5E, 0x00)) return false; // electrodes off
  if (!mprWriteRegister(0x80, 0x63)) return false; // soft reset
  sleep_ms(2);
  const uint8_t config[][2] = {
    {0x5C, 0x10}, {0x5D, 0x20}, {0x7D, 0xC9}, {0x7F, 0xB5},
    {0x7E, 0x83}, {0x7B, 0x0B}, {0x2B, 0x01}, {0x2F, 0x01},
    {0x2C, 0x01}, {0x30, 0x01}, {0x33, 0x01}, {0x2D, 0x00},
    {0x31, 0xFF}, {0x34, 0x00}, {0x2E, 0x00}, {0x32, 0x02},
    {0x35, 0x7F}, {0x5B, 0x00}
  };
  for (const auto &entry : config) {
    if (!mprWriteRegister(entry[0], entry[1])) return false;
  }
  if (!mprSetThresholds(15, 10) || !mprWriteRegister(0x5E, 0x8C)) return false;
  uint8_t ecr = 0;
  if (!mprReadRegisters(0x5E, &ecr, 1) || (ecr & 0x0F) != 0x0C) return false;
  if (!mprWriteRegister(0x5E, 0x00) || !mprSetThresholds(9, 5)) return false;
  return mprWriteRegister(0x5E, 0x8C);
}

static bool mprReadTouchStatus(uint16_t &status) {
  uint8_t data[2] = {0, 0};
  if (!mprReadRegisters(0x00, data, sizeof(data))) return false;
  status = uint16_t(data[0]) | (uint16_t(data[1] & 0x0F) << 8);
  return true;
}

static void drawTouchScreen() {
  memset(framebuffer, 0, sizeof(framebuffer));
  drawText(0, 0, "MPR121 TOUCH TEST");
  drawText(0, 10, mprReady ? "MPR121 OK GP0/1" : "MPR121 NO ACK");
  for (uint8_t key = 0; key < 12; ++key) {
    char label[8];
    snprintf(label, sizeof(label), "%02u %c", unsigned(key + 1),
             (keyMask & (1u << key)) ? 'P' : '-');
    drawText(int(key % 4) * 32, 23 + int(key / 4) * 10, label);
  }
  drawText(0, 56, "P=TOUCHED  -=IDLE");
  oledFlush();
  lastDrawnKeyState = (uint32_t(keyMask) << 1) | (mprReady ? 1u : 0u);
}

static void reportChangedKeys(uint16_t oldMask, uint16_t newMask) {
  for (uint8_t key = 0; key < 12; ++key) {
    const uint16_t bit = uint16_t(1u << key);
    if ((oldMask & bit) == (newMask & bit)) continue;
    Serial.print("KEY ");
    if (key + 1 < 10) Serial.print('0');
    Serial.print(key + 1);
    Serial.println((newMask & bit) ? " PRESSED" : " RELEASED");
  }
}

void setup() {
  Serial.begin(115200);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 1000) delay(10);

  oledInit();
  // Show a visible startup screen before touching the MPR121/I2C bus.
  mprReady = false;
  drawTouchScreen();
  delay(200);

  mprReady = mprBegin();
  Serial.println("T12 capacitive touch display test");
  Serial.println(mprReady ? "MPR121 initialized at 0x5A on GP0/GP1" : "MPR121 not responding on GP0/GP1");
  drawTouchScreen();
  lastTouchPoll = millis();
  lastDisplayRefresh = millis();
}

void loop() {
  const uint32_t now = millis();
  if (!mprReady && now - lastTouchPoll >= 1000) {
    lastTouchPoll = now;
    mprReady = mprBegin();
    drawTouchScreen();
  }
  if (mprReady && now - lastTouchPoll >= TOUCH_POLL_MS) {
    lastTouchPoll = now;
    uint16_t newElectrodeMask = 0;
    if (mprReadTouchStatus(newElectrodeMask)) {
      electrodeMask = newElectrodeMask;
      uint16_t newKeyMask = 0;
      for (uint8_t key = 0; key < 12; ++key) {
        if (electrodeMask & (1u << MPR_KEY_ELECTRODE[key])) newKeyMask |= uint16_t(1u << key);
      }
      if (newKeyMask != keyMask) {
        const uint16_t oldMask = keyMask;
        keyMask = newKeyMask;
        reportChangedKeys(oldMask, keyMask);
        drawTouchScreen();
      }
    } else {
      mprReady = false;
      drawTouchScreen();
    }
  }
  if (millis() - lastDisplayRefresh >= DISPLAY_REFRESH_MS) {
    lastDisplayRefresh = millis();
    const uint32_t state = (uint32_t(keyMask) << 1) | (mprReady ? 1u : 0u);
    if (state != lastDrawnKeyState) drawTouchScreen();
  }
  delay(1);
}
