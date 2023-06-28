/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <string>

namespace preferences {
    void load();
    void save();
    void reset();
    void print();

    bool mscEnabled();
    bool ledEnabled();
    bool hidEnabled();

    uint16_t getVID();
    uint16_t getPID();
    uint16_t getVersion();

    std::string getSerial();
    std::string getManufacturer();

    std::string getDefaultLayout();
    int getDefaultDelay();

    std::string getMainScript();

    int* getAttackColor();
    int* getSetupColor();
    int* getIdleColor();

    bool getFormat();
    std::string getDriveName();

    bool getDisableCapslock();
    bool getRunOnIndicator();

    int getInitialDelay();
}