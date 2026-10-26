#include <Arduino.h>
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "hardware/i2c.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include <Adafruit_NeoPixel.h>
#include <new>

// Pin assignments recovered from the T12 v20 UF2 display setup:
// RP2040 SPI0: CS=GP17, SCK=GP18, TX/MOSI=GP19.
// The display control pins are GP16 (D/C) and GP20 (RES).
static constexpr uint8_t OLED_DC = 16;
static constexpr uint8_t OLED_CS = 17;
static constexpr uint8_t OLED_SCK = 18;
static constexpr uint8_t OLED_MOSI = 19;
static constexpr uint8_t OLED_RESET = 20;
// The visible OLED window appears to start two RAM columns after column 0.
static constexpr uint8_t OLED_COLUMN_START = 2;

// Confirmed controls and MPR121 pins.
static constexpr uint8_t MPR_SDA = 0;
static constexpr uint8_t MPR_SCL = 1;
static constexpr uint8_t MPR_ADDRESS = 0x5A;
static constexpr uint8_t MPR_KEY_ELECTRODE[12] = {10, 6, 5, 0, 9, 7, 4, 2, 11, 8, 3, 1};
static constexpr uint8_t ENCODER_CLICK = 10;
static constexpr uint8_t ENCODER_A = 11;
static constexpr uint8_t ENCODER_B = 12;
static constexpr uint8_t OCTAVE_DOWN_LED = 22;
static constexpr uint8_t OCTAVE_UP_LED = 21;
static constexpr uint8_t OCTAVE_DOWN_BUTTON = 27;
static constexpr uint8_t OCTAVE_UP_BUTTON = 28;

// Jack GPIOs from the Doboz v20 UF2 analysis; jack assignments are being tested.
static constexpr uint8_t RESET_IN = 6;
static constexpr uint8_t CLOCK_IN = 3;
static constexpr uint8_t CV_IN = 26; // ADC0 / Arduino A0
static constexpr uint8_t NOTE_CV_OUT = 4;
static constexpr uint8_t AUX_CV_OUT = 5;
static constexpr uint8_t GATE_OUT = 7;

static constexpr uint32_t DEBOUNCE_MS = 20;
static constexpr uint32_t TOUCH_POLL_MS = 25;
static constexpr uint32_t DISPLAY_REFRESH_MS = 100;
static constexpr uint16_t PWM_TOP = 4095;
static constexpr uint8_t CV_NOTE_STEPS = 12;
static constexpr uint8_t PAGE_COUNT = 8;
static constexpr uint8_t CANDIDATE_PINS[] = {2, 8, 9, 13, 14, 15, 23, 24, 25, 29};
static constexpr uint8_t CANDIDATE_COUNT = sizeof(CANDIDATE_PINS) / sizeof(CANDIDATE_PINS[0]);
static constexpr uint8_t RGB_GPIO_PINS[] = {2, 8, 9, 13, 14, 15, 23, 24, 25};
static constexpr uint8_t RGB_GPIO_COUNT = sizeof(RGB_GPIO_PINS) / sizeof(RGB_GPIO_PINS[0]);
static constexpr uint8_t RGB_LED_COUNT = 12;
static constexpr uint8_t RGB_DATA_PIN = 2;
static constexpr neoPixelType RGB_TYPE = NEO_GRB + NEO_KHZ800;
static const char *RGB_ANIMATION_NAMES[] = {
  "RAINBOW", "COLOR CHASE", "BOUNCE", "COLOR WIPE",
  "THEATER", "COLOR BANDS", "BREATHE"
};
static constexpr uint8_t RGB_ANIMATION_COUNT = sizeof(RGB_ANIMATION_NAMES) / sizeof(RGB_ANIMATION_NAMES[0]);
static constexpr uint8_t BUTTON_DOWN_BIT = 1;
static constexpr uint8_t BUTTON_UP_BIT = 2;

