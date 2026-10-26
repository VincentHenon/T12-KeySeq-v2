/***** stable version v1_no record screen_no save-load (CLEAN, serial-free)
 * Encoder:
 *  - IDLE, long press  -> SETTINGS menu (General, Clock)
 *  - Any mode, single click -> MODE menu (Performance/Keys Edit/Record/Seq Edit)
 *  - EDITSEQ, double click -> PARAMETERS menu (TIME, RETRIG, GLIDE, VIBRATO)
 * Menus: turn to select, click to confirm; Return item in every list.
 * TIME per-step: -1 (half), 0 (rest, 1 clock), 1..8 clocks
 * RETRIG per-step: retrigger every clock while step spans multiple clocks
 * GLIDE/VIBRATO per-step: on/off
 *****************************************************************************/

// --- Forward declarations needed for Arduino preprocessor ---
struct BlobHeader;             // (not used; kept for forward-compat comments)
struct GlobalSettings;         // (not used: no save/load in this build)
struct SequenceBlob;           // (not used: no save/load in this build)

#include <Wire.h>
#include <EEncoder.h>
#include <U8g2lib.h>
#include <math.h>
#include <EEPROM.h>
#include <string.h>

/*** Pins *********************************************************************/
const int MPR_SDA = 0, MPR_SCL = 1;
const uint8_t MPR_ADDR = 0x5A;

const int ENC_CLK = 11;
const int ENC_DT  = 12;
const int ENC_SW  = 10;

const uint CLOCK_PIN = 3;
const uint8_t OCT_DOWN_PIN = 27; // ADC1, active-low
const uint8_t OCT_UP_PIN   = 28; // ADC2, active-low
const uint8_t OCT_DOWN_LED = 22;
const uint8_t OCT_UP_LED   = 21;

const int GATE_PIN = 7;
const int PITCH_CV_PIN = 4;
const int AUX_CV_PIN = 5;

const int OLED_CS_PIN = 17, OLED_DC_PIN = 16;
const int OLED_SCK_PIN = 18, OLED_MOSI_PIN = 19, OLED_RST_PIN = 20;

// ---------- Save/Load layout ----------
#define NUM_SLOTS      8
#define EEPROM_BYTES   4096

// ---- Sequence capacity must be defined before any use ----
#define SEQ_MAX 32

// ---- What we store per slot in EEPROM ----
// v1 (no name)
struct SequenceBlob {
  uint8_t  seqLen;
  uint8_t  seqKeys[SEQ_MAX];
  uint8_t  seqActive[SEQ_MAX];
  int8_t   seqTime[SEQ_MAX];
  uint8_t  seqRetrig[SEQ_MAX];
  uint8_t  seqVibrato[SEQ_MAX];
  uint8_t  seqGlide[SEQ_MAX];
  int8_t   seqOctaveOffset;
  uint8_t  tabNote[12];
  uint8_t  glideShape;
  float    vibRateHz;
  float    vibDepthCents;
  uint8_t  reserved[4];
};

// v2 (adds name[16])
struct SequenceBlob_v2 {
  uint8_t  seqLen;
  uint8_t  seqKeys[SEQ_MAX];
  uint8_t  seqActive[SEQ_MAX];
  int8_t   seqTime[SEQ_MAX];
  uint8_t  seqRetrig[SEQ_MAX];
  uint8_t  seqVibrato[SEQ_MAX];
  uint8_t  seqGlide[SEQ_MAX];
  int8_t   seqOctaveOffset;
  uint8_t  tabNote[12];
  uint8_t  glideShape;
  float    vibRateHz;
  float    vibDepthCents;
  char     name[16];            // NEW
};

struct BlobHeader {
  uint32_t magic;   // 'KSQ1'
  uint16_t version; // 0x0002
  uint16_t length;  // payload size (bytes)
  uint16_t crc;     // CRC16-CCITT of payload
  uint16_t flags;   // bit0=valid (1=has data)
};

static const uint32_t KSQ_MAGIC = 0x4B535131; // 'K''S''Q''1'
static const uint16_t KSQ_VERS  = 0x0003;

// ===== Name editor state =====
static const char NAME_CHARS[] =
  " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.";
static const uint8_t NAME_CHARS_COUNT = sizeof(NAME_CHARS) - 1; // no null

static const char* kNameSet = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";

bool     nameEditActive = false;
uint8_t  nameCursor     = 0;      // 0..15
char     nameBuf[16+1] = {0};             // 16 chars + NUL
uint8_t  nameMaxChars   = 16;     // visual length / max editable
uint8_t  pendingSlotIdx = 0;      // which slot we’re naming

struct GlobalSettings {
  float   V0_meas;
  float   Vfs_meas;
  uint8_t clockDiv;        // 1,2,4,8,16...
  uint8_t ledBrightness;   // 0..255
  uint8_t reserved[22];    // keep space for future fields (align to nice size)
};


// EEPROM addresses
static const int GLOBAL_HDR_ADDR   = 0;
static const int GLOBAL_PAY_ADDR   = GLOBAL_HDR_ADDR + (int)sizeof(BlobHeader);
static const int GLOBAL_PAY_SIZE   = (int)sizeof(GlobalSettings);

static const int SLOT_AREA_SIZE    = (int)sizeof(BlobHeader) + (int)sizeof(SequenceBlob);
static const int SLOTS_BASE_ADDR   = GLOBAL_PAY_ADDR + GLOBAL_PAY_SIZE;
static const int EEPROM_TOTAL_NEED = SLOTS_BASE_ADDR + NUM_SLOTS * SLOT_AREA_SIZE;

// ---- small helpers ----
static inline uint16_t crc16_ccitt(const uint8_t* data, size_t len) {
  uint16_t crc = 0xFFFF;
  while (len--) {
    crc ^= (uint16_t)*data++ << 8;
    for (uint8_t i = 0; i < 8; i++) {
      if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
      else              crc <<= 1;
    }
  }
  return crc;
}
static inline void eepromBeginIfNeeded() {
#if defined(ESP8266) || defined(ESP32) || defined(ARDUINO_ARCH_RP2040)
  EEPROM.begin(EEPROM_BYTES);
#endif
}
static inline void eepromCommitIfNeeded() {
#if defined(ESP8266) || defined(ESP32) || defined(ARDUINO_ARCH_RP2040)
  EEPROM.commit();
#endif
}
static inline int slotHeaderAddr(int idx) { return SLOTS_BASE_ADDR + idx * SLOT_AREA_SIZE; }
static inline int slotPayloadAddr(int idx){ return slotHeaderAddr(idx) + (int)sizeof(BlobHeader); }



/*** Gate / trigger ****************************/
const uint32_t TRIG_US = 5000;        // 5 ms legacy trigger

/*** Preview gate timing (for key/step preview) *******************************/
const uint32_t PREVIEW_FALLBACK_US = 120000; // 120 ms when no clock yet
const uint32_t PREVIEW_MIN_US      = 10000;  // clamp 10 ms
const uint32_t PREVIEW_MAX_US      = 500000; // clamp 500 ms

/*** Peripherals **************************************************************/
EEncoder encoder(ENC_CLK, ENC_DT, ENC_SW, 4); // rotation only
const bool REVERSE_ORDER = false;             // flip if keypad is mirrored

// OLED on I2C0 (Wire)
U8G2_SSD1306_128X64_NONAME_F_4W_HW_SPI u8g2(U8G2_R0, OLED_CS_PIN, OLED_DC_PIN, OLED_RST_PIN);

// The T12 OLED has a two-column horizontal wrap: physical columns 126 and
// 127 are the first two visible columns.  Keep the logical U8g2 framebuffer
// unchanged and rotate only the copy sent to the display.
static void sendOledBufferShifted() {
  uint8_t *buf = u8g2.getBufferPtr();
  uint8_t logical[1024];
  memcpy(logical, buf, sizeof(logical));
  for (uint8_t page = 0; page < 8; ++page) {
    uint8_t *dst = buf + page * 128;
    const uint8_t *src = logical + page * 128;
    // U8g2's physical column order on this panel is shifted right by two:
    // place logical columns 0 and 1 at the end of the transmitted row so
    // they appear at the left edge of the glass.
    memcpy(dst, src + 2, 126);
    dst[126] = src[0];
    dst[127] = src[1];
  }
  u8g2.sendBuffer();
  memcpy(buf, logical, sizeof(logical));
}

// UI throttle & dirty flag
uint32_t lastUiMs = 0;
const uint32_t UI_INTERVAL_MS = 50;    // ~20 FPS
volatile bool uiDirty = true;
inline void markUI() { uiDirty = true; }
inline void transposeOctave(int delta);
inline void editKeyTransposeOctave(int deltaOct);

static bool octDownPrev = true, octUpPrev = true;
static uint32_t lastOctButtonMs = 0;

static void serviceOctaveButtons();

// dynamic Y position for content after a header
int16_t g_contentStartY = 12;

/*** Overlay / selection state ************************************************/
// Parameter overlay (visual selection indices include "Return" at end)
int timeSelVis    = 1;  // 0=Return, 1..11 maps to (-1,0,1..9) -> we clamp to 8
int toggleSelVis  = 1;  // 0=Return, 1=OFF, 2=ON

// --- KEY EDIT UI state ---
uint8_t  lastTouchedKey = 1;                 // highlight last pressed/released
bool     keyNoteOverlayActive = false;       // show "note screen" while turning
uint32_t keyNoteOverlayUntilMs = 0;
const uint32_t KEY_NOTE_OVERLAY_TIMEOUT_MS = 500;

// ===== Blocking modal (OK button) =====
bool     modalActive = false;
char     modalMsg[48];

// ===== Modal kinds =====
enum ModalKind { MODAL_NONE, MODAL_OK, MODAL_CONFIRM_CALIB };
static ModalKind modalKind = MODAL_NONE;
static int8_t    modalChoiceIndex = 0; // for 2-button modals (0=left,1=right)

/*** Modes ********************************************************************/
enum Mode { IDLE, EDITKEY, RECSEQ, EDITSEQ, SETTINGS };
Mode currentMode = IDLE;

static void serviceOctaveButtons() {
  bool down = digitalRead(OCT_DOWN_PIN);
  bool up   = digitalRead(OCT_UP_PIN);
  if (millis() - lastOctButtonMs < 35) return;
  if (octDownPrev && !down) {
    if (currentMode == EDITKEY) editKeyTransposeOctave(-1); else transposeOctave(-1);
    digitalWrite(OCT_DOWN_LED, HIGH); digitalWrite(OCT_UP_LED, LOW);
    lastOctButtonMs = millis();
  } else if (octUpPrev && !up) {
    if (currentMode == EDITKEY) editKeyTransposeOctave(+1); else transposeOctave(+1);
    digitalWrite(OCT_UP_LED, HIGH); digitalWrite(OCT_DOWN_LED, LOW);
    lastOctButtonMs = millis();
  }
  octDownPrev = down; octUpPrev = up;
}

/*** Clock (simple) ***********************************************************/
volatile uint32_t clockTicks = 0;      // incremented in ISR
uint8_t playhead = 0;                  // 0..seqLen-1

// Period tracker (for preview + gate timing)
volatile uint32_t lastClockEdgeUs = 0;
volatile uint32_t prevClockEdgeUs = 0;
uint32_t          lastGoodPeriodUs = 500000;    // ~120 BPM default (0.5 s)
const uint32_t    PERIOD_MIN_US    = 2000;      // 500 Hz max
const uint32_t    PERIOD_MAX_US    = 2000000UL; // 0.5 Hz min

/*** Gate/trigger *************************************************************/
bool gateSustain = false;
bool trigActive  = false;
uint32_t trigOffAt = 0;

