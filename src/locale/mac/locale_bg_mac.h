/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../usb_hid_keys.h"

// Modifier(s), Key
const uint8_t ascii_bg_mac[] = {
    KEY_NONE,           KEY_NONE,           // NUL
    KEY_NONE,           KEY_NONE,           // SOH
    KEY_NONE,           KEY_NONE,           // STX
    KEY_NONE,           KEY_NONE,           // ETX
    KEY_NONE,           KEY_NONE,           // EOT
    KEY_NONE,           KEY_NONE,           // ENQ
    KEY_NONE,           KEY_NONE,           // ACK
    KEY_NONE,           KEY_NONE,           // BEL

    // 8, 0x08
    KEY_NONE,           KEY_BACKSPACE,      // BS Backspace
    KEY_NONE,           KEY_TAB,            // TAB Tab
    KEY_NONE,           KEY_ENTER,          // LF Enter

    KEY_NONE,           KEY_NONE,           // VT
    KEY_NONE,           KEY_NONE,           // FF
    KEY_NONE,           KEY_NONE,           // CR
    KEY_NONE,           KEY_NONE,           // SO
    KEY_NONE,           KEY_NONE,           // SI
    KEY_NONE,           KEY_NONE,           // DEL
    KEY_NONE,           KEY_NONE,           // DC1
    KEY_NONE,           KEY_NONE,           // DC2
    KEY_NONE,           KEY_NONE,           // DC3
    KEY_NONE,           KEY_NONE,           // DC4
    KEY_NONE,           KEY_NONE,           // NAK
    KEY_NONE,           KEY_NONE,           // SYN
    KEY_NONE,           KEY_NONE,           // ETB
    KEY_NONE,           KEY_NONE,           // CAN
    KEY_NONE,           KEY_NONE,           // EM
    KEY_NONE,           KEY_NONE,           // SUB
    KEY_NONE,           KEY_NONE,           // ESC
    KEY_NONE,           KEY_NONE,           // FS
    KEY_NONE,           KEY_NONE,           // GS
    KEY_NONE,           KEY_NONE,           // RS
    KEY_NONE,           KEY_NONE,           // US
    
    // 32, 0x20
    KEY_NONE,           KEY_SPACE,          // ' '
    KEY_MOD_LSHIFT,     KEY_1,              // !
    KEY_MOD_LSHIFT,     KEY_4,              // "
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_3,    // #

    // 36, 0x24
    KEY_MOD_LALT,       KEY_3,              // $
    KEY_MOD_LSHIFT,     KEY_5,              // %
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_7,    // &
    KEY_NONE,           KEY_NONE,           // '

    // 40, 0x28
    KEY_NONE,           KEY_BACKSLASH,      // (
    KEY_MOD_LSHIFT,     KEY_BACKSLASH,      // )
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_8,    // *
    KEY_MOD_LSHIFT,     KEY_3,              // +

    // 44, 0x2c
    KEY_NONE,           KEY_Q,              // ,
    KEY_NONE,           KEY_MINUS,          // -
    KEY_NONE,           KEY_EQUAL,          // .
    KEY_MOD_LSHIFT,     KEY_8,              // /

    // 48, 0x30
    KEY_NONE,           KEY_0,              // 0
    KEY_NONE,           KEY_1,              // 1
    KEY_NONE,           KEY_2,              // 2
    KEY_NONE,           KEY_3,              // 3

    // 52, 0x34
    KEY_NONE,           KEY_4,              // 4
    KEY_NONE,           KEY_5,              // 5
    KEY_NONE,           KEY_6,              // 6
    KEY_NONE,           KEY_7,              // 7

    // 56, 0x38
    KEY_NONE,           KEY_8,              // 8
    KEY_NONE,           KEY_9,              // 9
    KEY_MOD_LSHIFT,     KEY_7,              // :
    KEY_NONE,           KEY_RIGHTBRACE,     // ;

    // 60, 0x3c
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_COMMA,// <
    KEY_MOD_LSHIFT,     KEY_6,              // =
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_DOT,  // >
    KEY_MOD_LSHIFT,     KEY_2,              // ?

    // 64, 0x40
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_2,    // @
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_A,    // A
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_B,    // B
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_C,    // C

    // 68, 0x44
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_D,    // D
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_E,    // E
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_F,    // F
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_G,    // G

    // 72, 0x48
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_H,    // H
    KEY_MOD_LSHIFT,     KEY_MINUS,          // I
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_J,    // J
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_K,    // K

    // 76, 0x4c
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_L,    // L
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_M,    // M
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_N,    // N
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_O,    // O

    // 80, 0x50
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_P,    // P
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_Q,    // Q
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_R,    // R
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_S,    // S

    // 84, 0x54
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_T,    // T
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_U,    // U
    KEY_MOD_LSHIFT,     KEY_EQUAL,          // V
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_W,    // W

    // 88, 0x58
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_X,    // X
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_Y,    // Y
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_Z,    // Z
    KEY_MOD_LALT,       KEY_LEFTBRACE,      // [

    // 92, 0x5c
    KEY_NONE,           KEY_NONE,           // bslash
    KEY_MOD_LALT,       KEY_RIGHTBRACE,     // ]
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_6,    // ^
    KEY_MOD_LSHIFT,     KEY_9,              // _

    // 96, 0x60
    KEY_NONE,           KEY_RO,             // `
    KEY_MOD_LALT,       KEY_A,              // a
    KEY_MOD_LALT,       KEY_B,              // b
    KEY_MOD_LALT,       KEY_C,              // c

    // 100, 0x64
    KEY_MOD_LALT,       KEY_D,              // d
    KEY_MOD_LALT,       KEY_E,              // e
    KEY_MOD_LALT,       KEY_F,              // f
    KEY_MOD_LALT,       KEY_G,              // g

    // 104, 0x68
    KEY_MOD_LALT,       KEY_H,              // h
    KEY_MOD_LALT,       KEY_I,              // i
    KEY_MOD_LALT,       KEY_J,              // j
    KEY_MOD_LALT,       KEY_K,              // k

    // 108, 0x6c
    KEY_MOD_LALT,       KEY_L,              // l
    KEY_MOD_LALT,       KEY_M,              // m
    KEY_MOD_LALT,       KEY_N,              // n
    KEY_MOD_LALT,       KEY_O,              // o

    // 112, 0x70
    KEY_MOD_LALT,       KEY_P,              // p
    KEY_MOD_LALT,       KEY_Q,              // q
    KEY_MOD_LALT,       KEY_R,              // r
    KEY_MOD_LALT,       KEY_S,              // s

    // 116, 0x74
    KEY_MOD_LALT,       KEY_T,              // t
    KEY_MOD_LALT,       KEY_U,              // u
    KEY_MOD_LALT,       KEY_V,              // v
    KEY_MOD_LALT,       KEY_W,              // w

    // 120, 0x78
    KEY_MOD_LALT,       KEY_X,              // x
    KEY_MOD_LALT,       KEY_Y,              // y
    KEY_MOD_LALT,       KEY_Z,              // z
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_LEFTBRACE,// {

    // 124, 0x7c
    KEY_NONE,           KEY_NONE,           // |
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_RIGHTBRACE,// }
    KEY_MOD_LSHIFT,     KEY_102ND,          // ~
    KEY_NONE,           KEY_DELETE          // DEL
};

