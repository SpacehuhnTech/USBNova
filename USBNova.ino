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

    // Setup Mode
    if(selector::read()) {
        led::setColor(0, 255, 0);
        debugln("Setup Mode");

    }

    // Attack Mode
    else {
        led::setColor(255, 0, 0);
        debugln("Attack Mode");
        
        // Start reading file
        msc::prepareRead("/payload.script");
        
        // Read and parse file
        char buffer[READ_BUFFER];
        size_t len;
        do {
            len = msc::readLine(buffer, READ_BUFFER);
            duckparser::parse(buffer, len);
        } while(len > 0);
    }


    //Serial.begin(115200);

    // while ( !Serial ) delay(10);   // wait for native usb

    /*
        // Wait a bit
        delay(1000);

        msc::prepareRead("payload.dd");

        // Read script from SD Card
        char   last_buffer[READ_BUFFER];
        size_t last_buffer_len { 0 };

        char   buffer[READ_BUFFER];
        size_t buffer_len { 0 };

        do {
            buffer_len = msc::readLine(buffer, READ_BUFFER);

            duckparser::parse(buffer, buffer_len);

            int repeats = duckparser::getRepeats();
            if (repeats > 0) {
                debug("[repeat x");
                debug(repeats);
                debugln("]");

                for (int i = 0; i<repeats; ++i) {
                    debugln("[repeating]");
                    duckparser::parse(last_buffer, last_buffer_len);
                }
            }

            memcpy(last_buffer, buffer, buffer_len);
            last_buffer_len = buffer_len;
     #ifdef ENABLE_DEBUG

            for (size_t i = 0; i<buffer_len; ++i) {
                debug(buffer[i]);
            }
     #endif // ifdef ENABLE_DEBUG 3THIS ISA N3moal,lSCRUPT 1
        } while(buffer_len > 0);
     */
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