/*** Notes & calibration ******************************************************/
// Factory key assignment: chromatic notes centered around octave 2.
int tabNote[12]       = {24, 27, 31, 34, 36, 39, 43, 46, 48, 51, 55, 58};
int savedNotes[12]    = {0, 12, 7, 15, 24, 2, 3, 7, 8, 9, 10, 95}; // (unused mapping kept as example)
const char *tableNoteName[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

// ----- Runtime copies (used everywhere in the app) -----
float   V0_meas       = 0.022f;  // post-amp voltage at DAC=0
float   Vfs_meas      = 7.840f;   // post-amp voltage at DAC=4095
  uint8_t g_clockDiv    = 2;       // 2 incoming clocks per step by default
uint8_t g_ledBrightness = 255;   // 0..255

// --- Calibration reference output control ---
static bool calibRefActive = false;

// --- Calibration editor state (millivolts to avoid float editing) ---
int  calib_v0_mV   = 0;      // working copy (edits)
int  calib_vfs_mV  = 8000;   // working copy (edits)
uint8_t calibField = 0;      // 0 = V0, 1 = VFS
uint8_t calibPos   = 0;      // digit place: 0=1V, 1=0.1V, 2=0.01V, 3=0.001V


/*** Keypad debounce **********************************************************/
const uint32_t PRESS_MS   = 4;
const uint32_t RELEASE_MS = 8;
const uint32_t LOCK_MS    = 5;

uint8_t  stableKey        = 0;
uint8_t  pressCand        = 0;
uint32_t pressSinceMs     = 0;
uint32_t lastNonZeroMs    = 0;
uint32_t holdLockUntilMs  = 0;

// NO-RETRIGGER lock until true release:
uint8_t  lastPressedKey   = 0;

/*** App state ****************************************************************/
uint8_t  currentKey    = 0;  // last pressed key 1..12
int      currentOctave = 4;

/*** Encoder button (manual) **************************************************/
uint8_t  clickCounter = 0;
uint32_t lastButtonPress = 0;
const uint32_t DOUBLE_CLICK_INTERVAL = 300;  // ms
const uint32_t LONG_PRESS_MS = 800;          // ms
uint32_t buttonPressStart = 0;
bool buttonHeld = false;

/*** Sequencer ****************************************************************/
volatile uint8_t edgeDivCount = 0;
uint8_t  seqKeys[SEQ_MAX];    // 1..12
uint8_t  seqLen = 0;          // 0..32
uint8_t  writeIdx = 0;        // circular in RECSEQ
uint8_t  editStep = 0;        // index in EDITSEQ

// Per-step parameters
bool     seqActive[SEQ_MAX];
int8_t   seqTime[SEQ_MAX];    // -1,0..8 : half, rest(1clk), 1..8 clocks (default 1)
bool     seqRetrig[SEQ_MAX];
bool     seqVibrato[SEQ_MAX];
bool     seqGlide[SEQ_MAX];

bool   seqPlaying       = false; // Start/Pause still available (unused here)
int8_t seqOctaveOffset  = 0;     // global octave offset (−7..+7)

// Only apply transpose in IDLE mode
static inline int8_t effectiveOctaveOffset() {
  return (currentMode == IDLE) ? seqOctaveOffset : 0;
}

/*** Live key override while playing ******************************************/
bool     keyOverride  = false;  // true while a note key is held in IDLE playing
uint8_t  overrideKey  = 0;      // 1..12

/*** Vibrato engine ***********************************************************/
float vibRateHz        = 8.0f;     // LFO rate
float vibDepthCents    = 30.0f;    // +/- cents peak
float vibPhase         = 0.0f;     // radians
uint32_t vibLastMicros = 0;
const uint32_t VIB_UPDATE_US = 1000; // ~1 kHz updates
bool   vibEnabledNow   = false;

float  currentNoteBase  = 0.0f;   // base semitone of current sounding note

/*** Glide runtime ************************************************************/
const float     GLIDE_FRACTION   = 0.50f;
const uint32_t  MIN_GLIDE_US     = 10000;     // 10 ms minimum
const uint32_t  MAX_GLIDE_US     = 500000;    // 500 ms maximum

bool      glideActiveNow  = false;
float     glideStartNote  = 0.0f;
float     glideTargetNote = 0.0f;
uint32_t  glideStartUs    = 0;
uint32_t  glideDurUs      = 0;

// Glide curve
enum GlideShape { GLIDE_SMOOTHSTEP, GLIDE_LINEAR, GLIDE_EXPO };
GlideShape glideShape = GLIDE_EXPO;
const float GLIDE_EXPO_K = 4.0f;

/*** Half-step scheduler (for TIME=-1) ****************************************/
bool     subStepActive = false;
uint32_t subStepDueUs  = 0;
uint8_t  subStepIndex  = 0;

/*** Multi-clock holding ******************************************************/
uint8_t ticksLeftForStep = 0; // additional real-clock ticks to hold (after first)
bool    retrigHold       = false;

/*** SETTINGS MENU STATE (no Save/Load in this build) *************************/
enum SettingsState { S_NONE, S_MENU, S_GENERAL, S_CLOCK, S_CALIB, S_SAVELOAD, S_SLOT_ACTION, S_NAMEEDIT };
SettingsState settingsState = S_NONE;
int settingsIndex = 0;         // index within S_MENU
int saveLoadSlotIndex = 0;     // 0..NUM_SLOTS-1, NUM_SLOTS = RETURN
int slotActionIndex   = 0;     // 0:Save 1:Load 2:Clear, 3=RETURN
// Name editor working buffer (editable before saving)
char     nameEditBuf[16] = {0};
uint8_t  nameEditPos     = 0;    // 0..15 cursor within name
static const char* kSettingsItems[] = {
  "General",
  "Clock",
  "Calibration",
  "Save/Load",
};
#define SETTINGS_MENU_COUNT (int)(sizeof(kSettingsItems)/sizeof(kSettingsItems[0]))



/*** PARAMETERS MENU (EDITSEQ) ************************************************/
enum ParamState { P_NONE, P_MENU, P_TIME, P_RETRIG, P_GLIDE, P_VIBRATO };
ParamState paramState = P_NONE;
int paramIndex = 0;            // 0..4 (4 is RETURN)
int timeSelIndex = 0;          // 0..10 (10 is RETURN)
int boolSelIndex = 0;          // 0..2 (2 is RETURN)

/*** MODES MENU ***************************************************************/
enum ModesState { M_NONE, M_MENU };
ModesState modesState = M_NONE;
int modeMenuIndex = 0;       // 0: PERFORMANCE, 1: KEYS EDIT, 2: RECORD SEQ, 3: SEQ EDIT
Mode modeBeforeMenu = IDLE;

/*** Forward declarations *****************************************************/
void onPress(uint8_t k);
void onRelease(uint8_t k);
void onEncoderTurn(EEncoder& enc);
void onEncoderSingleClick();
void onEncoderDoubleClick();
void onEncoderLongPress();
void checkEncoderClick();

void handle_CV(float noteIndex, bool doTrigger = true);
uint8_t Read_Keypad();
void    scanKeys();

void clockISR();
void handleClock();
void playSequence();
void playOneStep(uint8_t i, uint32_t gatePeriodUs, uint32_t glideBasePeriodUs, const char* context);

inline void gateTrigger();
inline void gateStartHalfPeriod(uint32_t periodUs);
inline void gateHoldOn();
inline void gateHoldOff();
inline void processGatePulse();
inline void previewGate();

inline void updatePitchMods();

inline void togglePlay();
inline void manualReset();
inline void transposeOctave(int delta);
inline void editKeyTransposeOctave(int deltaOct);

void onEncoderChangeEditSeq(int8_t delta);
void previewStep(uint8_t stepIndex);

void drawScreen();
void drawListHeader(const char* title);
void drawListWithReturn(const char* title, const char* const* items, int itemsCount, int selectedIndex, bool showReturn);
void drawSettings();
void drawGeneral();
void drawClockPage();
void drawParamMenu();
void drawParamTime();
void drawParamToggle(const char* title, int selected);
void drawModesMenu();
void drawEditSeqScreen();
void drawEditKeyScreen();
void drawRecSeqScreen();
inline void transposeOctave(int delta);
inline void editKeyTransposeOctave(int deltaOct);
static inline void serviceKeyOverlayTimeout();
void scanBus(TwoWire &bus, const char* name);
static inline void drawRightAligned(int y, const char* s, int rightMargin = 2);
static inline void noteNameFromSemi(int semi, char* out, size_t outsz);
static inline bool keyOverlayActiveNow();
static void noteNameForKey(uint8_t key, char* out, size_t outsz);
static void drawStepCircleCell(int cx, int cy, uint8_t r, bool isSelected, bool isPlayhead, bool isRest);
static void drawNameEditor();
static bool readSlotName(uint8_t slot, char* out, size_t outsz);
static void prepareDefaultNameForSlot(uint8_t slot, char* out, size_t outsz);
static char  nextCharInSet(char c, int dir);
static void  trimTrailingSpaces(char* s);
static bool  saveSlotWithName(uint8_t slotIdx0, const char* nm);
static bool  loadSlot(uint8_t slotIdx0);
static void  fillSequenceBlobV2FromRAM(SequenceBlob_v2 &b);
static void  autosaveSequenceIfChanged();


/*** Setup (core 0) ***********************************************************/
void setup() {
  // I2C0 for the MPR121 touch controller.
  Wire.setSCL(MPR_SCL);
  Wire.setSDA(MPR_SDA);
  Wire.begin();
  Wire.setClock(400000);
  // MPR121 baseline/filters: 12 electrodes enabled.
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x5E); Wire.write(0x00); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x2B); Wire.write(0x01); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x2C); Wire.write(0x01); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x2D); Wire.write(0x00); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x2E); Wire.write(0x00); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x5B); Wire.write(0x10); Wire.endTransmission();
  // Keep the confirmed charge/current configuration, but use the minimum
  // electrode sample interval (ESI=1 ms) to reduce touch latency.
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x5C); Wire.write(0x20); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x5D); Wire.write(0x00); Wire.endTransmission();
  Wire.beginTransmission(MPR_ADDR); Wire.write(0x5E); Wire.write(0x0C); Wire.endTransmission();

  analogWriteRange(4095);
  analogWriteFreq(48828);

  // Clock input
  pinMode(CLOCK_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(CLOCK_PIN), clockISR, FALLING);

  // Encoder (rotation only)
  encoder.setEncoderHandler(onEncoderTurn);
  encoder.setAcceleration(false);
  pinMode(ENC_SW, INPUT_PULLUP);
  pinMode(OCT_DOWN_PIN, INPUT_PULLUP);
  pinMode(OCT_UP_PIN, INPUT_PULLUP);
  pinMode(OCT_DOWN_LED, OUTPUT);
  pinMode(OCT_UP_LED, OUTPUT);
  digitalWrite(OCT_DOWN_LED, LOW);
  digitalWrite(OCT_UP_LED, LOW);

  // Gate/trigger pin
  pinMode(GATE_PIN, OUTPUT);
  digitalWrite(GATE_PIN, LOW);

  // EEPROM
  eepromBeginIfNeeded();

  /*if (!loadGlobals()) {
    setDefaultGlobals();
    saveGlobals();         // make sure something valid is stored
  }
  applyGlobalsToHardware();*/

  handle_CV(0.0f, false);

  lastTouchedKey = 1;
  currentKey     = 1;
  markUI();

  // Init sequence params
  for (uint8_t i = 0; i < SEQ_MAX; ++i) {
    seqActive[i]  = true;
    seqTime[i]    = 1;
    seqRetrig[i]  = false;
    seqVibrato[i] = false;
    seqGlide[i]   = false;
  }

  // Slot 0 is the automatic working-sequence backup.
  loadSlot(0);

  vibLastMicros = micros();
}

/*** loop (core 0) ************************************************************/
void loop() {
  processGatePulse();
  handleClock();

  // Service scheduled half-step if due (for TIME=-1)
  if (subStepActive && (int32_t)(micros() - subStepDueUs) >= 0) {
    const uint32_t fullPeriod = (lastGoodPeriodUs > 0) ? lastGoodPeriodUs : PREVIEW_FALLBACK_US;
    const uint32_t halfPeriod = fullPeriod >> 1;
    playOneStep(subStepIndex, halfPeriod, fullPeriod, "[HALF]");
    subStepActive = false;
    uiDirty = true;
  }

  updatePitchMods();
  scanKeys();
  serviceOctaveButtons();
  serviceKeyOverlayTimeout();
  encoder.update();
  checkEncoderClick();
  autosaveSequenceIfChanged();
}

/*** Core 1: OLED renderer ****************************************************/
void setup1() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  lastUiMs = 0;
  markUI();
}

void loop1() {
  if (uiDirty && (millis() - lastUiMs) >= UI_INTERVAL_MS) {
    drawScreen();
    lastUiMs = millis();
    uiDirty = false;
  }
  delay(1);
}

/*** Clock: ISR & handler *****************************************************/
void clockISR() {
  uint32_t now = micros();
  prevClockEdgeUs = lastClockEdgeUs;
  lastClockEdgeUs = now;

  // period tracking as you already do…

  // Software clock division. Start on the first edge, then divide by d.
  // This avoids adding one complete input-clock period of startup latency.
  uint8_t d = g_clockDiv ? g_clockDiv : 1;
  if (edgeDivCount == 0) clockTicks++;
  edgeDivCount = (uint8_t)((edgeDivCount + 1) % d);
}

static inline bool clockActive() {
  uint32_t lastEdge;
  noInterrupts();
  lastEdge = lastClockEdgeUs;
  interrupts();
  if (lastEdge == 0 || lastGoodPeriodUs == 0) return false;
  uint32_t now = micros();
  return (uint32_t)(now - lastEdge) <= (3U * lastGoodPeriodUs);
}

void handleClock() {
  // Always update period
  uint32_t edgeNow, edgePrev;
  noInterrupts();
  edgeNow  = lastClockEdgeUs;
  edgePrev = prevClockEdgeUs;
  interrupts();
  if (edgePrev != 0 && edgeNow > edgePrev) {
    uint32_t periodUs = edgeNow - edgePrev;
    if (periodUs >= PERIOD_MIN_US && periodUs <= PERIOD_MAX_US) {
      lastGoodPeriodUs = periodUs;
    }
  }

  if (currentMode != IDLE) return; // only auto-run in IDLE

  uint32_t ticks;
  noInterrupts();
  ticks = clockTicks; clockTicks = 0;
  interrupts();

  while (ticks--) playSequence();
}

/*** TIME helpers *************************************************************/
static inline uint8_t timeToTicks(int8_t t) {
  if (t == -1) return 0; // special, handled via half-step path
  if (t == 0)  return 1; // 1 clock long rest
  if (t < 0)   return 1;
  if (t > 8)   return 8;
  return (uint8_t)t;
}

/*** Sequence tick ************************************************************/
void playSequence() {
  // If we're inside a multi-clock step, handle it first
  if (ticksLeftForStep > 0) {
    const uint32_t fullPeriod = (lastGoodPeriodUs > 0) ? lastGoodPeriodUs : PREVIEW_FALLBACK_US;

    if (retrigHold) {
      gateHoldOff();
      gateStartHalfPeriod(fullPeriod);
    }
    ticksLeftForStep--;
    if (ticksLeftForStep == 0) {
      playhead = (playhead + 1) % max(1, (int)seqLen);
    }
    uiDirty = true;
    return;
  }

  // No sequence recorded: tick-driven override only
  if (seqLen == 0) {
    if (keyOverride && overrideKey >= 1 && overrideKey <= 12) {
      int base = tabNote[overrideKey - 1];
      glideActiveNow  = false;
      vibEnabledNow   = false;
      currentNoteBase = (float)base;
      handle_CV((float)base, /*doTrigger=*/false);

      const uint32_t fullPeriod = (lastGoodPeriodUs > 0) ? lastGoodPeriodUs : PREVIEW_FALLBACK_US;
      gateHoldOff();
      gateStartHalfPeriod(fullPeriod);
    }
    uiDirty = true;
    return;
  }

  if (playhead >= seqLen) playhead = 0;

  // Live override while playing
  if (keyOverride) {
    uint8_t k = overrideKey;
    const uint32_t fullPeriod = (lastGoodPeriodUs > 0) ? lastGoodPeriodUs : PREVIEW_FALLBACK_US;

    if (k >= 1 && k <= 12) {
      int base = tabNote[k - 1];
      glideActiveNow  = false;
      vibEnabledNow   = false;
      currentNoteBase = (float)base;
      handle_CV((float)base, /*doTrigger=*/false);
      gateHoldOff();
      gateStartHalfPeriod(fullPeriod);
    } else {
      gateHoldOff();
    }
    playhead = (playhead + 1) % seqLen;
    uiDirty = true;
    return;
  }

  // ----- Normal step handling with TIME/RETRIG -----
  uint8_t i = playhead;
  const uint32_t fullPeriod = (lastGoodPeriodUs > 0) ? lastGoodPeriodUs : PREVIEW_FALLBACK_US;

  // Handle rests (seqActive false) as TIME=0
  int8_t t = seqActive[i] ? seqTime[i] : 0;
  t = constrain(t, -1, 8);

  if (t == -1) {
    // half-step: play now, schedule next step after half period, and jump +2
    playOneStep(i, fullPeriod >> 1, fullPeriod, "[PLAY]");
    subStepIndex  = (playhead + 1) % seqLen;
    subStepDueUs  = micros() + (fullPeriod >> 1);
    subStepActive = true;
    playhead = (playhead + 2) % seqLen;
    uiDirty = true;
    return;
  }

  // t == 0 (rest, lasts 1 clock)
  if (t == 0) {
    gateHoldOff();
    vibEnabledNow  = false;
    glideActiveNow = false;
    ticksLeftForStep = 1;     // hold one clock, then advance next tick
    retrigHold = false;
    uiDirty = true;
    return;
  }

  // t >= 1
  if (seqRetrig[i]) {
    playOneStep(i, fullPeriod, fullPeriod, "[PLAY]");
    ticksLeftForStep = (uint8_t)(t - 1);
    retrigHold = true;
    if (ticksLeftForStep == 0) {
      playhead = (playhead + 1) % max(1, (int)seqLen);
    }
  } else {
    uint64_t stepPeriod = (uint64_t)fullPeriod * (uint64_t)t;
    if (stepPeriod > 4000000000ULL) stepPeriod = 4000000000ULL;
    playOneStep(i, (uint32_t)stepPeriod, fullPeriod, "[PLAY]");
    ticksLeftForStep = (uint8_t)(t - 1);
    retrigHold = false;
    if (ticksLeftForStep == 0) {
      playhead = (playhead + 1) % max(1, (int)seqLen);
    }
  }
  uiDirty = true;
}

