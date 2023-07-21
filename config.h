/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#define VERSION "1.2.0"

// ===== DEBUG Settings ===== //
// #define ENABLE_DEBUG
#define DEBUG_PORT Serial
#define DEBUG_BAUD 115200

// ===== Storage Settings ===== //
#define READ_BUFFER 2048

// ===== Parser Settings ===== //
#define CASE_SENSETIVE false
#define DEFAULT_SLEEP 5

// ===== Other Stuff ====== //
#define PREFERENCES_PATH "preferences.json"

// ===== Pin Definitions ===== //

// USB Nova MKI (SAMD21)
#if defined(ARDUINO_QTPY_M0)
    #define LED_PIN 11
    #define SELECTOR A0

// USB Nova MKII (RP2040)
#elif defined(ARDUINO_GENERIC_RP2040)
    #define LED_PIN 12
    #define SELECTOR 13

// DIY USB Nova using Adafruit Trinkey (RP2040)
#elif defined(ARDUINO_ADAFRUIT_TRINKEYQT_RP2040)
    #define LED_PIN 27
    #define SELECTOR 12

// DIY USB Nova using Raspberry Pi Pico (RP2040)
#elif defined(ARDUINO_RASPBERRY_PI_PICO)
    #define LED_PIN -1
    #define SELECTOR 16

#else // if defined(ARDUINO_BOARD_QTPY_M0_NOVA)
    #error "No board defined!"
#endif // if defined(ARDUINO_BOARD_QTPY_M0_NOVA)