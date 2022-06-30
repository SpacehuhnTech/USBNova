/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "selector.h"

#include <Arduino.h> // pinMode(), digitalRead()

#include "../../config.h"

namespace selector {
    void init() {
        pinMode(SELECTOR, INPUT_PULLUP);
    }

    int read() {
        return digitalRead(SELECTOR);
    }
}