/*** One step player (reused by [PLAY], [HALF], [PREV]) ************************/
void playOneStep(uint8_t i, uint32_t gatePeriodUs, uint32_t glideBasePeriodUs, const char* /*context*/) {
  if (i >= seqLen) return;

  if (!seqActive[i]) {
    gateHoldOff();
    vibEnabledNow = false;
    glideActiveNow = false;
    return;
  }

  uint8_t key = seqKeys[i];
  if (key < 1 || key > 12) {
    gateHoldOff();
    vibEnabledNow = false;
    glideActiveNow = false;
    return;
  }

  int base = tabNote[key - 1];
  int pc   = base % 12;
  int oct  = base / 12;
  int effOct  = constrain(oct + effectiveOctaveOffset(), 0, 7);
  float effNote = (float)(pc + 12 * effOct);

  // Vibrato on this step?
  vibEnabledNow = seqVibrato[i];
  vibPhase = 0.0f;

  // Previous effective note (for glide)
  bool prevOk = false;
  float prevNoteEff = effNote;
  uint8_t iPrev = (i + seqLen - 1) % seqLen;
  if (seqActive[iPrev] && seqKeys[iPrev] >= 1 && seqKeys[iPrev] <= 12) {
    int prevBase = tabNote[seqKeys[iPrev] - 1];
    int ppc     = prevBase % 12;
    int poct    = prevBase / 12;
    int peffOct = constrain(poct + effectiveOctaveOffset(), 0, 7);
    prevNoteEff = (float)(ppc + 12 * peffOct);
    prevOk = true;
  }

  // Glide time always based on FULL period
  if (seqGlide[i] && prevOk) {
    glideActiveNow  = true;
    glideStartNote  = prevNoteEff;
    glideTargetNote = effNote;
    glideStartUs    = micros();

    uint32_t desired = (uint32_t)(glideBasePeriodUs * GLIDE_FRACTION);
    if (desired < MIN_GLIDE_US) desired = MIN_GLIDE_US;
    if (desired > MAX_GLIDE_US) desired = MAX_GLIDE_US;
    glideDurUs = desired;

    currentNoteBase = glideStartNote;
    handle_CV(glideStartNote, /*doTrigger=*/false);
  } else {
    glideActiveNow = false;
    currentNoteBase = effNote;
    handle_CV(effNote, /*doTrigger=*/false);
  }

  // Gate: 50% of THIS step’s gate period (full, half, or multi-clock)
  gateHoldOff();
  gateStartHalfPeriod(gatePeriodUs);
}

/*** MPR121 raw read **********************************************************/
uint8_t Read_Keypad() {
  Wire.beginTransmission(MPR_ADDR);
  Wire.write(0x00);
  if (Wire.endTransmission(false) != 0) return 0;
  if (Wire.requestFrom(MPR_ADDR, (uint8_t)2) != 2) return 0;
  uint16_t raw = uint16_t(Wire.read()) | (uint16_t(Wire.read()) << 8);
  // Physical T12 pad order: key 1 is electrode 10, then 6,5,0,...
  static const uint8_t electrode[12] = {10,6,5,0,9,7,4,2,11,8,3,1};
  for (uint8_t k = 0; k < 12; ++k)
    if (raw & (uint16_t(1) << electrode[k])) return uint8_t(k + 1);
  return 0;
}

/*** Keypad scanner (with no-retrigger lock) **********************************/
void scanKeys() {
  const uint32_t now = millis();
  uint8_t raw = Read_Keypad();

  if (stableKey == 0) {
    if (raw == 0) { pressCand = 0; return; }
    // The MPR121 already applies its own touch filter/debounce. Trigger on
    // the first reported status change to avoid adding software latency.
    if (raw == lastPressedKey) return;
    pressCand = raw;
    stableKey = raw;
    lastPressedKey = stableKey;
    onPress(stableKey);
    lastNonZeroMs   = now;
    holdLockUntilMs = now + LOCK_MS;
    return;
  }

  if (raw == stableKey) { lastNonZeroMs = now; return; }
  if (raw != 0) return;
  if (now < holdLockUntilMs) return;

  if (now - lastNonZeroMs >= RELEASE_MS) {
    uint8_t k = stableKey;
    stableKey = 0;
    lastPressedKey = 0;
    onRelease(k);
  }
}

/*** Encoder rotation *********************************************************/
void onEncoderTurn(EEncoder& enc) {
  int8_t inc = enc.getIncrement();
  if (inc == 0) return;

  // Handle 2-button modal selection
  if (modalActive && modalKind == MODAL_CONFIRM_CALIB) {
    modalChoiceIndex = (modalChoiceIndex + (inc > 0 ? 1 : -1) + 2) % 2;
    markUI();
    return;
  }

  if (modalActive && modalKind == MODAL_OK) return;

  // --- NAME EDITOR top priority ---
  if (nameEditActive) {
    int8_t inc = enc.getIncrement();
    if (inc != 0) {
      nameBuf[nameCursor] = nextCharInSet(nameBuf[nameCursor], inc);
      markUI();
    }
    return;
  }

  // --- Give PARAM overlay top priority ---
  if (paramState != P_NONE) {
    if (paramState == P_MENU) {
      const int total = 4 + 1; // 4 items + RETURN
      paramIndex = (paramIndex + (inc > 0 ? 1 : -1) + total) % total;
      markUI();
    } else if (paramState == P_TIME) {
      const int total = 10 + 1;
      timeSelIndex = (timeSelIndex + (inc > 0 ? 1 : -1) + total) % total;
      markUI();
    } else {
      const int total = 2 + 1;
      boolSelIndex = (boolSelIndex + (inc > 0 ? 1 : -1) + total) % total;
      markUI();
    }
    return;
  }

  // --- SETTINGS navigation (includes SAVE/LOAD pages) ---
  if (settingsState != S_NONE) {
    if (settingsState == S_MENU) {
      const int total = SETTINGS_MENU_COUNT + 1; // General, Clock, Save/Load, RETURN
      settingsIndex = (settingsIndex + (inc > 0 ? 1 : -1) + total) % total;
      markUI();
    } else if (settingsState == S_CALIB) {
      // encoder changes the active place of the active field
      int step = placeStep_mV(calibPos);
      if (calibField == 0) {
        calib_v0_mV = clampV0mV(calib_v0_mV + (inc>0 ? step : -step));
      } else {
        calib_vfs_mV = clampVFSmV(calib_vfs_mV + (inc>0 ? step : -step));
      }
      // keep VFS > V0 + 100mV
      if (calib_vfs_mV <= calib_v0_mV + 100) calib_vfs_mV = clampVFSmV(calib_v0_mV + 100);
      markUI();

    } else if (settingsState == S_SAVELOAD) {
      const int total = NUM_SLOTS + 1; // slots + RETURN
      saveLoadSlotIndex = (saveLoadSlotIndex + (inc > 0 ? 1 : -1) + total) % total;
      markUI();
    } else if (settingsState == S_SLOT_ACTION) {
      const int total = 3 + 1; // Save, Load, Clear, RETURN
      slotActionIndex = (slotActionIndex + (inc > 0 ? 1 : -1) + total) % total;
      markUI();
    }
    return;
  } else if (settingsState == S_NAMEEDIT) {
    // Change current character
    int dir = (inc > 0) ? +1 : -1;
    char c = nameEditBuf[nameEditPos];
    if (c == 0) c = ' ';
    nameEditBuf[nameEditPos] = nextCharInSet(c, dir);
    markUI();
    return;
  }



  // --- MODE MENU lowest priority overlay ---
  if (modesState == M_MENU) {
    const int total = 4 + 1; // + RETURN
    modeMenuIndex = (modeMenuIndex + (inc > 0 ? 1 : -1) + total) % total;
    markUI();
    return;
  }

  // 4) NORMAL MODES
  switch (currentMode) {
    case IDLE:
      transposeOctave(inc);
      markUI();
      break;

    case EDITKEY: {
      if (currentKey >= 1 && currentKey <= 12) {
        int &note = tabNote[currentKey - 1];
        note = constrain(note + inc, 0, 95);
        currentNoteBase = (float)note;
        vibPhase = 0.0f; vibEnabledNow = true;
        handle_CV((float)note, /*doTrigger=*/false);
        previewGate();

        int octave = note / 12;
        currentOctave = octave;

        // Show the big note overlay while tweaking
        keyNoteOverlayActive  = true;
        keyNoteOverlayUntilMs = millis() + KEY_NOTE_OVERLAY_TIMEOUT_MS;
        markUI();
      }
      break;
    }

    case RECSEQ: {
      // Left turn = undo last recorded step
      if (inc < 0 && seqLen > 0) {
        // Optional: clear flags of the removed slot (not required, but tidy)
        uint8_t idx = seqLen - 1;
        seqActive[idx]  = false;
        seqRetrig[idx]  = false;
        seqVibrato[idx] = false;
        seqGlide[idx]   = false;
        seqTime[idx]    = 1;   // default

        seqLen--;

        // stop any sustained gate on undo
        subStepActive    = false;
        ticksLeftForStep = 0;
        retrigHold       = false;
        vibEnabledNow    = false;
        glideActiveNow   = false;
        gateHoldOff();

        markUI();
      }
      // Right turn does nothing
      break;
    }

    case EDITSEQ:
      onEncoderChangeEditSeq(inc);
      break;

    case SETTINGS:
      break;
  }
}

/*** Encoder button (manual, on release) **************************************/
void checkEncoderClick() {
  const bool pressed = (digitalRead(ENC_SW) == LOW);  // active low
  const uint32_t now = millis();

  if (pressed && !buttonHeld) { buttonHeld = true; buttonPressStart = now; return; }

  if (!pressed && buttonHeld) {
    const uint32_t pressDuration = now - buttonPressStart;
    buttonHeld = false;

    if (pressDuration >= LONG_PRESS_MS) {
      onEncoderLongPress();
      clickCounter = 0;
    } else {
      if (now - lastButtonPress < DOUBLE_CLICK_INTERVAL) {
        clickCounter++;
        if (clickCounter == 2) { onEncoderDoubleClick(); clickCounter = 0; }
      } else {
        clickCounter = 1; lastButtonPress = now;
      }
    }
  }

  if (clickCounter == 1 && (now - lastButtonPress) > DOUBLE_CLICK_INTERVAL) {
    onEncoderSingleClick();
    clickCounter = 0;
  }
}

/*** Click handlers ***********************************************************/
// Single click: open/validate menus (Settings, Params, Modes)
void onEncoderSingleClick() {
  if (modalActive) {
    if (modalKind == MODAL_OK) {
      modalActive = false;
      modalKind   = MODAL_NONE;
      markUI();
      return;
    } else if (modalKind == MODAL_CONFIRM_CALIB) {
      // 0 = Save, 1 = Delete(discard)
      if (modalChoiceIndex == 0) {
        // Save
        V0_meas  = calib_v0_mV  / 1000.0f;
        Vfs_meas = calib_vfs_mV / 1000.0f;
        saveGlobals();
        // Leave calibration page and show confirmation
        settingsState = S_MENU;
        modalKind     = MODAL_NONE;
        modalActive   = false;
        showModalOK("Calibration saved");
      } else {
        // Discard
        // (Optionally restore working copies from runtime)
        calib_v0_mV  = (int)roundf(V0_meas  * 1000.0f);
        calib_vfs_mV = (int)roundf(Vfs_meas * 1000.0f);
        settingsState = S_MENU;
        modalKind     = MODAL_NONE;
        modalActive   = false;
        showModalOK("Discarded");
      }
      markUI();
      return;
    }
  }

  if (nameEditActive) {
    nameCursor = (nameCursor + 1) % nameMaxChars;
    markUI();
    return;
  }


  // ---------------- SETTINGS ----------------
  if (settingsState != S_NONE) {
    switch (settingsState) {
      case S_MENU: {
        const int returnIndex = SETTINGS_MENU_COUNT; // dynamic "Return"
        if (settingsIndex == returnIndex) {
          settingsState = S_NONE; currentMode = IDLE; markUI(); return;
        }

        switch (settingsIndex) {
          case 0: // General
            settingsState = S_GENERAL; markUI(); return;

          case 1: // Clock
            settingsState = S_CLOCK;   markUI(); return;

          case 2: { // Calibration
            // seed working copies from current globals
            calib_v0_mV  = (int)roundf(V0_meas  * 1000.0f);
            calib_vfs_mV = (int)roundf(Vfs_meas * 1000.0f);
            calib_v0_mV  = clampV0mV(calib_v0_mV);
            calib_vfs_mV = clampVFSmV(calib_vfs_mV);
            if (calib_vfs_mV <= calib_v0_mV + 100) calib_vfs_mV = clampVFSmV(calib_v0_mV + 100);
            calibField = 0;           // start editing V0
            calibPos   = 0;           // ones place (1V)
            settingsState = S_CALIB;  // enter calibration page
            markUI(); return;
          }

          case 3: // Save/Load
            settingsState     = S_SAVELOAD;
            saveLoadSlotIndex = 0;
            markUI(); return;
        }
        break;
      }

      case S_CALIB: {
        // Step the active digit. We use 4 places: 0..3 (1V, 0.1V, 0.01V, 0.001V)
        enterCalibrationRef();

        if (++calibPos > 3) {           // wrapped past last digit
          calibPos = 0;
          if (calibField == 0) {
            // Finished MIN → move to MAX field
            calibField = 1;
            setCalibRefOutput();
          } else {
            // Finished MAX → validate, then ask to save
            if (calib_vfs_mV <= calib_v0_mV + 100) {
              // enforce at least 0.100 V span
              calib_vfs_mV = clampVFSmV(calib_v0_mV + 100);
              showModalOK("Max must be > Min by 0.100V");
            } else {
              showModalConfirmCalib();   // Save / Delete modal
            }
          }
        } else {
          // moved to next digit within the same field
          setCalibRefOutput();
        }
        markUI(); 
        return;
      }

      case S_SAVELOAD: {
        // 0..NUM_SLOTS-1 slots, NUM_SLOTS = RETURN
        if (saveLoadSlotIndex == NUM_SLOTS) { settingsState = S_MENU; markUI(); return; }
        settingsState   = S_SLOT_ACTION;
        slotActionIndex = 0;
        markUI(); return;
      }

      case S_SLOT_ACTION: {
        // Index map: 0=Save, 1=Load, 2=Clear, 3=RETURN
        if (slotActionIndex == 3) { 
          settingsState = S_SAVELOAD; 
          markUI(); 
          return; 
        }

        if (slotActionIndex == 0) { 
          // Save -> open name editor (blocking overlay)
          // Prefill suggestion; you can read an existing name from EEPROM instead.
          char prefill[17];
          snprintf(prefill, sizeof(prefill), "Slot %d", (int)saveLoadSlotIndex + 1);

          startNameEditor((uint8_t)saveLoadSlotIndex, prefill);
          // Keep SETTINGS context; drawScreen() should detect nameEditActive and render the editor.
          return;
        }

        // Load / Clear remain immediate
        if (slotActionIndex == 1) {
          bool ok = loadSlot((uint8_t)saveLoadSlotIndex);
          showModalOK(ok ? "Loaded." : "Load failed / empty slot.");
        } else if (slotActionIndex == 2) {
          bool ok = clearSlot((uint8_t)saveLoadSlotIndex);
          showModalOK(ok ? "Cleared." : "Clear failed.");
        }

        settingsState = S_NONE; 
        currentMode   = IDLE; 
        markUI(); 
        return;
      }

      case S_GENERAL:
      case S_CLOCK:
        // Click exits those pages
        settingsState = S_NONE; currentMode = IDLE; markUI(); return;

      default: break;
    }
  }

  // ---------------- PARAMETERS (SEQ EDIT) ----------------
  if (paramState != P_NONE) {
    if (paramState == P_MENU) {
      // 0..3 items, 4 = RETURN
      if (paramIndex == 4) { paramState = P_NONE; markUI(); return; }
      switch (paramIndex) {
        case 0: paramState = P_TIME;    markUI(); break;
        case 1: paramState = P_RETRIG;  boolSelIndex = seqRetrig [editStep] ? 1 : 0; markUI(); break;
        case 2: paramState = P_GLIDE;   boolSelIndex = seqGlide  [editStep] ? 1 : 0; markUI(); break;
        case 3: paramState = P_VIBRATO; boolSelIndex = seqVibrato[editStep] ? 1 : 0; markUI(); break;
      }
      return;
    } else if (paramState == P_TIME) {
      // 0..9 are values; 10 = RETURN
      if (timeSelIndex == 10) { paramState = P_MENU; markUI(); return; }
      int8_t val = (timeSelIndex == 0) ? -1 : (int8_t)min(timeSelIndex - 1, 8);
      seqTime[editStep] = val;
      previewStep(editStep);
      paramState = P_MENU;
      markUI(); return;
    } else {
      // Toggles: 0=OFF,1=ON, 2=RETURN
      if (boolSelIndex == 2) { paramState = P_MENU; markUI(); return; }
      bool on = (boolSelIndex == 1);
      if      (paramState == P_RETRIG)  seqRetrig [editStep] = on;
      else if (paramState == P_GLIDE)   seqGlide  [editStep] = on;
      else if (paramState == P_VIBRATO) seqVibrato[editStep] = on;
      previewStep(editStep);
      paramState = P_MENU;
      markUI(); return;
    }
  }

  // ---------------- MODE MENU ----------------
  if (modesState == M_MENU) {
    // 0..3 = modes, 4 = RETURN
    if (modeMenuIndex == 4) { modesState = M_NONE; currentMode = modeBeforeMenu; markUI(); return; }

    switch (modeMenuIndex) {
      case 0: currentMode = IDLE;    break;
      case 1: currentMode = EDITKEY; break;
      case 2: currentMode = RECSEQ;  break;
      case 3:
        if (seqLen == 0) {
          showModalOK("No sequence to edit...");
          markUI();
          return; // keep menu open
        } else {
          currentMode = EDITSEQ;
          playhead = 0; gateHoldOff(); vibEnabledNow = false;
          if (editStep >= seqLen) editStep = 0;
        }
        break;
    }
    modesState = M_NONE;
    markUI(); 
    return;
  }

  // Open MODE menu if nothing else is active
  if (currentMode == IDLE || currentMode == EDITKEY || currentMode == RECSEQ || currentMode == EDITSEQ) {
    modesState = M_MENU;
    modeBeforeMenu = currentMode;
    switch (currentMode) {
      case IDLE:    modeMenuIndex = 0; break;
      case EDITKEY: modeMenuIndex = 1; break;
      case RECSEQ:  modeMenuIndex = 2; break;
      case EDITSEQ: modeMenuIndex = 3; break;
      default:      modeMenuIndex = 0; break;
    }
    markUI(); return;
  }
}

