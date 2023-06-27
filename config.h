/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#define VERSION "1.1.3"

// ===== DEBUG Settings ===== //
// #define ENABLE_DEBUG
#define DEBUG_PORT Serial
#define DEBUG_BAUD 115200

// ===== Storage Settings ===== //
#define READ_BUFFER 2048

// ===== LED Settings ===== //

#if defined(ARDUINO_ARCH_RP2040)
#define LED_PIN 12
#else // if defined(ARDUINO_ARCH_RP2040)
#define LED_PIN 11
#endif // if defined(ARDUINO_ARCH_RP2040)

// ===== SELECTOR SWITCH ===== //

#if defined(ARDUINO_ARCH_RP2040)
#define SELECTOR 13
#else // if defined(ARDUINO_ARCH_RP2040)
#define SELECTOR A0
#endif // if defined(ARDUINO_ARCH_RP2040)

// ===== Parser Settings ===== //
#define CASE_SENSETIVE false
#define DEFAULT_SLEEP 5

// ===== Other Stuff ====== //
#define PREFERENCES_PATH "preferences.json"