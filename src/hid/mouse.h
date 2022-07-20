/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <cstdint> // uint8_t

namespace mouse {
    typedef struct report_t {
        uint8_t buttons;
        int8_t  x;
        int8_t  y;
        int8_t  vertical;
        int8_t  horizontal;
    } report_t;

    void send(report_t* m);
    void release();

    void move(int8_t x, int8_t y);

    void click(uint8_t button);
    void press(uint8_t button);
    void release(uint8_t button);

    void scroll(int8_t vertical, int8_t horizontal);
}