void onEncoderDoubleClick() {
  if (modalActive) {
    modalActive = false;
    modalKind   = MODAL_NONE;
    markUI();
    return;
  }

  if (nameEditActive) {
    finishNameEditor(/*saveIt=*/false);
    return;
  }

  // PARAM overlays (SEQ EDIT)
  if (currentMode == EDITSEQ && settingsState == S_NONE) {
    if (modesState != M_NONE) modesState = M_NONE; // prevent stealing input
    if (paramState == P_NONE) {
      if (seqLen == 0) return;
      paramState  = P_MENU;
      paramIndex  = 0;
      int8_t tv = constrain(seqTime[editStep], -1, 8);
      timeSelIndex = (tv == -1) ? 0 : (tv + 1);
      boolSelIndex = seqRetrig[editStep] ? 1 : 0;
      markUI();
    } else if (paramState == P_MENU) {
      paramState = P_NONE; markUI();
    } else {
      paramState = P_MENU; markUI();
    }
    return;
  }

  // SETTINGS: back everywhere with double click
  if (settingsState != S_NONE) {
    if (settingsState == S_CALIB) { 
      leaveCalibrationRef(); 
      settingsState = S_MENU; 
      markUI(); 
      return; 
    }
    if (settingsState == S_GENERAL || settingsState == S_CLOCK || settingsState == S_SAVELOAD || settingsState == S_SLOT_ACTION) {
      settingsState = S_MENU; markUI(); return;
    }
    if (settingsState == S_MENU) {
      settingsState = S_NONE; currentMode = IDLE; markUI(); return;
    }
  }

  // MODE MENU: cancel
  if (modesState == M_MENU) {
    modesState  = M_NONE;
    currentMode = modeBeforeMenu;
    markUI();
    return;
  }

  // Elsewhere: shortcut to EDITSEQ if a sequence exists
  if (settingsState != S_NONE) return;
  keyOverride = false; overrideKey = 0;
  if (seqLen == 0) return;
  currentMode = EDITSEQ;
  playhead = 0; gateHoldOff(); vibEnabledNow = false;
  if (editStep >= seqLen) editStep = 0;
  markUI();
}

void onEncoderLongPress() {
  if (modalActive) return;

  if (nameEditActive) {
    finishNameEditor(/*saveIt=*/true);
    return;
  }

  // RECSEQ: long press = clear all
  if (currentMode == RECSEQ && settingsState == S_NONE && paramState == P_NONE && modesState == M_NONE) {
    seqLen = 0;
    writeIdx = 0;
    playhead = 0;
    subStepActive    = false;
    ticksLeftForStep = 0;
    retrigHold       = false;
    vibEnabledNow    = false;
    glideActiveNow   = false;
    gateHoldOff();
    uiDirty = true;
    showModalOK("Sequence erased");
    return;
  }

  // MODE MENU: cancel (return)
  if (modesState == M_MENU) {
    modesState  = M_NONE;
    currentMode = modeBeforeMenu;
    markUI();
    return;
  }

  // SETTINGS: open from IDLE
  if (currentMode == IDLE && settingsState == S_NONE && paramState == P_NONE && modesState == M_NONE) {
    currentMode    = SETTINGS;
    settingsState  = S_MENU;
    settingsIndex  = 0;
    markUI();
    return;
  }

  // SETTINGS: in CALIB → save & back
  if (settingsState == S_CALIB) {
    V0_meas  = calib_v0_mV  / 1000.0f;
    Vfs_meas = calib_vfs_mV / 1000.0f;
    saveGlobals();
    showModalOK("Calibration saved");
    leaveCalibrationRef(); 
    settingsState = S_MENU;
    markUI();
    return;
  }

  if (settingsState == S_NAMEEDIT) {
    trimTrailingSpaces(nameEditBuf);
    bool ok = saveSlotWithName((uint8_t)saveLoadSlotIndex, nameEditBuf[0] ? nameEditBuf : "UNTITLED");
    settingsState = S_NONE;
    currentMode   = IDLE;
    showModalOK(ok ? "Saved." : "Save failed.");
    markUI();
    return;
  }

  // SETTINGS: long press = back one level (others)
  if (settingsState != S_NONE) {
    if      (settingsState == S_SLOT_ACTION) { settingsState = S_SAVELOAD; }
    else if (settingsState == S_SAVELOAD || settingsState == S_GENERAL || settingsState == S_CLOCK) { settingsState = S_MENU; }
    else if (settingsState == S_MENU) { settingsState = S_NONE; currentMode = IDLE; }
    markUI();
    return;
  }
}

/*** Key handlers *************************************************************/
void onPress(uint8_t k) {
  if (modalActive) return;

  // Ignore key presses while in overlays/menus
  if (settingsState != S_NONE || paramState != P_NONE || modesState == M_MENU) return;

  lastTouchedKey = k;  // highlight & info
  markUI();

  // EDITKEY octave ± via keys 15/16 (kept)
  if (currentMode == EDITKEY && (k == 15 || k == 16)) {
    editKeyTransposeOctave(k == 15 ? -1 : +1);
    uiDirty = true;
    return;
  }

  // IDLE transport / transpose keys (kept minimal)
  if (currentMode == IDLE && k >= 13 && k <= 16) {
    switch (k) {
      case 14: manualReset();       break;
    }
    uiDirty = true;
    return;
  }

  // ignore non-note keys otherwise
  if (k < 1 || k > 12) return;

  currentKey = k;
  const int base = tabNote[k - 1];

  switch (currentMode) {
    case IDLE: {
      if (clockActive()) {
        keyOverride    = true;
        overrideKey    = k;
        vibEnabledNow  = false;
        glideActiveNow = false;
      } else {
        currentNoteBase = (float)base;
        vibPhase        = 0.0f;
        vibEnabledNow   = false;
        handle_CV((float)base, /*doTrigger=*/false);
        previewGate();
      }
      uiDirty = true;
      break;
    }

    case EDITKEY: {
      currentNoteBase = (float)base;
      vibPhase = 0.0f; vibEnabledNow = false;
      handle_CV((float)base, /*doTrigger=*/false);
      previewGate();
      uiDirty = true;
      break;
    }
    case RECSEQ: {
      // Only accept note keys 1..12
      if (k >= 1 && k <= 12) {
        if (seqLen < SEQ_MAX) {
          // Append step at the end
          uint8_t idx = seqLen;
          seqKeys[idx]     = k;
          seqActive[idx]   = true;
          seqTime[idx]     = 1;
          seqRetrig[idx]   = false;
          seqVibrato[idx]  = false;
          seqGlide[idx]    = false;
          seqLen++;

          // Preview the recorded note
          int base = tabNote[k - 1];
          currentNoteBase = (float)base;
          vibPhase = 0.0f; 
          vibEnabledNow = false;
          handle_CV((float)base, /*doTrigger=*/false);
          previewGate();

          markUI();
        } else {
          // Already at 32 steps → ignore extra input
        }
      }
      break;
    }
    case EDITSEQ: {
      if (seqLen > 0) {
        seqKeys[editStep] = k;
        previewStep(editStep);
        uiDirty = true;
      }
      break;
    }
    case SETTINGS:
      break;
  }
}

void onRelease(uint8_t k) {
  if (modalActive) return;

  if (settingsState != S_NONE || paramState != P_NONE || modesState == M_MENU) return;

  lastTouchedKey = k;  // also highlight last released
  markUI();

  if (keyOverride && k == overrideKey) {
    keyOverride = false; overrideKey = 0;
    uiDirty = true;
  }
}

/*** EDITSEQ scrolling helper *************************************************/
void onEncoderChangeEditSeq(int8_t delta) {
  if (seqLen == 0) return;
  int newStep = (int)editStep + delta;
  while (newStep < 0) newStep += seqLen;
  while (newStep >= (int)seqLen) newStep -= seqLen;
  editStep = (uint8_t)newStep;
  previewStep(editStep);
  uiDirty = true;
}

/*** Step preview with vibrato + glide (+ time half) **************************/
void previewStep(uint8_t stepIndex) {
  if (seqLen == 0 || stepIndex >= seqLen) return;

  if (!seqActive[stepIndex] || seqTime[stepIndex] == 0) {
    vibEnabledNow = false;
    gateHoldOff();
    uiDirty = true;
    return;
  }

  uint8_t key = seqKeys[stepIndex];
  if (key < 1 || key > 12) {
    vibEnabledNow = false;
    gateHoldOff();
    uiDirty = true;
    return;
  }

  int base = tabNote[key - 1];
  int pc   = base % 12;
  int oct  = base / 12;
  int effOct  = constrain(oct + effectiveOctaveOffset(), 0, 7);
  float effNote = (float)(pc + 12 * effOct);

  vibEnabledNow = seqVibrato[stepIndex];
  vibPhase = 0.0f;

  const uint32_t fullPeriod = lastGoodPeriodUs ? lastGoodPeriodUs : PREVIEW_FALLBACK_US;

  // half if TIME = -1
  const bool isHalf = (seqTime[stepIndex] == -1);
  uint32_t gatePeriod = isHalf ? (fullPeriod >> 1) : fullPeriod;

  // Glide preview (time for glide based on full period)
  uint8_t iPrev = (stepIndex + seqLen - 1) % seqLen;
  bool prevActive = seqActive[iPrev] && (seqKeys[iPrev] >= 1 && seqKeys[iPrev] <= 12);

  if (seqGlide[stepIndex] && prevActive) {
    int prevBase = tabNote[seqKeys[iPrev] - 1];
    int ppc     = prevBase % 12;
    int poct    = prevBase / 12;
    int peffOct = constrain(poct + effectiveOctaveOffset(), 0, 7);
    float prevNoteEff = (float)(ppc + 12 * peffOct);

    glideActiveNow  = true;
    glideStartNote  = prevNoteEff;
    glideTargetNote = effNote;
    glideStartUs    = micros();

    uint32_t desired = (uint32_t)(fullPeriod * GLIDE_FRACTION);
    if (desired < MIN_GLIDE_US) desired = MIN_GLIDE_US;
    if (desired > MAX_GLIDE_US) desired = MAX_GLIDE_US;
    glideDurUs = desired;

    currentNoteBase = glideStartNote;
    handle_CV(glideStartNote, /*doTrigger=*/false);
  } else {
    glideActiveNow = false;
    currentNoteBase = effNote;
    handle_CV(effNote, /*doTrigger=*/false);
  }

  uint32_t previewHigh = gatePeriod >> 1;
  if (previewHigh < PREVIEW_MIN_US) previewHigh = PREVIEW_MIN_US;
  if (previewHigh > PREVIEW_MAX_US) previewHigh = PREVIEW_MAX_US;
  digitalWrite(GATE_PIN, HIGH);
  trigActive = true;
  trigOffAt  = micros() + previewHigh;

  uiDirty = true;
}