static uint8_t framebuffer[128 * 64 / 8];
static bool mprReady = false;
static uint16_t electrodeMask = 0;
static uint16_t keyMask = 0;
static uint32_t lastTouchPoll = 0;
static uint32_t lastDisplayRefresh = 0;
static uint32_t lastAdcRead = 0;
static uint16_t cvAdcRaw = 0;
static uint8_t displayPage = 0;
static bool resetInvert = false;
static bool clockInvert = false;
static volatile uint32_t resetEdgeCount = 0;
static volatile uint32_t clockEdgeCount = 0;
static volatile bool resetLastRawHigh = true;
static volatile bool clockLastRawHigh = true;
static volatile uint16_t candidateEdgeCounts[CANDIDATE_COUNT] = {};
static bool gateHigh = false;
static uint8_t noteCvStep = 0;
static uint8_t auxCvStep = 0;
static uint8_t rgbAnimation = 0;
static uint16_t rgbFrame = 0;
static uint32_t lastRgbFrame = 0;
static bool rgbTestReady = false;
alignas(Adafruit_NeoPixel) static uint8_t rgbStorage[sizeof(Adafruit_NeoPixel)];
static Adafruit_NeoPixel *rgbPixels = nullptr;
static uint8_t buttonsStable = 0;
static uint8_t buttonsCandidate = 0;
static uint32_t buttonsCandidateSince = 0;
static int8_t encoderQuarterSteps = 0;
static uint8_t encoderPrevious = 0;
static uint8_t encoderDetentState = 0;

static void drawTestPage();
static bool mprBegin();
static bool mprReadTouchStatus(uint16_t &status);
static bool mprWriteRegister(uint8_t reg, uint8_t value);
static bool mprReadRegisters(uint8_t firstReg, uint8_t *data, size_t length);
static void updateControls(uint32_t now);
static uint8_t readButtons();
static void updateCvOutputs();
static void updateGateOutput();
static void startRgbTest();
static void stopRgbTest();
static void drawRgbTestPattern();
static void updateRgbAnimation(uint32_t now);
static uint32_t rgbWheel(uint8_t position);
static void jackInputIrq(uint gpio, uint32_t events);
static void reportChangedKeys(uint16_t oldMask, uint16_t newMask);

// Compact 5x7 font. Each byte is a vertical column, least significant bit
// at the top. Unsupported characters are drawn as spaces.
static const uint8_t* glyphFor(char c);
static void drawText(int x, int y, const char *text);
static void spiWriteByte(uint8_t value);
static void oledCommand(uint8_t value);
static void oledData(const uint8_t *data, size_t length);
static void oledInit();
static void oledFlush();
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
  static const uint8_t sharp[5] = {0x14,0x7F,0x14,0x7F,0x14};

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
    case '#': return sharp;
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

static uint8_t readButtons() {
  return uint8_t((gpio_get(ENCODER_CLICK) ? 0 : 1) |
                 (gpio_get(OCTAVE_DOWN_BUTTON) ? 0 : BUTTON_DOWN_BIT) |
                 (gpio_get(OCTAVE_UP_BUTTON) ? 0 : BUTTON_UP_BIT));
}

static uint16_t cvDutyForMilliVolts(uint16_t milliVolts) {
  return uint16_t((uint32_t(milliVolts) * PWM_TOP + 4000u) / 8000u);
}

