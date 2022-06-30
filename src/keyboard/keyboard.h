/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

// If you get an error here, you probably have selected the wrong board.
// You can find the correct board under Tools > Board.
#include "../locale/locale.h"

namespace keyboard
{
    struct report
    {
        uint8_t modifiers;
        uint8_t keys[6];
    };

    void begin();
    bool mounted();

    void setLocale(hid_locale_t *locale);

    void send(report *k);
    void release();

    void pressKey(uint8_t key, uint8_t modifiers = KEY_NONE);
    void pressModifier(uint8_t key);

    uint8_t press(const char *strPtr);

    uint8_t write(const char *c);
    void write(const char *str, size_t len);
}