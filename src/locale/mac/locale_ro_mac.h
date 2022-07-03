/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../usb_hid_keys.h"

// Modifier(s), Key
const uint8_t ascii_ro_mac[] = {
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
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_APOSTROPHE,// "
    KEY_MOD_LSHIFT,     KEY_3,              // #

    // 36, 0x24
    KEY_MOD_LSHIFT,     KEY_4,              // $
    KEY_MOD_LSHIFT,     KEY_5,              // %
    KEY_MOD_LSHIFT,     KEY_7,              // &
    KEY_MOD_LALT,       KEY_APOSTROPHE,     // '

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
    KEY_MOD_LSHIFT,     KEY_DOT,            // :
    KEY_MOD_LSHIFT,     KEY_COMMA,          // ;

    // 60, 0x3c
    KEY_MOD_LALT,       KEY_COMMA,          // <
    KEY_NONE,           KEY_EQUAL,          // =
    KEY_MOD_LALT,       KEY_DOT,            // >
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
    KEY_MOD_LALT,       KEY_LEFTBRACE,      // [

    // 92, 0x5c
    KEY_NONE,           KEY_102ND,          // bslash
    KEY_MOD_LALT,       KEY_RIGHTBRACE,     // ]
    KEY_MOD_LSHIFT,     KEY_6,              // ^
    KEY_MOD_LSHIFT,     KEY_MINUS,          // _

    // 96, 0x60
    KEY_MOD_LALT,       KEY_GRAVE,          // `
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
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_LEFTBRACE,// {

    // 124, 0x7c
    KEY_MOD_LSHIFT,     KEY_102ND,          // |
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_RIGHTBRACE,// }
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_GRAVE,// ~
    KEY_NONE,           KEY_DELETE          // DEL
};

