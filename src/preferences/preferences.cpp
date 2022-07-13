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

    std::string main_script { "main.script" };

    int attack_color[3] { 128, 0, 0 };
    int setup_color[3] { 0, 0, 20 };
    int idle_color[3] { 0, 30, 0 };

    bool format { false };
    std::string drive_name { "USB Nova" };

    void toJson(JsonDocument& root) {
        root["enable_msc"] = enable_msc;
        root["enable_led"] = enable_led;

        root["hid_vid"] = hid_vid;
        root["hid_pid"] = hid_pid;
        root["hid_rev"] = hid_rev;

        root["msc_vid"] = msc_vid;
        root["msc_pid"] = msc_pid;
        root["msc_rev"] = msc_rev;

        root["default_layout"] = default_layout;
        root["default_delay"]  = default_delay;

        root["main_script"] = main_script;

        JsonArray attack_color_arr = root.createNestedArray("attack_color");
        attack_color_arr.add(attack_color[0]);
        attack_color_arr.add(attack_color[1]);
        attack_color_arr.add(attack_color[2]);

        JsonArray setup_color_arr = root.createNestedArray("setup_color");
        setup_color_arr.add(setup_color[0]);
        setup_color_arr.add(setup_color[1]);
        setup_color_arr.add(setup_color[2]);

        JsonArray idle_color_arr = root.createNestedArray("idle_color");
        idle_color_arr.add(idle_color[0]);
        idle_color_arr.add(idle_color[1]);
        idle_color_arr.add(idle_color[2]);
    }

    // ======== PUBLIC ======== //
    void load() {
        // Read config file
        char buffer[1024];
        StaticJsonDocument<1024> config_doc;

        // Open the file and read it into a buffer
        if (!msc::open("preferences.json")) return;
        msc::read(buffer, sizeof(buffer));

        // Deserialize the JSON document
        DeserializationError error = deserializeJson(config_doc, buffer);

        // Test if parsing succeeds.
        if (error) {
            debug("deserializeJson() failed: ");
            debugln(error.f_str());
            return;
        }

        // === Add missing values === //
        if (!config_doc.containsKey("enable_msc")) config_doc["enable_msc"] = enable_msc;
        if (!config_doc.containsKey("enable_led")) config_doc["enable_led"] = enable_led;

        if (!config_doc.containsKey("hid_vid")) config_doc["hid_vid"] = hid_vid;
        if (!config_doc.containsKey("hid_pid")) config_doc["hid_pid"] = hid_pid;
        if (!config_doc.containsKey("hid_rev")) config_doc["hid_rev"] = hid_rev;

        if (!config_doc.containsKey("msc_vid")) config_doc["msc_vid"] = msc_vid;
        if (!config_doc.containsKey("msc_pid")) config_doc["msc_pid"] = msc_pid;
        if (!config_doc.containsKey("msc_rev")) config_doc["msc_rev"] = msc_rev;

        if (!config_doc.containsKey("default_layout")) config_doc["default_layout"] = default_layout;
        if (!config_doc.containsKey("default_delay")) config_doc["default_delay"] = default_delay;

        if (!config_doc.containsKey("main_script")) config_doc["main_script"] = main_script;

        if (!config_doc.containsKey("attack_color")) {
            JsonArray arr = config_doc.createNestedArray("attack_color");
            arr.add(attack_color[0]);
            arr.add(attack_color[1]);
            arr.add(attack_color[2]);
        }

        if (!config_doc.containsKey("setup_color")) {
            JsonArray arr = config_doc.createNestedArray("setup_color");
            arr.add(setup_color[0]);
            arr.add(setup_color[1]);
            arr.add(setup_color[2]);
        }

        if (!config_doc.containsKey("idle_color")) {
            JsonArray arr = config_doc.createNestedArray("idle_color");
            arr.add(idle_color[0]);
            arr.add(idle_color[1]);
            arr.add(idle_color[2]);
        }

        // === Fetch values === //
        enable_msc = config_doc["enable_msc"].as<bool>();
        enable_led = config_doc["enable_led"].as<bool>();

        hid_vid = config_doc["hid_vid"].as<std::string>();
        hid_pid = config_doc["hid_pid"].as<std::string>();
        hid_rev = config_doc["hid_rev"].as<std::string>();

        msc_vid = config_doc["msc_vid"].as<std::string>();
        msc_pid = config_doc["msc_pid"].as<std::string>();
        msc_rev = config_doc["msc_rev"].as<std::string>();

        default_layout = config_doc["default_layout"].as<std::string>();
        default_delay  = config_doc["default_delay"].as<int>();

        main_script = config_doc["main_script"].as<std::string>();

        // Attack LED Color
        JsonArray attack_color_array = config_doc["attack_color"].as<JsonArray>();

        for (size_t i = 0; i<attack_color_array.size() && i<3; ++i) {
            attack_color[i] = attack_color_array[i].as<int>();
        }

        // Setup LED Color
        JsonArray setup_color_array = config_doc["setup_color"].as<JsonArray>();

        for (size_t i = 0; i<setup_color_array.size() && i<3; ++i) {
            setup_color[i] = setup_color_array[i].as<int>();
        }

        // Idle LED Color
        JsonArray idle_color_array = config_doc["idle_color"].as<JsonArray>();

        for (size_t i = 0; i<idle_color_array.size() && i<3; ++i) {
            idle_color[i] = idle_color_array[i].as<int>();
        }

        // Format Flash (Drive name/Disk label max 11 characters)
        format = config_doc.containsKey("format");
        if (format) {
            drive_name = config_doc["format"].as<std::string>().substr(0, 11);
        }
    }

    void save() {
        // Create a new JSON document (and string buffer)
        StaticJsonDocument<1024> json_doc;
        // JsonObject json_obj = json_doc.as<JsonObject>();
        std::string json_str = { "" };

        // Add values
        toJson(json_doc);

        // Serialize JSON to buffer
        serializeJsonPretty(json_doc, json_str);

        // Write the buffer to file
        msc::open("preferences.json", true);
        debugln(json_str.length());
        debugln(msc::write(json_str.c_str(), json_str.length()));
        msc::close();

        //debugln(json_str.length());
        //debugln(json_str.c_str());
        debugln("Saved preferences.json");
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

    std::string getMainScript() {
        return main_script;
    }

    int* getAttackColor() {
        return attack_color;
    }

    int* getSetupColor() {
        return setup_color;
    }

    int* getIdleColor() {
        return idle_color;
    }

    bool getFormat() {
        return format;
    }

    std::string getDriveName() {
        return drive_name;
    }
}