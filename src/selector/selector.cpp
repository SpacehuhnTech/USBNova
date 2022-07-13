/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "selector.h"

#include <Arduino.h> // pinMode(), digitalRead()

#include "../../config.h"

namespace selector {
    // ===== PRIVATE ===== //
    bool change_flag = false;

    void isr() {
        change_flag = true;
    }

    // ===== PUBLIC ===== //
    void init() {
        pinMode(SELECTOR, INPUT_PULLUP);
    
        attachInterrupt(digitalPinToInterrupt(SELECTOR), isr, CHANGE);
    }

    int read() {
        return digitalRead(SELECTOR);
    }

    bool changed() {
        bool temp = change_flag;
        change_flag = false;
        delay(50);
        return temp;
    }
}