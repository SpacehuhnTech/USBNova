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
    std::string vid { "239A" };
    std::string pid { "80CB" };
    std::string default_layout { "US" };

    // ======== PUBLIC ======== //
    void load() {
        // Read config file
        char buffer[256];
        StaticJsonDocument<256> config_doc;

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
        vid            = config_doc["vid"].as<std::string>();
        pid            = config_doc["pid"].as<std::string>();
        default_layout = config_doc["default_layout"].as<std::string>();
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