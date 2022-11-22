/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "preferences.h"

#include "../../config.h"
#include "../../debug.h"

#include <ArduinoJson.h>
#include "../msc/msc.h"

#define JSON_SIZE 1536

/*
   How to add new settings:
   1. Add a variable in the top of the namespace
   2. Add it to toJSON()
   3. Add it to load() (missing values)
   4. Add it to load() (fetching)
   5. Add getter functions and add then to the .h file
 */

namespace preferences {
    // ========== PRIVATE ========= //
    bool enable_msc { false };
    bool enable_led { true };
    bool enable_hid { true };

    std::string hid_vid { "16D0" };
    std::string hid_pid { "11A4" };
    std::string hid_rev { "0100" };

    std::string msc_vid { "SpHuhn" }; // max. 8 chars
    std::string msc_pid { "USB Nova" }; // max. 16 chars
    std::string msc_rev { "1.0" }; // max. 4 chars

    std::string default_layout { "US" };
    int default_delay { 5 };

    std::string main_script { "main_script.txt" };

    int attack_color[4] { 128, 0, 0, 0 };
    int setup_color[4] { 0, 0, 20, 0 };
    int idle_color[4] { 0, 30, 0, 0 };

    bool format { false };
    std::string drive_name { "USB Nova" };

    bool disable_capslock { true };
    bool run_on_indicator { false };

    int initial_delay { 1000 };

    // Array help functions
    void add_array(JsonDocument& doc, const char* name, int* array, int size) {
        JsonArray jarr = doc.createNestedArray(name);
        for(size_t i = 0; i < size; ++i) {
            jarr.add(array[i]);
        }
    }

    void read_array(JsonDocument& doc, const char* name, int* array, int size) {
        JsonArray jarr = doc[name].as<JsonArray>();

        for (size_t i = 0; i<jarr.size() && i<size; ++i) {
            array[i] = jarr[i].as<int>();
        }
    }

    void toJson(JsonDocument& root) {
        root["enable_msc"] = enable_msc;
        root["enable_led"] = enable_led;
        root["enable_hid"] = enable_hid;

        root["hid_vid"] = hid_vid;
        root["hid_pid"] = hid_pid;
        root["hid_rev"] = hid_rev;

        root["msc_vid"] = msc_vid;
        root["msc_pid"] = msc_pid;
        root["msc_rev"] = msc_rev;

        root["default_layout"] = default_layout;
        root["default_delay"]  = default_delay;

        root["main_script"] = main_script;

        add_array(root, "attack_color", attack_color, 4);
        add_array(root, "setup_color", setup_color, 4);
        add_array(root, "idle_color", idle_color, 4);

        root["disable_capslock"] = disable_capslock;
        root["run_on_indicator"]  = run_on_indicator;

        root["initial_delay"] = initial_delay;
    }

