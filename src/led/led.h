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
    void setColor(int r, int g, int b, unsigned long intv = 0);

    void setMode(Color color, Mode mode);

    void update();
}