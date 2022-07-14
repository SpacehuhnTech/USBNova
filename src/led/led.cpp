/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "led.h"

#include "../../config.h"

#include <Arduino.h>           // pinMode(), analogWrite(), millis()
#include <Adafruit_NeoPixel.h> // Adafruit_NeoPixel

namespace led {
    // ========== PRIVATE ========= //
    Adafruit_NeoPixel led { 1, LED_PIN, NEO_GRB + NEO_KHZ800 };

    uint8_t blink_color[3] { 0, 0, 0 };
    unsigned long blink_intv { 0 };
    bool blink_flag { false };
    unsigned long last_blink { 0 };

    // ========== PUBLIC ========= //
    void init() {
        led.begin();
        led.show();
    }

    void setEnable(bool enabled) {
        if (enabled) {
            led.setBrightness(255);
        } else {
            led.setBrightness(0);
        }
    }

    void setColor(int* color) {
        setColor(color[0], color[1], color[2]);
    }

    void setColor(int r, int g, int b) {
        for (size_t i = 0; i<led.numPixels(); i++) {
            led.setPixelColor(i, r, g, b);
        }

        led.show();
    }

    void startBlink(uint8_t r, uint8_t g, uint8_t b, unsigned long intv) {
        blink_color[0] = r;
        blink_color[1] = g;
        blink_color[2] = b;
        blink_intv     = intv;
    }

    void stopBlink() {
        blink_intv = 0;
    }

    void setMode(Color color, Mode mode) {
        uint8_t r = (color == RED) ? 255 : 0;
        uint8_t g = (color == GREEN) ? 255 : 0;
        uint8_t b = (color == BLUE) ? 255 : 0;

        switch (mode) {
            case SOLID:
                setColor(r, g, b);
                break;
            case SLOW:
                startBlink(r, g, b, 1000);
                break;
            case FAST:
                startBlink(r, g, b, 200);
                break;
            default:
                setColor(0, 0, 0);
                stopBlink();
        }
    }

    void update() {
        if ((blink_intv > 0) && (millis() - last_blink >= blink_intv)) {
            last_blink = millis();
            blink_flag = !blink_flag;

            if (blink_flag) {
                setColor(blink_color[0], blink_color[1], blink_color[2]);
            } else {
                setColor(0, 0, 0);
            }
        }
    }
}