    // ======== PUBLIC ======== //
    void load() {
        // Read config file
        char* buffer = (char*)malloc(JSON_SIZE);
        DynamicJsonDocument config_doc(JSON_SIZE);

        // Open the file and read it into a buffer
        if (!msc::open(PREFERENCES_PATH), false) return;
        size_t read = msc::read(buffer, JSON_SIZE);
        msc::close();
        
        buffer[read] = '\0';

        // Deserialize the JSON document
        DeserializationError error = deserializeJson(config_doc, buffer);

        free(buffer);

        // Test if parsing succeeds.
        if (error) {
            debug("deserializeJson() failed: ");
            debugln(error.f_str());
            return;
        }

        // === Add missing values === //
        if (!config_doc.containsKey("enable_msc")) config_doc["enable_msc"] = enable_msc;
        if (!config_doc.containsKey("enable_led")) config_doc["enable_led"] = enable_led;
        if (!config_doc.containsKey("enable_hid")) config_doc["enable_hid"] = enable_hid;

        if (!config_doc.containsKey("hid_vid")) config_doc["hid_vid"] = hid_vid;
        if (!config_doc.containsKey("hid_pid")) config_doc["hid_pid"] = hid_pid;
        if (!config_doc.containsKey("hid_rev")) config_doc["hid_rev"] = hid_rev;

        if (!config_doc.containsKey("msc_vid")) config_doc["msc_vid"] = msc_vid;
        if (!config_doc.containsKey("msc_pid")) config_doc["msc_pid"] = msc_pid;
        if (!config_doc.containsKey("msc_rev")) config_doc["msc_rev"] = msc_rev;

        if (!config_doc.containsKey("default_layout")) config_doc["default_layout"] = default_layout;
        if (!config_doc.containsKey("default_delay")) config_doc["default_delay"] = default_delay;

        if (!config_doc.containsKey("main_script")) config_doc["main_script"] = main_script;

        if (!config_doc.containsKey("attack_color")) add_array(config_doc, "attack_color", attack_color, 4);
        if (!config_doc.containsKey("setup_color")) add_array(config_doc, "setup_color", setup_color, 4);
        if (!config_doc.containsKey("idle_color")) add_array(config_doc, "idle_color", idle_color, 4);

        if (!config_doc.containsKey("disable_capslock")) config_doc["disable_capslock"] = disable_capslock;
        if (!config_doc.containsKey("run_on_indicator")) config_doc["run_on_indicator"] = run_on_indicator;
        
        if (!config_doc.containsKey("initial_delay")) config_doc["initial_delay"] = initial_delay;

        // === Fetch values === //
        enable_msc = config_doc["enable_msc"].as<bool>();
        enable_led = config_doc["enable_led"].as<bool>();
        enable_hid = config_doc["enable_hid"].as<bool>();

        hid_vid = config_doc["hid_vid"].as<std::string>();
        hid_pid = config_doc["hid_pid"].as<std::string>();
        hid_rev = config_doc["hid_rev"].as<std::string>();

        msc_vid = config_doc["msc_vid"].as<std::string>();
        msc_pid = config_doc["msc_pid"].as<std::string>();
        msc_rev = config_doc["msc_rev"].as<std::string>();

        default_layout = config_doc["default_layout"].as<std::string>();
        default_delay  = config_doc["default_delay"].as<int>();

        main_script = config_doc["main_script"].as<std::string>();

        read_array(config_doc, "attack_color", attack_color, 4);
        read_array(config_doc, "setup_color", setup_color, 4);
        read_array(config_doc, "idle_color", idle_color, 4);

        // Format Flash (Drive name/Disk label max 11 characters)
        format = config_doc.containsKey("format");
        if (format) {
            drive_name = config_doc["format"].as<std::string>().substr(0, 11);
        }

        disable_capslock = config_doc["disable_capslock"].as<bool>();
        run_on_indicator  = config_doc["run_on_indicator"].as<bool>();
        
        initial_delay  = config_doc["initial_delay"].as<int>();
    }

    void save() {
        // Create a new JSON document (and string buffer)
        DynamicJsonDocument json_doc(JSON_SIZE);
        // JsonObject json_obj = json_doc.as<JsonObject>();
        std::string json_str = { "" };

        // Add values
        toJson(json_doc);

        // Serialize JSON to buffer
        serializeJsonPretty(json_doc, json_str);
        json_doc.clear();

        // Write the buffer to file (and print results)
        debugln(json_str.c_str());
        msc::write(PREFERENCES_PATH, json_str.c_str(), json_str.length());

        debug("Saved ");
        debugln(PREFERENCES_PATH);
    }
    
    void reset() {
        enable_msc = false;
        enable_led = true;
        enable_hid = true;

        hid_vid = "16D0";
        hid_pid = "11A4";
        hid_rev = "0100";

        msc_vid = "SpHuhn";
        msc_pid = "USB Nova";
        msc_rev = "1.0";

        default_layout = "US";
        default_delay = 5;

        main_script = "main_script.txt";

        attack_color[0] = 128;
        attack_color[1] = 0;
        attack_color[2] = 0;
        attack_color[3] = 0;

        setup_color[0] = 0;
        setup_color[1] = 0;
        setup_color[2] = 20;
        setup_color[3] = 0;

        idle_color[0] = 0;
        idle_color[1] = 30;
        idle_color[2] = 0;
        idle_color[3] = 0;

        format = false;
        drive_name = "USB Nova";

        disable_capslock = true;
        run_on_indicator = false;

        initial_delay = 1000;
    }
    
    void print() {
        // Create a new JSON document (and string buffer)
        DynamicJsonDocument json_doc(JSON_SIZE);
        // JsonObject json_obj = json_doc.as<JsonObject>();
        std::string json_str = { "" };

        // Add values
        toJson(json_doc);

        // Serialize JSON to buffer
        serializeJsonPretty(json_doc, json_str);
        json_doc.clear();

        // Write the buffer to file (and print results)
        debugln(json_str.c_str());
    }

    bool mscEnabled() {
        return enable_msc;
    }

    bool ledEnabled() {
        return enable_led;
    }

    bool hidEnabled() {
        return enable_hid;
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

    bool getDisableCapslock() {
        return disable_capslock;
    }

    bool getRunOnIndicator() {
        return run_on_indicator;
    }
    
    int getInitialDelay() {
        return initial_delay;
    }
}