const uint8_t utf8_ro_mac[] = {
    0xC2, 0xA0, 0x00, 0x00, KEY_MOD_LALT,           KEY_SPACE,          //  
    0xC2, 0xA5, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_M,       // ¥
    0xC2, 0xA7, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_P,       // §
    0xC2, 0xA8, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_U,       // ¨
    0xC2, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_C,              // ©
    0xC2, 0xAB, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_COMMA,   // «
    0xC2, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_R,              // ®
    0xC2, 0xB0, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_8,       // °
    0xC2, 0xB1, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_EQUAL,   // ±
    0xC2, 0xB5, 0x00, 0x00, KEY_MOD_LALT,           KEY_M,              // µ
    0xC2, 0xB7, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_9,       // ·
    0xC2, 0xBB, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_DOT,     // »
    0xC2, 0xBF, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_SLASH,   // ¿
    0xC3, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Y,       // Á
    0xC3, 0x82, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_BACKSLASH,      // Â
    0xC3, 0x85, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_A,       // Å
    0xC3, 0x8D, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_S,       // Í
    0xC3, 0x8E, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_RIGHTBRACE,     // Î
    0xC3, 0x8F, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_F,       // Ï
    0xC3, 0x93, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_H,       // Ó
    0xC3, 0x94, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_J,       // Ô
    0xC3, 0x9F, 0x00, 0x00, KEY_MOD_LALT,           KEY_S,              // ß
    0xC3, 0xA2, 0x00, 0x00, KEY_NONE,               KEY_BACKSLASH,      // â
    0xC3, 0xA5, 0x00, 0x00, KEY_MOD_LALT,           KEY_A,              // å
    0xC3, 0xAE, 0x00, 0x00, KEY_NONE,               KEY_RIGHTBRACE,     // î
    0xC3, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_SLASH,          // ÷
    0xC4, 0x82, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      // Ă
    0xC4, 0x83, 0x00, 0x00, KEY_NONE,               KEY_LEFTBRACE,      // ă
    0xC4, 0x90, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_D,       // Đ
    0xC4, 0x91, 0x00, 0x00, KEY_MOD_LALT,           KEY_D,              // đ
    0xC4, 0xB1, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_B,       // ı
    0xC5, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_L,       // Ł
    0xC5, 0x82, 0x00, 0x00, KEY_MOD_LALT,           KEY_L,              // ł
    0xC5, 0x92, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Q,       // Œ
    0xC5, 0x93, 0x00, 0x00, KEY_MOD_LALT,           KEY_Q,              // œ
    0xC6, 0x92, 0x00, 0x00, KEY_MOD_LALT,           KEY_F,              // ƒ
    0xC6, 0xB5, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Z,       // Ƶ
    0xC6, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_Z,              // ƶ
    0xC8, 0x98, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      // Ș
    0xC8, 0x99, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      // ș
    0xC8, 0x9A, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_APOSTROPHE,     // Ț
    0xC8, 0x9B, 0x00, 0x00, KEY_NONE,               KEY_APOSTROPHE,     // ț
    0xCB, 0x86, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_I,       // ˆ
    0xCB, 0x99, 0x00, 0x00, KEY_MOD_LALT,           KEY_H,              // ˙
    0xCB, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_K,              // ˚
    0xCB, 0x9B, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_X,       // ˛
    0xCB, 0x9C, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_N,       // ˜
    0xCB, 0x9D, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_G,       // ˝
    0xCE, 0x98, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_T,       // Θ
    0xCE, 0xB8, 0x00, 0x00, KEY_MOD_LALT,           KEY_T,              // θ
    0xCF, 0x80, 0x00, 0x00, KEY_MOD_LALT,           KEY_P,              // π
    0xE2, 0x80, 0x94, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_MINUS,   // —
    0xE2, 0x80, 0x9A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_0,       // ‚
    0xE2, 0x80, 0x9C, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_102ND,   // “
    0xE2, 0x80, 0x9D, 0x00, KEY_MOD_LSHIFT,         KEY_GRAVE,          // ”
    0xE2, 0x80, 0x9E, 0x00, KEY_NONE,               KEY_GRAVE,          // „
    0xE2, 0x80, 0xA1, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_7,       // ‡
    0xE2, 0x80, 0xB0, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_R,       // ‰
    0xE2, 0x80, 0xB9, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_3,       // ‹
    0xE2, 0x80, 0xBA, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_4,       // ›
    0xE2, 0x81, 0x84, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       // ⁄
    0xE2, 0x82, 0xAC, 0x00, KEY_MOD_LALT,           KEY_E,              // €
    0xE2, 0x88, 0x86, 0x00, KEY_MOD_LALT,           KEY_J,              // ∆
    0xE2, 0x88, 0x91, 0x00, KEY_MOD_LALT,           KEY_W,              // ∑
    0xE2, 0x88, 0x9A, 0x00, KEY_MOD_LALT,           KEY_V,              // √
    0xE2, 0x88, 0xAB, 0x00, KEY_MOD_LALT,           KEY_B,              // ∫
    0xE2, 0x89, 0x88, 0x00, KEY_MOD_LALT,           KEY_X,              // ≈
    0xE2, 0x89, 0xA4, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_5,       // ≤
    0xE2, 0x89, 0xA5, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_6,       // ≥
    0xE2, 0x97, 0x8A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_V,       // ◊
    0xEF, 0xA3, 0xBF, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_K,       // 
};

