/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "keyboard.h"

#include "hid.h"
#include <Arduino.h> // pgm_read_byte

namespace keyboard {
    // ====== PRIVATE ====== //
    hid_locale_t* locale { locale::get_default() };

    report_t prev_report = report_t{ KEY_NONE, { KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE } };

    report_t makeReport(uint8_t modifiers = 0, uint8_t key1 = 0, uint8_t key2 = 0, uint8_t key3 = 0, uint8_t key4 = 0, uint8_t key5 = 0, uint8_t key6 = 0);

    report_t makeReport(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6) {
        report_t k;

        k.modifiers = modifiers;

        k.keys[0] = key1;
        k.keys[1] = key2;
        k.keys[2] = key3;
        k.keys[3] = key4;
        k.keys[4] = key5;
        k.keys[5] = key6;

        return k;
    }

    // ====== PUBLIC ====== //
    void setLocale(hid_locale_t* locale) {
        if (locale == nullptr) return;
        keyboard::locale = locale;
    }

    void send(report_t* k) {
        hid::sendKeyboardReport(k->modifiers, k->keys);
    }

    void release() {
        prev_report = makeReport();
        send(&prev_report);
    }

    void pressKey(uint8_t key, uint8_t modifiers) {
        for (uint8_t i = 0; i < 6; ++i) {
            if (prev_report.keys[i] == KEY_NONE) {
                prev_report.modifiers |= modifiers;
                prev_report.keys[i]    = key;
                send(&prev_report);
                return;
            }
        }
    }

    void pressModifier(uint8_t key) {
        prev_report.modifiers |= key;

        send(&prev_report);
    }

    uint8_t press(const char* strPtr) {
        // Check for linebreaks
        if ((*strPtr == '\n') || (*strPtr == '\r')) {
            pressKey(KEY_ENTER);
            return 1;
        }

        // Convert string pointer into a byte pointer
        uint8_t* b = (uint8_t*)strPtr;

        // Key combinations (accent keys)
        // We have to check them first, because sometimes ASCII keys are in here
        for (uint8_t i = 0; i<locale->combinations_len; ++i) {
            uint8_t res = 0;

            // Read utf8 code and match it with the given data
            for (uint8_t j = 0; j<4; ++j) {
                uint8_t key_code = pgm_read_byte(locale->combinations + (i * 8) + j);

                if (key_code == 0) {
                    break;
                }

                if (key_code == b[j]) {
                    ++res;
                } else {
                    res = 0;
                    break;
                }
            }

            // If a match was found, read out the data and type it
            if (res > 0) {
                uint8_t comboModifiers = pgm_read_byte(locale->combinations + (i * 8) + 4);
                uint8_t comboKey       = pgm_read_byte(locale->combinations + (i * 8) + 5);

                uint8_t modifiers = pgm_read_byte(locale->combinations + (i * 8) + 6);
                uint8_t key       = pgm_read_byte(locale->combinations + (i * 8) + 7);

                pressKey(comboKey, comboModifiers);
                release();
                pressKey(key, modifiers);

                // Return the number of extra bytes we used from the string pointer
                return res-1;
            }
        }

        // ASCII
        if (b[0] < locale->ascii_len) {
            uint8_t modifiers = pgm_read_byte(locale->ascii + (b[0] * 2) + 0);
            uint8_t key       = pgm_read_byte(locale->ascii + (b[0] * 2) + 1);

            pressKey(key, modifiers);

            return 0;
        }

        // UTF8
        for (size_t i = 0; i < locale->utf8_len; ++i) {
            uint8_t res = 0;

            // Read utf8 code and match it with the given data
            for (uint8_t j = 0; j < 4; ++j) {
                uint8_t key_code = pgm_read_byte(locale->utf8 + (i * 6) + j);

                if (key_code == 0) {
                    break;
                }

                if (key_code == b[j]) {
                    ++res;
                } else {
                    res = 0;
                    break;
                }
            }

            // If a match was found, read out the data and type it
            if (res > 0) {
                uint8_t modifiers = pgm_read_byte(locale->utf8 + (i * 6) + 4);
                uint8_t key       = pgm_read_byte(locale->utf8 + (i * 6) + 5);

                pressKey(key, modifiers);

                // Return the number of extra bytes we used from the string pointer
                return res - 1;
            }
        }

        return 0;
    }

    uint8_t write(const char* c) {
        uint8_t res = press(c);

        release();

        return res;
    }

    void write(const char* str, size_t len) {
        for (size_t i = 0; i < len; ++i) {
            i += write(&str[i]);
        }
    }

    void disableCapslock() {
        if (hid::getIndicator() & 2) { /*KEYBOARD_LED_CAPSLOCK*/
            pressKey(KEY_CAPSLOCK);
            release();
        }
    }
}