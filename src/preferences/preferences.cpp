/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "preferences.h"

#include "../../config.h"
#include "../../debug.h"

#include <ArduinoJson.h>
#include "../msc/msc.h"

#define JSON_SIZE 2048

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
    bool enable_msc;
    bool enable_led;
    bool enable_hid;

    std::string vid1;
    std::string pid1;
    std::string version1;
    std::string serial1;
    std::string manufacturer1;
    std::string product1;

    std::string vid2;
    std::string pid2;
    std::string version2;
    std::string serial2;
    std::string manufacturer2;
    std::string product2;

    std::string default_layout;
    int default_delay;

    // std::string main_script;

    int attack_color[4];
    int setup_color[4];
    int idle_color[4];

    bool format;
    std::string drive_name;

    bool disable_capslock;
    bool run_on_indicator;

    int initial_delay;

    // Array help functions
    void add_array(JsonDocument& doc, const char* name, int* array, int size) {
        JsonArray jarr = doc.createNestedArray(name);

        for (size_t i = 0; i < size; ++i) {
            jarr.add(array[i]);
        }
    }

    void toJson(JsonDocument& root) {
        root["$schema"] = "https://raw.githubusercontent.com/SpacehuhnTech/USBNova/malduino/schema.json";

        root["enable_msc"] = enable_msc;
        root["enable_led"] = enable_led;
        root["enable_hid"] = enable_hid;

        root["vid1"]          = vid1;
        root["pid1"]          = pid1;
        root["version1"]      = version1;
        root["serial1"]       = serial1;
        root["manufacturer1"] = manufacturer1;
        root["product1"]      = product1;

        root["vid2"]          = vid2;
        root["pid2"]          = pid2;
        root["version2"]      = version2;
        root["serial2"]       = serial2;
        root["manufacturer2"] = manufacturer2;
        root["product2"]      = product2;

        root["default_layout"] = default_layout;
        root["default_delay"]  = default_delay;

        /*
                root["main_script"] = main_script;

                add_array(root, "attack_color", attack_color, 4);
                add_array(root, "setup_color", setup_color, 4);
                add_array(root, "idle_color", idle_color, 4);
         */
        root["disable_capslock"] = disable_capslock;
        root["run_on_indicator"] = run_on_indicator;

        root["initial_delay"] = initial_delay;
    }

    void read_array(JsonDocument& doc, const char* name, int* array, int size) {
        JsonVariant val = doc[name];

        if (val.isNull()) return;

        JsonArray jarr = val.as<JsonArray>();

        for (size_t i = 0; i<jarr.size() && i<size; ++i) {
            array[i] = jarr[i].as<int>();
        }
    }

    template<typename T>
    void read_item(JsonDocument& doc, const char* name, T& val) {
        JsonVariant new_val = doc[name];

        if (new_val.isNull()) return;
        val = new_val.as<T>();
    }

    // ======== PUBLIC ======== //
    void load() {
        // Read config file
        char* buffer = (char*)calloc(JSON_SIZE, sizeof(char));
        DynamicJsonDocument config_doc(JSON_SIZE);

        // Open the file and read it into a buffer
        if (!msc::open(PREFERENCES_PATH), false) return;
        size_t read = msc::read(buffer, JSON_SIZE);
        msc::close();

        // Deserialize the JSON document
        DeserializationError error = deserializeJson(config_doc, buffer);

        free(buffer);

        // Test if parsing succeeds.
        if (error) {
            debug("deserializeJson() failed: ");
            debugln(error.f_str());
            return;
        }

        // === Fetch values === //
        read_item<bool>(config_doc, "enable_msc", enable_msc);
        read_item<bool>(config_doc, "enable_led", enable_led);
        read_item<bool>(config_doc, "enable_hid", enable_hid);

        read_item<std::string>(config_doc, "vid1", vid1);
        read_item<std::string>(config_doc, "pid1", pid1);
        read_item<std::string>(config_doc, "version1", version1);
        read_item<std::string>(config_doc, "serial1", serial1);
        read_item<std::string>(config_doc, "manufacturer1", manufacturer1);
        read_item<std::string>(config_doc, "product1", product1);

        read_item<std::string>(config_doc, "vid2", vid2);
        read_item<std::string>(config_doc, "pid2", pid2);
        read_item<std::string>(config_doc, "version2", version2);
        read_item<std::string>(config_doc, "serial2", serial2);
        read_item<std::string>(config_doc, "manufacturer2", manufacturer2);
        read_item<std::string>(config_doc, "product2", product2);

        read_item<std::string>(config_doc, "default_layout", default_layout);
        read_item<int>(config_doc, "default_delay", default_delay);

        // read_item<std::string>(config_doc, "main_script", main_script);

        // read_array(config_doc, "attack_color", attack_color, 4);
        // read_array(config_doc, "setup_color", setup_color, 4);
        // read_array(config_doc, "idle_color", idle_color, 4);

        // Format Flash (Drive name/Disk label max 11 characters)
        format = config_doc.containsKey("format");
        if (format) {
            drive_name = config_doc["format"].as<std::string>().substr(0, 11);
        }

        disable_capslock = config_doc["disable_capslock"].as<bool>();
        run_on_indicator = config_doc["run_on_indicator"].as<bool>();

        initial_delay = config_doc["initial_delay"].as<int>();
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

        vid1          = "16D0";
        pid1          = "103F";
        version1      = "0100";
        serial1       = "1337";
        manufacturer1 = "Maltronics";
        product1      = "MalDuino";

        vid2          = "16D0";
        pid2          = "103F";
        version2      = "0100";
        serial2       = "1337";
        manufacturer2 = "Maltronics";
        product2      = "MalDuino";

        default_layout = "US";
        default_delay  = 5;

        // main_script = "main_script.txt";

        attack_color[0] = 0;
        attack_color[2] = 0;
        attack_color[3] = 0;
        attack_color[1] = 0;

        setup_color[0] = 255;
        setup_color[1] = 0;
        setup_color[2] = 0;
        setup_color[3] = 0;

        idle_color[0] = 0;
        idle_color[1] = 0;
        idle_color[2] = 0;
        idle_color[3] = 0;

        format     = false;
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

    uint16_t getVID1() {
        return std::stoi(vid1, nullptr, 16);
    }

    uint16_t getPID1() {
        return std::stoi(pid1, nullptr, 16);
    }

    uint16_t getVersion1() {
        return std::stoi(version1, nullptr, 16);
    }

    std::string getSerial1() {
        return serial1;
    }

    std::string getManufacturer1() {
        return manufacturer1;
    }

    std::string getProduct1() {
        return product1;
    }

    uint16_t getVID2() {
        return std::stoi(vid2, nullptr, 16);
    }

    uint16_t getPID2() {
        return std::stoi(pid2, nullptr, 16);
    }

    uint16_t getVersion2() {
        return std::stoi(version2, nullptr, 16);
    }

    std::string getSerial2() {
        return serial2;
    }

    std::string getManufacturer2() {
        return manufacturer2;
    }

    std::string getProduct2() {
        return product2;
    }

    std::string getDefaultLayout() {
        return default_layout;
    }

    int getDefaultDelay() {
        return default_delay;
    }

    /*
        std::string getMainScript() {
            return main_script;
        }
     */
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