const uint8_t combinations_ro_mac[] = {
    0xC2, 0xB4, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_SPACE,          // ´
    0xC2, 0xB8, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_SPACE,          // ¸
    0xC3, 0x80, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_A,              // À
    0xC3, 0x83, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_A,              // Ã
    0xC3, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_MOD_LSHIFT,     KEY_A,              // Ä
    0xC3, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_C,              // Ç
    0xC3, 0x88, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_E,              // È
    0xC3, 0x89, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_E,              // É
    0xC3, 0x8A, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_MOD_LSHIFT,     KEY_E,              // Ê
    0xC3, 0x8B, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_MOD_LSHIFT,     KEY_E,              // Ë
    0xC3, 0x8C, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_I,              // Ì
    0xC3, 0x91, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_N,              // Ñ
    0xC3, 0x92, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_O,              // Ò
    0xC3, 0x95, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_O,              // Õ
    0xC3, 0x96, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_MOD_LSHIFT,     KEY_O,              // Ö
    0xC3, 0x99, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_U,              // Ù
    0xC3, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_U,              // Ú
    0xC3, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_MOD_LSHIFT,     KEY_U,              // Û
    0xC3, 0x9C, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_MOD_LSHIFT,     KEY_U,              // Ü
    0xC3, 0x9D, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_Y,              // Ý
    0xC3, 0xA0, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_A,              // à
    0xC3, 0xA1, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_A,              // á
    0xC3, 0xA3, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_A,              // ã
    0xC3, 0xA4, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_A,              // ä
    0xC3, 0xA7, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_C,              // ç
    0xC3, 0xA8, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_E,              // è
    0xC3, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_E,              // é
    0xC3, 0xAA, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_E,              // ê
    0xC3, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_E,              // ë
    0xC3, 0xAC, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_I,              // ì
    0xC3, 0xAD, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_I,              // í
    0xC3, 0xAF, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_I,              // ï
    0xC3, 0xB1, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_N,              // ñ
    0xC3, 0xB2, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_O,              // ò
    0xC3, 0xB3, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_O,              // ó
    0xC3, 0xB4, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_O,              // ô
    0xC3, 0xB5, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_O,              // õ
    0xC3, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_O,              // ö
    0xC3, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_U,              // ù
    0xC3, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_U,              // ú
    0xC3, 0xBB, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_U,              // û
    0xC3, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_U,              // ü
    0xC3, 0xBD, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_Y,              // ý
    0xC3, 0xBF, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_Y,              // ÿ
    0xC4, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_A,              // Ą
    0xC4, 0x85, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_A,              // ą
    0xC4, 0x86, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_C,              // Ć
    0xC4, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_C,              // ć
    0xC4, 0x88, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_MOD_LSHIFT,     KEY_C,              // Ĉ
    0xC4, 0x89, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_C,              // ĉ
    0xC4, 0x8A, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_C,              // Ċ
    0xC4, 0x8B, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_C,              // ċ
    0xC4, 0x8C, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_C,              // Č
    0xC4, 0x8D, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_C,              // č
    0xC4, 0x8E, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_D,              // Ď
    0xC4, 0x8F, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_D,              // ď
    0xC4, 0x94, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_E,              // Ĕ
    0xC4, 0x95, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_E,              // ĕ
    0xC4, 0x96, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_E,              // Ė
    0xC4, 0x97, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_E,              // ė
    0xC4, 0x98, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_E,              // Ę
    0xC4, 0x99, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_E,              // ę
    0xC4, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_E,              // Ě
    0xC4, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_E,              // ě
    0xC4, 0xA8, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_I,              // Ĩ
    0xC4, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_I,              // ĩ
    0xC4, 0xAC, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_I,              // Ĭ
    0xC4, 0xAD, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_I,              // ĭ
    0xC4, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_I,              // Į
    0xC4, 0xAF, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_I,              // į
    0xC4, 0xB0, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_I,              // İ
    0xC4, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_L,              // Ĺ
    0xC4, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_L,              // ĺ
    0xC4, 0xBB, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_L,              // Ļ
    0xC4, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_L,              // ļ
    0xC4, 0xBD, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_L,              // Ľ
    0xC4, 0xBE, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_L,              // ľ
    0xC5, 0x83, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_N,              // Ń
    0xC5, 0x84, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_N,              // ń
    0xC5, 0x85, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_N,              // Ņ
    0xC5, 0x86, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_N,              // ņ
    0xC5, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_N,              // Ň
    0xC5, 0x88, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_N,              // ň
    0xC5, 0x8E, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_O,              // Ŏ
    0xC5, 0x8F, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_O,              // ŏ
    0xC5, 0x90, 0x00, 0x00, KEY_MOD_LALT,           KEY_0,              KEY_MOD_LSHIFT,     KEY_O,              // Ő
    0xC5, 0x91, 0x00, 0x00, KEY_MOD_LALT,           KEY_0,              KEY_NONE,           KEY_O,              // ő
    0xC5, 0x94, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_R,              // Ŕ
    0xC5, 0x95, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_R,              // ŕ
    0xC5, 0x96, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_R,              // Ŗ
    0xC5, 0x97, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_R,              // ŗ
    0xC5, 0x98, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_R,              // Ř
    0xC5, 0x99, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_R,              // ř
    0xC5, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_S,              // Ś
    0xC5, 0x9B, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_S,              // ś
    0xC5, 0x9C, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_MOD_LSHIFT,     KEY_S,              // Ŝ
    0xC5, 0x9D, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_S,              // ŝ
    0xC5, 0x9E, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_S,              // Ş
    0xC5, 0x9F, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_S,              // ş
    0xC5, 0xA0, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_S,              // Š
    0xC5, 0xA1, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_S,              // š
    0xC5, 0xA2, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_T,              // Ţ
    0xC5, 0xA3, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_T,              // ţ
    0xC5, 0xA4, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_T,              // Ť
    0xC5, 0xA5, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_T,              // ť
    0xC5, 0xA8, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_U,              // Ũ
    0xC5, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_U,              // ũ
    0xC5, 0xAC, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_MOD_LSHIFT,     KEY_U,              // Ŭ
    0xC5, 0xAD, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_U,              // ŭ
    0xC5, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_5,              KEY_MOD_LSHIFT,     KEY_U,              // Ů
    0xC5, 0xAF, 0x00, 0x00, KEY_MOD_LALT,           KEY_5,              KEY_NONE,           KEY_U,              // ů
    0xC5, 0xB0, 0x00, 0x00, KEY_MOD_LALT,           KEY_0,              KEY_MOD_LSHIFT,     KEY_U,              // Ű
    0xC5, 0xB1, 0x00, 0x00, KEY_MOD_LALT,           KEY_0,              KEY_NONE,           KEY_U,              // ű
    0xC5, 0xB2, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_U,              // Ų
    0xC5, 0xB3, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_U,              // ų
    0xC5, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_MOD_LSHIFT,     KEY_Y,              // Ŷ
    0xC5, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_Y,              // ŷ
    0xC5, 0xB8, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_MOD_LSHIFT,     KEY_Y,              // Ÿ
    0xC5, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_MOD_LSHIFT,     KEY_Z,              // Ź
    0xC5, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              KEY_NONE,           KEY_Z,              // ź
    0xC5, 0xBB, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_Z,              // Ż
    0xC5, 0xBC, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_Z,              // ż
    0xC5, 0xBD, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_Z,              // Ž
    0xC5, 0xBE, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_Z,              // ž
    0xC7, 0x8D, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_A,              // Ǎ
    0xC7, 0x8E, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_A,              // ǎ
    0xC7, 0x8F, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_I,              // Ǐ
    0xC7, 0x90, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_I,              // ǐ
    0xC7, 0x91, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_O,              // Ǒ
    0xC7, 0x92, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_O,              // ǒ
    0xC7, 0x93, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_MOD_LSHIFT,     KEY_U,              // Ǔ
    0xC7, 0x94, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_U,              // ǔ
    0xC7, 0xAA, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_MOD_LSHIFT,     KEY_O,              // Ǫ
    0xC7, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              KEY_NONE,           KEY_O,              // ǫ
    0xC7, 0xB8, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_N,              // Ǹ
    0xC7, 0xB9, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_N,              // ǹ
    0xC8, 0xA6, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_A,              // Ȧ
    0xC8, 0xA7, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_A,              // ȧ
    0xC8, 0xA8, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_E,              // Ȩ
    0xC8, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_E,              // ȩ
    0xC8, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_O,              // Ȯ
    0xC8, 0xAF, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_O,              // ȯ
    0xCB, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              KEY_NONE,           KEY_SPACE,          // ˇ
    0xCB, 0x98, 0x00, 0x00, KEY_MOD_LALT,           KEY_4,              KEY_NONE,           KEY_SPACE,          // ˘
    0xCC, 0x82, 0x00, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_N,              // ̂
    0xCC, 0x88, 0x00, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_MOD_LSHIFT,     KEY_T,              // ̈
    0xCC, 0x8A, 0x00, 0x00, KEY_MOD_LALT,           KEY_5,              KEY_NONE,           KEY_E,              // ̊
    0xCC, 0xA7, 0x00, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_Z,              // ̧
    0xE1, 0xB8, 0x8A, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_D,              // Ḋ
    0xE1, 0xB8, 0x8B, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_D,              // ḋ
    0xE1, 0xB8, 0x90, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_MOD_LSHIFT,     KEY_D,              // Ḑ
    0xE1, 0xB8, 0x91, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          KEY_NONE,           KEY_D,              // ḑ
    0xE1, 0xB9, 0x84, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_N,              // Ṅ
    0xE1, 0xB9, 0x85, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_N,              // ṅ
    0xE1, 0xB9, 0x98, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_R,              // Ṙ
    0xE1, 0xB9, 0x99, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_R,              // ṙ
    0xE1, 0xB9, 0xA0, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_S,              // Ṡ
    0xE1, 0xB9, 0xA1, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_S,              // ṡ
    0xE1, 0xB9, 0xAA, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_T,              // Ṫ
    0xE1, 0xB9, 0xAB, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_T,              // ṫ
    0xE1, 0xBA, 0x8E, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_MOD_LSHIFT,     KEY_Y,              // Ẏ
    0xE1, 0xBA, 0x8F, 0x00, KEY_MOD_LALT,           KEY_8,              KEY_NONE,           KEY_Y,              // ẏ
    0xE1, 0xBA, 0x90, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_MOD_LSHIFT,     KEY_Z,              // Ẑ
    0xE1, 0xBA, 0x91, 0x00, KEY_MOD_LALT,           KEY_3,              KEY_NONE,           KEY_Z,              // ẑ
    0xE1, 0xBA, 0x97, 0x00, KEY_MOD_LALT,           KEY_MINUS,          KEY_NONE,           KEY_T,              // ẗ
    0xE1, 0xBA, 0x99, 0x00, KEY_MOD_LALT,           KEY_5,              KEY_NONE,           KEY_Y,              // ẙ
    0xE1, 0xBA, 0xBC, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_E,              // Ẽ
    0xE1, 0xBA, 0xBD, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_E,              // ẽ
    0xE1, 0xBB, 0xB2, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_MOD_LSHIFT,     KEY_Y,              // Ỳ
    0xE1, 0xBB, 0xB3, 0x00, KEY_MOD_LALT,           KEY_7,              KEY_NONE,           KEY_Y,              // ỳ
    0xE1, 0xBB, 0xB8, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_MOD_LSHIFT,     KEY_Y,              // Ỹ
    0xE1, 0xBB, 0xB9, 0x00, KEY_MOD_LALT,           KEY_1,              KEY_NONE,           KEY_Y,              // ỹ
};

static hid_locale_t locale_ro_mac {
    (uint8_t*)ascii_ro_mac, 128,
    (uint8_t*)utf8_ro_mac, sizeof(utf8_ro_mac) / 6,
    (uint8_t*)combinations_ro_mac, sizeof(combinations_ro_mac) / 8,
};