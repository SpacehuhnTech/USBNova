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

    uint16_t getHid1Vid();
    uint16_t getHid1Pid();
    uint16_t getHid2Vid();
    uint16_t getHid2Pid();
    uint16_t getHidRev();

    std::string getMscVid();
    std::string getMscPid();
    std::string getMscRev();

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
    bool getRunOnMSC();

    int getInitialDelay();
}