static const char *noteName(uint8_t index, uint8_t baseOctave) {
  static const char *names[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
  static char result[5];
  const uint8_t octave = uint8_t(baseOctave + index / 12);
  snprintf(result, sizeof(result), "%s%u", names[index % 12], unsigned(octave));
  return result;
}

static uint16_t cvDutyForNote(uint8_t index, uint8_t baseOctave) {
  const uint16_t milliVolts = uint16_t(baseOctave * 1000u + (uint32_t(index) * 1000u + 6u) / 12u);
  return cvDutyForMilliVolts(milliVolts);
}

static void updateCvOutputs() {
  const uint16_t noteDuty = displayPage == 3 ? cvDutyForNote(noteCvStep, 3) : 0;
  const uint16_t auxDuty = displayPage == 4 ? cvDutyForNote(auxCvStep, 2) : 0;
  pwm_set_gpio_level(NOTE_CV_OUT, noteDuty);
  pwm_set_gpio_level(AUX_CV_OUT, auxDuty);
}

static void updateGateOutput() {
  gpio_put(GATE_OUT, gateHigh ? 1 : 0);
}

static void releaseRgbPixels(bool restoreInput) {
  if (!rgbPixels) return;
  const uint8_t oldPin = uint8_t(rgbPixels->getPin());
  rgbPixels->clear();
  rgbPixels->show();
  delayMicroseconds(350);
  rgbPixels->~Adafruit_NeoPixel();
  rgbPixels = nullptr;
  rgbTestReady = false;
  if (restoreInput) {
    gpio_set_function(oldPin, GPIO_FUNC_SIO);
    gpio_set_dir(oldPin, GPIO_IN);
    gpio_set_input_enabled(oldPin, true);
    gpio_disable_pulls(oldPin);
    gpio_set_irq_enabled(oldPin, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
  }
}

static uint32_t rgbWheel(uint8_t position) {
  position = uint8_t(255 - position);
  if (position < 85) return rgbPixels->Color(uint8_t(255 - position * 3), 0, uint8_t(position * 3));
  if (position < 170) {
    position = uint8_t(position - 85);
    return rgbPixels->Color(0, uint8_t(position * 3), uint8_t(255 - position * 3));
  }
  position = uint8_t(position - 170);
  return rgbPixels->Color(uint8_t(position * 3), uint8_t(255 - position * 3), 0);
}

static void drawRgbTestPattern() {
  if (!rgbPixels || !rgbTestReady) return;
  const uint8_t frame = uint8_t(rgbFrame);
  switch (rgbAnimation) {
    case 0: // Rainbow moving through the strip.
      for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) rgbPixels->setPixelColor(i, rgbWheel(uint8_t(i * 256 / RGB_LED_COUNT + frame * 3)));
      rgbPixels->setBrightness(96);
      break;
    case 1: // A bright pixel chases a dim trail.
      for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) {
        const uint8_t distance = uint8_t((i + RGB_LED_COUNT - frame % RGB_LED_COUNT) % RGB_LED_COUNT);
        const uint8_t level = distance == 0 ? 160 : (distance < 4 ? uint8_t(48 / distance) : 0);
        rgbPixels->setPixelColor(i, 0, level, distance == 0 ? 160 : 0);
      }
      rgbPixels->setBrightness(128);
      break;
    case 2: { // Single colored dot bouncing between the ends.
      const uint8_t phase = uint8_t(frame % (2 * (RGB_LED_COUNT - 1)));
      const uint8_t head = phase < RGB_LED_COUNT ? phase : uint8_t(2 * (RGB_LED_COUNT - 1) - phase);
      rgbPixels->clear();
      rgbPixels->setPixelColor(head, 180, 30, 0);
      if (head > 0) rgbPixels->setPixelColor(head - 1, 36, 6, 0);
      if (head + 1 < RGB_LED_COUNT) rgbPixels->setPixelColor(head + 1, 36, 6, 0);
      rgbPixels->setBrightness(128);
      break;
    }
    case 3: // Wipe through solid red, green, blue, white, then repeat.
      for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) {
        const uint8_t lit = uint8_t(frame % (RGB_LED_COUNT + 1));
        const uint8_t color = uint8_t((frame / (RGB_LED_COUNT + 1)) & 3);
        rgbPixels->setPixelColor(i, i < lit ? (color == 0 || color == 3 ? 128 : 0) : 0,
                                 i < lit ? (color == 1 || color == 3 ? 128 : 0) : 0,
                                 i < lit ? (color == 2 || color == 3 ? 128 : 0) : 0);
      }
      rgbPixels->setBrightness(112);
      break;
    case 4: // Three dots advance like a theater marquee.
      for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) {
        const bool on = (i + frame) % 3 == 0;
        rgbPixels->setPixelColor(i, on ? 0 : 0, on ? 0 : 0, on ? 150 : 0);
      }
      rgbPixels->setBrightness(128);
      break;
    case 5: // Fixed repeating RGBW groups, with moving group phase.
      for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) {
        switch ((i + frame / 4) & 3) {
          case 0: rgbPixels->setPixelColor(i, 128, 0, 0); break;
          case 1: rgbPixels->setPixelColor(i, 0, 128, 0); break;
          case 2: rgbPixels->setPixelColor(i, 0, 0, 128); break;
          default: rgbPixels->setPixelColor(i, 96, 96, 96); break;
        }
      }
      rgbPixels->setBrightness(112);
      break;
    default: { // All LEDs breathe together; brightness is the animation.
      const uint8_t triangle = uint8_t(frame % 64);
      const uint8_t level = uint8_t(20 + (triangle < 32 ? triangle : 63 - triangle) * 6);
      for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) rgbPixels->setPixelColor(i, 0, 0, 160);
      rgbPixels->setBrightness(level);
      break;
    }
  }
  rgbPixels->show();
}