/*** DAC & gate helpers *******************************************************/
void handle_CV(float noteIndex, bool doTrigger) {
  float v = noteIndex / 12.0f;     // 1V/oct
  v = constrain(v, 0.0f, 8.0f);

  float span = Vfs_meas - V0_meas;
  int code = 0;
  if (span > 0.001f) {
    float norm = (v - V0_meas) / span;
    norm = constrain(norm, 0.0f, 1.0f);
    code = (int)round(norm * 4095.0f);
  }
  // T12 CV stages invert the PWM analogue level.  Calibrated 0..8 V is
  // represented by the same normalized code as the original DAC path.
  uint16_t pwm = uint16_t(constrain(code, 0, 4095));
  analogWrite(PITCH_CV_PIN, 4095 - pwm);
  analogWrite(AUX_CV_PIN, 4095 - pwm);

  if (doTrigger) gateTrigger();
}

inline void gateTrigger() {
  digitalWrite(GATE_PIN, HIGH);
  trigActive = true;
  trigOffAt = micros() + TRIG_US;
}

inline void gateStartHalfPeriod(uint32_t periodUs) {
  uint32_t highUs = periodUs >> 1; // 50% duty
  digitalWrite(GATE_PIN, HIGH);
  trigActive = true;
  trigOffAt = micros() + highUs;
}

inline void previewGate() {
  uint32_t dur = lastGoodPeriodUs ? (lastGoodPeriodUs >> 1) : PREVIEW_FALLBACK_US;
  if (dur < PREVIEW_MIN_US) dur = PREVIEW_MIN_US;
  if (dur > PREVIEW_MAX_US) dur = PREVIEW_MAX_US;
  digitalWrite(GATE_PIN, HIGH);
  trigActive = true;
  trigOffAt  = micros() + dur;
}

inline void gateHoldOn() {
  digitalWrite(GATE_PIN, HIGH);
  gateSustain = true;
}

inline void gateHoldOff() {
  gateSustain = false;
  if (!trigActive) digitalWrite(GATE_PIN, LOW);
}

inline void processGatePulse() {
  if (trigActive && (int32_t)(micros() - trigOffAt) >= 0) {
    trigActive = false;
    if (!gateSustain) digitalWrite(GATE_PIN, LOW);
  }
}

/*** Mods updater: glide + vibrato ********************************************/
inline void updatePitchMods() {
  if (settingsState == S_CALIB) return;
  if (!gateSustain && !trigActive) return;

  float noteOut = currentNoteBase;

  // Glide
  if (glideActiveNow) {
    uint32_t now = micros();
    float t = (glideDurUs > 0) ? (float)(now - glideStartUs) / (float)glideDurUs : 1.0f;

    if (t >= 1.0f) {
      glideActiveNow = false;
      currentNoteBase = glideTargetNote;
      noteOut = glideTargetNote;
    } else if (t <= 0.0f) {
      noteOut = glideStartNote;
    } else {
      float s;
      switch (glideShape) {
        case GLIDE_LINEAR:    s = t; break;
        case GLIDE_EXPO:      s = 1.0f - expf(-GLIDE_EXPO_K * t); break;
        case GLIDE_SMOOTHSTEP:
        default:              s = t * t * (3.0f - 2.0f * t); break;
      }
      noteOut = glideStartNote + (glideTargetNote - glideStartNote) * s;
    }
  }

  // Vibrato
  uint32_t now2 = micros();
  if ((uint32_t)(now2 - vibLastMicros) >= VIB_UPDATE_US) {
    float dt = (now2 - vibLastMicros) / 1000000.0f;
    vibLastMicros = now2;

    if (vibEnabledNow) {
      float depthSemi = vibDepthCents / 100.0f;
      float omega = 2.0f * 3.14159265f * vibRateHz;
      vibPhase += omega * dt;
      if (vibPhase > 6.2831853f) vibPhase -= 6.2831853f;
      noteOut += depthSemi * sinf(vibPhase);
    }
    handle_CV(noteOut, /*doTrigger=*/false);
  }
}

/*** Transport & utilities ****************************************************/
inline void togglePlay() {
  seqPlaying = !seqPlaying;
  keyOverride = false; overrideKey = 0;
  if (!seqPlaying) {
    noInterrupts(); clockTicks = 0; interrupts();
    glideActiveNow = false;
    gateHoldOff();
    trigActive = false;
    digitalWrite(GATE_PIN, LOW);
    vibEnabledNow = false;
    subStepActive = false;
    ticksLeftForStep = 0;
    retrigHold = false;
  }
  uiDirty = true;
}

inline void manualReset() {
  playhead = 0;
  keyOverride = false; overrideKey = 0;
  noInterrupts(); clockTicks = 0; interrupts();
  glideActiveNow = false;
  gateHoldOff();
  trigActive = false;
  digitalWrite(GATE_PIN, LOW);
  vibEnabledNow = false;
  subStepActive = false;
  ticksLeftForStep = 0;
  retrigHold = false;
  uiDirty = true;
}

// Compute the allowed global octave offset so every affected note stays in 0..7.
static inline void computeTransposeBounds(int &minOff, int &maxOff) {
  minOff = -7;   // widest possible range
  maxOff =  7;
  bool any = false;

  auto accumulate = [&](int oct) {
    // To keep this note in [0..7], offset must satisfy: 0 - oct <= off <= 7 - oct
    minOff = max(minOff, 0 - oct);
    maxOff = min(maxOff, 7 - oct);
    any = true;
  };

  if (seqLen > 0) {
    for (uint8_t i = 0; i < seqLen; ++i) {
      if (!seqActive[i]) continue;
      uint8_t k = seqKeys[i];
      if (k < 1 || k > 12) continue;
      int base = tabNote[k - 1];
      int oct  = base / 12;
      accumulate(oct);
    }
  }

  // If there’s no sequence, bound by the 12 key mappings instead
  if (!any) {
    for (uint8_t k = 1; k <= 12; ++k) {
      int base = tabNote[k - 1];
      int oct  = base / 12;
      accumulate(oct);
    }
  }

  if (minOff > maxOff) { minOff = 0; maxOff = 0; } // degenerate safety
}

inline void transposeOctave(int delta) {
  int minOff, maxOff;
  computeTransposeBounds(minOff, maxOff);

  int newOff = (int)seqOctaveOffset + delta;
  if (newOff < minOff) newOff = minOff;
  if (newOff > maxOff) newOff = maxOff;

  if (newOff != seqOctaveOffset) {
    seqOctaveOffset = (int8_t)newOff;
    markUI();
  }
}

inline void editKeyTransposeOctave(int deltaOct) {
  if (currentKey < 1 || currentKey > 12) return;
  int base = tabNote[currentKey - 1];
  int pc   = base % 12;
  int oct  = base / 12;
  int newOct  = constrain(oct + deltaOct, 0, 7);
  int newNote = pc + 12 * newOct;
  if (newNote != base) tabNote[currentKey - 1] = newNote;
  currentOctave = newOct;
  currentNoteBase = (float)newNote;
  vibPhase = 0.0f; vibEnabledNow = true;
  handle_CV((float)newNote, /*doTrigger=*/false);
  previewGate();
  uiDirty = true;
}

void setClockDiv(uint8_t d) {
  // constrain to allowed values (example: 1,2,4,8,16)
  const uint8_t allowed[] = {1,2,4,8,16};
  uint8_t chosen = 1;
  for (uint8_t i=0;i<sizeof(allowed);++i) if (d==allowed[i]) { chosen = d; break; }
  g_clockDiv = chosen;
  saveGlobals();
}

/*** UI helpers + drawing *****************************************************/
void drawListHeader(const char* title) {
  u8g2.setFont(u8g2_font_6x10_tf);
  const int16_t baseline = 10;
  u8g2.drawUTF8(2, baseline, title);

  int16_t lineHeight = u8g2.getAscent() - u8g2.getDescent();
  g_contentStartY = baseline + lineHeight + 2;
}

void drawListWithReturn(const char* title,
                        const char* const* items,
                        int itemsCount,
                        int selectedIndex,
                        bool showReturn) {
  drawListHeader(title);

  u8g2.setFont(u8g2_font_6x10_tf);
  const int startY  = g_contentStartY;
  const int lineH   = 12;
  const int rows    = 4;               // max visible rows

  const int total   = itemsCount + (showReturn ? 1 : 0);
  if (selectedIndex < 0) selectedIndex = 0;
  if (selectedIndex >= total) selectedIndex = total - 1;

  int first = selectedIndex - rows/2;
  if (first < 0) first = 0;
  if (first > total - rows) first = max(0, total - rows);

  const int visible = min(rows, total);

  for (int i = 0; i < visible; ++i) {
    const int idx = first + i;
    const int y   = startY + i * lineH;

    const char* label;
    static char retBuf[] = "RETURN";
    if (idx < itemsCount) label = items[idx];
    else                  label = retBuf; // RETURN

    if (idx == selectedIndex) {
      u8g2.drawBox(2, y - 9, 124, 11);
      u8g2.setDrawColor(0);
      u8g2.drawUTF8(6, y, label);
      u8g2.setDrawColor(1);
    } else {
      u8g2.drawUTF8(6, y, label);
    }
  }

  if (first > 0)                     u8g2.drawTriangle(122, g_contentStartY - 4, 126, g_contentStartY - 4, 124, g_contentStartY - 8);
  if (first + rows < total)          u8g2.drawTriangle(122, 62, 126, 62, 124, 66);
}

void drawModesMenu() {
  static const char* items[] = {"PERFORMANCE", "KEYS EDIT", "RECORD SEQ", "SEQ EDIT"};
  drawListWithReturn("MODE", items, 4, modeMenuIndex, /*showReturn=*/true);
}

void drawCalibrationPage() {
  // Header + baseline setup (also updates g_contentStartY)
  drawListHeader("CALIBRATION");

  u8g2.setFont(u8g2_font_6x10_tf);

  const int left       = 6;
  const int lineH      = 12;
  const int sectionGap = 4;

  // start just below the header
  int y = g_contentStartY + 2;

  // 1) title: min voltage
  u8g2.drawUTF8(left, y, "min voltage");
  y += lineH;

  // 2) min value
    drawValueEditor_0_000V(left, y, calib_v0_mV, (calibField == 0) ? calibPos : 255);
  y += lineH + sectionGap;

  // 3) title: max voltage
  u8g2.drawUTF8(left, y, "max voltage");
  y += lineH;

  // 4) max value
    drawValueEditor_0_000V(left, y, calib_vfs_mV, (calibField == 1) ? calibPos : 255);
}

// Right-align any UTF-8 string to the display's right edge (2px margin by default)
static inline void drawRightAligned(int y, const char* s, int rightMargin) {
  int x = u8g2.getDisplayWidth() - rightMargin - u8g2.getUTF8Width(s);
  if (x < 0) x = 0;
  u8g2.drawUTF8(x, y, s);
}

