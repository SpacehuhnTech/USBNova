/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "hid.h"

#include <Adafruit_TinyUSB.h>
#include <Arduino.h> // delay()

namespace hid {
    // ====== PRIVATE ====== //
    uint8_t indicator         = 0;     // Indicator LED state
    bool    indicator_changed = false; // Whether or not any indicator changed since last time
    bool    indicator_read    = false; // If initial indicator was read

    std::string serial       = "1337";
    std::string manufacturer = "SpacehuhnTech";

    // HID report descriptor using TinyUSB's template
    // Single Report (no ID) descriptor
    uint8_t const desc_hid_report[] = {
        TUD_HID_REPORT_DESC_KEYBOARD(HID_REPORT_ID(RID::KEYBOARD)),
        TUD_HID_REPORT_DESC_MOUSE(HID_REPORT_ID(RID::MOUSE)),
        TUD_HID_REPORT_DESC_CONSUMER(HID_REPORT_ID(RID::CONSUMER_CONTROL))
    };

    // USB HID object. For ESP32 these values cannot be changed after this declaration
    // desc report, desc len, protocol, interval, use out endpoint
    Adafruit_USBD_HID usb_hid(desc_hid_report, sizeof(desc_hid_report), HID_ITF_PROTOCOL_KEYBOARD, 2, false);

    // Output report callback for LED indicator such as Caplocks
    void hid_report_callback(uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize) {
        (void)report_id;
        (void)bufsize;

        // LED indicator is output report with only 1 byte length
        if (report_type != HID_REPORT_TYPE_OUTPUT)
            return;

        // The LED bit map is as follows: (also defined by KEYBOARD_LED_* )
        // Kana (4) | Compose (3) | ScrollLock (2) | CapsLock (1) | Numlock (0)
        uint8_t tmp = buffer[0];

        // Save caps lock state
        if (tmp != indicator) {
            indicator         = tmp;
            indicator_changed = true;
        }

        // Making sure that indicator_changed isn't set to true because of an initial read
        if (!indicator_read) {
            indicator_read    = true;
            indicator_changed = false;
        }

        // turn on LED if capslock is set
        // digitalWrite(LED_BUILTIN, ledIndicator & KEYBOARD_LED_CAPSLOCK);
    }

    // ====== PUBLIC ====== //
    void init() {
        // Notes: following commented-out functions has no affect on ESP32
        usb_hid.setBootProtocol(HID_ITF_PROTOCOL_KEYBOARD);
        // usb_hid.setPollInterval(2);
        // usb_hid.setReportDescriptor(desc_hid_report, sizeof(desc_hid_report));
        // usb_hid.setStringDescriptor("TinyUSB Keyboard");

        // Set up output report (on control endpoint) for Capslock indicator
        usb_hid.setReportCallback(NULL, hid_report_callback);

        usb_hid.begin();
    }

    void setID(uint16_t vid, uint16_t pid, uint16_t version) {
        TinyUSBDevice.setID(vid, pid);
        TinyUSBDevice.setDeviceVersion(version);
    }

    void setSerial(std::string serialstr) {
        hid::serial = serialstr;
        TinyUSBDevice.setSerialDescriptor(serial.c_str());
    }

    void setManufacturer(std::string manufacturerstr) {
        hid::manufacturer = manufacturerstr;
        TinyUSBDevice.setManufacturerDescriptor(manufacturer.c_str());
    }

    bool mounted() {
        return TinyUSBDevice.mounted();
    }

    void sendKeyboardReport(uint8_t modifier, uint8_t* keys) {
        if (TinyUSBDevice.suspended()) {
            // Wake up host if we are in suspend mode
            // and REMOTE_WAKEUP feature is enabled by host
            TinyUSBDevice.remoteWakeup();
        }

        // Wait until ready to send next report
        while (!usb_hid.ready()) {
            delay(1);
        }

        usb_hid.keyboardReport(RID::KEYBOARD, modifier, keys);
    }

    void sendMouseReport(uint8_t buttons, int8_t x, int8_t y, int8_t vertical, int8_t horizontal) {
        if (TinyUSBDevice.suspended()) {
            // Wake up host if we are in suspend mode
            // and REMOTE_WAKEUP feature is enabled by host
            TinyUSBDevice.remoteWakeup();
        }

        // Wait until ready to send next report
        while (!usb_hid.ready()) {
            delay(1);
        }

        usb_hid.mouseReport(RID::MOUSE, buttons, x, y, vertical, horizontal);
    }

    uint8_t getIndicator() {
        return indicator;
    }

    bool indicatorChanged() {
        bool res = indicator_changed;

        indicator_changed = false;
        return res;
    }
}