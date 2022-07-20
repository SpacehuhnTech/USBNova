/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "mouse.h"

#include "hid.h"

namespace mouse {
    // ====== PRIVATE ====== //
    report_t prev_report = report_t{  0, 0, 0, 0, 0 };

    report_t make_report(uint8_t buttons = 0, int8_t x = 0, int8_t y = 0, int8_t vertical = 0, int8_t horizontal = 0);

    report_t make_report(uint8_t buttons, int8_t x, int8_t y, int8_t vertical, int8_t horizontal) {
        report_t m;

        m.buttons    = buttons;
        m.x          = x;
        m.y          = y;
        m.vertical   = vertical;
        m.horizontal = horizontal;

        return m;
    }

    // ====== PUBLIC ====== //
    void send(report_t* m) {
        hid::sendMouseReport(m->buttons, m->x, m->y, m->vertical, m->horizontal);
    }

    void release() {
        prev_report = make_report();
        send(&prev_report);
    }

    void move(int8_t x, int8_t y) {
        prev_report.x += x;
        prev_report.y += y;

        send(&prev_report);
        release();
    }

    void click(uint8_t button) {
        // Mouse buttons: https://github.com/hathach/tinyusb/blob/master/src/class/hid/hid.h#L306
        press(button);
        release(button);
    }

    void press(uint8_t button) {
        prev_report.buttons |= button;

        send(&prev_report);
    }

    void release(uint8_t button) {
        prev_report.buttons &= ~button;

        send(&prev_report);
    }

    void scroll(int8_t vertical, int8_t horizontal) {
        prev_report.vertical   += vertical;
        prev_report.horizontal += horizontal;

        send(&prev_report);
        release();
    }
}