// Note name from semitone (0..95) -> e.g. "C#3"
static inline void noteNameFromSemi(int semi, char* out, size_t outsz) {
  semi = constrain(semi, 0, 95);
  static const char* nn[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
  int pc  = semi % 12;
  int oct = semi / 12;
  snprintf(out, outsz, "%s%d", nn[pc], oct);
}

// Overlay state gate: true while active AND not expired. Also auto-clears flag when expired.
static inline bool keyOverlayActiveNow() {
  if (!keyNoteOverlayActive) return false;
  int32_t dt = (int32_t)(millis() - keyNoteOverlayUntilMs);
  if (dt >= 0) {                // expired
    keyNoteOverlayActive = false;
    markUI();
    return false;
  }
  return true;
}

// -------- utils note ----------
static void noteNameForKey(uint8_t key, char* out, size_t outsz) {
  if (!key || key > 12) { snprintf(out, outsz, "--"); return; }
  int base = tabNote[key - 1];
  int pc   = base % 12;
  int oct  = base / 12;
  int effOct = constrain(oct + effectiveOctaveOffset(), 0, 7);
  static const char* nn[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
  snprintf(out, outsz, "%s%d", nn[(pc+12)%12], effOct);
}

// Bottom-left transpose indicator (only in IDLE)
static inline void drawTransposeBL() {
  if (currentMode != IDLE) return;
  u8g2.setFont(u8g2_font_7x13_tf);
  char tr[12];
  snprintf(tr, sizeof(tr), "TR:%+d", (int)seqOctaveOffset);  // e.g. TR:+2
  u8g2.drawUTF8(2, 63, tr);
}

// ===== Blocking modal (OK button) =====

static inline void showModalOK(const char* txt) {
  strncpy(modalMsg, txt, sizeof(modalMsg) - 1);
  modalMsg[sizeof(modalMsg) - 1] = 0;
  modalKind   = MODAL_OK;
  modalActive = true;
  markUI();
}

// Draws centered modal with an "OK" button; caller still draws the usual screen behind.
static inline void drawModalIfAny() {
  if (!modalActive) return;

  // --- style / metrics ---
  u8g2.setFont(u8g2_font_6x13B_tf);
  const int padX = 14;
  const int padY = 12;
  const int gapTextBtn = 12;
  const int btnH = 16;
  const int btnRad = 3;
  const int maxPanelW = 120;

  // wrap text (same as before)
  const int ascent  = u8g2.getAscent();
  const int descent = u8g2.getDescent();
  const int lineH   = ascent - descent;
  const int lineGap = 2;

  static char lines[5][64];
  int nLines = 0;
  for (int i=0;i<5;i++) lines[i][0] = '\0';
  const int maxTextW = maxPanelW - 2 * padX;

  const char* s = modalMsg;
  char cur[64] = {0};
  while (*s && nLines < 5) {
    char word[40]; int wi=0;
    while (*s==' ') ++s;
    while (*s && *s!=' ' && wi<39) word[wi++]=*s++;
    word[wi]=0;
    if (!wi) break;

    char test[64];
    if (cur[0]==0) { strncpy(test, word, sizeof(test)-1); test[sizeof(test)-1]=0; }
    else { snprintf(test, sizeof(test), "%s %s", cur, word); }

    if (u8g2.getUTF8Width(test) <= maxTextW) { strncpy(cur, test, sizeof(cur)-1); cur[sizeof(cur)-1]=0; }
    else {
      if (cur[0]) { strncpy(lines[nLines++], cur, sizeof(lines[0])-1); lines[nLines-1][sizeof(lines[0])-1]=0; cur[0]=0; }
      if (u8g2.getUTF8Width(word) > maxTextW) {
        int len=strlen(word), cut=len;
        while (cut>1) {
          char tmp[64]; strncpy(tmp, word, min(cut,(int)sizeof(tmp)-1)); tmp[min(cut,(int)sizeof(tmp)-1)]=0;
          if (u8g2.getUTF8Width(tmp) <= maxTextW) break; --cut;
        }
        if (cut<=1) cut=min(len,20);
        char chunk[64]; strncpy(chunk, word, cut); chunk[cut]=0;
        strncpy(lines[nLines++], chunk, sizeof(lines[0])-1);
        lines[nLines-1][sizeof(lines[0])-1]=0;
        if (nLines<5 && cut<len) { strncpy(cur, word+cut, sizeof(cur)-1); cur[sizeof(cur)-1]=0; }
      } else {
        strncpy(cur, word, sizeof(cur)-1); cur[sizeof(cur)-1]=0;
      }
    }
  }
  if (cur[0] && nLines<5) { strncpy(lines[nLines++], cur, sizeof(lines[0])-1); lines[nLines-1][sizeof(lines[0])-1]=0; }
  if (nLines==0) { strcpy(lines[0], " "); nLines=1; }
  const int maxLines=4;
  if (nLines>maxLines) {
    nLines=maxLines;
    int L=strlen(lines[nLines-1]);
    if (L>3){ lines[nLines-1][max(0,L-3)]=0; strcat(lines[nLines-1],"..."); }
    else { strcpy(lines[nLines-1],"..."); }
  }

  int widest = 0;
  for (int i=0;i<nLines;i++) { widest = max(widest, u8g2.getUTF8Width(lines[i])); }

  // Button layout depends on modal kind
  int panelW = 0, panelH = 0, textBlockH = nLines * lineH + (nLines - 1) * lineGap;

  if (modalKind == MODAL_OK) {
    const int btnW = 40;
    widest = max(widest, btnW);
    panelW = min(maxPanelW, widest + 2*padX);
    panelH = padY + textBlockH + gapTextBtn + btnH + padY;

    int px=(128-panelW)/2, py=(64-panelH)/2;

    u8g2.setDrawColor(1); u8g2.drawRBox(px,py,panelW,panelH,4);
    u8g2.setDrawColor(0); u8g2.drawRFrame(px,py,panelW,panelH,4);

    int textTop = py + padY + ascent;
    for (int i=0;i<nLines;i++){
      int w=u8g2.getUTF8Width(lines[i]);
      int tx = px + (panelW - w)/2;
      int ty = textTop + i*(lineH+lineGap);
      u8g2.drawUTF8(tx, ty, lines[i]);
    }

    // OK button (outline, panel is white)
    int bx = px + (panelW - 40)/2;
    int by = py + panelH - padY - btnH;
    u8g2.drawRFrame(bx, by, 40, btnH, btnRad);
    int okW = u8g2.getUTF8Width("OK");
    u8g2.drawUTF8(bx + (40-okW)/2, by + btnH - 3, "OK");

    u8g2.setDrawColor(1);
    return;
  }

  // --- Confirm modal: two buttons ---
  // Measure label widths
  const char* leftLbl  = "Save";
  const char* rightLbl = "Delete";
  int leftW  = max(32, u8g2.getUTF8Width(leftLbl)  + 12); // padding
  int rightW = max(44, u8g2.getUTF8Width(rightLbl) + 12);
  const int gapBtns = 8;
  const int btnRowW = leftW + gapBtns + rightW;

  widest = max(widest, btnRowW);
  panelW = min(maxPanelW, widest + 2*padX);
  panelH = padY + textBlockH + gapTextBtn + btnH + padY;

  int px=(128-panelW)/2, py=(64-panelH)/2;

  u8g2.setDrawColor(1); u8g2.drawRBox(px,py,panelW,panelH,4);
  u8g2.setDrawColor(0); u8g2.drawRFrame(px,py,panelW,panelH,4);

  int textTop = py + padY + ascent;
  for (int i=0;i<nLines;i++){
    int w=u8g2.getUTF8Width(lines[i]);
    int tx = px + (panelW - w)/2;
    int ty = textTop + i*(lineH+lineGap);
    u8g2.drawUTF8(tx, ty, lines[i]);
  }

  int btnY = py + panelH - padY - btnH;
  int rowX = px + (panelW - btnRowW)/2;

  // Left button (Save)
  if (modalChoiceIndex == 0) {
    u8g2.drawRBox(rowX, btnY, leftW, btnH, btnRad);        // filled
    u8g2.setDrawColor(1);                                   // white text
    int tW = u8g2.getUTF8Width(leftLbl);
    u8g2.drawUTF8(rowX + (leftW - tW)/2, btnY + btnH - 3, leftLbl);
    u8g2.setDrawColor(0);
  } else {
    u8g2.drawRFrame(rowX, btnY, leftW, btnH, btnRad);      // outline
    int tW = u8g2.getUTF8Width(leftLbl);
    u8g2.drawUTF8(rowX + (leftW - tW)/2, btnY + btnH - 3, leftLbl);
  }

  // Right button (Delete)
  int rx = rowX + leftW + gapBtns;
  if (modalChoiceIndex == 1) {
    u8g2.drawRBox(rx, btnY, rightW, btnH, btnRad);
    u8g2.setDrawColor(1);
    int tW = u8g2.getUTF8Width(rightLbl);
    u8g2.drawUTF8(rx + (rightW - tW)/2, btnY + btnH - 3, rightLbl);
    u8g2.setDrawColor(0);
  } else {
    u8g2.drawRFrame(rx, btnY, rightW, btnH, btnRad);
    int tW = u8g2.getUTF8Width(rightLbl);
    u8g2.drawUTF8(rx + (rightW - tW)/2, btnY + btnH - 3, rightLbl);
  }

  u8g2.setDrawColor(1);
}

// -------- dessin cellule ----------
static void drawStepCircleCell(int cx, int cy, uint8_t r, bool isSelected, bool isPlayhead, bool isRest) {
  u8g2.setDrawColor(1);
  if (isSelected) {
    u8g2.drawDisc(cx, cy, r);
    u8g2.setDrawColor(0);
    if (r > 1) u8g2.drawCircle(cx, cy, r-1);
    u8g2.setDrawColor(1);
  } else {
    u8g2.drawCircle(cx, cy, r);
  }
  if (isRest) {
    u8g2.drawLine(cx-(r-1), cy+(r-1), cx+(r-1), cy-(r-1));
  }
  if (isPlayhead) {
    int px = cx + r + 1;
    int py = cy - 1;
    if (px <= 126) u8g2.drawBox(px, py, 3, 3);
  }
}

// Vue principale de SEQ EDIT (grille + infos)
void drawEditSeqScreen() {
  u8g2.setFont(u8g2_font_6x10_tf);

  if (seqLen > 0 && editStep >= seqLen) editStep = seqLen - 1;
  const uint8_t sel  = (seqLen > 0) ? editStep       : 0;
  const uint8_t page = (seqLen > 0) ? (sel / 16)     : 0;         // 0 or 1
  const uint8_t base = page * 16;
  const uint8_t last = (seqLen > (base + 16)) ? (base + 16) : seqLen; // exclusive

  // Grid on the left
  const int gridLeft = 2;
  const int top      = 8;     // no title → move grid up
  const int cols     = 4;
  const int r        = 4;     // circle radius (8px diameter)
  const int hGap     = 6, vGap = 6;
  const int cellW    = (r*2) + hGap;
  const int cellH    = (r*2) + vGap;

  for (uint8_t i = 0; i < 16; ++i) {
    const uint8_t s = base + i;
    if (s >= last) break;

    const int row = i / cols;
    const int col = i % cols;
    const int cx  = gridLeft + col * cellW + r;
    const int cy  = top      + row * cellH + r;

    const bool rest  = (!seqActive[s]) || (seqTime[s] == 0);
    const bool isSel = (s == sel);

    drawStepCircleCell(cx, cy, r, isSel, /*isPlayhead=*/false, rest);
  }

  // Top-right page counter: NN/16 (right-aligned)
  {
    char stepsBuf[12];
    if (seqLen > 0) snprintf(stepsBuf, sizeof(stepsBuf), "%02d/%02d", (int)(sel + 1), (int)seqLen);
    else            snprintf(stepsBuf, sizeof(stepsBuf), "00/00");
    drawRightAligned(top, stepsBuf, /*margin*/2);
  }

  if (seqLen == 0) return;

  // Right-side info anchored at bottom-right
  const int baseY = 62;   // bottom baseline
  const int lineH = 12;

  // K:xx NOTE
  char noteBuf[8], kLine[20];
  if (seqKeys[sel] >= 1 && seqKeys[sel] <= 12) {
    noteNameForKey(seqKeys[sel], noteBuf, sizeof(noteBuf));
    snprintf(kLine, sizeof(kLine), "K:%02d %s", seqKeys[sel], noteBuf);
  } else {
    snprintf(kLine, sizeof(kLine), "K:-- --");
  }
  drawRightAligned(baseY - 2*lineH, kLine, 2);

  // T:...
  char tLine[12];
  {
    int8_t t = seqTime[sel];
    if      (t == -1) snprintf(tLine, sizeof(tLine), "T:1/2");
    else if (t == 0 ) snprintf(tLine, sizeof(tLine), "T:0");
    else              snprintf(tLine, sizeof(tLine), "T:%dx", (int)t);
  }
  drawRightAligned(baseY - 1*lineH, tLine, 2);

  // R/G/V or _ _ _
  char toggles[8];
  const char rCh = seqRetrig [sel] ? 'R' : '_';
  const char gCh = seqGlide  [sel] ? 'G' : '_';
  const char vCh = seqVibrato[sel] ? 'V' : '_';
  snprintf(toggles, sizeof(toggles), "%c %c %c", rCh, gCh, vCh);
  drawRightAligned(baseY, toggles, 2);
}

// --- Draw the 4x3 key grid (squares), center horizontally, highlight lastTouchedKey ---
static void drawKeyEditGrid() {
  const int cols = 4, rows = 3;
  const int cell = 12;
  const int gapX = 6, gapY = 6;
  const int gridW = cols * cell + (cols - 1) * gapX;
  const int gridH = rows * cell + (rows - 1) * gapY;
  const int left  = (128 - gridW) / 2;
  const int top   = (64  - gridH) / 2;

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      uint8_t k = r * cols + c + 1;   // 1..12
      int x = left + c * (cell + gapX);
      int y = top  + r * (cell + gapY);

      if (k == lastTouchedKey && k >= 1 && k <= 12) {
        u8g2.drawBox(x, y, cell, cell);
        u8g2.setDrawColor(0);
        u8g2.drawFrame(x+1, y+1, cell-2, cell-2);
        u8g2.setDrawColor(1);
      } else {
        u8g2.drawFrame(x, y, cell, cell);
      }
    }
  }

  // Info en haut-droite: K:nn NOTE
  if (lastTouchedKey >= 1 && lastTouchedKey <= 12) {
    char noteBuf[8];
    noteNameForKey(lastTouchedKey, noteBuf, sizeof(noteBuf));
    char kbuf[20];
    snprintf(kbuf, sizeof(kbuf), "K:%02d %s", lastTouchedKey, noteBuf);
    u8g2.setFont(u8g2_font_6x10_tf);
    drawRightAligned(10, kbuf, 2);
  }
}

static void drawKeyNoteOverlay() {
  if (currentKey < 1 || currentKey > 12) return;

  u8g2.clearBuffer();

  int semi     = tabNote[currentKey - 1];
  int semiPrev = max(0,  semi - 1);
  int semiNext = min(95, semi + 1);

  char cur[8], prv[8], nxt[8];
  noteNameFromSemi(semi,     cur, sizeof(cur));
  noteNameFromSemi(semiPrev, prv, sizeof(prv));
  noteNameFromSemi(semiNext, nxt, sizeof(nxt));

  // Top-right: K:xx
  u8g2.setFont(u8g2_font_6x10_tf);
  char kbuf[10]; snprintf(kbuf, sizeof(kbuf), "K:%02d", currentKey);
  drawRightAligned(10, kbuf, 2);

  // Center note — big
  u8g2.setFont(u8g2_font_fub20_tf);
  int wCur = u8g2.getUTF8Width(cur);
  int xCur = (128 - wCur) / 2;
  int yCur = 46;
  u8g2.drawUTF8(xCur, yCur, cur);

  // Prev/Next
  u8g2.setFont(u8g2_font_10x20_tf);
  int ySide = yCur;
  u8g2.drawUTF8(2,  ySide, prv);
  drawRightAligned(ySide, nxt, 2);

  sendOledBufferShifted();
}

void drawEditKeyScreen() {
  if (keyNoteOverlayActive) {
    drawKeyNoteOverlay();
    return;
  }
  u8g2.clearBuffer();
  drawKeyEditGrid();
  sendOledBufferShifted();
}

void drawRecSeqScreen() {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.clearBuffer();

  // Title
  //drawModeTitle(); // should show "RECORD"

  // Geometry: 4 rows × 8 cols
  const int cols = 8;
  const int r    = 4;     // circle radius
  const int gapX = 6;     // horizontal gap between circles
  const int gapY = 6;     // vertical gap
  const int top  = 16;    // leave room for the title
  const int left = 2;

  // We draw only:
  //  - Filled discs for recorded steps [0 .. seqLen-1]
  //  - ONE hollow circle at the next slot (seqLen), if seqLen < SEQ_MAX
  const int nextIndex = (seqLen < SEQ_MAX) ? seqLen : -1;

  auto drawDot = [&](int i, bool filled, bool selected) {
    int row = i / cols;        // 0..3
    int col = i % cols;        // 0..7
    int cx  = left + col * ((2*r) + gapX) + r;
    int cy  = top  + row * ((2*r) + gapY) + r;

    u8g2.setDrawColor(1);
    if (filled) {
      if (selected) {
        u8g2.drawDisc(cx, cy, r);
        u8g2.setDrawColor(0);
        if (r > 1) u8g2.drawCircle(cx, cy, r-1);
        u8g2.setDrawColor(1);
      } else {
        u8g2.drawDisc(cx, cy, r);
      }
    } else {
      u8g2.drawCircle(cx, cy, r);
    }
  };

  // 1) Draw all recorded steps (filled)
  for (int i = 0; i < seqLen; ++i) {
    bool isLast = (i == (seqLen - 1));
    drawDot(i, /*filled=*/true, /*selected=*/isLast);
  }

  // 2) Draw the "next" hollow circle (only one), or step 1 if empty
  if (nextIndex >= 0 && nextIndex < SEQ_MAX) {
    drawDot(nextIndex, /*filled=*/false, /*selected=*/false);
  }

  // Top-right counter: "current step / current length"
  // Here "current step" is the next slot index (1-based), unless full.
  {
    char buf[12];
    int cur = (seqLen < SEQ_MAX) ? (seqLen + 1) : seqLen;
    snprintf(buf, sizeof(buf), "%02d/%02d", cur, (int)seqLen);
    drawRightAligned(10, buf, 2);
  }

  // Bottom-right: last recorded K:nn NOTE (or placeholders)
  if (seqLen > 0) {
    uint8_t k = seqKeys[seqLen - 1];
    char noteBuf[8], kLine[20];
    if (k >= 1 && k <= 12) {
      noteNameForKey(k, noteBuf, sizeof(noteBuf));
      snprintf(kLine, sizeof(kLine), "K:%02d %s", k, noteBuf);
    } else {
      snprintf(kLine, sizeof(kLine), "K:-- --");
    }
    drawRightAligned(62, kLine, 2);
  } else {
    drawRightAligned(62, "K:-- --", 2);
  }

  // Draw any modal message on top
  drawModalIfAny();
  sendOledBufferShifted();
}

static inline void serviceKeyOverlayTimeout() {
  if (keyNoteOverlayActive && (int32_t)(millis() - keyNoteOverlayUntilMs) >= 0) {
    keyNoteOverlayActive = false;
    markUI();
  }
}

