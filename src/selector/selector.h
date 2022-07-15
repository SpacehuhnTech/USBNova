/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

enum Mode {
    SETUP, ATTACK
};

namespace selector {
    void init();

    Mode mode();
    Mode read();

    bool changed();
}