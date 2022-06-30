/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <cstdint> // uint8_t
#include <cstddef> // size_t

typedef struct hid_locale_t {
    uint8_t* ascii;
    uint8_t  ascii_len;

    uint8_t* extended_ascii;
    size_t   extended_ascii_len;

    uint8_t* utf8;
    size_t   utf8_len;
} hid_locale_t;