/*** Settings pages (no Save/Load) ********************************************/
void drawSettings() {
  drawListWithReturn("SETTINGS", kSettingsItems, SETTINGS_MENU_COUNT, settingsIndex, /*showReturn=*/true);
}

static void drawNameEditor() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_7x13B_tf);
  u8g2.drawUTF8(24, 12, "NAME SLOT");

  // Draw editable row centered
  u8g2.setFont(u8g2_font_7x13_tf);
  int y = 40;
  int totalW = u8g2.getUTF8Width(nameBuf);
  int x = (128 - totalW) / 2;
  // draw string
  u8g2.drawUTF8(x, y, nameBuf);

  // cursor invert block on current char
  // measure width up to cursor
  char tmp[18]; strncpy(tmp, nameBuf, min((int)nameCursor, 16)); tmp[min((int)nameCursor, 16)] = 0;
  int preW = u8g2.getUTF8Width(tmp);
  int cw   = u8g2.getUTF8Width("M");       // approx fixed cell width
  u8g2.drawBox(x + preW, y - 11, cw, 13);
  u8g2.setDrawColor(0);
  char cur[2] = { nameBuf[nameCursor], 0 };
  u8g2.drawUTF8(x + preW, y, cur);
  u8g2.setDrawColor(1);

  // tiny hint
  u8g2.setFont(u8g2_font_5x8_tf);
  u8g2.drawUTF8(10, 62, "Turn: change  Click: next  Long: save  Dbl: cancel");

  sendOledBufferShifted();
}

void drawSaveLoadSlots() {
  drawListHeader("SAVE/LOAD");

  static char rows[NUM_SLOTS][22];
  static const char* ptrs[NUM_SLOTS];

  for (int i=0;i<NUM_SLOTS;i++){
    BlobHeader h; EEPROM.get(slotHeaderAddr(i), h);
    bool used = (h.magic==KSQ_MAGIC) && (h.flags&1);

    const char* suffix = used ? "[USED]" : "[EMPTY]";
    char name16[17]; name16[0]=0;

    if (used && h.length == sizeof(SequenceBlob_v2)) {
      SequenceBlob_v2 b2; EEPROM.get(slotPayloadAddr(i), b2);
      // ensure null-terminated
      memcpy(name16, b2.name, 16); name16[16] = 0;
    }

    if (used && name16[0]) {
      snprintf(rows[i], sizeof(rows[i]), "Slot %d  %s  %s", i+1, suffix, name16);
    } else {
      snprintf(rows[i], sizeof(rows[i]), "Slot %d  %s", i+1, suffix);
    }
    ptrs[i] = rows[i];
  }
  drawListWithReturn("SAVE/LOAD", ptrs, NUM_SLOTS, saveLoadSlotIndex, /*showReturn=*/true);
}

void drawSlotActions() {
  static const char* items[] = {"Save", "Load", "Clear"};
  char head[20]; snprintf(head, sizeof(head), "Slot %d", saveLoadSlotIndex+1);
  drawListWithReturn(head, items, 3, slotActionIndex, /*showReturn=*/true);
}

void drawGeneral() {
  drawListHeader("GENERAL");
  u8g2.setFont(u8g2_font_7x13_tf);
  char l1[24], l2[24];
  snprintf(l1, sizeof(l1), "V0  : %0.3f V", V0_meas);
  snprintf(l2, sizeof(l2), "Vfs : %0.3f V", Vfs_meas);
  u8g2.drawUTF8(6, 30, l1);
  u8g2.drawUTF8(6, 46, l2);
  u8g2.drawUTF8(6, 62, "Click: exit");
}

void drawClockPage() {
  drawListHeader("CLOCK");
  u8g2.setFont(u8g2_font_7x13_tf);
  char l1[28];
  float ms = lastGoodPeriodUs/1000.0f;
  snprintf(l1, sizeof(l1), "Period: %0.2f ms", ms);
  u8g2.drawUTF8(6, 30, l1);
  u8g2.drawUTF8(6, 46, "Click: exit");
}

/*** Parameters pages (EDITSEQ) ***********************************************/
void drawParamMenu() {
  static const char* items[] = {"TIME", "RETRIG", "GLIDE", "VIBRATO"};
  drawListWithReturn("PARAMETERS", items, 4, paramIndex, /*showReturn=*/true);
}

void drawParamTime() {
  // 10 values: -1, 0, 1..8 (index 0..9), index 10 is RETURN (drawListWithReturn adds return)
  static char rows[10][14];
  static const char* ptrs[10];
  snprintf(rows[0], sizeof(rows[0]), "-1  (1/2)");
  snprintf(rows[1], sizeof(rows[1]), "0   (REST)");
  for (int v = 1; v <= 8; ++v) snprintf(rows[v+1], sizeof(rows[v+1]), "%d   clk", v);
  for (int i = 0; i < 10; ++i) ptrs[i] = rows[i];
  drawListWithReturn("TIME", ptrs, 10, timeSelIndex, /*showReturn=*/true);
}

void drawParamToggle(const char* title, int selected) {
  static const char* items[] = {"OFF", "ON"};
  drawListWithReturn(title, items, 2, selected, /*showReturn=*/true);
}

