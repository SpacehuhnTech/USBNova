/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "duckparser.h"

#include "../../config.h"
#include "../keyboard/keyboard.h"
#include "../led/led.h"

#include <Arduino.h> // millis(), delay()

extern "C" {
 #include "parser.h" // parse_lines
}

namespace duckparser {
    // ====== PRIVATE ===== //
    bool in_string       = false;
    bool in_comment      = false;
    bool in_large_string = false;
    bool loop_begin      = false;
    bool loop_end        = false;

    int default_delay = 5;
    int repeat_num    = 0;
    int loop_num      = 0;

    std::string import_path = "";

    unsigned long interpret_time   = 0;
    unsigned long sleep_start_time = 0;
    unsigned long sleep_time       = 0;

    void type(const char* str, size_t len) {
        keyboard::write(str, len);
    }

    void press(const char* str, size_t len) {
        // character
        if (len == 1) keyboard::press(str);

        // Keys
        else if (compare(str, len, "ENTER", CASE_SENSETIVE)) keyboard::pressKey(KEY_ENTER);
        else if (compare(str, len, "MENU", CASE_SENSETIVE) || compare(str, len, "APP", CASE_SENSETIVE)) keyboard::pressKey(KEY_PROPS);
        else if (compare(str, len, "DELETE", CASE_SENSETIVE)) keyboard::pressKey(KEY_DELETE);
        else if (compare(str, len, "BACKSPACE", CASE_SENSETIVE)) keyboard::pressKey(KEY_BACKSPACE);
        else if (compare(str, len, "HOME", CASE_SENSETIVE)) keyboard::pressKey(KEY_HOME);
        else if (compare(str, len, "INSERT", CASE_SENSETIVE)) keyboard::pressKey(KEY_INSERT);
        else if (compare(str, len, "PAGEUP", CASE_SENSETIVE)) keyboard::pressKey(KEY_PAGEUP);
        else if (compare(str, len, "PAGEDOWN", CASE_SENSETIVE)) keyboard::pressKey(KEY_PAGEDOWN);
        else if (compare(str, len, "UPARROW", CASE_SENSETIVE) || compare(str, len, "UP", CASE_SENSETIVE)) keyboard::pressKey(KEY_UP);
        else if (compare(str, len, "DOWNARROW", CASE_SENSETIVE) || compare(str, len, "DOWN", CASE_SENSETIVE)) keyboard::pressKey(KEY_DOWN);
        else if (compare(str, len, "LEFTARROW", CASE_SENSETIVE) || compare(str, len, "LEFT", CASE_SENSETIVE)) keyboard::pressKey(KEY_LEFT);
        else if (compare(str, len, "RIGHTARROW", CASE_SENSETIVE) || compare(str, len, "RIGHT", CASE_SENSETIVE)) keyboard::pressKey(KEY_RIGHT);
        else if (compare(str, len, "TAB", CASE_SENSETIVE)) keyboard::pressKey(KEY_TAB);
        else if (compare(str, len, "END", CASE_SENSETIVE)) keyboard::pressKey(KEY_END);
        else if (compare(str, len, "ESC", CASE_SENSETIVE) || compare(str, len, "ESCAPE", CASE_SENSETIVE)) keyboard::pressKey(KEY_ESC);
        else if (compare(str, len, "SPACE", CASE_SENSETIVE)) keyboard::pressKey(KEY_SPACE);
        else if (compare(str, len, "PAUSE", CASE_SENSETIVE) || compare(str, len, "BREAK", CASE_SENSETIVE)) keyboard::pressKey(KEY_PAUSE);
        else if (compare(str, len, "CAPSLOCK", CASE_SENSETIVE)) keyboard::pressKey(KEY_CAPSLOCK);
        else if (compare(str, len, "NUMLOCK", CASE_SENSETIVE)) keyboard::pressKey(KEY_NUMLOCK);
        else if (compare(str, len, "PRINTSCREEN", CASE_SENSETIVE)) keyboard::pressKey(KEY_SYSRQ);
        else if (compare(str, len, "SCROLLLOCK", CASE_SENSETIVE)) keyboard::pressKey(KEY_SCROLLLOCK);

        // Function Keys
        else if (compare(str, len, "F1", CASE_SENSETIVE)) keyboard::pressKey(KEY_F1);
        else if (compare(str, len, "F2", CASE_SENSETIVE)) keyboard::pressKey(KEY_F2);
        else if (compare(str, len, "F3", CASE_SENSETIVE)) keyboard::pressKey(KEY_F3);
        else if (compare(str, len, "F4", CASE_SENSETIVE)) keyboard::pressKey(KEY_F4);
        else if (compare(str, len, "F5", CASE_SENSETIVE)) keyboard::pressKey(KEY_F5);
        else if (compare(str, len, "F6", CASE_SENSETIVE)) keyboard::pressKey(KEY_F6);
        else if (compare(str, len, "F7", CASE_SENSETIVE)) keyboard::pressKey(KEY_F7);
        else if (compare(str, len, "F8", CASE_SENSETIVE)) keyboard::pressKey(KEY_F8);
        else if (compare(str, len, "F9", CASE_SENSETIVE)) keyboard::pressKey(KEY_F9);
        else if (compare(str, len, "F10", CASE_SENSETIVE)) keyboard::pressKey(KEY_F10);
        else if (compare(str, len, "F11", CASE_SENSETIVE)) keyboard::pressKey(KEY_F11);
        else if (compare(str, len, "F12", CASE_SENSETIVE)) keyboard::pressKey(KEY_F12);

        // NUMPAD KEYS
        else if (compare(str, len, "NUM_0", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP0);
        else if (compare(str, len, "NUM_1", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP1);
        else if (compare(str, len, "NUM_2", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP2);
        else if (compare(str, len, "NUM_3", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP3);
        else if (compare(str, len, "NUM_4", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP4);
        else if (compare(str, len, "NUM_5", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP5);
        else if (compare(str, len, "NUM_6", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP6);
        else if (compare(str, len, "NUM_7", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP7);
        else if (compare(str, len, "NUM_8", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP8);
        else if (compare(str, len, "NUM_9", CASE_SENSETIVE)) keyboard::pressKey(KEY_KP9);
        else if (compare(str, len, "NUM_ASTERIX", CASE_SENSETIVE)) keyboard::pressKey(KEY_KPASTERISK);
        else if (compare(str, len, "NUM_ENTER", CASE_SENSETIVE)) keyboard::pressKey(KEY_KPENTER);
        else if (compare(str, len, "NUM_MINUS", CASE_SENSETIVE)) keyboard::pressKey(KEY_KPMINUS);
        else if (compare(str, len, "NUM_DOT", CASE_SENSETIVE)) keyboard::pressKey(KEY_KPDOT);
        else if (compare(str, len, "NUM_PLUS", CASE_SENSETIVE)) keyboard::pressKey(KEY_KPPLUS);

        // Modifiers
        else if (compare(str, len, "CTRL", CASE_SENSETIVE) || compare(str, len, "CONTROL", CASE_SENSETIVE)) keyboard::pressModifier(KEY_MOD_LCTRL);
        else if (compare(str, len, "SHIFT", CASE_SENSETIVE)) keyboard::pressModifier(KEY_MOD_LSHIFT);
        else if (compare(str, len, "ALT", CASE_SENSETIVE)) keyboard::pressModifier(KEY_MOD_LALT);
        else if (compare(str, len, "ALTGR", CASE_SENSETIVE)) keyboard::pressModifier(KEY_MOD_RALT);
        else if (compare(str, len, "WINDOWS", CASE_SENSETIVE) || compare(str, len, "GUI", CASE_SENSETIVE)) keyboard::pressModifier(KEY_MOD_LMETA);

        // Numpad Keys

        // Utf8 character
        else keyboard::press(str);
    }

    void release() {
        keyboard::release();
    }

    unsigned int toInt(const char* str, size_t len) {
        if (!str || (len == 0)) return 0;

        unsigned int val = 0;

        // HEX
        if ((len > 2) && (str[0] == '0') && (str[1] == 'x')) {
            for (size_t i = 2; i < len; ++i) {
                uint8_t b = str[i];

                if ((b >= '0') && (b <= '9')) b = b - '0';
                else if ((b >= 'a') && (b <= 'f')) b = b - 'a' + 10;
                else if ((b >= 'A') && (b <= 'F')) b = b - 'A' + 10;

                val = (val << 4) | (b & 0xF);
            }
        }
        // DECIMAL
        else {
            for (size_t i = 0; i < len; ++i) {
                if ((str[i] >= '0') && (str[i] <= '9')) {
                    val = val * 10 + (str[i] - '0');
                }
            }
        }

        return val;
    }

    void sleep(unsigned long time) {
        unsigned long offset = millis() - interpret_time;

        if (time > offset) {
            sleep_start_time = millis();
            sleep_time       = time - offset;

            delay(sleep_time);
        }
    }

    // ====== PUBLIC ===== //

    void setDefaultDelay(int defaultDelay) {
        default_delay = defaultDelay;
    }

    void parse(const char* str, size_t len) {
        interpret_time = millis();

        // Split str into a list of lines
        line_list* l = parse_lines(str, len);

        // Go through all lines
        line_node* n = l->first;

        // Flag, no default delay after this command
        bool ignore_delay;

        while (n) {
            ignore_delay = false;
            loop_begin   = false;
            loop_end     = false;

            word_list* wl  = n->words;
            word_node* cmd = wl->first;

            // String of the entire line excluding the command keyword (i.e. "STRING ")
            const char* line_str = cmd->str + cmd->len + 1;
            size_t line_str_len  = n->len - cmd->len - 1;

            char last_char = n->str[n->len];
            bool line_end  = last_char == '\r' || last_char == '\n';

            // Check if we're in a large string
            if (in_large_string) {
                // Stop it
                if (compare(cmd->str, cmd->len, "LSTRING_END", CASE_SENSETIVE)) {
                    in_large_string = false;
                    ignore_delay    = true;
                }
                // or type out the entire line
                else {
                    type(n->str, n->len);
                    keyboard::pressKey(KEY_ENTER);
                }
            }
            // LSTRING_BEGIN (-> type each character including linebreaks until LSTRING_END)
            else if (compare(cmd->str, cmd->len, "LSTRING_BEGIN", CASE_SENSETIVE)) {
                in_large_string = true;
                ignore_delay    = true;
            }
            // REM or # (= Comment -> do nothing)
            else if (in_comment || compare(cmd->str, cmd->len, "REM", CASE_SENSETIVE) || compare(cmd->str, cmd->len, "#", CASE_SENSETIVE)) {
                in_comment   = !line_end;
                ignore_delay = true;
            }
            // default_delay/DEFAULT_DELAY (set default delay per command)
            else if (compare(cmd->str, cmd->len, "default_delay", CASE_SENSETIVE) || compare(cmd->str, cmd->len, "DEFAULT_DELAY", CASE_SENSETIVE)) {
                default_delay = toInt(line_str, line_str_len);
                ignore_delay  = true;
            }
            // DELAY (-> sleep for x ms)
            else if (compare(cmd->str, cmd->len, "DELAY", CASE_SENSETIVE)) {
                sleep(toInt(line_str, line_str_len));
                ignore_delay = true;
            }
            // STRING (-> type each character)
            else if (in_string || compare(cmd->str, cmd->len, "STRING", CASE_SENSETIVE)) {
                // Type the entire line
                if (in_string) {
                    type(n->str, n->len);
                }
                // Type the everything after "STRING "
                else {
                    type(line_str, line_str_len);
                }

                in_string = !line_end;
            }
            // REPEAT (-> repeat last command n times)
            else if (compare(cmd->str, cmd->len, "REPEAT", CASE_SENSETIVE) || compare(cmd->str, cmd->len, "REPLAY", CASE_SENSETIVE)) {
                repeat_num   = toInt(line_str, line_str_len) + 1;
                ignore_delay = true;
            }
            // LOOP_BEGIN
            else if (compare(cmd->str, cmd->len, "LOOP_BEGIN", CASE_SENSETIVE)) {
                loop_num     = toInt(line_str, line_str_len);
                loop_begin   = true;
                ignore_delay = true;
            }
            // LOOP_END
            else if (compare(cmd->str, cmd->len, "LOOP_END", CASE_SENSETIVE)) {
                loop_end     = true;
                ignore_delay = true;
            }
            // LOCALE (-> change keyboard layout)
            else if (compare(cmd->str, cmd->len, "LOCALE", CASE_SENSETIVE)) {
                word_node* w = cmd->next;

                keyboard::setLocale(locale::get(w->str));

                ignore_delay = true;
            }
            // LED
            else if (compare(cmd->str, cmd->len, "LED", CASE_SENSETIVE)) {
                word_node* w = cmd->next;

                int c[3];

                for (uint8_t i = 0; i<3; ++i) {
                    if (w) {
                        c[i] = toInt(w->str, w->len);
                        w    = w->next;
                    } else {
                        c[i] = 0;
                    }
                }

                led::setColor(c[0], c[1], c[2]);
            }
            // KEYCODE
            else if (compare(cmd->str, cmd->len, "KEYCODE", CASE_SENSETIVE)) {
                word_node* w = cmd->next;
                if (w) {
                    keyboard::report_t k;

                    k.modifiers = (uint8_t)toInt(w->str, w->len);
                    w           = w->next;

                    for (uint8_t i = 0; i<6; ++i) {
                        if (w) {
                            k.keys[i] = (uint8_t)toInt(w->str, w->len);
                            w         = w->next;
                        } else {
                            k.keys[i] = 0;
                        }
                    }

                    keyboard::send(&k);
                    keyboard::release();
                }
            }
            // IMPORT (-> open another script)
            else if (compare(cmd->str, cmd->len, "IMPORT", CASE_SENSETIVE)) {
                import_path = std::string(line_str, line_str_len);
            }
            // Otherwise go through words and look for keys to press
            else {
                word_node* w = wl->first;

                while (w) {
                    press(w->str, w->len);
                    w = w->next;
                }

                if (line_end) release();
            }

            n = n->next;

            if (!in_string && !in_comment && !ignore_delay) sleep(default_delay);

            if (line_end && (repeat_num > 0)) --repeat_num;

            interpret_time = millis();
        }

        line_list_destroy(l);
    }

    int getRepeats() {
        return repeat_num;
    }

    unsigned int getDelayTime() {
        unsigned long finishTime  = sleep_start_time + sleep_time;
        unsigned long currentTime = millis();

        if (currentTime > finishTime) {
            return 0;
        } else {
            unsigned long remainingTime = finishTime - currentTime;
            return (unsigned int)remainingTime;
        }
    }

    bool loopBegin() {
        return loop_begin;
    }

    bool loopEnd() {
        return loop_end;
    }

    int getLoops() {
        return loop_num;
    }

    bool import() {
        return !import_path.empty();
    }

     std::string getImport() {
        std::string path = import_path;
        import_path.clear();
        return path;
    }
}