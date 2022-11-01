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
#include "../selector/selector.h"

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
        msc::open(path);

        // Read and parse file
        char buffer[READ_BUFFER];

        size_t   len      = 0;
        uint32_t prev_pos = 0;
        uint32_t cur_pos  = 0;
        int repeats       = 0;

        // For LOOP_START and LOOP_END
        uint32_t start_pos = 0;
        int loops          = 0;

        while (true) {
            debug("Reading line...");
            if (!msc::getInLine()) cur_pos = msc::getPosition();
            len = msc::readLine(buffer, READ_BUFFER);
            debugln(len);
            //debugln(std::string(buffer, len-1).c_str());

            // Reached end of file
            if (len == 0) {
                debugln("Reached end of file");
                if (msc::openNextFile()) continue;
                else break;
            }

            debug("Parsing...");
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

            // For LOOP_START/LOOP_STOP
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

            debugln("OK");
        }

        debugln("Attack finished");
    }

    void start() {
        // Get switch position
        int pos = selector::position();

        // Find file that starts with that number
        std::string path = msc::find(pos);

        // If script was found, start running it
        if(path != "") start(path.c_str());
    }
}