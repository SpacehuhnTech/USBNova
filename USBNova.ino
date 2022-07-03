/*
 * Note2: If your flash is not formatted as FAT12 previously, you could format it using
 * follow sketch https://github.com/adafruit/Adafruit_SPIFlash/tree/master/examples/SdFat_format
 */

#include "config.h"
#include "debug.h"

#include "src/keyboard/keyboard.h"
#include "src/led/led.h"
#include "src/duckparser/duckparser.h"
#include "src/msc/msc.h"
#include "src/selector/selector.h"

void setup() {
    debug_init();
    debugln("Started");

    msc::init();
    keyboard::init();
    selector::init();
    led::init();

    /*
    // Wait until Serial Monitor was opened
    while (!Serial) {
        delay(1);
    }
    */

    delay(1000);
    debugln("Started");

    // Setup Mode
    if (selector::read()) {
        led::setColor(0, 255, 0);
        debugln("Setup Mode");
    }
    // Attack Mode
    else {
        led::setColor(255, 0, 0);
        debugln("Attack Mode");

        msc::open("/payload.script");

        delay(1000);

        start_attack();
    }

    debugln("Finished");
}

void loop() {
    /*
       if(msc::changed()) {
        FatFile file;

        if(file.open("/payload.dd")) {
            size_t fsize = file.fileSize();

            char _buf[fsize + 1];

            file.read(_buf, fsize);
            _buf[fsize] = '\0';

            Serial.println(_buf);

            file.close();
        }
       }*/
}

void start_attack() {
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
        debugln(std::string(buffer, len-1).c_str());

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
            loops          = duckparser::getLoops();
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
}