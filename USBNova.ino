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

void setup() {
    // ===== Initialize the minimum required modules to start the USB device stack ===== //
    debug_init();
    selector::init();
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
    preferences::load();
    hid::setID(preferences::getHidVid(), preferences::getHidPid(), preferences::getHidRev());
    msc::setID(preferences::getMscVid().c_str(), preferences::getMscPid().c_str(), preferences::getMscRev().c_str());

    // ===== Initialize the USB device stack ===== //
    // Start Keyboard
    hid::init();
    // Start USB Drive
    if (preferences::mscEnabled() || (selector::mode() == SETUP)) msc::enableDrive();

    // ===== Initialize the remaining modules ===== //
    led::init();
    tasks::setCallback(loop);
    led::setEnable(preferences::ledEnabled());
    keyboard::setLocale(locale::get(preferences::getDefaultLayout().c_str()));
    duckparser::setDefaultDelay(preferences::getDefaultDelay());

    // ---

    // Format Flash
    if ((selector::mode() == SETUP) && preferences::getFormat()) {
        led::setColor(255, 255, 255);
        format::start(preferences::getDriveName().c_str());
    }

    // Create preferences file if it doesn't exist yet
    if (!msc::exists(PREFERENCES_PATH)) {
        preferences::save();
    }

    // Wait 1s to give the computer time to initialize the keyboard
    delay(1000);

    // Disable capslock if needed
    if (preferences::getDisableCapslock()) {
        keyboard::disableCapslock();
        delay(10);
        hid::indicatorChanged();
    }

    // ==========  Setup Mode ==========  //
    if (selector::mode() == SETUP) {
        led::setColor(preferences::getSetupColor()); // Set LED to blue

        while (true) {
            if (selector::changed() && selector::read() == ATTACK) {
                preferences::load();                         // Reload the settings (in case the main script path changed)
                attack::start();                             // Start keystroke injection attack
                led::setColor(preferences::getSetupColor()); // Set LED to blue
            }
            delay(100);
        }
    }
    // ==========  Setup Mode ==========  //
    else if (selector::mode() == ATTACK) {
        // Run on capslock
        if (preferences::getRunOnIndicator()) {
            while (!hid::indicatorChanged()) {
                delay(100);
            }
            keyboard::disableCapslock();
        }

        attack::start(); // Start keystroke injection attack

        while (true) {
            if (selector::changed() && selector::read() == ATTACK) {
                attack::start(); // Start keystroke injection attack
            }
            delay(100);
        }
    }

    debugln("[Finished]");
}

void loop() {
    led::update();
}