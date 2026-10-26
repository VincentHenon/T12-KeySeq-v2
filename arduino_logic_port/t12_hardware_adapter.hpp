#pragma once

// Mapping matériel du T12 utilisé par le port de la logique Arduino.
// Ce fichier ne modifie pas encore le sketch copié ; il sert de contrat pour
// l'adaptateur Pico SDK qui remplacera les périphériques Arduino.
namespace t12_arduino_port {
constexpr unsigned MPR121_SDA = 0;
constexpr unsigned MPR121_SCL = 1;
constexpr unsigned RGB_DATA = 2;
constexpr unsigned CLOCK_IN = 3;
constexpr unsigned PITCH_CV_PWM = 4;
constexpr unsigned AUX_CV_PWM = 5;
constexpr unsigned RESET_IN = 6;
constexpr unsigned GATE_OUT = 7;
constexpr unsigned ENCODER_CLICK = 10;
constexpr unsigned ENCODER_A = 11;
constexpr unsigned ENCODER_B = 12;
constexpr unsigned OLED_DC = 16;
constexpr unsigned OLED_CS = 17;
constexpr unsigned OLED_SCK = 18;
constexpr unsigned OLED_MOSI = 19;
constexpr unsigned OLED_RESET = 20;
constexpr unsigned CV_IN_ADC = 26;
}
