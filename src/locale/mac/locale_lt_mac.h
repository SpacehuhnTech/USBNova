/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../usb_hid_keys.h"

// Modifier(s), Key
const uint8_t ascii_lt_mac[] = {
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
    KEY_NONE,           KEY_NONE,           // !
    KEY_MOD_LSHIFT,     KEY_APOSTROPHE,     // "
    KEY_NONE,           KEY_NONE,           // #

    // 36, 0x24
    KEY_NONE,           KEY_NONE,           // $
    KEY_NONE,           KEY_NONE,           // %
    KEY_NONE,           KEY_NONE,           // &
    KEY_NONE,           KEY_APOSTROPHE,     // '

    // 40, 0x28
    KEY_MOD_LSHIFT,     KEY_9,              // (
    KEY_MOD_LSHIFT,     KEY_0,              // )
    KEY_NONE,           KEY_NONE,           // *
    KEY_NONE,           KEY_NONE,           // +

    // 44, 0x2c
    KEY_NONE,           KEY_COMMA,          // ,
    KEY_NONE,           KEY_MINUS,          // -
    KEY_NONE,           KEY_DOT,            // .
    KEY_NONE,           KEY_SLASH,          // /

    // 48, 0x30
    KEY_NONE,           KEY_0,              // 0
    KEY_NONE,           KEY_NONE,           // 1
    KEY_NONE,           KEY_NONE,           // 2
    KEY_NONE,           KEY_NONE,           // 3

    // 52, 0x34
    KEY_NONE,           KEY_NONE,           // 4
    KEY_NONE,           KEY_NONE,           // 5
    KEY_NONE,           KEY_NONE,           // 6
    KEY_NONE,           KEY_NONE,           // 7

    // 56, 0x38
    KEY_NONE,           KEY_NONE,           // 8
    KEY_NONE,           KEY_9,              // 9
    KEY_MOD_LSHIFT,     KEY_SEMICOLON,      // :
    KEY_NONE,           KEY_SEMICOLON,      // ;

    // 60, 0x3c
    KEY_MOD_LSHIFT,     KEY_COMMA,          // <
    KEY_NONE,           KEY_NONE,           // =
    KEY_MOD_LSHIFT,     KEY_DOT,            // >
    KEY_MOD_LSHIFT,     KEY_SLASH,          // ?

    // 64, 0x40
    KEY_NONE,           KEY_NONE,           // @
    KEY_MOD_LSHIFT,     KEY_A,              // A
    KEY_MOD_LSHIFT,     KEY_B,              // B
    KEY_MOD_LSHIFT,     KEY_C,              // C

    // 68, 0x44
    KEY_MOD_LSHIFT,     KEY_D,              // D
    KEY_MOD_LSHIFT,     KEY_E,              // E
    KEY_MOD_LSHIFT,     KEY_F,              // F
    KEY_MOD_LSHIFT,     KEY_G,              // G

    // 72, 0x48
    KEY_MOD_LSHIFT,     KEY_H,              // H
    KEY_MOD_LSHIFT,     KEY_I,              // I
    KEY_MOD_LSHIFT,     KEY_J,              // J
    KEY_MOD_LSHIFT,     KEY_K,              // K

    // 76, 0x4c
    KEY_MOD_LSHIFT,     KEY_L,              // L
    KEY_MOD_LSHIFT,     KEY_M,              // M
    KEY_MOD_LSHIFT,     KEY_N,              // N
    KEY_MOD_LSHIFT,     KEY_O,              // O

    // 80, 0x50
    KEY_MOD_LSHIFT,     KEY_P,              // P
    KEY_MOD_LSHIFT,     KEY_Q,              // Q
    KEY_MOD_LSHIFT,     KEY_R,              // R
    KEY_MOD_LSHIFT,     KEY_S,              // S

    // 84, 0x54
    KEY_MOD_LSHIFT,     KEY_T,              // T
    KEY_MOD_LSHIFT,     KEY_U,              // U
    KEY_MOD_LSHIFT,     KEY_V,              // V
    KEY_MOD_LSHIFT,     KEY_W,              // W

    // 88, 0x58
    KEY_MOD_LSHIFT,     KEY_X,              // X
    KEY_MOD_LSHIFT,     KEY_Y,              // Y
    KEY_MOD_LSHIFT,     KEY_Z,              // Z
    KEY_NONE,           KEY_LEFTBRACE,      // [

    // 92, 0x5c
    KEY_NONE,           KEY_BACKSLASH,      // bslash
    KEY_NONE,           KEY_RIGHTBRACE,     // ]
    KEY_NONE,           KEY_NONE,           // ^
    KEY_MOD_LSHIFT,     KEY_MINUS,          // _

    // 96, 0x60
    KEY_NONE,           KEY_RO,             // `
    KEY_NONE,           KEY_A,              // a
    KEY_NONE,           KEY_B,              // b
    KEY_NONE,           KEY_C,              // c

    // 100, 0x64
    KEY_NONE,           KEY_D,              // d
    KEY_NONE,           KEY_E,              // e
    KEY_NONE,           KEY_F,              // f
    KEY_NONE,           KEY_G,              // g

    // 104, 0x68
    KEY_NONE,           KEY_H,              // h
    KEY_NONE,           KEY_I,              // i
    KEY_NONE,           KEY_J,              // j
    KEY_NONE,           KEY_K,              // k

    // 108, 0x6c
    KEY_NONE,           KEY_L,              // l
    KEY_NONE,           KEY_M,              // m
    KEY_NONE,           KEY_N,              // n
    KEY_NONE,           KEY_O,              // o

    // 112, 0x70
    KEY_NONE,           KEY_P,              // p
    KEY_NONE,           KEY_Q,              // q
    KEY_NONE,           KEY_R,              // r
    KEY_NONE,           KEY_S,              // s

    // 116, 0x74
    KEY_NONE,           KEY_T,              // t
    KEY_NONE,           KEY_U,              // u
    KEY_NONE,           KEY_V,              // v
    KEY_NONE,           KEY_W,              // w

    // 120, 0x78
    KEY_NONE,           KEY_X,              // x
    KEY_NONE,           KEY_Y,              // y
    KEY_NONE,           KEY_Z,              // z
    KEY_MOD_LSHIFT,     KEY_LEFTBRACE,      // {

    // 124, 0x7c
    KEY_MOD_LSHIFT,     KEY_BACKSLASH,      // |
    KEY_MOD_LSHIFT,     KEY_RIGHTBRACE,     // }
    KEY_MOD_LSHIFT,     KEY_102ND,          // ~
    KEY_NONE,           KEY_DELETE          // DEL
};

