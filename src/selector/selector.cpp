/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "selector.h"

#include <Arduino.h> // pinMode(), digitalRead()

#include "../../config.h"

#define CHANGE_DELAY 50

namespace selector {
    // ===== PRIVATE ===== //
    bool change_flag = false;
    Mode initial_mode;
    unsigned long change_time = 0;

    void isr() {
        change_flag = true;
        change_time = millis();
    }

    // ===== PUBLIC ===== //
    void init() {
        pinMode(SELECTOR, INPUT_PULLUP);
    
        attachInterrupt(digitalPinToInterrupt(SELECTOR), isr, CHANGE);

        initial_mode = read();
    }

    Mode mode() {
        return initial_mode;
    }

    Mode read() {
        return digitalRead(SELECTOR) ? SETUP : ATTACK;
    }

    bool changed() {
        if(change_flag && (millis() - change_time) > CHANGE_DELAY) {
            change_flag = false;
            return true;
        }
        return false; 
    }
}