static void updateRgbAnimation(uint32_t now) {
  if (displayPage != 7 || !rgbTestReady || now - lastRgbFrame < 70) return;
  lastRgbFrame = now;
  ++rgbFrame;
  drawRgbTestPattern();
}

static void startRgbTest() {
  const uint8_t pin = RGB_DATA_PIN;
  if (rgbPixels) releaseRgbPixels(true);
  gpio_set_irq_enabled(pin, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, false);
  rgbPixels = new (rgbStorage) Adafruit_NeoPixel(RGB_LED_COUNT, pin, RGB_TYPE);
  rgbTestReady = rgbPixels->begin();
  if (rgbTestReady) {
    rgbFrame = 0;
    lastRgbFrame = 0;
    drawRgbTestPattern();
  }
}

static void stopRgbTest() {
  if (rgbPixels) releaseRgbPixels(true);
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

static void drawTestPage() {
  memset(framebuffer, 0, sizeof(framebuffer));
  char line[24];
  snprintf(line, sizeof(line), "JACK TEST %u/%u", unsigned(displayPage + 1), unsigned(PAGE_COUNT));
  drawText(0, 0, line);

  const bool resetRawHigh = gpio_get(RESET_IN);
  const bool clockRawHigh = gpio_get(CLOCK_IN);
  const bool resetActive = resetInvert ? resetRawHigh : !resetRawHigh;
  const bool clockActive = clockInvert ? clockRawHigh : !clockRawHigh;
  const uint32_t resetEdges = resetEdgeCount;
  const uint32_t clockEdges = clockEdgeCount;
  const uint8_t padCount = __builtin_popcount(unsigned(keyMask));

  switch (displayPage) {
    case 0:
      drawText(0, 11, "RESET IN GP6");
      snprintf(line, sizeof(line), "RAW %s ACT %s", resetRawHigh ? "HIGH" : "LOW", resetActive ? "YES" : "NO");
      drawText(0, 22, line);
      snprintf(line, sizeof(line), "EDGES %lu", (unsigned long)resetEdges);
      drawText(0, 33, line);
      snprintf(line, sizeof(line), "%s CLICK FLIP", resetInvert ? "HIGH" : "LOW");
      drawText(0, 44, line);
      snprintf(line, sizeof(line), "MPR %s PADS %02u", mprReady ? "OK" : "ERR", unsigned(padCount));
      drawText(0, 55, line);
      break;
    case 1:
      drawText(0, 11, "CLOCK IN GP3");
      snprintf(line, sizeof(line), "RAW %s ACT %s", clockRawHigh ? "HIGH" : "LOW", clockActive ? "YES" : "NO");
      drawText(0, 22, line);
      snprintf(line, sizeof(line), "EDGES %lu", (unsigned long)clockEdges);
      drawText(0, 33, line);
      snprintf(line, sizeof(line), "%s CLICK FLIP", clockInvert ? "HIGH" : "LOW");
      drawText(0, 44, line);
      snprintf(line, sizeof(line), "MPR %s PADS %02u", mprReady ? "OK" : "ERR", unsigned(padCount));
      drawText(0, 55, line);
      break;
    case 2: {
      drawText(0, 11, "CV IN GP26 A0");
      snprintf(line, sizeof(line), "ADC %04u / 4095", unsigned(cvAdcRaw));
      drawText(0, 22, line);
      const uint16_t milliVolts = uint16_t(uint32_t(cvAdcRaw) * 3300u / 4095u);
      snprintf(line, sizeof(line), "ADC %u.%03uV", unsigned(milliVolts / 1000), unsigned(milliVolts % 1000));
      drawText(0, 33, line);
      drawText(0, 44, "VOLTAGE AT MCU PIN");
      snprintf(line, sizeof(line), "PADS %02u  MPR %s", unsigned(padCount), mprReady ? "OK" : "ERR");
      drawText(0, 55, line);
      break;
    }
    case 3: {
      drawText(0, 11, "NOTE CV OUT GP4");
      const uint16_t duty = cvDutyForNote(noteCvStep, 3);
      snprintf(line, sizeof(line), "NOTE %s PWM %04u", noteName(noteCvStep, 3), unsigned(duty));
      drawText(0, 22, line);
      snprintf(line, sizeof(line), "CV ~%u.%03uV", unsigned((3000u + (uint32_t(noteCvStep) * 1000u + 6u) / 12u) / 1000u), unsigned((3000u + (uint32_t(noteCvStep) * 1000u + 6u) / 12u) % 1000u));
      drawText(0, 33, line);
      drawText(0, 44, "1V/OCT ASSUMPTION");
      snprintf(line, sizeof(line), "PADS %02u  MPR %s", unsigned(padCount), mprReady ? "OK" : "ERR");
      drawText(0, 55, line);
      break;
    }
    case 4: {
      drawText(0, 11, "AUX CV OUT GP5");
      const uint16_t duty = cvDutyForNote(auxCvStep, 2);
      snprintf(line, sizeof(line), "AUX %s PWM %04u", noteName(auxCvStep, 2), unsigned(duty));
      drawText(0, 22, line);
      snprintf(line, sizeof(line), "CV ~%u.%03uV", unsigned((2000u + (uint32_t(auxCvStep) * 1000u + 6u) / 12u) / 1000u), unsigned((2000u + (uint32_t(auxCvStep) * 1000u + 6u) / 12u) % 1000u));
      drawText(0, 33, line);
      drawText(0, 44, "1V/OCT ASSUMPTION");
      snprintf(line, sizeof(line), "PADS %02u  MPR %s", unsigned(padCount), mprReady ? "OK" : "ERR");
      drawText(0, 55, line);
      break;
    }
    case 5:
      drawText(0, 11, "GATE OUT GP7");
      drawText(0, 22, gateHigh ? "STATE HIGH" : "STATE LOW");
      drawText(0, 33, "OCT+ TOGGLE GATE");
      drawText(0, 44, "OCT- FORCE LOW");
      snprintf(line, sizeof(line), "PADS %02u  MPR %s", unsigned(padCount), mprReady ? "OK" : "ERR");
      drawText(0, 55, line);
      break;
    case 6: {
      drawText(0, 11, gateHigh ? "GATE HIGH H/L" : "GATE LOW H/L");
      for (uint8_t i = 0; i < CANDIDATE_COUNT + 2; ++i) {
        char entry[12];
        uint8_t pin;
        uint16_t count;
        if (i == 0) { pin = CLOCK_IN; count = uint16_t(clockEdgeCount > 999 ? 999 : clockEdgeCount); }
        else if (i == 1) { pin = RESET_IN; count = uint16_t(resetEdgeCount > 999 ? 999 : resetEdgeCount); }
        else { pin = CANDIDATE_PINS[i - 2]; count = candidateEdgeCounts[i - 2]; }
        snprintf(entry, sizeof(entry), "GP%02u %c %03u", unsigned(pin), gpio_get(pin) ? 'H' : 'L', unsigned(count > 999 ? 999 : count));
        const uint8_t col = (i / 6) * 66;
        const uint8_t row = uint8_t(i % 6);
        drawText(col, 19 + row * 7, entry);
      }
      break;
    }
    default: {
      drawText(0, 11, "RGB ANIMATION GP2");
      snprintf(line, sizeof(line), "ANIM %u/%u", unsigned(rgbAnimation + 1), unsigned(RGB_ANIMATION_COUNT));
      drawText(0, 22, line);
      drawText(0, 33, RGB_ANIMATION_NAMES[rgbAnimation]);
      drawText(0, 44, "GRB 800K CONFIRMED");
      drawText(0, 55, rgbTestReady ? "OCT- PREV OCT+ NEXT" : "LED INIT ERROR");
      break;
    }
  }
  oledFlush();
}

static void jackInputIrq(uint gpio, uint32_t events) {
  (void)events;
  const bool rawHigh = gpio_get(gpio);
  if (gpio == RESET_IN) {
    if (rawHigh != resetLastRawHigh) { ++resetEdgeCount; resetLastRawHigh = rawHigh; }
  } else if (gpio == CLOCK_IN) {
    if (rawHigh != clockLastRawHigh) { ++clockEdgeCount; clockLastRawHigh = rawHigh; }
  } else {
    for (uint8_t i = 0; i < CANDIDATE_COUNT; ++i) {
      if (gpio == CANDIDATE_PINS[i]) {
        if (candidateEdgeCounts[i] < 1000) ++candidateEdgeCounts[i];
        break;
      }
    }
  }
}

static void updateControls(uint32_t now) {
  const uint8_t rawButtons = readButtons();
  if (rawButtons != buttonsCandidate) {
    buttonsCandidate = rawButtons;
    buttonsCandidateSince = now;
  } else if (rawButtons != buttonsStable && now - buttonsCandidateSince >= DEBOUNCE_MS) {
    const uint8_t previous = buttonsStable;
    buttonsStable = rawButtons;
    gpio_put(OCTAVE_DOWN_LED, (buttonsStable & BUTTON_DOWN_BIT) ? 1 : 0);
    gpio_put(OCTAVE_UP_LED, (buttonsStable & BUTTON_UP_BIT) ? 1 : 0);

    const bool downPressed = (buttonsStable & BUTTON_DOWN_BIT) && !(previous & BUTTON_DOWN_BIT);
    const bool upPressed = (buttonsStable & BUTTON_UP_BIT) && !(previous & BUTTON_UP_BIT);
    const bool clickPressed = (buttonsStable & 1) && !(previous & 1);
    if (clickPressed) {
      if (displayPage == 0) resetInvert = !resetInvert;
      else if (displayPage == 1) clockInvert = !clockInvert;
    }
    if ((displayPage == 5 || displayPage == 6) && upPressed) gateHigh = !gateHigh;
    if (displayPage == 7 && downPressed) {
      rgbAnimation = uint8_t((rgbAnimation + RGB_ANIMATION_COUNT - 1) % RGB_ANIMATION_COUNT);
      rgbFrame = 0;
      drawRgbTestPattern();
    }
    if (displayPage == 7 && upPressed) {
      rgbAnimation = uint8_t((rgbAnimation + 1) % RGB_ANIMATION_COUNT);
      rgbFrame = 0;
      drawRgbTestPattern();
    }
    if (displayPage == 3 || displayPage == 4) {
      uint8_t &level = (displayPage == 3) ? noteCvStep : auxCvStep;
      if (downPressed && level > 0) --level;
      if (upPressed && level < CV_NOTE_STEPS) ++level;
      updateCvOutputs();
    }
    if ((displayPage == 5 || displayPage == 6) && downPressed) gateHigh = false;
    updateGateOutput();
  }

  const uint8_t encoderNow = uint8_t((gpio_get(ENCODER_A) ? 2 : 0) | (gpio_get(ENCODER_B) ? 1 : 0));
  static const int8_t transition[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
  const int8_t step = transition[uint8_t((encoderPrevious << 2) | encoderNow)];
  if (step) encoderQuarterSteps += step;
  if (encoderNow == encoderDetentState && encoderQuarterSteps != 0) {
    if (encoderQuarterSteps >= 4 || encoderQuarterSteps <= -4) {
      const uint8_t previousPage = displayPage;
      displayPage = uint8_t((int(displayPage) + (encoderQuarterSteps > 0 ? 1 : PAGE_COUNT - 1)) % PAGE_COUNT);
      // Remove test voltage/gate when leaving that output's page.
      if (previousPage == 3) noteCvStep = 0;
      if (previousPage == 4) auxCvStep = 0;
      if (previousPage == 5 || previousPage == 6) gateHigh = false;
      if (previousPage == 7) stopRgbTest();
      updateCvOutputs();
      if (previousPage == 5 || previousPage == 6) updateGateOutput();
      if (displayPage == 7) startRgbTest();
      Serial.print("JACK TEST PAGE ");
      Serial.println(displayPage + 1);
    }
    encoderQuarterSteps = 0;
  }
  encoderPrevious = encoderNow;
}

void setup() {
  Serial.begin(115200);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 1000) delay(10);

  oledInit();
  drawTestPage();

  // Preserve the verified button, LED, encoder, and MPR121 connections.
  const uint8_t controlInputs[] = {ENCODER_CLICK, ENCODER_A, ENCODER_B,
                                   OCTAVE_DOWN_BUTTON, OCTAVE_UP_BUTTON};
  for (uint8_t pin : controlInputs) {
    gpio_set_function(pin, GPIO_FUNC_SIO);
    gpio_set_dir(pin, GPIO_IN);
    gpio_set_input_enabled(pin, true);
    gpio_set_pulls(pin, true, false);
  }
  gpio_init(OCTAVE_DOWN_LED);
  gpio_set_dir(OCTAVE_DOWN_LED, GPIO_OUT);
  gpio_put(OCTAVE_DOWN_LED, 0);
  gpio_init(OCTAVE_UP_LED);
  gpio_set_dir(OCTAVE_UP_LED, GPIO_OUT);
  gpio_put(OCTAVE_UP_LED, 0);

  // Jack inputs are read-only; rely on the board's conditioning circuit.
  const uint8_t jackInputPins[] = {RESET_IN, CLOCK_IN};
  for (uint8_t pin : jackInputPins) {
    gpio_set_function(pin, GPIO_FUNC_SIO);
    gpio_set_dir(pin, GPIO_IN);
    gpio_set_input_enabled(pin, true);
    gpio_disable_pulls(pin);
  }
  adc_init();
  adc_gpio_init(CV_IN);
  adc_select_input(0);
  adc_set_round_robin(0);

  // PWM CV outputs start at zero; gate output starts low.
  const uint slice = pwm_gpio_to_slice_num(NOTE_CV_OUT);
  pwm_config pwmConfig = pwm_get_default_config();
  pwm_config_set_wrap(&pwmConfig, PWM_TOP);
  pwm_config_set_clkdiv(&pwmConfig, 16.0f);
  pwm_init(slice, &pwmConfig, false);
  gpio_set_function(NOTE_CV_OUT, GPIO_FUNC_PWM);
  gpio_set_function(AUX_CV_OUT, GPIO_FUNC_PWM);
  pwm_set_gpio_level(NOTE_CV_OUT, 0);
  pwm_set_gpio_level(AUX_CV_OUT, 0);
  pwm_set_enabled(slice, true);
  gpio_init(GATE_OUT);
  gpio_set_dir(GATE_OUT, GPIO_OUT);
  gpio_put(GATE_OUT, 0);

  encoderPrevious = uint8_t((gpio_get(ENCODER_A) ? 2 : 0) | (gpio_get(ENCODER_B) ? 1 : 0));
  encoderDetentState = encoderPrevious;
  buttonsCandidate = readButtons();
  buttonsStable = buttonsCandidate;
  buttonsCandidateSince = millis();
  gpio_put(OCTAVE_DOWN_LED, (buttonsStable & BUTTON_DOWN_BIT) ? 1 : 0);
  gpio_put(OCTAVE_UP_LED, (buttonsStable & BUTTON_UP_BIT) ? 1 : 0);

  mprReady = mprBegin();
  resetLastRawHigh = gpio_get(RESET_IN);
  clockLastRawHigh = gpio_get(CLOCK_IN);
  gpio_set_irq_enabled_with_callback(RESET_IN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &jackInputIrq);
  gpio_set_irq_enabled(CLOCK_IN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
  for (uint8_t i = 0; i < CANDIDATE_COUNT; ++i) {
    gpio_set_function(CANDIDATE_PINS[i], GPIO_FUNC_SIO);
    gpio_set_dir(CANDIDATE_PINS[i], GPIO_IN);
    gpio_set_input_enabled(CANDIDATE_PINS[i], true);
    gpio_disable_pulls(CANDIDATE_PINS[i]);
    gpio_set_irq_enabled(CANDIDATE_PINS[i], GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
  }
  Serial.println("T12 jack I/O test; outputs start at zero/low");
  Serial.println("Rotate encoder: page; click: invert Reset/Clock logic");
  Serial.println("CV pages: chromatic C3-C4 and C2-C3, 1V/oct assumed; meter to verify.");
  Serial.println("Page 7 scans inputs. Page 8 runs RGB animations on confirmed GP2 GRB 800k; Oct-/+ selects animation.");
  Serial.println(mprReady ? "MPR121 OK on GP0/GP1" : "MPR121 not responding on GP0/GP1");
  lastTouchPoll = millis();
  lastDisplayRefresh = millis();
  lastAdcRead = millis();
  drawTestPage();
}

void loop() {
  const uint32_t now = millis();
  updateControls(now);
  updateRgbAnimation(now);

  if (now - lastAdcRead >= 20) {
    lastAdcRead = now;
    adc_select_input(0);
    cvAdcRaw = adc_read();
  }

  if (now - lastTouchPoll >= TOUCH_POLL_MS) {
    lastTouchPoll = now;
    if (!mprReady) mprReady = mprBegin();
    if (mprReady) {
      uint16_t newElectrodeMask = 0;
      if (mprReadTouchStatus(newElectrodeMask)) {
        electrodeMask = newElectrodeMask;
        uint16_t newKeyMask = 0;
        for (uint8_t key = 0; key < 12; ++key) {
          if (electrodeMask & (1u << MPR_KEY_ELECTRODE[key])) newKeyMask |= uint16_t(1u << key);
        }
        if (newKeyMask != keyMask) {
          reportChangedKeys(keyMask, newKeyMask);
          keyMask = newKeyMask;
        }
      } else {
        mprReady = false;
      }
    }
  }

  if (now - lastDisplayRefresh >= DISPLAY_REFRESH_MS) {
    lastDisplayRefresh = now;
    drawTestPage();
  }
  delay(1);
}
