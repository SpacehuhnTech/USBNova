/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <stddef.h> // size_t

namespace duckparser {
    void parse(const char* str, size_t len);
    int getRepeats();
    unsigned int getDelayTime();
    bool loopBegin();
    bool loopEnd();
    int getLoops();
};