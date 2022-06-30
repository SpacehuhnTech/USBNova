/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <cstdint> // uint8_t, unsigned long

namespace led {
    void begin();
    void setColor(int r, int g, int b);
    void start_blink(uint8_t r, uint8_t g, uint8_t b, unsigned long intv);
    void stop_blink();
    void update();
}