const uint8_t utf8_lt_mac[] = {
    0xC2, 0xA3, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              // £
    0xC2, 0xA7, 0x00, 0x00, KEY_NONE,               KEY_GRAVE,          // §
    0xC2, 0xA8, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_U,       // ¨
    0xC2, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_G,              // ©
    0xC2, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_BACKSLASH,      // «
    0xC2, 0xAC, 0x00, 0x00, KEY_MOD_LALT,           KEY_L,              // ¬
    0xC2, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_R,              // ®
    0xC2, 0xB0, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_8,       // °
    0xC2, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              // ¶
    0xC2, 0xBB, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_BACKSLASH, // »
    0xC3, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Y,       // Á
    0xC3, 0x8D, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_S,       // Í
    0xC3, 0x93, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_H,       // Ó
    0xC3, 0x94, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_J,       // Ô
    0xC3, 0x9A, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_SEMICOLON, // Ú
    0xC3, 0x9D, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_COMMA,   // Ý
    0xC3, 0x9F, 0x00, 0x00, KEY_MOD_LALT,           KEY_S,              // ß
    0xC3, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_SLASH,          // ÷
    0xC3, 0xBD, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_DOT,     // ý
    0xC4, 0x80, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_A,       // Ā
    0xC4, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_C,       // ā
    0xC4, 0x84, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_1,              // Ą
    0xC4, 0x85, 0x00, 0x00, KEY_NONE,               KEY_1,              // ą
    0xC4, 0x86, 0x00, 0x00, KEY_MOD_LALT,           KEY_A,              // Ć
    0xC4, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_C,              // ć
    0xC4, 0x8C, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_2,              // Č
    0xC4, 0x8D, 0x00, 0x00, KEY_NONE,               KEY_2,              // č
    0xC4, 0x96, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_4,              // Ė
    0xC4, 0x97, 0x00, 0x00, KEY_NONE,               KEY_4,              // ė
    0xC4, 0x98, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_3,              // Ę
    0xC4, 0x99, 0x00, 0x00, KEY_NONE,               KEY_3,              // ę
    0xC4, 0xA2, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_X,       // Ģ
    0xC4, 0xA3, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_APOSTROPHE, // ģ
    0xC4, 0xAA, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_GRAVE,          // Ī
    0xC4, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_Y,              // ī
    0xC4, 0xAE, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_5,              // Į
    0xC4, 0xAF, 0x00, 0x00, KEY_NONE,               KEY_5,              // į
    0xC4, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_M,              // Ķ
    0xC4, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_H,              // ķ
    0xC4, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_Z,              // Ĺ
    0xC4, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_APOSTROPHE,     // ĺ
    0xC4, 0xBB, 0x00, 0x00, KEY_MOD_LALT,           KEY_P,              // Ļ
    0xC4, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              // ļ
    0xC4, 0xBD, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              // Ľ
    0xC4, 0xBE, 0x00, 0x00, KEY_MOD_LALT,           KEY_0,              // ľ
    0xC5, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Z,       // Ł
    0xC5, 0x82, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_P,       // ł
    0xC5, 0x83, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              // Ń
    0xC5, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_F,              // ń
    0xC5, 0x85, 0x00, 0x00, KEY_MOD_LALT,           KEY_O,              // Ņ
    0xC5, 0x86, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_SLASH,   // ņ
    0xC5, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_X,              // Ň
    0xC5, 0x8C, 0x00, 0x00, KEY_MOD_LALT,           KEY_Q,              // Ō
    0xC5, 0x91, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Q,       // ő
    0xC5, 0x95, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       // ŕ
    0xC5, 0x96, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_6,       // Ŗ
    0xC5, 0x97, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_7,       // ŗ
    0xC5, 0x98, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_2,       // Ř
    0xC5, 0x99, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_5,       // ř
    0xC5, 0x9A, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_M,       // Ś
    0xC5, 0xA0, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_6,              // Š
    0xC5, 0xA1, 0x00, 0x00, KEY_NONE,               KEY_6,              // š
    0xC5, 0xAA, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_8,              // Ū
    0xC5, 0xAB, 0x00, 0x00, KEY_NONE,               KEY_8,              // ū
    0xC5, 0xAE, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_L,       // Ů
    0xC5, 0xB1, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_B,       // ű
    0xC5, 0xB2, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_7,              // Ų
    0xC5, 0xB3, 0x00, 0x00, KEY_NONE,               KEY_7,              // ų
    0xC5, 0xBB, 0x00, 0x00, KEY_MOD_LALT,           KEY_K,              // Ż
    0xC5, 0xBC, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_G,       // ż
    0xC5, 0xBD, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_EQUAL,          // Ž
    0xC5, 0xBE, 0x00, 0x00, KEY_NONE,               KEY_EQUAL,          // ž
    0xCB, 0x87, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_T,       // ˇ
    0xE2, 0x80, 0x93, 0x00, KEY_MOD_LALT,           KEY_MINUS,          // –
    0xE2, 0x80, 0x94, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_MINUS,   // —
    0xE2, 0x80, 0x98, 0x00, KEY_MOD_LALT,           KEY_RIGHTBRACE,     // ‘
    0xE2, 0x80, 0x99, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_RIGHTBRACE, // ’
    0xE2, 0x80, 0x9A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_0,       // ‚
    0xE2, 0x80, 0x9C, 0x00, KEY_MOD_LALT,           KEY_LEFTBRACE,      // “
    0xE2, 0x80, 0x9D, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_LEFTBRACE, // ”
    0xE2, 0x80, 0x9E, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_W,       // „
    0xE2, 0x80, 0xA0, 0x00, KEY_MOD_LALT,           KEY_T,              // †
    0xE2, 0x80, 0xA2, 0x00, KEY_MOD_LALT,           KEY_8,              // •
    0xE2, 0x80, 0xA6, 0x00, KEY_MOD_LALT,           KEY_SEMICOLON,      // …
    0xE2, 0x80, 0xB9, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_3,       // ‹
    0xE2, 0x80, 0xBA, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_4,       // ›
    0xE2, 0x84, 0xA2, 0x00, KEY_MOD_LALT,           KEY_2,              // ™
    0xE2, 0x88, 0x82, 0x00, KEY_MOD_LALT,           KEY_D,              // ∂
    0xE2, 0x88, 0x86, 0x00, KEY_MOD_LALT,           KEY_J,              // ∆
    0xE2, 0x88, 0x91, 0x00, KEY_MOD_LALT,           KEY_W,              // ∑
    0xE2, 0x88, 0x9A, 0x00, KEY_MOD_LALT,           KEY_V,              // √
    0xE2, 0x89, 0xA0, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          // ≠
    0xE2, 0x89, 0xA4, 0x00, KEY_MOD_LALT,           KEY_COMMA,          // ≤
    0xE2, 0x89, 0xA5, 0x00, KEY_MOD_LALT,           KEY_DOT,            // ≥
    0xE2, 0x97, 0x8A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_V,       // ◊
};

