/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include <Arduino.h>

#include "config.h"
#include "debug.h"

#include "hid/hid.h"
#include "hid/keyboard.h"
#include "led/led.h"
#include "msc/msc.h"
#include "selector/selector.h"
#include "attack/attack.h"
#include "preferences/preferences.h"
#include "duckparser/duckparser.h"
#include "tasks/tasks.h"
#include "cli/cli.h"

void update() {
    led::update();
    // cli::update();
}

void setup() {
    led::init();

    // Start Serial (for debug) or disable it
    debug_init();

#ifdef USE_CUSTOM_SPI_PINOUT    
    // Setup SPI with custom pinout
    SPI1.setSCK(SD_PIN_SCK);
    SPI1.setTX(SD_PIN_MOSI);
    SPI1.setRX(SD_PIN_MISO);
    SPI1.setCS(SD_PIN_CS);
    SPI1.begin();
#endif

    // Initialize memory and check for problems
    bool msc_ok = msc::init();
    if (!msc_ok) {
        debugln("Couldnt init SD");
        led::setColor(255, 0, 0, 200);
        // Don't abort; continue with defaults but skip MSC functionality.
    }

    // Read mode from selector switch
    selector::init();

    // Load setting and set USB Device IDs
    preferences::reset();
    if (msc_ok) {
        preferences::load();
    } else {
        // msc unavailable: keep defaults in preferences
    }

    if (selector::mode() == SETUP) preferences::save();

#ifdef MULTI_SELECTOR
    if (selector::position() == 1) {
        hid::setID(preferences::getVID1(), preferences::getPID1(), preferences::getVersion1());
        hid::setSerial(preferences::getSerial1());
        hid::setManufacturer(preferences::getManufacturer1());
        hid::setProduct(preferences::getProduct1());
    } else {
        hid::setID(preferences::getVID2(), preferences::getPID2(), preferences::getVersion2());
        hid::setSerial(preferences::getSerial2());
        hid::setManufacturer(preferences::getManufacturer2());
        hid::setProduct(preferences::getProduct2());
    }
#else
    hid::setID(preferences::getVID(), preferences::getPID(), preferences::getVersion());
    hid::setSerial(preferences::getSerial());
    hid::setManufacturer(preferences::getManufacturer());
    hid::setProduct(preferences::getProduct());
#endif

    // Start Keyboard
    if ((selector::mode() == ATTACK) || preferences::hidEnabled()) {
        hid::init();
    }

    // Start USB Drive (only if MSC initialized and enabled)
    if (msc_ok && (preferences::mscEnabled() || (selector::mode() == SETUP))) {
        msc::enableDrive();
    }

    #if !defined(LED_SIMPLE)
        // Enable LED instantly if RGB LED
        led::setEnable(preferences::ledEnabled());;
    #endif

    if (selector::mode() == SETUP) {
        #if defined(LED_SIMPLE)
            // Simple LED is always on in setup mode if enabled
            led::setEnable(preferences::ledEnabled());;
        #endif
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

#ifdef MULTI_SELECTOR
    // Create 1.txt file if it doesn't exist yet
    if (msc::find(1) == "") {
        msc::write("1.txt", "# Hello World\n", 14);
    }

    // Create 2.txt file if it doesn't exist yet
    if (msc::find(2) == "") {
        msc::write("2.txt", "# Hello World\n", 14);
    }
#else
    // Create main_script.txt if it doesn't exist yet
    if (!msc::exists(preferences::getMainScript().c_str())) {
        char message[21];
        sprintf(message, "# USB Nova (v%s)\n", VERSION);
        msc::write(preferences::getMainScript().c_str(), message, 20);
    }
#endif

    // Setup background tasks
    tasks::setCallback(update);

    // Make sure we don't start with a mode change
    selector::changed();

    // Start attack
    if ((selector::mode() == ATTACK) && !preferences::getRunOnIndicator()) {
        delay(preferences::getInitialDelay()); // Wait to give computer time to init keyboard
        #if defined(LED_SIMPLE)
            // If Simple LED is enabled turn it on for duration of attack
            led::setEnable(preferences::ledEnabled());
        #endif
        attack::start(); // Start keystroke injection attack
        #if defined(LED_SIMPLE)
            // Disable Simple LED after attack
            led::setEnable(false);
        #else
            led::setColor(preferences::getIdleColor()); // Set LED to green
        #endif
    }

    // Setup CLI
#ifdef ENABLE_DEBUG
    cli::init();
#endif // ifdef ENABLE_DEBUG

    debugln("[Started]");
}

void loop() {
    tasks::update();
    cli::update();

    if (selector::read() != ATTACK) return;

    // Only start the attack if run-on-indicator is disabled, or indicator actually changed
    if (preferences::getRunOnIndicator() && hid::indicatorChanged()) {
        delay(100);
        attack::start();                            // Run script
        led::setColor(preferences::getIdleColor()); // Set LED to green

        // Don't run again
        while (true) {
            tasks::update();
            cli::update();
        }
    } else if (selector::changed()) {
        // ==========  Setup Mode ==========  //
        if ((selector::mode() == SETUP) && preferences::hidEnabled()) {
            preferences::load(); // Reload the settings (in case the main script path changed)

            // Attack settings
            keyboard::setLocale(locale::get(preferences::getDefaultLayout().c_str()));
            duckparser::setDefaultDelay(preferences::getDefaultDelay());

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