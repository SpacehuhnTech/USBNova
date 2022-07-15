/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <cstdint> // uint8_t

namespace hid {
    // Report ID
    enum RID {
        KEYBOARD = 1,
        MOUSE = 2,
        CONSUMER_CONTROL = 3, // Media, volume etc ..
    };

    void init();
    void setID(uint16_t vid, uint16_t pid, uint16_t version);
    bool mounted();

    void sendKeyboardReport(uint8_t modifier, uint8_t* keys);

    uint8_t getIndicator();
    bool indicatorChanged();
}