#line 1 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v08_screen_button_rgb_test/T12_Screen_Button_RGB_Test/T12_Screen_Button_RGB_Test.ino"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
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

// Confirmed user pin observations; the OLED implementation below is copied
// unchanged from v05, which is known to display correctly on this module.
static constexpr uint8_t ENCODER_CLICK = 10;
static constexpr uint8_t ENCODER_A = 11;
static constexpr uint8_t ENCODER_B = 12;
static constexpr uint8_t OCTAVE_UP_LED = 21;
static constexpr uint8_t OCTAVE_DOWN_LED = 22;
static constexpr uint8_t OCTAVE_DOWN_BUTTON = 27; // ADC1
static constexpr uint8_t OCTAVE_UP_BUTTON = 28;   // ADC2
static constexpr uint8_t RGB_LED_COUNT = 12;
static constexpr uint8_t RGB_CANDIDATES[] = {4, 5, 7, 8, 9, 13, 14, 15, 23, 24, 25};
static constexpr size_t RGB_CANDIDATE_COUNT = sizeof(RGB_CANDIDATES) / sizeof(RGB_CANDIDATES[0]);
static constexpr uint32_t DEBOUNCE_MS = 20;
static constexpr uint32_t DISPLAY_REFRESH_MS = 100;
static constexpr uint32_t RGB_DWELL_MS = 1500;

static Adafruit_NeoPixel pixels(RGB_LED_COUNT, RGB_CANDIDATES[0], NEO_GRB + NEO_KHZ800);
static uint8_t framebuffer[128 * 64 / 8];
static uint32_t lastDisplayRefresh = 0;
static uint32_t lastRgbTest = 0;
static size_t displayPage = 0; // 0=controls, 1=RGB pin test
static size_t rgbCandidate = 0;
static uint8_t lastRgbPin = 255;
static bool rgbScanEnabled = false;
static bool pixelPioOk = true;
static uint8_t buttonsStable = 0;
static uint8_t buttonsCandidate = 0;
static uint32_t buttonsCandidateSince = 0;
static uint32_t encoderClickCount = 0;
static int8_t encoderQuarterSteps = 0;
static uint8_t encoderPrevious = 0;
static uint8_t encoderDetentState = 0;

static void drawDiagnostic();
static void reportInitial();
static void updateButtons(uint32_t now);
static void showRainbowOnCandidate();
static uint8_t readButtons();

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
#line 198 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v08_screen_button_rgb_test/T12_Screen_Button_RGB_Test/T12_Screen_Button_RGB_Test.ino"
static void setOctaveIndicators(uint8_t state);
#line 68 "/Users/vincenthenon/Desktop/T12_alternative_firmware/firmware_versions/v08_screen_button_rgb_test/T12_Screen_Button_RGB_Test/T12_Screen_Button_RGB_Test.ino"
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

static uint8_t readButtons() {
  // Board buttons are treated as active-low; weak pull-ups keep them stable.
  return uint8_t((gpio_get(ENCODER_CLICK) ? 0 : 1) |
                 (gpio_get(OCTAVE_DOWN_BUTTON) ? 0 : 2) |
                 (gpio_get(OCTAVE_UP_BUTTON) ? 0 : 4));
}

static void setOctaveIndicators(uint8_t state) {
  // The current LED driver assumption is active-high; reverse here if the
  // display reports UP while the corresponding physical LED remains on.
  gpio_put(OCTAVE_DOWN_LED, (state & 2) != 0);
  gpio_put(OCTAVE_UP_LED, (state & 4) != 0);
}

static void drawDiagnostic() {
  memset(framebuffer, 0, sizeof(framebuffer));
  if (displayPage == 0) {
    drawText(0, 0, "T12 CTRL TEST");
    drawText(98, 0, "1/2");
    drawText(0, 11, "TURN: CHANGE PAGE");
    char line[24];
    snprintf(line, sizeof(line), "ENC CLICK: %s", (buttonsStable & 1) ? "DOWN" : "UP");
    drawText(0, 22, line);
    snprintf(line, sizeof(line), "CLICK COUNT: %lu", (unsigned long)encoderClickCount);
    drawText(0, 32, line);
    snprintf(line, sizeof(line), "OCT- %s LED %s", (buttonsStable & 2) ? "DOWN" : "UP",
             (buttonsStable & 2) ? "ON" : "OFF");
    drawText(0, 42, line);
    snprintf(line, sizeof(line), "OCT+ %s LED %s", (buttonsStable & 4) ? "DOWN" : "UP",
             (buttonsStable & 4) ? "ON" : "OFF");
    drawText(0, 52, line);
  } else {
    drawText(0, 0, "T12 RGB GPIO TEST");
    drawText(98, 0, "2/2");
    drawText(0, 11, "CLICK: START / STOP");
    drawText(0, 22, rgbScanEnabled ? "SCAN: RUNNING" : "SCAN: STOPPED");
    char line[24];
    snprintf(line, sizeof(line), "LAST GPIO: %u", lastRgbPin == 255 ? 0 : lastRgbPin);
    drawText(0, 33, line);
    if (!pixelPioOk) drawText(0, 44, "NEOPIXEL PIO ERROR");
    else drawText(0, 44, "12 LEDS: RAINBOW");
    drawText(0, 55, "TURN: CHANGE PAGE");
  }
  oledFlush();
}

