#include <Arduino.h>
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include <Wire.h>
#include "T12MPR121.h"

// Pin assignments recovered from the T12 v20 UF2 display setup:
// RP2040 SPI0: CS=GP17, SCK=GP18, TX/MOSI=GP19.
// The display control pins are GP16 (D/C) and GP20 (RES).
static constexpr uint8_t OLED_DC = 16;
static constexpr uint8_t OLED_CS = 17;
static constexpr uint8_t OLED_SCK = 18;
static constexpr uint8_t OLED_MOSI = 19;
static constexpr uint8_t OLED_RESET = 20;

// MPR121: GP0/GP1 are I2C0. GP2 is the likely IRQ wire and stays untouched.
// Polling the MPR121 status avoids configuring or driving its IRQ pin.
static constexpr uint8_t MPR_SDA = 0;
static constexpr uint8_t MPR_SCL = 1;
static constexpr uint8_t MPR_ADDRESS = 0x5A;
static constexpr uint32_t TOUCH_POLL_MS = 25;
static constexpr uint32_t DISPLAY_REFRESH_MS = 100;
// Logical keypad order recovered from the original T12 v20 firmware.
static constexpr uint8_t KEY_ELECTRODE[12] = {10, 6, 5, 0, 9, 7, 4, 2, 11, 8, 3, 1};

static uint8_t framebuffer[128 * 64 / 8];
static T12MPR121 touch;
static bool touchReady = false;
static uint16_t electrodeMask = 0;
static uint16_t keyMask = 0;
static uint16_t lastDrawnKeyMask = 0xFFFF;
static uint32_t lastTouchPoll = 0;
static uint32_t lastDisplayRefresh = 0;

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


static void drawTouchScreen() {
  memset(framebuffer, 0, sizeof(framebuffer));
  drawText(0, 0, "MPR121 TOUCH TEST");
  drawText(0, 10, touchReady ? "I2C GP0/1 ACK" : "I2C NO ACK GP0/1");

  for (uint8_t key = 0; key < 12; ++key) {
    char label[8];
    snprintf(label, sizeof(label), "%02u=%c", unsigned(key + 1),
             (keyMask & (1u << key)) ? 'P' : '-');
    drawText(int(key % 4) * 32, 22 + int(key / 4) * 10, label);
  }

  drawText(0, 56, "P=TOUCHED -=IDLE");
  oledFlush();
  lastDrawnKeyMask = keyMask;
}

static void reportKeyChanges(uint16_t oldMask, uint16_t newMask) {
  for (uint8_t key = 0; key < 12; ++key) {
    const uint16_t bit = uint16_t(1u << key);
    if ((oldMask & bit) == (newMask & bit)) continue;
    Serial.print("KEY ");
    if (key + 1 < 10) Serial.print('0');
    Serial.print(key + 1);
    Serial.print(" ELECTRODE ");
    Serial.print(KEY_ELECTRODE[key]);
    Serial.println((newMask & bit) ? " PRESSED" : " RELEASED");
  }
}

void setup() {
  Serial.begin(115200);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 1000) delay(10);

  // OLED implementation and pin mapping are reused unchanged from working v05.
  oledInit();
  drawTouchScreen();

  Wire.setSDA(MPR_SDA);
  Wire.setSCL(MPR_SCL);
  Wire.begin();
  Wire.setClock(100000);

  touchReady = touch.begin(Wire, MPR_ADDRESS);
  Serial.println("T12 MPR121 touch test");
  Serial.println("I2C0: SDA GP0, SCL GP1; GP2 IRQ untouched; I2C polling");
  Serial.println(touchReady ? "MPR121 initialized at 0x5A" : "MPR121 init failed; retrying");
  drawTouchScreen();
  lastTouchPoll = millis();
  lastDisplayRefresh = millis();
}

void loop() {
  const uint32_t now = millis();
  if (!touchReady && now - lastTouchPoll >= 1000) {
    lastTouchPoll = now;
    touchReady = touch.begin(Wire, MPR_ADDRESS);
    drawTouchScreen();
  }

  if (touchReady && now - lastTouchPoll >= TOUCH_POLL_MS) {
    lastTouchPoll = now;
    uint16_t newElectrodeMask = 0;
    if (touch.readTouchStatus(newElectrodeMask)) {
      electrodeMask = newElectrodeMask;
      uint16_t newKeyMask = 0;
      for (uint8_t key = 0; key < 12; ++key) {
        if (electrodeMask & (1u << KEY_ELECTRODE[key])) newKeyMask |= uint16_t(1u << key);
      }
      if (newKeyMask != keyMask) {
        const uint16_t oldMask = keyMask;
        keyMask = newKeyMask;
        reportKeyChanges(oldMask, keyMask);
        drawTouchScreen();
      }
    } else {
      touchReady = false;
      drawTouchScreen();
    }
  }

  if (now - lastDisplayRefresh >= DISPLAY_REFRESH_MS) {
    lastDisplayRefresh = now;
    if (lastDrawnKeyMask != keyMask) drawTouchScreen();
  }
  delay(1);
}