const uint8_t combinations_lt_mac[] = {
    0xC3, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_MOD_LSHIFT,     KEY_A,              // Ä
    0xC3, 0x95, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_MOD_LSHIFT,     KEY_O,              // Õ
    0xC3, 0x96, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_MOD_LSHIFT,     KEY_O,              // Ö
    0xC3, 0xA1, 0x00, 0x00, KEY_MOD_LALT,           KEY_E,              KEY_NONE,           KEY_A,              // á
    0xC3, 0xA4, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_NONE,           KEY_A,              // ä
    0xC3, 0xAD, 0x00, 0x00, KEY_MOD_LALT,           KEY_E,              KEY_NONE,           KEY_I,              // í
    0xC3, 0xB3, 0x00, 0x00, KEY_MOD_LALT,           KEY_E,              KEY_NONE,           KEY_O,              // ó
    0xC3, 0xB4, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              KEY_NONE,           KEY_O,              // ô
    0xC3, 0xB5, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_NONE,           KEY_O,              // õ
    0xC3, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_NONE,           KEY_O,              // ö
    0xC3, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_E,              KEY_NONE,           KEY_U,              // ú
    0xC4, 0x8E, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_NONE,           KEY_E,              // Ď
    0xC4, 0x93, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_NONE,           KEY_I,              // ē
    0xC4, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              KEY_NONE,           KEY_U,              // ě
    0xC5, 0x90, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_MOD_LSHIFT,     KEY_A,              // Ő
    0xC5, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              KEY_MOD_LSHIFT,     KEY_E,              // ś
    0xC5, 0xA4, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              KEY_MOD_LSHIFT,     KEY_E,              // Ť
    0xC5, 0xAF, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              KEY_MOD_LSHIFT,     KEY_U,              // ů
    0xC5, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              KEY_NONE,           KEY_E,              // ź
};

static hid_locale_t locale_lt_mac {
    (uint8_t*)ascii_lt_mac, 128,
    (uint8_t*)utf8_lt_mac, sizeof(utf8_lt_mac) / 6,
    (uint8_t*)combinations_lt_mac, sizeof(combinations_lt_mac) / 8,
};