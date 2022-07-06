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

enum Mode {
    SETUP, ATTACK
};

Mode mode;

void setup() {
    // Initialize all the things
    debug_init();
    msc::init();
    selector::init();
    led::init();
    preferences::load();

    // Read the mode from the toggle switch position
    mode = selector::read() ? SETUP : ATTACK;

    // Preferences
    led::setEnable(preferences::ledEnabled());
    keyboard::setLocale(locale::get(preferences::getDefaultLayout().c_str()));
    keyboard::setID(preferences::getHidVid(), preferences::getHidPid(), preferences::getHidRev());
    msc::setID(preferences::getMscVid().c_str(), preferences::getMscPid().c_str(), preferences::getMscRev().c_str());
    duckparser::setDefaultDelay(preferences::getDefaultDelay());

    // Start Keyboard
    keyboard::init();

    // Start USB Drive
    if (preferences::mscEnabled() || (mode == SETUP)) msc::enableDrive();

    // ==========  Setup Mode ==========  //
    if (mode == SETUP) {
        led::setColor(0, 0, 20); // Set LED to blue

        while (true) {
            if (selector::changed()) {
                mode = selector::read() ? SETUP : ATTACK;

                if (mode == ATTACK) {
                    led::setColor(128, 0, 0); // Turn LED red
                    attack::start();          // Start keystroke injection attack
                    led::setColor(0, 0, 20);  // Set LED to blue
                    mode = SETUP;
                }
            }
            delay(100);
        }
    }
    // ==========  Setup Mode ==========  //
    else if (mode == ATTACK) {
        delay(1000);              // Wait 1s to give the computer time to initialize the keyboard

        led::setColor(128, 0, 0); // Turn LED red
        attack::start();          // Start keystroke injection attack
        led::setColor(0, 30, 0);  // Turn LED green

        while (true) {
            if (selector::changed()) {
                mode = selector::read() ? SETUP : ATTACK;

                if (mode == ATTACK) {
                    led::setColor(128, 0, 0); // Turn LED red
                    attack::start();          // Start keystroke injection attack
                    led::setColor(0, 30, 0);  // Turn LED green
                }
            }
            delay(100);
        }
    }

    debugln("[Finished]");
}

void loop() {}