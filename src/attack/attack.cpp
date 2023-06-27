/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "attack.h"

#include "../../config.h"
#include "../../debug.h"

#include "../msc/msc.h"
#include "../duckparser/duckparser.h"
#include "../preferences/preferences.h"
#include "../led/led.h"
#include "../hid/hid.h"
#include "../hid/keyboard.h"

namespace attack {
    // ====== PRIVATE ====== //

    // ====== PUBLIC ====== //
    void start(const char* path) {
        // If script doesn't exist, don't do anything
        if (!msc::exists(path)) return;

        // Set attack color
        led::setColor(preferences::getAttackColor());

        // Disable capslock if needed
        if (preferences::getDisableCapslock()) {
            keyboard::disableCapslock();
            delay(10);
            hid::indicatorChanged();
        }

        // Open main BadUSB script
        msc::open(preferences::getMainScript().c_str());

        // Read and parse file
        char buffer[READ_BUFFER];

        size_t   len      = 0;
        uint32_t prev_pos = 0;
        uint32_t cur_pos  = 0;
        int repeats       = 0;

        // For LOOP_BEGIN and LOOP_END
        uint32_t start_pos = 0;
        int loops          = 0;

        while (true) {
            debugF("Reading line...");
            if (!msc::getInLine()) cur_pos = msc::getPosition();
            len = msc::readLine(buffer, READ_BUFFER);

            // Reached end of file
            if (len == 0) {
                debuglnF("Reached end of file");
                if (msc::openNextFile()) continue;
                else break;
            }

            debugln(len);
            debugln(std::string(buffer, len-1).c_str());

            debugF("Parsing...");
            duckparser::parse(buffer, len);

            // For REPEAT/REPLAY
            repeats = duckparser::getRepeats();

            for (int i = 0; i<repeats; ++i) {
                msc::gotoPosition(prev_pos);

                do {
                    len = msc::readLine(buffer, READ_BUFFER);
                    duckparser::parse(buffer, len);
                } while (msc::getInLine());
            }

            if (!msc::getInLine()) prev_pos = cur_pos;

            // For LOOP_BEGIN/LOOP_END
            if (duckparser::loopBegin()) {
                start_pos = msc::getPosition();
                loops     = duckparser::getLoops();
            } else if (duckparser::loopEnd() && (loops > 1)) {
                msc::gotoPosition(start_pos);
                --loops;
            }

            // For IMPORT
            if (duckparser::import()) {
                std::string path = duckparser::getImport();
                msc::open(path.c_str());
            }

            debuglnF("OK");
        }
        debuglnF("Attack finished");
    }

    void start() {
        start(preferences::getMainScript().c_str());
    }
}