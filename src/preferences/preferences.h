/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <string>

namespace preferences {
    void load();

    bool mscEnabled();
    bool ledEnabled();
    uint16_t getVid();
    uint16_t getPid();
    uint16_t getVersion();
    std::string getDefaultLayout();
}