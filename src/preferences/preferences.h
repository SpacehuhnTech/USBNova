/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <string>

namespace preferences {
    void load();

    bool mscEnabled();
    bool ledEnabled();
    std::string getVid();
    std::string getPid();
    std::string getDefaultLayout();
}