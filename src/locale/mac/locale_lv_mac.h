/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../usb_hid_keys.h"

// Modifier(s), Key
const uint8_t ascii_lv_mac[] = {
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
    KEY_MOD_LSHIFT,     KEY_APOSTROPHE,     // "
    KEY_MOD_LSHIFT,     KEY_GRAVE,          // #

    // 36, 0x24
    KEY_MOD_LSHIFT,     KEY_4,              // $
    KEY_MOD_LSHIFT,     KEY_5,              // %
    KEY_MOD_LSHIFT,     KEY_7,              // &
    KEY_NONE,           KEY_102ND,          // '

    // 40, 0x28
    KEY_MOD_LSHIFT,     KEY_9,              // (
    KEY_MOD_LSHIFT,     KEY_0,              // )
    KEY_MOD_LSHIFT,     KEY_8,              // *
    KEY_MOD_LSHIFT,     KEY_EQUAL,          // +

    // 44, 0x2c
    KEY_NONE,           KEY_COMMA,          // ,
    KEY_NONE,           KEY_MINUS,          // -
    KEY_NONE,           KEY_DOT,            // .
    KEY_NONE,           KEY_SLASH,          // /

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
    KEY_MOD_LSHIFT,     KEY_SEMICOLON,      // :
    KEY_NONE,           KEY_SEMICOLON,      // ;

    // 60, 0x3c
    KEY_MOD_LSHIFT,     KEY_COMMA,          // <
    KEY_NONE,           KEY_EQUAL,          // =
    KEY_MOD_LSHIFT,     KEY_DOT,            // >
    KEY_MOD_LSHIFT,     KEY_SLASH,          // ?

    // 64, 0x40
    KEY_MOD_LSHIFT,     KEY_2,              // @
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
    KEY_MOD_LSHIFT,     KEY_6,              // ^
    KEY_MOD_LSHIFT,     KEY_MINUS,          // _

    // 96, 0x60
    KEY_MOD_LALT,       KEY_102ND,          // `
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

const uint8_t utf8_lv_mac[] = {
    0xC2, 0xA3, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_3,              // £
    0xC2, 0xA7, 0x00, 0x00, KEY_NONE,               KEY_GRAVE,          // §
    0xC2, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_Q,              // ©
    0xC2, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_BACKSLASH,      // «
    0xC2, 0xAC, 0x00, 0x00, KEY_MOD_LALT,           KEY_P,              // ¬
    0xC2, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_Y,              // ®
    0xC2, 0xB0, 0x00, 0x00, KEY_MOD_LALT,           KEY_M,              // °
    0xC2, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              // ¶
    0xC2, 0xBB, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_BACKSLASH, // »
    0xC3, 0x9F, 0x00, 0x00, KEY_MOD_LALT,           KEY_X,              // ß
    0xC3, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_SLASH,          // ÷
    0xC4, 0x80, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_A,       // Ā
    0xC4, 0x81, 0x00, 0x00, KEY_MOD_LALT,           KEY_A,              // ā
    0xC4, 0x8C, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_C,       // Č
    0xC4, 0x8D, 0x00, 0x00, KEY_MOD_LALT,           KEY_C,              // č
    0xC4, 0x92, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_E,       // Ē
    0xC4, 0x93, 0x00, 0x00, KEY_MOD_LALT,           KEY_E,              // ē
    0xC4, 0xA2, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_G,       // Ģ
    0xC4, 0xA3, 0x00, 0x00, KEY_MOD_LALT,           KEY_G,              // ģ
    0xC4, 0xAA, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_I,       // Ī
    0xC4, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              // ī
    0xC4, 0xB6, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_K,       // Ķ
    0xC4, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_K,              // ķ
    0xC4, 0xBB, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_L,       // Ļ
    0xC4, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_L,              // ļ
    0xC5, 0x85, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_N,       // Ņ
    0xC5, 0x86, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              // ņ
    0xC5, 0x8C, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_O,       // Ō
    0xC5, 0x8D, 0x00, 0x00, KEY_MOD_LALT,           KEY_O,              // ō
    0xC5, 0x96, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_R,       // Ŗ
    0xC5, 0x97, 0x00, 0x00, KEY_MOD_LALT,           KEY_R,              // ŗ
    0xC5, 0xA0, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_S,       // Š
    0xC5, 0xA1, 0x00, 0x00, KEY_MOD_LALT,           KEY_S,              // š
    0xC5, 0xAA, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_U,       // Ū
    0xC5, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              // ū
    0xC5, 0xBD, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Z,       // Ž
    0xC5, 0xBE, 0x00, 0x00, KEY_MOD_LALT,           KEY_Z,              // ž
    0xE2, 0x80, 0x93, 0x00, KEY_MOD_LALT,           KEY_MINUS,          // –
    0xE2, 0x80, 0x94, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_MINUS,   // —
    0xE2, 0x80, 0x98, 0x00, KEY_MOD_LALT,           KEY_0,              // ‘
    0xE2, 0x80, 0x99, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_RIGHTBRACE, // ’
    0xE2, 0x80, 0x9A, 0x00, KEY_MOD_LALT,           KEY_9,              // ‚
    0xE2, 0x80, 0x9C, 0x00, KEY_MOD_LALT,           KEY_RIGHTBRACE,     // “
    0xE2, 0x80, 0x9D, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_LEFTBRACE, // ”
    0xE2, 0x80, 0x9E, 0x00, KEY_MOD_LALT,           KEY_LEFTBRACE,      // „
    0xE2, 0x80, 0xA0, 0x00, KEY_MOD_LALT,           KEY_T,              // †
    0xE2, 0x80, 0xA2, 0x00, KEY_MOD_LALT,           KEY_8,              // •
    0xE2, 0x80, 0xA6, 0x00, KEY_MOD_LALT,           KEY_SEMICOLON,      // …
    0xE2, 0x80, 0xB9, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_3,       // ‹
    0xE2, 0x80, 0xBA, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_4,       // ›
    0xE2, 0x82, 0xAC, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Q,       // €
    0xE2, 0x84, 0xA2, 0x00, KEY_MOD_LALT,           KEY_2,              // ™
    0xE2, 0x88, 0x82, 0x00, KEY_MOD_LALT,           KEY_D,              // ∂
    0xE2, 0x88, 0x86, 0x00, KEY_MOD_LALT,           KEY_J,              // ∆
    0xE2, 0x88, 0x91, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_W,       // ∑
    0xE2, 0x88, 0x9A, 0x00, KEY_MOD_LALT,           KEY_V,              // √
    0xE2, 0x89, 0xA0, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          // ≠
    0xE2, 0x89, 0xA4, 0x00, KEY_MOD_LALT,           KEY_COMMA,          // ≤
    0xE2, 0x89, 0xA5, 0x00, KEY_MOD_LALT,           KEY_DOT,            // ≥
    0xE2, 0x97, 0x8A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_V,       // ◊
};

const uint8_t combinations_lv_mac[] = {
    0xC2, 0xA8, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_SPACE,          // ¨
    0xC3, 0x81, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_A,              // Á
    0xC3, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_A,              // Ä
    0xC3, 0x89, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_E,              // É
    0xC3, 0x8D, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_I,              // Í
    0xC3, 0x93, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_O,              // Ó
    0xC3, 0x94, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_O,              // Ô
    0xC3, 0x96, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_O,              // Ö
    0xC3, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_U,              // Ú
    0xC3, 0x9C, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_U,              // Ü
    0xC3, 0x9D, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_Y,              // Ý
    0xC3, 0xA1, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_A,              // á
    0xC3, 0xA4, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_A,              // ä
    0xC3, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_E,              // é
    0xC3, 0xAD, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_I,              // í
    0xC3, 0xB3, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_O,              // ó
    0xC3, 0xB4, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_O,              // ô
    0xC3, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_O,              // ö
    0xC3, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_U,              // ú
    0xC3, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_U,              // ü
    0xC3, 0xBD, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_Y,              // ý
    0xC4, 0x86, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_C,              // Ć
    0xC4, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_C,              // ć
    0xC4, 0x8E, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_D,              // Ď
    0xC4, 0x8F, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_D,              // ď
    0xC4, 0x96, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_E,              // Ė
    0xC4, 0x97, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_E,              // ė
    0xC4, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_E,              // Ě
    0xC4, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_E,              // ě
    0xC4, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_L,              // Ĺ
    0xC4, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_L,              // ĺ
    0xC4, 0xBD, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_L,              // Ľ
    0xC4, 0xBE, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_L,              // ľ
    0xC5, 0x83, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_N,              // Ń
    0xC5, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_N,              // ń
    0xC5, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_N,              // Ň
    0xC5, 0x88, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_N,              // ň
    0xC5, 0x90, 0x00, 0x00, KEY_MOD_LALT,           KEY_W,              KEY_MOD_LSHIFT,     KEY_O,              // Ő
    0xC5, 0x91, 0x00, 0x00, KEY_MOD_LALT,           KEY_W,              KEY_NONE,           KEY_O,              // ő
    0xC5, 0x94, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_R,              // Ŕ
    0xC5, 0x95, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_R,              // ŕ
    0xC5, 0x98, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_R,              // Ř
    0xC5, 0x99, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_R,              // ř
    0xC5, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_S,              // Ś
    0xC5, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_S,              // ś
    0xC5, 0xA4, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_T,              // Ť
    0xC5, 0xA5, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_T,              // ť
    0xC5, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_W,              // Ů
    0xC5, 0xAF, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_W,              // ů
    0xC5, 0xB0, 0x00, 0x00, KEY_MOD_LALT,           KEY_W,              KEY_MOD_LSHIFT,     KEY_U,              // Ű
    0xC5, 0xB1, 0x00, 0x00, KEY_MOD_LALT,           KEY_W,              KEY_NONE,           KEY_U,              // ű
    0xC5, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_MOD_LSHIFT,     KEY_Z,              // Ź
    0xC5, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              KEY_NONE,           KEY_Z,              // ź
    0xC5, 0xBB, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_Z,              // Ż
    0xC5, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_Z,              // ż
    0xCB, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_SPACE,          // ˇ
};

static hid_locale_t locale_lv_mac {
    (uint8_t*)ascii_lv_mac, 128,
    (uint8_t*)utf8_lv_mac, sizeof(utf8_lv_mac) / 6,
    (uint8_t*)combinations_lv_mac, sizeof(combinations_lv_mac) / 8,
};