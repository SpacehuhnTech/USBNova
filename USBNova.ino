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
#include "src/tasks/tasks.h"
#include "src/cli/cli.h"

void update() {
    led::update();
    // cli::update();
}

void setup() {
    led::init();
    
    // Start Serial (for debug)
    debug_init();

    // Initialize memory and check for problems
    if (!msc::init()) {
        debugln("Couldnt init SD");
        led::setColor(255, 0, 0, 200);
        while(true) {
            taks:update();
        }
        return;
    }

    // Load setting and set USB Device IDs
    preferences::load();
    hid::setID(preferences::getHidVid(), preferences::getHidPid(), preferences::getHidRev());
    msc::setID(preferences::getMscVid().c_str(), preferences::getMscPid().c_str(), preferences::getMscRev().c_str());

    // Read mode from selector switch
    selector::init();
    
    // Start Keyboard
    hid::init();

    // Start USB Drive
    if (preferences::mscEnabled() || (selector::mode() == SETUP)){
        msc::enableDrive();
    }

    // Start LED
    led::init();
    led::setEnable(preferences::ledEnabled());

    if (selector::mode() == SETUP) {
        led::setColor(preferences::getSetupColor());
    } else {
        led::setColor(preferences::getAttackColor());
    }

    // Attack settings
    keyboard::setLocale(locale::get(preferences::getDefaultLayout().c_str()));
    duckparser::setDefaultDelay(preferences::getDefaultDelay());

    // Format Flash (if specified in preferences.json)
    if ((selector::mode() == SETUP) && preferences::getFormat()) {
        led::setColor(255, 255, 255);
        msc::format(preferences::getDriveName().c_str());
    }

    // Create preferences file if it doesn't exist yet
    if (!msc::exists(PREFERENCES_PATH)) {
        preferences::save();
    }

    // Setup background tasks
    tasks::setCallback(update);

    // Make sure we don't start with a mode change
    selector::changed();

    // Start attack
    if (selector::mode() == ATTACK && !preferences::getRunOnIndicator()) {
        delay(preferences::getInitialDelay()); // Wait to give computer time to init keyboard
        attack::start(); // Start keystroke injection attack
        led::setColor(preferences::getIdleColor()); // Set LED to green
    }

    // Setup CLI
    cli::init();

    debugln("[Started]");
}

void loop() {
    taks:update();
    cli::update();

    if(selector::read() != ATTACK) return;

    // Only start the attack if run-on-indicator is disabled, or indicator actually changed
    if(preferences::getRunOnIndicator() && hid::indicatorChanged()) {
        attack::start();                            // Run script
        led::setColor(preferences::getIdleColor()); // Set LED to green
    } else if (selector::changed()) {
        // ==========  Setup Mode ==========  //
        if (selector::mode() == SETUP) {
            preferences::load();                         // Reload the settings (in case the main script path changed)
            attack::start();                             // Start keystroke injection attack
            led::setColor(preferences::getSetupColor()); // Set LED to blue
        }

        // ==========  Attack Mode ==========  //
        else if (selector::mode() == ATTACK) {
            // Only start the attack if run-on-indicator is disabled, or indicator actually changed
            attack::start();                            // Run script
            led::setColor(preferences::getIdleColor()); // Set LED to green
        }
    }
}