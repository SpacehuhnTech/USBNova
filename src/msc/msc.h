/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "SdFat.h"

namespace msc {
    void init();
    bool changed();
    bool open(const char* path);
    bool openNextFile();

    uint32_t getPosition();
    void gotoPosition(uint32_t pos);

    size_t readLine(char* buffer, size_t len);
    bool getInLine();
}