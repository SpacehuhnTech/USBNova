/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "selector.h"

#include <Arduino.h> // pinMode(), digitalRead()

#include "../../config.h"

namespace selector {
    void init() {
        pinMode(SELECTOR_1, INPUT_PULLUP);
        pinMode(SELECTOR_2, INPUT_PULLUP);
        pinMode(SELECTOR_3, INPUT_PULLUP);
    }

    int read() {
        if (!digitalRead(SELECTOR_1)) {
            return 1;
        } else if (!digitalRead(SELECTOR_2)) {
            return 2;
        } else if (!digitalRead(SELECTOR_3)) {
            return 3;
        } else {
            return 0;
        }
    }
}