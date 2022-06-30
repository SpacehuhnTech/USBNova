/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "led.h"

#include "../../config.h"

#include <Arduino.h> // pinMode(), analogWrite(), millis()
#include <Adafruit_NeoPixel.h> // Adafruit_NeoPixel

namespace led {
    // ========== PRIVATE ========= //
    Adafruit_NeoPixel led { 1, LED_PIN, NEO_GRB + NEO_KHZ800 };

    uint8_t blink_color[3] { 0, 0, 0 };
    unsigned long blink_intv { 0 };
    bool blink_flag { false };
    unsigned long last_blink { 0 };

    // ========== PUBLIC ========= //
    void start_blink(uint8_t r, uint8_t g, uint8_t b, unsigned long intv) {
        blink_color[0] = r;
        blink_color[1] = g;
        blink_color[2] = b;
        blink_intv     = intv;
    }

    void stop_blink() {
        blink_intv = 0;
        setColor(blink_color[0], blink_color[1], blink_color[2]);
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

    void begin() {
        led.begin();
        led.show();
    }

    void setColor(int r, int g, int b) {
        for (size_t i = 0; i<led.numPixels(); i++) {
            led.setPixelColor(i, r, g, b);
        }

        led.show();
    }
}