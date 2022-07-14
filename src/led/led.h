/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <cstdint> // uint8_t, unsigned long

namespace led {
    enum Color : uint8_t {
        RED,
        GREEN,
        BLUE
    };

    enum Mode : uint8_t {
        OFF,
        SOLID,
        SLOW,
        FAST
    };

    void init();
    void setEnable(bool enabled);

    void setColor(int* color);
    void setColor(int r, int g, int b);

    void startBlink(uint8_t r, uint8_t g, uint8_t b, unsigned long intv);
    void stopBlink();

    void setMode(Color color, Mode mode);

    void update();
}