/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "keyboard.h"
#include <Adafruit_TinyUSB.h>
#include <Arduino.h> // millis(), delay()

namespace keyboard {
    // ====== PRIVATE ====== //
    hid_locale_t* locale { locale::get_default() };
    report_t prev_report = report_t{ KEY_NONE, KEY_NONE, { KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE, KEY_NONE } };

    // HID report descriptor using TinyUSB's template
    // Single Report (no ID) descriptor
    uint8_t const desc_hid_report[] = {
        TUD_HID_REPORT_DESC_KEYBOARD()
    };

    // USB HID object. For ESP32 these values cannot be changed after this declaration
    // desc report, desc len, protocol, interval, use out endpoint
    Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_KEYBOARD, 2, false);

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

    // Output report callback for LED indicator such as Caplocks
    void hid_report_callback(uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) {
        (void)report_id;
        (void)bufsize;

        // LED indicator is output report with only 1 byte length
        if (report_type != HID_REPORT_TYPE_OUTPUT)
            return;

        // The LED bit map is as follows: (also defined by KEYBOARD_LED_* )
        // Kana (4) | Compose (3) | ScrollLock (2) | CapsLock (1) | Numlock (0)
        uint8_t ledIndicator = buffer[0];

        // turn on LED if capslock is set
        // digitalWrite(LED_BUILTIN, ledIndicator & KEYBOARD_LED_CAPSLOCK);
    }

    // ====== PUBLIC ====== //
    void init() {
        // Notes: following commented-out functions has no affect on ESP32
        // usb_hid.setBootProtocol(HID_ITF_PROTOCOL_KEYBOARD);
        // usb_hid.setPollInterval(2);
        // usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
        // usb_hid.setStringDescriptor("TinyUSB Keyboard");

        // Set up output report (on control endpoint) for Capslock indicator
        usb_hid.setReportCallback(NULL, hid_report_callback);

        usb_hid.begin();
    }

    bool mounted() {
        return TinyUSBDevice.mounted();
    }

    void setLocale(hid_locale_t* locale) {
        if (locale == nullptr) return;
        keyboard::locale = locale;
    }

    void send(report_t* k) {
        if (TinyUSBDevice.suspended()) {
            // Wake up host if we are in suspend mode
            // and REMOTE_WAKEUP feature is enabled by host
            TinyUSBDevice.remoteWakeup();
        }

        // skip if hid is not ready e.g still transferring previous report
        if (!usb_hid.ready()) return;

        uint8_t const report_id = 0;

        usb_hid.keyboardReport(report_id, k->modifiers, k->keys);
    }

    void release() {
        prev_report = makeReport();
        usb_hid.keyboardRelease(0);
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
        // Convert string pointer into a byte pointer
        uint8_t* b = (uint8_t*)strPtr;

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

        // Extended ASCII
        for (uint8_t i = 0; i < locale->extended_ascii_len; ++i) {
            uint8_t key_code = pgm_read_byte(locale->extended_ascii + (i * 3));

            if (b[0] == key_code) {
                uint8_t modifiers = pgm_read_byte(locale->extended_ascii + (i * 3) + 1);
                uint8_t key       = pgm_read_byte(locale->extended_ascii + (i * 3) + 2);

                pressKey(key, modifiers);

                return 0;
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
}