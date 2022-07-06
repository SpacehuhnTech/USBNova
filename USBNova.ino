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

enum Mode {
    SETUP, ATTACK
};

Mode mode;

void setup() {
    // Initialize all the things
    debug_init();
    msc::init();
    keyboard::init();
    selector::init();
    led::init();
    preferences::load();

    // Preferences
    led::setEnable(preferences::ledEnabled());

    // Start doing the work
    mode = selector::read() ? SETUP : ATTACK;

    // ==========  Setup Mode ==========  //
    if (mode == SETUP) {
        // Set LED to green
        led::setColor(0, 255, 0);

        while (true) {
            if (selector::changed()) {
                mode = selector::read() ? SETUP : ATTACK;

                if (mode == ATTACK) {
                    led::setColor(255, 0, 0); // Turn LED red
                    attack::start();          // Start attack
                    led::setColor(0, 255, 0); // Turn LED green
                    mode = SETUP;
                }
            }
            delay(100);
        }
    }
    // ==========  Setup Mode ==========  //
    else if (mode == ATTACK) {
        // Set LED to red
        led::setColor(255, 0, 0);

        // Start running keystroke injection attack
        attack::start();
    }

    debugln("[Finished]");
}

void loop() {}