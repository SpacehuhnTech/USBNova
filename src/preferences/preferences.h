/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <string>

namespace preferences {
    void load();

    bool mscEnabled();
    bool ledEnabled();

    uint16_t getHidVid();
    uint16_t getHidPid();
    uint16_t getHidRev();

    std::string getMscVid();
    std::string getMscPid();
    std::string getMscRev();

    std::string getDefaultLayout();
}