/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <Arduino.h>
#include "config.h"

#ifdef ENABLE_DEBUG

#define debug_init() DEBUG_PORT.begin(DEBUG_BAUD);

#define debugF(...) if (DEBUG_PORT) DEBUG_PORT.print(F(__VA_ARGS__))
#define debuglnF(...) if (DEBUG_PORT) DEBUG_PORT.println(F(__VA_ARGS__))

#define debug(...) if (DEBUG_PORT) DEBUG_PORT.print(__VA_ARGS__)
#define debugln(...) if (DEBUG_PORT) DEBUG_PORT.println(__VA_ARGS__)

#else /* ifdef ENABLE_DEBUG */

#define debug_init() Serial.end();

#define debugF(...) 0
#define debuglnF(...) 0

#define debug(...) 0
#define debugln(...) 0

#endif /* ifdef ENABLE_DEBUG */