static void reportInitial() {
  Serial.println("T12 V08 screen, buttons, RGB test");
  Serial.println("OLED pin mapping and init reused from hardware-confirmed v05.");
  Serial.println("Buttons GP10/11/12 and GP27/28 have internal pull-ups.");
  Serial.println("RGB test candidates: GP4,5,7,8,9,13,14,15,23,24,25.");
  Serial.println("Candidate GPIO is driven only during the RGB scan; unplug patch leads.");
}

static void updateButtons(uint32_t now) {
  const uint8_t raw = readButtons();
  if (raw != buttonsCandidate) {
    buttonsCandidate = raw;
    buttonsCandidateSince = now;
    return;
  }
  if (buttonsStable == buttonsCandidate || now - buttonsCandidateSince < DEBOUNCE_MS) return;

  const uint8_t oldState = buttonsStable;
  buttonsStable = buttonsCandidate;
  setOctaveIndicators(buttonsStable);
  if ((buttonsStable & 1) && !(oldState & 1)) {
    ++encoderClickCount;
    if (displayPage == 1) {
      rgbScanEnabled = !rgbScanEnabled;
      lastRgbTest = 0;
      Serial.println(rgbScanEnabled ? "RGB SCAN START" : "RGB SCAN STOP");
    }
  }
}

static void showRainbowOnCandidate() {
  const uint8_t pin = RGB_CANDIDATES[rgbCandidate];
  Serial.print("RAINBOW GPIO");
  Serial.println(pin);
  pixels.setPin(pin);
  if (!pixels.begin()) {
    pixelPioOk = false;
    rgbScanEnabled = false;
    Serial.println("NeoPixel PIO claim failed");
    gpio_set_function(pin, GPIO_FUNC_SIO);
    gpio_set_dir(pin, GPIO_IN);
    gpio_set_pulls(pin, false, false);
    return;
  }
  pixels.setBrightness(48);
  for (uint8_t i = 0; i < RGB_LED_COUNT; ++i) {
    const uint16_t hue = uint16_t(i) * 65535u / RGB_LED_COUNT;
    pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(hue)));
  }
  pixels.show();
  lastRgbPin = pin;
  delay(1000);
  pixels.clear();
  pixels.show();
  gpio_set_function(pin, GPIO_FUNC_SIO);
  gpio_set_dir(pin, GPIO_IN);
  gpio_set_pulls(pin, false, false);
}

void setup() {
  Serial.begin(115200);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 1000) delay(10);

  oledInit();
  // Active-high indicator LEDs, initialized off.
  gpio_init(OCTAVE_UP_LED);
  gpio_set_dir(OCTAVE_UP_LED, GPIO_OUT);
  gpio_put(OCTAVE_UP_LED, 0);
  gpio_init(OCTAVE_DOWN_LED);
  gpio_set_dir(OCTAVE_DOWN_LED, GPIO_OUT);
  gpio_put(OCTAVE_DOWN_LED, 0);

  const uint8_t inputs[] = {ENCODER_CLICK, ENCODER_A, ENCODER_B,
                            OCTAVE_DOWN_BUTTON, OCTAVE_UP_BUTTON};
  for (uint8_t pin : inputs) {
    gpio_set_function(pin, GPIO_FUNC_SIO);
    gpio_set_dir(pin, GPIO_IN);
    gpio_set_input_enabled(pin, true);
    gpio_set_pulls(pin, true, false);
  }

  encoderPrevious = uint8_t((gpio_get(ENCODER_A) ? 2 : 0) | (gpio_get(ENCODER_B) ? 1 : 0));
  encoderDetentState = encoderPrevious;
  buttonsCandidate = readButtons();
  buttonsStable = buttonsCandidate;
  buttonsCandidateSince = millis();
  setOctaveIndicators(buttonsStable);
  reportInitial();
  drawDiagnostic();
  lastDisplayRefresh = millis();
}

void loop() {
  const uint32_t now = millis();
  updateButtons(now);

  const uint8_t encoderNow = uint8_t((gpio_get(ENCODER_A) ? 2 : 0) | (gpio_get(ENCODER_B) ? 1 : 0));
  static const int8_t transition[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
  const int8_t step = transition[uint8_t((encoderPrevious << 2) | encoderNow)];
  if (step) encoderQuarterSteps += step;
  if (encoderNow == encoderDetentState && encoderQuarterSteps != 0) {
    if (encoderQuarterSteps >= 4 || encoderQuarterSteps <= -4) {
      displayPage = 1 - displayPage;
      Serial.print("DISPLAY PAGE ");
      Serial.println(displayPage + 1);
    }
    encoderQuarterSteps = 0;
  }
  encoderPrevious = encoderNow;

  const uint32_t afterInput = millis();
  if (displayPage == 1 && rgbScanEnabled && afterInput - lastRgbTest >= RGB_DWELL_MS) {
    showRainbowOnCandidate();
    rgbCandidate = (rgbCandidate + 1) % RGB_CANDIDATE_COUNT;
    lastRgbTest = millis();
  }

  if (millis() - lastDisplayRefresh >= DISPLAY_REFRESH_MS) {
    drawDiagnostic();
    lastDisplayRefresh = millis();
  }
  delay(1);
}

