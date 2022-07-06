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
    std::string hid_version { "0100" };
    std::string default_layout { "US" };

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
        enable_msc     = config_doc["enable_msc"];
        enable_led     = config_doc["enable_led"];
        hid_vid        = config_doc["hid_vid"].as<std::string>();
        hid_pid        = config_doc["hid_pid"].as<std::string>();
        hid_version    = config_doc["hid_version"].as<std::string>();
        default_layout = config_doc["default_layout"].as<std::string>();
    }

    bool mscEnabled() {
        return enable_msc;
    }

    bool ledEnabled() {
        return enable_led;
    }

    uint16_t getVid() {
        return std::stoi(hid_vid, nullptr, 16);
    }

    uint16_t getPid() {
        return std::stoi(hid_pid, nullptr, 16);
    }

    uint16_t getVersion() {
        return std::stoi(hid_version, nullptr, 16);
    }

    std::string getDefaultLayout() {
        return default_layout;
    }
}