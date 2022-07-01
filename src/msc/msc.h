/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "SdFat.h"

namespace msc {
    void init();
    bool changed();
    bool prepareRead(const char* path);
    size_t readLine(char* buffer, size_t len);
}