const uint8_t utf8_bg_mac[] = {
    0xC2, 0xA3, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              // £
    0xC2, 0xA7, 0x00, 0x00, KEY_NONE,               KEY_GRAVE,          // §
    0xC2, 0xB0, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              // °
    0xC2, 0xB1, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_GRAVE,          // ±
    0xC2, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              // ¶
    0xD0, 0x90, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_D,              // А
    0xD0, 0x91, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SLASH,          // Б
    0xD0, 0x92, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_L,              // В
    0xD0, 0x93, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_H,              // Г
    0xD0, 0x94, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_O,              // Д
    0xD0, 0x95, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_E,              // Е
    0xD0, 0x96, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_G,              // Ж
    0xD0, 0x97, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_P,              // З
    0xD0, 0x98, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_R,              // И
    0xD0, 0x99, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_X,              // Й
    0xD0, 0x9A, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_U,              // К
    0xD0, 0x9B, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_DOT,            // Л
    0xD0, 0x9C, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      // М
    0xD0, 0x9D, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_K,              // Н
    0xD0, 0x9E, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_F,              // О
    0xD0, 0x9F, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_M,              // П
    0xD0, 0xA0, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_COMMA,          // Р
    0xD0, 0xA1, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_I,              // С
    0xD0, 0xA2, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_J,              // Т
    0xD0, 0xA3, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_W,              // У
    0xD0, 0xA4, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_B,              // Ф
    0xD0, 0xA5, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_N,              // Х
    0xD0, 0xA6, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      // Ц
    0xD0, 0xA7, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_APOSTROPHE,     // Ч
    0xD0, 0xA8, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_T,              // Ш
    0xD0, 0xA9, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_Y,              // Щ
    0xD0, 0xAA, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_C,              // Ъ
    0xD0, 0xAD, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_V,              // Э
    0xD0, 0xAE, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_Z,              // Ю
    0xD0, 0xAF, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_S,              // Я
    0xD0, 0xB0, 0x00, 0x00, KEY_NONE,               KEY_D,              // а
    0xD0, 0xB1, 0x00, 0x00, KEY_NONE,               KEY_SLASH,          // б
    0xD0, 0xB2, 0x00, 0x00, KEY_NONE,               KEY_L,              // в
    0xD0, 0xB3, 0x00, 0x00, KEY_NONE,               KEY_H,              // г
    0xD0, 0xB4, 0x00, 0x00, KEY_NONE,               KEY_O,              // д
    0xD0, 0xB5, 0x00, 0x00, KEY_NONE,               KEY_E,              // е
    0xD0, 0xB6, 0x00, 0x00, KEY_NONE,               KEY_G,              // ж
    0xD0, 0xB7, 0x00, 0x00, KEY_NONE,               KEY_P,              // з
    0xD0, 0xB8, 0x00, 0x00, KEY_NONE,               KEY_R,              // и
    0xD0, 0xB9, 0x00, 0x00, KEY_NONE,               KEY_X,              // й
    0xD0, 0xBA, 0x00, 0x00, KEY_NONE,               KEY_U,              // к
    0xD0, 0xBB, 0x00, 0x00, KEY_NONE,               KEY_DOT,            // л
    0xD0, 0xBC, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      // м
    0xD0, 0xBD, 0x00, 0x00, KEY_NONE,               KEY_K,              // н
    0xD0, 0xBE, 0x00, 0x00, KEY_NONE,               KEY_F,              // о
    0xD0, 0xBF, 0x00, 0x00, KEY_NONE,               KEY_M,              // п
    0xD1, 0x80, 0x00, 0x00, KEY_NONE,               KEY_COMMA,          // р
    0xD1, 0x81, 0x00, 0x00, KEY_NONE,               KEY_I,              // с
    0xD1, 0x82, 0x00, 0x00, KEY_NONE,               KEY_J,              // т
    0xD1, 0x83, 0x00, 0x00, KEY_NONE,               KEY_W,              // у
    0xD1, 0x84, 0x00, 0x00, KEY_NONE,               KEY_B,              // ф
    0xD1, 0x85, 0x00, 0x00, KEY_NONE,               KEY_N,              // х
    0xD1, 0x86, 0x00, 0x00, KEY_NONE,               KEY_LEFTBRACE,      // ц
    0xD1, 0x87, 0x00, 0x00, KEY_NONE,               KEY_APOSTROPHE,     // ч
    0xD1, 0x88, 0x00, 0x00, KEY_NONE,               KEY_T,              // ш
    0xD1, 0x89, 0x00, 0x00, KEY_NONE,               KEY_Y,              // щ
    0xD1, 0x8A, 0x00, 0x00, KEY_NONE,               KEY_C,              // ъ
    0xD1, 0x8B, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_Q,              // ы
    0xD1, 0x8C, 0x00, 0x00, KEY_NONE,               KEY_A,              // ь
    0xD1, 0x8D, 0x00, 0x00, KEY_NONE,               KEY_V,              // э
    0xD1, 0x8E, 0x00, 0x00, KEY_NONE,               KEY_Z,              // ю
    0xD1, 0x8F, 0x00, 0x00, KEY_NONE,               KEY_S,              // я
    0xD1, 0x9D, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_A,              // ѝ
    0xD2, 0x90, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              // Ґ
    0xE2, 0x80, 0x93, 0x00, KEY_MOD_LALT,           KEY_MINUS,          // –
    0xE2, 0x80, 0x94, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_MINUS,   // —
    0xE2, 0x80, 0x98, 0x00, KEY_MOD_LALT,           KEY_BACKSLASH,      // ‘
    0xE2, 0x80, 0x99, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_BACKSLASH, // ’
    0xE2, 0x80, 0x9C, 0x00, KEY_MOD_LALT,           KEY_APOSTROPHE,     // “
    0xE2, 0x80, 0x9D, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_APOSTROPHE, // ”
    0xE2, 0x80, 0x9E, 0x00, KEY_MOD_LALT,           KEY_4,              // „
    0xE2, 0x80, 0xA0, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       // †
    0xE2, 0x80, 0xA2, 0x00, KEY_MOD_LALT,           KEY_0,              // •
    0xE2, 0x82, 0xAC, 0x00, KEY_MOD_LALT,           KEY_1,              // €
    0xE2, 0x84, 0x96, 0x00, KEY_MOD_LSHIFT,         KEY_0,              // №
    0xE2, 0x84, 0xA2, 0x00, KEY_MOD_LALT,           KEY_5,              // ™
    0xE2, 0x88, 0x9E, 0x00, KEY_MOD_LALT,           KEY_6,              // ∞
};

