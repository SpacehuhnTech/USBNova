/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <stddef.h> // size_t
#include <string> // std::string

namespace duckparser {
    void setDefaultDelay(int defaultDelay);

    void parse(const char* str, size_t len);

    int getRepeats();
    unsigned int getDelayTime();

    bool loopBegin();
    bool loopEnd();
    int getLoops();

    bool import();
    std::string getImport();
};