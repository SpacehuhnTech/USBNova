/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "cli.h"

#include <SimpleCLI.h>

#include "../duckparser/duckparser.h"

#define BUFFER_SIZE 1024

namespace cli {
    // ====== PRIVATE ====== //
    SimpleCLI  cli;
    char buffer[BUFFER_SIZE];

    // Copied from https://github.com/SpacehuhnTech/esp8266_deauther/blob/b70dc19579e7af65857726ae45e3e477899942ac/esp8266_deauther/cli.cpp#L1602
    size_t read(char* dest, size_t max_len) {
        size_t i = 0;

        while (i < max_len) {
            // Wait until input is available
            if (!Serial.available()) {
                delay(1);
                continue;
            }

            // Read next character
            int c = Serial.read();

            // Printable ASCII characters
            if ((c >= ' ') && (c <= '~')) {
                // Add it to the string
                dest[i++] = c;
            }
            // If end of line, check next char and break the loop
            else if ((c == '\r') || (c == '\n')) {
                delay(1);
                c = Serial.peek();
                if ((c == '\r') || (c == '\n')) Serial.read();

                dest[i++] = '\n';

                break;
            }
            // Backspace key
            else if ((c == 127) || (c == 8)) {
                --i;
            }
        }

        return i;
    }

    // ====== PUBLIC ====== //
    void init() {
        Serial.begin(115200);
        /*
        // help
        cli.addCmd("format", [](cmd* c) {
            cli.help();
        });

        // version
        cli.addCmd("format", [](cmd* c) {
            Serial.println(VERSION);
        });

        // format
        cli.addCmd("format", [](cmd* c) {
            msc::format();
        });

        // reset
        cli.addCmd("rest", [](cmd* c) {
            preferences::reset();
        });
        */
    }

    void update() {
        if (Serial.available()) {
            size_t len = read(buffer, BUFFER_SIZE);
            if (len == 0) return;

            // Starts with an uppercase character => BadUSB Script
            if ((buffer[0] >= 'A') && (buffer[0] <= 'Z')) {
                duckparser::parse(buffer, len);
            }
            // Otherwise => CLI
            else {
                cli.parse(buffer, len);
            }
        }
    }
}