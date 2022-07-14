/*
 * Note2: If your flash is not formatted as FAT12 previously, you could format it using
 * follow sketch https://github.com/adafruit/Adafruit_SPIFlash/tree/master/examples/SdFat_format
 */

#include "config.h"
#include "debug.h"

#include "src/keyboard/keyboard.h"
#include "src/led/led.h"
#include "src/msc/msc.h"
#include "src/selector/selector.h"
#include "src/attack/attack.h"
#include "src/preferences/preferences.h"
#include "src/duckparser/duckparser.h"
#include "src/format/format.h"

enum Mode {
    SETUP, ATTACK
};

Mode mode;

void setup() {
    // Initialize all the things
    debug_init();
    selector::init();
    led::init();

    // Initialize memory and ceck for problems
    if (!msc::init()) {
        format::start(); // Format the drive

        // If it still fails, blink red LED
        if (!msc::init()) {
            while (true) {
                led::setColor(255, 0, 0);
                delay(500);
                led::setColor(0, 0, 0);
                delay(500);
            }
        }
    }

    // Read the mode from the toggle switch position
    mode = selector::read() ? SETUP : ATTACK;

    // Preferences
    preferences::load();
    led::setEnable(preferences::ledEnabled());
    keyboard::setLocale(locale::get(preferences::getDefaultLayout().c_str()));
    keyboard::setID(preferences::getHidVid(), preferences::getHidPid(), preferences::getHidRev());
    msc::setID(preferences::getMscVid().c_str(), preferences::getMscPid().c_str(), preferences::getMscRev().c_str());
    duckparser::setDefaultDelay(preferences::getDefaultDelay());

    // Start Keyboard
    keyboard::init();

    // Start USB Drive
    if (preferences::mscEnabled() || (mode == SETUP)) msc::enableDrive();

    // Wait 1s to give the computer time to initialize the keyboard
    delay(1000);

    // Disable capslock if needed
    if (preferences::getDisableCapslock()) {
        keyboard::disableCapslock();
    }

    // Format Flash
    if ((mode == SETUP) && preferences::getFormat()) {
        led::setColor(255, 255, 255);
        format::start(preferences::getDriveName().c_str());
    }

    // Create preferences file if it doesn't exist yet
    if (!msc::exists(PREFERENCES_PATH)) {
        preferences::save();
    }

    // ==========  Setup Mode ==========  //
    if (mode == SETUP) {
        led::setColor(preferences::getSetupColor()); // Set LED to blue

        while (true) {
            if (selector::changed()) {
                mode = selector::read() ? SETUP : ATTACK;

                if (mode == ATTACK) {
                    preferences::load();                          // Reload the settings (in case the main script path changed)

                    led::setColor(preferences::getAttackColor()); // Turn LED red
                    attack::start();                              // Start keystroke injection attack
                    led::setColor(preferences::getSetupColor());  // Set LED to blue

                    mode = SETUP;
                }
            }
            delay(100);
        }
    }
    // ==========  Setup Mode ==========  //
    else if (mode == ATTACK) {
        led::setColor(preferences::getAttackColor()); // Turn LED red
        attack::start();                              // Start keystroke injection attack
        led::setColor(preferences::getIdleColor());   // Turn LED green

        while (true) {
            if (selector::changed()) {
                mode = selector::read() ? SETUP : ATTACK;

                if (mode == ATTACK) {
                    led::setColor(preferences::getAttackColor()); // Turn LED red
                    attack::start();                              // Start keystroke injection attack
                    led::setColor(preferences::getIdleColor());   // Turn LED green
                }
            }
            delay(100);
        }
    }

    debugln("[Finished]");
}

void loop() {}