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

    uint16_t getVID1();
    uint16_t getPID1();
    uint16_t getVersion1();
    std::string getSerial1();
    std::string getManufacturer1();
    std::string getProduct1();

    uint16_t getVID2();
    uint16_t getPID2();
    uint16_t getVersion2();
    std::string getSerial2();
    std::string getManufacturer2();
    std::string getProduct2();

    std::string getDefaultLayout();
    int getDefaultDelay();

    // std::string getMainScript();

    int* getAttackColor();
    int* getSetupColor();
    int* getIdleColor();

    bool getFormat();
    std::string getDriveName();

    bool getDisableCapslock();
    bool getRunOnIndicator();

    int getInitialDelay();
}