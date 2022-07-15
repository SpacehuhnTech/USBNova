#include "config.h"
#include "debug.h"

#include "src/hid/hid.h"
#include "src/hid/keyboard.h"
#include "src/led/led.h"
#include "src/msc/msc.h"
#include "src/selector/selector.h"
#include "src/attack/attack.h"
#include "src/preferences/preferences.h"
#include "src/duckparser/duckparser.h"
#include "src/format/format.h"
#include "src/tasks/tasks.h"

enum Mode {
    SETUP, ATTACK
};

Mode mode;

void setup() {
    // Initialize all the things
    debug_init();
    selector::init();
    led::init();
    tasks::setCallback(loop);

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
    hid::setID(preferences::getHidVid(), preferences::getHidPid(), preferences::getHidRev());
    msc::setID(preferences::getMscVid().c_str(), preferences::getMscPid().c_str(), preferences::getMscRev().c_str());
    duckparser::setDefaultDelay(preferences::getDefaultDelay());

    // Start Keyboard
    hid::init();

    // Start USB Drive
    if (preferences::mscEnabled() || (mode == SETUP)) msc::enableDrive();

    // Wait 1s to give the computer time to initialize the keyboard
    delay(1000);

    // Disable capslock if needed
    if (preferences::getDisableCapslock()) {
        keyboard::disableCapslock();
        delay(10);
        hid::indicatorChanged();
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
                    led::stopBlink();                             // Stop LED blink

                    mode = SETUP;
                }
            }
            delay(100);
        }
    }
    // ==========  Setup Mode ==========  //
    else if (mode == ATTACK) {
        // Run on capslock
        if (preferences::getRunOnIndicator()) {
            while (!hid::indicatorChanged()) {
                delay(100);
            }
            keyboard::disableCapslock();
        }

        led::setColor(preferences::getAttackColor()); // Turn LED red
        attack::start();                              // Start keystroke injection attack
        led::setColor(preferences::getIdleColor());   // Turn LED green
        led::stopBlink();                             // Stop LED blink

        while (true) {
            if (selector::changed()) {
                mode = selector::read() ? SETUP : ATTACK;

                if (mode == ATTACK) {
                    led::setColor(preferences::getAttackColor()); // Turn LED red
                    attack::start();                              // Start keystroke injection attack
                    led::setColor(preferences::getIdleColor());   // Turn LED green
                    led::stopBlink();                             // Stop LED blink
                }
            }
            delay(100);
        }
    }

    debugln("[Finished]");
}

void loop() {
    led::update();
}