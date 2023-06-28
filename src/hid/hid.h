/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../../config.h"

#include <cstdint> // uint8_t
#include <string>  // std::string

namespace hid {
    // Report ID
    enum RID {
        KEYBOARD         = 1,
        MOUSE            = 2,
        CONSUMER_CONTROL = 3, // Media, volume etc ..
    };

    void init();
    void setID(uint16_t vid, uint16_t pid, uint16_t version);
    void setSerial(std::string serialstr);
    void setManufacturer(std::string manufacturerstr);

    bool mounted();

    void sendKeyboardReport(uint8_t modifier, uint8_t* keys);
    void sendMouseReport(uint8_t buttons, int8_t x, int8_t y, int8_t vertical, int8_t horizontal);

    uint8_t getIndicator();
    bool indicatorChanged();
}