const uint8_t combinations_bg_mac[] = {
    0xD0, 0x82, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_D,              // Ђ
    0xD0, 0x83, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_E,              // Ѓ
    0xD0, 0x84, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_R,              // Є
    0xD0, 0x87, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_F,              // Ї
    0xD0, 0x89, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_W,              // Љ
    0xD0, 0x8A, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_C,              // Њ
    0xD0, 0x8B, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_V,              // Ћ
    0xD0, 0x8E, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_Z,              // Ў
    0xD0, 0x8F, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_S,              // Џ
    0xD1, 0x92, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_D,              // ђ
    0xD1, 0x93, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_E,              // ѓ
    0xD1, 0x94, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_R,              // є
    0xD1, 0x97, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_F,              // ї
    0xD1, 0x99, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_W,              // љ
    0xD1, 0x9A, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_C,              // њ
    0xD1, 0x9B, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_V,              // ћ
    0xD1, 0x9C, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_MOD_LSHIFT,     KEY_Q,              // ќ
    0xD1, 0x9E, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_Z,              // ў
    0xD1, 0x9F, 0x00, 0x00, KEY_NONE,               KEY_102ND,          KEY_NONE,           KEY_S,              // џ
};

static hid_locale_t locale_bg_mac {
    (uint8_t*)ascii_bg_mac, 128,
    (uint8_t*)utf8_bg_mac, sizeof(utf8_bg_mac) / 6,
    (uint8_t*)combinations_bg_mac, sizeof(combinations_bg_mac) / 8,
};