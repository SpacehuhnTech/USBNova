/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "preferences.h"

#include "../../config.h"
#include "../../debug.h"

#include <ArduinoJson.h>

namespace preferences {
    // ========== PRIVATE ========= //
    StaticJsonDocument<256> config_doc;

    bool enable_msc;
    bool enable_led;
    std::string vid;
    std::string pid;
    std::string default_layout;

    // ======== PUBLIC ======== //
    void load() {
        // Read config file
        char buffer[256];

        msc::open("preferences.json");
        msc::read(buffer, sizeof(buffer));

        // Deserialize the JSON document
        DeserializationError error = deserializeJson(config_doc, json);

        // Test if parsing succeeds.
        if (error) {
            debug("deserializeJson() failed: ");
            debugln(error.f_str());
            return;
        }

        // Fetch values.
        enable_msc     = config_doc["enable_msc"];
        enable_led     = config_doc["enable_led"];
        vid            = config_doc["vid"];
        pid            = config_doc["pid"];
        default_layout = config_doc["default_layout"];
    }

    bool mscEnabled() {
        return enable_msc;
    }

    bool ledEnabled() {
        return enable_led;
    }

    std::string getVid() {
        return vid;
    }

    std::string getPid() {
        return pid;
    }

    std::string getDefaultLayout() {
        return default_layout;
    }
}