/*** Base screen (IDLE/EDITKEY/RECSEQ/EDITSEQ) ********************************/
void drawScreen() {
  u8g2.clearBuffer();

  if (nameEditActive) { 
    drawNameEditor(); 
    return; 
  }

  // SETTINGS overlays
  if (settingsState != S_NONE) {
    switch (settingsState) {
      case S_MENU:        drawSettings(); break;
      case S_GENERAL:     drawGeneral(); break;
      case S_CLOCK:       drawClockPage(); break;
      case S_CALIB:     drawCalibrationPage(); break;
      case S_SAVELOAD:    drawSaveLoadSlots(); break;
      case S_SLOT_ACTION: drawSlotActions(); break;
      default:           drawSettings(); break;
    }
    // Draw "SETTINGS" only on the root menu
    if (settingsState == S_MENU) {
      u8g2.setFont(u8g2_font_6x10_tf);
      u8g2.drawUTF8(40, 10, "SETTINGS");
    }
    drawModalIfAny();
    sendOledBufferShifted();
    return;
  }

  // PARAMETER overlays (EDITSEQ)
  if (paramState != P_NONE) {
    switch (paramState) {
      case P_MENU:     drawParamMenu(); break;
      case P_TIME:     drawParamTime(); break;
      case P_RETRIG:   drawParamToggle("RETRIG",  boolSelIndex); break;
      case P_GLIDE:    drawParamToggle("GLIDE",   boolSelIndex); break;
      case P_VIBRATO:  drawParamToggle("VIBRATO", boolSelIndex); break;
      default:         drawParamMenu(); break;
    }
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawUTF8(34, 10, "SEQ PARAMETERS");
    drawModalIfAny();
    sendOledBufferShifted();
    return;
  }

  // MODES MENU overlay
  if (modesState == M_MENU) {
    drawModesMenu();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawUTF8(52, 10, "MODE");
    drawModalIfAny();
    sendOledBufferShifted();
    return;
  }

  // --- REC screen
  if (currentMode == RECSEQ) { drawRecSeqScreen(); return; } 

  // --- SEQ EDIT : dedicated view ---
  if (currentMode == EDITSEQ) { drawEditSeqScreen(); sendOledBufferShifted(); return; }

  // --- EDIT KEY screen
  if (currentMode == EDITKEY) { drawEditKeyScreen(); return; }

  // ---------- Determine which key to highlight (1..12) ----------
  uint8_t hiKey = 0;
  if (keyOverride && overrideKey >= 1 && overrideKey <= 12) {
    hiKey = overrideKey;
  } else if (seqLen > 0 && seqKeys[playhead] >= 1 && seqKeys[playhead] <= 12) {
    hiKey = seqKeys[playhead];
  } else if (currentKey >= 1 && currentKey <= 12) {
    hiKey = currentKey;
  }

  // ---------- Compute note text (bottom-right) ----------
  char noteStr[6] = "";
  {
    int showSemi = 0;
    if (keyOverride && overrideKey >= 1 && overrideKey <= 12) {
      showSemi = tabNote[overrideKey - 1];
    } else if (seqLen > 0) {
      uint8_t k = seqKeys[playhead];
      if (k >= 1 && k <= 12) {
        int base = tabNote[k - 1];
        int pc   = base % 12;
        int oct  = base / 12;
        int effOct = constrain(oct + effectiveOctaveOffset(), 0, 7);
        showSemi = pc + 12 * effOct;
      }
    } else if (currentKey >= 1 && currentKey <= 12) {
      showSemi = tabNote[currentKey - 1];
    }
    static const char* nn[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    int pc = (showSemi % 12 + 12) % 12;
    int oct = showSemi / 12;
    if (showSemi < 0 && (showSemi % 12)) oct--;
    snprintf(noteStr, sizeof(noteStr), "%s%d", nn[pc], oct);
  }

  // ---------- Header: K and S ----------
  const uint8_t headerY = 12;
  u8g2.setFont(u8g2_font_7x13_tf);
  {
    char kbuf[8];
    if (hiKey) snprintf(kbuf, sizeof(kbuf), "%02d", hiKey);
    else       snprintf(kbuf, sizeof(kbuf), "--");
    u8g2.drawStr(0, headerY, "K:");
    int kpx = u8g2.getStrWidth("K:");
    u8g2.setFont(u8g2_font_7x13B_tf);
    u8g2.drawStr(kpx, headerY, kbuf);
  }
  {
    char sbuf[8];
    if (seqLen > 0) snprintf(sbuf, sizeof(sbuf), "%02d", playhead + 1);
    else            snprintf(sbuf, sizeof(sbuf), "--");
    u8g2.setFont(u8g2_font_7x13_tf);
    int sw = u8g2.getStrWidth("S:") + u8g2.getStrWidth(sbuf);
    int x  = 128 - sw;
    u8g2.drawStr(x, headerY, "S:");
    int px = u8g2.getStrWidth("S:");
    u8g2.setFont(u8g2_font_7x13B_tf);
    u8g2.drawStr(x + px, headerY, sbuf);
  }

  // ---------- 4×3 grid ----------
  const uint8_t cols = 4, rows = 3;
  const uint8_t cellW = 12, cellH = 12, gapX  = 6, gapY  = 6;
  const uint8_t gridWidth  = cols * cellW + (cols - 1) * gapX;
  const uint8_t gridLeft   = (128 - gridWidth) / 2;
  const uint8_t gridTop    = 16;

  for (uint8_t r = 0; r < rows; r++) {
    for (uint8_t c = 0; c < cols; c++) {
      uint8_t k = r * cols + c + 1;
      uint8_t x = gridLeft + c * (cellW + gapX);
      uint8_t y = gridTop  + r * (cellH + gapY);

      if (k == hiKey) {
        u8g2.drawBox(x, y, cellW, cellH);
        u8g2.setDrawColor(0);
        u8g2.drawFrame(x+1, y+1, cellW-2, cellH-2);
        u8g2.setDrawColor(1);
      } else {
        u8g2.drawFrame(x, y, cellW, cellH);
      }
    }
  }

  // ---------- Bottom-right note ----------
  u8g2.setFont(u8g2_font_7x13_tf);
  int nw = u8g2.getStrWidth(noteStr);
  int nx = 128 - nw;
  int ny = 63;
  u8g2.drawUTF8(nx, ny, noteStr);

    // ---------- Bottom-left transpose (IDLE only) ----------
  if (currentMode == IDLE) {
    char tbuf[10];
    snprintf(tbuf, sizeof(tbuf), "T:%+d", (int)seqOctaveOffset); // e.g., T:+1, T:0, T:-2
    u8g2.drawUTF8(2, ny, tbuf);
  }

  drawModalIfAny();
  sendOledBufferShifted();


}

/*** EEPROM *******************************************************************/
static inline int nameCharIndexOf(char c) {
  for (uint8_t i=0;i<NAME_CHARS_COUNT;i++) if (NAME_CHARS[i]==c) return i;
  return 0; // default to space if not found
}

static void startNameEditor(uint8_t slotIdx, const char* initial) {
  pendingSlotIdx  = slotIdx;
  nameMaxChars    = 16;
  // seed buffer
  size_t n = 0;
  if (initial) {
    while (initial[n] && n < nameMaxChars) { nameBuf[n] = initial[n]; n++; }
  }
  while (n < nameMaxChars) nameBuf[n++] = ' ';
  nameBuf[nameMaxChars] = '\0';
  nameCursor     = 0;
  nameEditActive = true;
  markUI();
}

static void finishNameEditor(bool saveIt) {
  trimTrailingSpaces(nameBuf);
  if (saveIt) {
    bool ok = saveSlotWithName(pendingSlotIdx, (nameBuf[0] ? nameBuf : "UNTITLED"));
    showModalOK(ok ? "Saved." : "Save failed.");
  }
  nameEditActive = false;
  markUI();
}

static char nextCharInSet(char c, int dir) {
  int n = (int)strlen(kNameSet);
  int idx = 0;
  const char* p = strchr(kNameSet, c);
  if (p) idx = (int)(p - kNameSet);
  idx = (idx + (dir > 0 ? 1 : -1) + n) % n;
  return kNameSet[idx];
}

static void trimTrailingSpaces(char* s) {
  int len = (int)strlen(s);
  while (len > 0 && s[len-1] == ' ') s[--len] = 0;
}

static void prepareDefaultNameForSlot(uint8_t slot, char* out, size_t outsz) {
  // If slot already has a name, reuse it; else "SLOT n"
  if (readSlotName(slot, out, outsz)) {
    if (out[0] != 0) return;
  }
  snprintf(out, outsz, "SLOT %u", (unsigned)(slot+1));
}

// Read name without trusting version (only when used); returns true if readable
static bool readSlotName(uint8_t slot, char* out, size_t outsz) {
  if (out && outsz) out[0] = 0;
  if (slot >= NUM_SLOTS) return false;

  BlobHeader h; EEPROM.get(slotHeaderAddr(slot), h);
  if (h.magic != KSQ_MAGIC || (h.flags & 1) == 0) return false;

  if (h.version == 0x0003 && h.length == sizeof(SequenceBlob_v2)) {
    SequenceBlob_v2 b2; EEPROM.get(slotPayloadAddr(slot), b2);
    if (out && outsz) { strncpy(out, b2.name, outsz-1); out[outsz-1]=0; }
    return true;
  }

  // older slot has no name
  if (out && outsz) out[0] = 0;
  return true;
}

// Save "globals" (calibration) from RAM → struct and back
static void saveGlobalSettingsToRAM(GlobalSettings &g) {
  g.V0_meas  = V0_meas;
  g.Vfs_meas = Vfs_meas;
}

static void loadGlobalSettingsFromRAM(const GlobalSettings &g) {
  V0_meas  = g.V0_meas;
  Vfs_meas = g.Vfs_meas;
}

// Sequence: RAM → blob
static void fillSequenceBlobFromRAM(SequenceBlob &b) {
  b.seqLen = seqLen;
  for (int i=0;i<SEQ_MAX;i++){
    b.seqKeys[i]    = seqKeys[i];
    b.seqActive[i]  = seqActive[i] ? 1 : 0;
    b.seqTime[i]    = seqTime[i];
    b.seqRetrig[i]  = seqRetrig[i] ? 1 : 0;
    b.seqVibrato[i] = seqVibrato[i] ? 1 : 0;
    b.seqGlide[i]   = seqGlide[i] ? 1 : 0;
  }
  b.seqOctaveOffset = seqOctaveOffset;
  for (int i=0;i<12;i++) b.tabNote[i] = (uint8_t)constrain(tabNote[i], 0, 95);
  b.glideShape   = (uint8_t)glideShape;
  b.vibRateHz    = vibRateHz;
  b.vibDepthCents= vibDepthCents;
}

// v2: RAM → blob
static void fillSequenceBlobV2FromRAM(SequenceBlob_v2 &b) {
  b.seqLen = seqLen;
  for (int i=0;i<SEQ_MAX;i++){
    b.seqKeys[i]    = seqKeys[i];
    b.seqActive[i]  = seqActive[i] ? 1 : 0;
    b.seqTime[i]    = seqTime[i];
    b.seqRetrig[i]  = seqRetrig[i] ? 1 : 0;
    b.seqVibrato[i] = seqVibrato[i] ? 1 : 0;
    b.seqGlide[i]   = seqGlide[i] ? 1 : 0;
  }
  b.seqOctaveOffset = seqOctaveOffset;
  for (int i=0;i<12;i++) b.tabNote[i] = (uint8_t)constrain(tabNote[i], 0, 95);
  b.glideShape    = (uint8_t)glideShape;
  b.vibRateHz     = vibRateHz;
  b.vibDepthCents = vibDepthCents;
  for (int i=0;i<16;i++) b.name[i] = 0;
}

// v2: blob → RAM  (overload)
static void applySequenceBlobToRAM(const SequenceBlob_v2 &b) {
  seqLen = constrain(b.seqLen, 0, (uint8_t)SEQ_MAX);
  for (int i=0;i<SEQ_MAX;i++){
    seqKeys[i]    = b.seqKeys[i];
    seqActive[i]  = (b.seqActive[i] != 0);
    seqTime[i]    = (int8_t)constrain((int)b.seqTime[i], -1, 8);
    seqRetrig[i]  = (b.seqRetrig[i] != 0);
    seqVibrato[i] = (b.seqVibrato[i] != 0);
    seqGlide[i]   = (b.seqGlide[i] != 0);
  }
  seqOctaveOffset = constrain((int)b.seqOctaveOffset, -7, 7);
  for (int i=0;i<12;i++) tabNote[i] = (int)constrain(b.tabNote[i], 0, 95);
  glideShape    = (GlideShape)constrain((int)b.glideShape, 0, 2);
  vibRateHz     = b.vibRateHz;
  vibDepthCents = b.vibDepthCents;

  // reset running state
  playhead = 0;
  subStepActive = false;
  gateHoldOff();
  vibEnabledNow = false;
  glideActiveNow = false;
  ticksLeftForStep = 0;
  retrigHold = false;
}

static void applySequenceBlobToRAM(const SequenceBlob &b) {
  seqLen = constrain(b.seqLen, 0, (uint8_t)SEQ_MAX);
  for (int i=0;i<SEQ_MAX;i++){
    seqKeys[i]    = b.seqKeys[i];
    seqActive[i]  = (b.seqActive[i] != 0);
    seqTime[i]    = (int8_t)constrain((int)b.seqTime[i], -1, 8);
    seqRetrig[i]  = (b.seqRetrig[i] != 0);
    seqVibrato[i] = (b.seqVibrato[i] != 0);
    seqGlide[i]   = (b.seqGlide[i] != 0);
  }
  seqOctaveOffset = constrain((int)b.seqOctaveOffset, -7, 7);
  for (int i=0;i<12;i++) tabNote[i] = (int)constrain(b.tabNote[i], 0, 95);
  glideShape    = (GlideShape)constrain((int)b.glideShape, 0, 2);
  vibRateHz     = b.vibRateHz;
  vibDepthCents = b.vibDepthCents;

  // reset running state
  playhead = 0;
  subStepActive = false;
  gateHoldOff();
  vibEnabledNow = false;
  glideActiveNow = false;
  ticksLeftForStep = 0;
  retrigHold = false;
}


static bool saveGlobals() {
  GlobalSettings gs; saveGlobalSettingsToRAM(gs);
  BlobHeader h;
  h.magic = KSQ_MAGIC;
  h.version = KSQ_VERS;
  h.length = sizeof(GlobalSettings);
  h.crc = crc16_ccitt((const uint8_t*)&gs, sizeof(gs));
  h.flags = 1;
  EEPROM.put(GLOBAL_HDR_ADDR, h);
  EEPROM.put(GLOBAL_PAY_ADDR, gs);
  eepromCommitIfNeeded();
  return true;
}

static bool loadGlobals() {
  BlobHeader h; EEPROM.get(GLOBAL_HDR_ADDR, h);
  if (h.magic != KSQ_MAGIC || h.version != KSQ_VERS || h.length != sizeof(GlobalSettings) || (h.flags & 1) == 0) {
    return false;
  }
  GlobalSettings gs; EEPROM.get(GLOBAL_PAY_ADDR, gs);
  uint16_t crc = crc16_ccitt((const uint8_t*)&gs, sizeof(gs));
  if (crc != h.crc) return false;

  // Validate ranges; if invalid, signal failure so defaults are used.
  float span = gs.Vfs_meas - gs.V0_meas;
  bool ok = (gs.V0_meas >= -0.2f && gs.V0_meas <= 0.5f) &&
            (gs.Vfs_meas >= 7.7f && gs.Vfs_meas <= 8.5f) &&
            (span >= 0.5f);
  if (!ok) return false;

  loadGlobalSettingsFromRAM(gs);
  return true;
}

static bool saveSlotWithName(uint8_t slotIdx0, const char* name16) {
  if (slotIdx0 >= NUM_SLOTS) return false;

  SequenceBlob_v2 b; 
  fillSequenceBlobV2FromRAM(b);

  // copy (truncate) name
  memset(b.name, 0, 16);
  if (name16 && name16[0]) {
    size_t n = min((size_t)16, strlen(name16));
    memcpy(b.name, name16, n);
  }

  BlobHeader h;
  h.magic   = KSQ_MAGIC;
  h.version = 0x0003;                        // NEW version for named slots
  h.length  = sizeof(SequenceBlob_v2);
  h.crc     = crc16_ccitt((const uint8_t*)&b, sizeof(b));
  h.flags   = 1;

  EEPROM.put(slotHeaderAddr(slotIdx0), h);
  EEPROM.put(slotPayloadAddr(slotIdx0), b);
  eepromCommitIfNeeded();
  return true;
}

// Keep old helper (fallback default name)
static bool saveSlot(uint8_t slotIdx0) {
  char def[16]; prepareDefaultNameForSlot(slotIdx0, def, sizeof(def));
  return saveSlotWithName(slotIdx0, def);
}

static bool loadSlot(uint8_t slotIdx0) {
  if (slotIdx0 >= NUM_SLOTS) return false;

  const int ha = slotHeaderAddr(slotIdx0);
  const int pa = slotPayloadAddr(slotIdx0);

  BlobHeader h; EEPROM.get(ha, h);
  if (h.magic != KSQ_MAGIC || (h.flags & 1) == 0) return false;

  if (h.version == 0x0001 && h.length == sizeof(SequenceBlob)) {
    SequenceBlob b1; EEPROM.get(pa, b1);
    uint16_t crc = crc16_ccitt((const uint8_t*)&b1, sizeof(b1));
    if (crc != h.crc) return false;
    applySequenceBlobToRAM(b1);        // v1 apply
    return true;

  } else if (h.version == 0x0003 && h.length == sizeof(SequenceBlob_v2)) {
    SequenceBlob_v2 b2; EEPROM.get(pa, b2);
    uint16_t crc = crc16_ccitt((const uint8_t*)&b2, sizeof(b2));
    if (crc != h.crc) return false;
    applySequenceBlobToRAM(b2);        // v2 apply
    return true;
  }

  return false; // unknown version/size
}


static bool clearSlot(uint8_t slotIdx0) {
  if (slotIdx0 >= NUM_SLOTS) return false;
  BlobHeader h; memset(&h, 0, sizeof(h));
  EEPROM.put(slotHeaderAddr(slotIdx0), h);
  eepromCommitIfNeeded();
  return true;
}

// Write current RAM globals into a struct
static void packGlobals(GlobalSettings &g) {
  g.V0_meas       = V0_meas;
  g.Vfs_meas      = Vfs_meas;
  g.clockDiv      = g_clockDiv;
  g.ledBrightness = g_ledBrightness;
}

// Copy struct values back into runtime globals
static void applyGlobals(const GlobalSettings &g) {
  V0_meas        = g.V0_meas;
  Vfs_meas       = g.Vfs_meas;
  g_clockDiv     = g.clockDiv ? g.clockDiv : 1;   // never 0
  g_ledBrightness= g.ledBrightness;
}

// Sane defaults if nothing was stored yet
static void setDefaultGlobals() {
  V0_meas         = 0.001f;
  Vfs_meas        = 8.10f;
  g_clockDiv      = 2;
  g_ledBrightness = 255;
}

static void applyGlobalsToHardware() {
  // LED brightness (example)
  // analogWrite(LED_PIN, g_ledBrightness);     // if using a PWM LED
  // or set PWM slice on RP2040 as needed.

  // Clock division is used by ISR; no direct hardware call needed here.
}

/* Helpers for calibration ****************************************************/
// Format "00.000 V" from millivolts
static inline void format_mV_str(char* out, size_t n, int mv) {
  mv = constrain(mv, 0, 12000);
  int V = mv / 1000;
  int m = mv % 1000;
  snprintf(out, n, "%d.%03dV", V, m);
}

// Clamp helpers and place steps (in millivolts)
static inline int clampV0mV(int v){ return constrain(v, 0, 2000); }    // 0.000 .. 2.000V
static inline int clampVFSmV(int v){ return constrain(v, 1000, 9000); } // 1.000 .. 9.000 V
static inline int placeStep_mV(uint8_t pos) {
  switch (pos) {
    case 0: return 1000;  // 1.000 V
    case 1: return 100;   // 0.100 V
    case 2: return 10;    // 0.010 V
    default: return 1;    // 0.001 V
  }
}

// Compact "0.000 V" editor with tight spacing.
// cursorPos: 0=integer, 1=0.1, 2=0.01, 3=0.001, other=no highlight
static void   drawValueEditor_0_000V(int x, int y, int mv, uint8_t cursorPos){
  // clamp to what we can display (0.000 .. 9.999 V)
  mv = constrain(mv, 0, 9999);

  int ones = (mv / 1000) % 10;  // integer digit
  int d1   = (mv / 100)  % 10;  // 0.1
  int d2   = (mv / 10)   % 10;  // 0.01
  int d3   =  mv % 10;          // 0.001

  // Build glyphs: [ones][.][d1][d2][d3]
  const char g0[2] = { char('0' + ones), 0 };
  const char g1[]  = ".";
  const char g2[2] = { char('0' + d1), 0 };
  const char g3[2] = { char('0' + d2), 0 };
  const char g4[2] = { char('0' + d3), 0 };
  const char* glyphs[5] = { g0, g1, g2, g3, g4 };

  // Map cursor position to glyph index
  int hiIndex = -1;
  if      (cursorPos == 0) hiIndex = 0; // integer
  else if (cursorPos == 1) hiIndex = 2; // 0.1
  else if (cursorPos == 2) hiIndex = 3; // 0.01
  else if (cursorPos == 3) hiIndex = 4; // 0.001

  // Use current font metrics for tight boxes
  const int ascent  = u8g2.getAscent();    // +ve
  const int descent = u8g2.getDescent();   // <= 0
  const int boxTop  = y - ascent;
  const int boxH    = ascent - descent;

  // Spacing & padding (tweak to taste)
  const int padX = 1;   // horizontal padding inside highlight box
  const int padY = 1;   // vertical padding inside highlight box
  const int gapX = 1;   // gap between glyphs

  int cx = x;
  for (int i = 0; i < 5; ++i) {
    int gw = u8g2.getUTF8Width(glyphs[i]);
    if (i == hiIndex) {
      u8g2.drawBox(cx - padX, boxTop - padY, gw + 2*padX, boxH + 2*padY);
      u8g2.setDrawColor(0);
      u8g2.drawUTF8(cx, y, glyphs[i]);
      u8g2.setDrawColor(1);
    } else {
      u8g2.drawUTF8(cx, y, glyphs[i]);
    }
    cx += gw + gapX;
  }

  // Small gap then "V"
  cx += 2;
  u8g2.drawUTF8(cx, y, "V");
}

static inline void setDACCode(uint16_t code) {
  if (code > 4095) code = 4095;
  analogWrite(PITCH_CV_PIN, 4095 - code);
  analogWrite(AUX_CV_PIN, 4095 - code);
}

static inline void setCalibRefOutput() {
  if (!calibRefActive) return;
  if (calibField == 0) setDACCode(0);       // V0 measurement
  else                 setDACCode(4095);    // VFS measurement
}

static inline void enterCalibrationRef() {
  calibRefActive = true;
  gateHoldOff(); trigActive = false;        // keep outputs quiet
  setCalibRefOutput();
}

static inline void leaveCalibrationRef() {
  calibRefActive = false;
  gateHoldOff(); trigActive = false;
}

//confirmation modal specifically for calibration
static inline void showModalConfirmCalib() {
  strncpy(modalMsg, "Save the calibration?", sizeof(modalMsg) - 1);
  modalMsg[sizeof(modalMsg) - 1] = 0;
  modalKind        = MODAL_CONFIRM_CALIB;
  modalChoiceIndex = 0;     // default highlight = "Save"
  modalActive      = true;
  markUI();
}

/*** I2C Scanners *************************************************************/
void scanBus(TwoWire &bus, const char* /*name*/) {
  for (uint8_t addr = 1; addr < 127; addr++) {
    bus.beginTransmission(addr);
    uint8_t err = bus.endTransmission();
    (void)err;
  }
}

// Persist the working sequence in flash-backed EEPROM slot 0.  A snapshot
// comparison prevents writes while the sequencer is merely running.
static void autosaveSequenceIfChanged() {
  static SequenceBlob_v2 previous;
  static bool havePrevious = false;
  static uint32_t lastWriteMs = 0;
  SequenceBlob_v2 current;
  fillSequenceBlobV2FromRAM(current);
  if (!havePrevious) {
    previous = current;
    havePrevious = true;
    return;
  }
  if (memcmp(&current, &previous, sizeof(current)) == 0) return;
  if (millis() - lastWriteMs < 500) return;
  if (saveSlotWithName(0, "AUTO")) {
    previous = current;
    lastWriteMs = millis();
  }
}
