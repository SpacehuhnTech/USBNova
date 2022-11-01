/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "cli.h"

#include <SimpleCLI.h>

#include "../duckparser/duckparser.h"
#include "../preferences/preferences.h"
#include "../selector/selector.h"
#include "../led/led.h"
#include "../attack/attack.h"
#include "../msc/msc.h"
#include "../../config.h"

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
        
        // error
        cli.setOnError([](cmd_error* e) {
            CommandError cmdError(e);

            Serial.print("ERROR: ");
            Serial.println(cmdError.toString());

            if (cmdError.hasCommand()) {
                Serial.print("Did you mean \"");
                Serial.print(cmdError.getCommand().toString());
                Serial.println("\"?");
            }
        });

        // help
        cli.addCmd("help", [](cmd* c) {
            Serial.println("[ = Available Commands =]");
            Serial.print(cli.toString());
            Serial.println("Enter any BadUSB Scripts to run it.");
            Serial.println();
        }).setDescription(" Get a list of available commands.");

        // version
        cli.addCmd("version", [](cmd* c) {
            Serial.println("[ = USB Nova =]");
            Serial.print("Version ");
            Serial.println(VERSION);
            Serial.println("Source: https://github.com/spacehuhntech/usbnova");
            Serial.println("Made with <3 by Spacehuhn (spacehuhn.com)");
            Serial.println();
        }).setDescription(" Print the firmware version.");

        // format
        cli.addCmd("format", [](cmd* c) {
            led::setColor(255, 255, 255);
            msc::format(preferences::getDriveName().c_str());
            preferences::save();
            if(selector::mode() == SETUP) {
                led::setColor(preferences::getSetupColor());
            } else {
                led::setColor(preferences::getIdleColor());
            }
            
            Serial.println("Done formatting!");
            Serial.println();
        }).setDescription(" Fromat the internal memory.");

        // reset
        cli.addCmd("reset", [](cmd* c) {
            preferences::reset();
            preferences::save();
            
            Serial.println("Done resetting!");
            Serial.println();
        }).setDescription(" Reset the preferences.");
        
        // TODO: preferences
        cli.addSingleArgCmd("preferences", [](cmd* c) {
            preferences::print();
        }).setDescription(" Print preferences.");

        // ls
        cli.addSingleArgCmd("ls", [](cmd* c) {
            msc::print();
        }).setDescription(" Show available files on the drive.");

        // run
        cli.addSingleArgCmd("run", [](cmd* c) {
            Command cmd(c);
            Argument arg = cmd.getArgument(0);
            attack::start(arg.getValue().c_str());
            if(selector::mode() == SETUP) {
                led::setColor(preferences::getSetupColor());
            } else {
                led::setColor(preferences::getIdleColor());
            }
        }).setDescription(" Start a BadUSB Script.");
        
        // find
        cli.addSingleArgCmd("find", [](cmd* c) {
            const int pos { selector::position() };
            const std::string file { msc::find(pos) };

            Serial.print("Position: ");
            Serial.println(pos);
            Serial.print("Script: ");
            Serial.println(file.c_str());
        }).setDescription(" Find script based on switch position.");
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