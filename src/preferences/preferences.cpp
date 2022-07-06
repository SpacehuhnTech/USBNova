/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "preferences.h"

#include "../../config.h"
#include "../../debug.h"

#include <ArduinoJson.h>
#include "../msc/msc.h"

namespace preferences {
    // ========== PRIVATE ========= //
    bool enable_msc { false };
    bool enable_led { true };

    std::string hid_vid { "239A" };
    std::string hid_pid { "80CB" };
    std::string hid_rev { "0100" };

    std::string msc_vid { "Adafruit" };
    std::string msc_pid { "External Flash" };
    std::string msc_rev { "1.0" };

    std::string default_layout { "US" };
    int default_delay { 5 };

    // ======== PUBLIC ======== //
    void load() {
        // Read config file
        char buffer[1024];
        StaticJsonDocument<1024> config_doc;

        msc::open("preferences.json");
        msc::read(buffer, sizeof(buffer));

        // Deserialize the JSON document
        DeserializationError error = deserializeJson(config_doc, buffer);

        // Test if parsing succeeds.
        if (error) {
            debug("deserializeJson() failed: ");
            debugln(error.f_str());
            return;
        }

        // Fetch values.
        enable_msc     = config_doc["enable_msc"].as<bool>();
        enable_led     = config_doc["enable_led"].as<bool>();
        hid_vid        = config_doc["hid_vid"].as<std::string>();
        hid_pid        = config_doc["hid_pid"].as<std::string>();
        hid_rev        = config_doc["hid_rev"].as<std::string>();
        msc_vid        = config_doc["msc_vid"].as<std::string>();
        msc_pid        = config_doc["msc_pid"].as<std::string>();
        msc_rev        = config_doc["msc_rev"].as<std::string>();
        default_layout = config_doc["default_layout"].as<std::string>();
        default_delay  = config_doc["default_delay"].as<int>();
    }

    bool mscEnabled() {
        return enable_msc;
    }

    bool ledEnabled() {
        return enable_led;
    }

    uint16_t getHidVid() {
        return std::stoi(hid_vid, nullptr, 16);
    }

    uint16_t getHidPid() {
        return std::stoi(hid_pid, nullptr, 16);
    }

    uint16_t getHidRev() {
        return std::stoi(hid_rev, nullptr, 16);
    }

    std::string getMscVid() {
        return msc_vid;
    }

    std::string getMscPid() {
        return msc_pid;
    }

    std::string getMscRev() {
        return msc_rev;
    }

    std::string getDefaultLayout() {
        return default_layout;
    }

    int getDefaultDelay() {
        return default_delay;
    }
}