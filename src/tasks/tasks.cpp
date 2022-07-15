/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "tasks.h"

#include <cstddef> // NULL

namespace tasks {
    // ====== PRIVATE ====== //
    void (*callback)(void) = NULL;

    // ====== PUBLIC ====== //
    void setCallback(void (*_callback)(void)) {
        callback = _callback;
    }

    void update() {
        if (callback != NULL) {
            callback();
        }
    }   
}