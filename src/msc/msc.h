/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "SdFat.h"

namespace msc {
    void init();
    bool changed();
    bool prepare_read(const char* path);
    size_t read_line(char* buffer, size_t len);
}