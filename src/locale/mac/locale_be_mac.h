/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../usb_hid_keys.h"

// Modifier(s), Key
const uint8_t ascii_be_mac[] = {
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
    KEY_NONE,           KEY_8,              // !
    KEY_NONE,           KEY_3,              // "
    KEY_MOD_LSHIFT,     KEY_GRAVE,          // #

    // 36, 0x24
    KEY_NONE,           KEY_RIGHTBRACE,     // $
    KEY_MOD_LSHIFT,     KEY_APOSTROPHE,     // %
    KEY_NONE,           KEY_1,              // &
    KEY_NONE,           KEY_4,              // '

    // 40, 0x28
    KEY_NONE,           KEY_5,              // (
    KEY_NONE,           KEY_MINUS,          // )
    KEY_MOD_LSHIFT,     KEY_RIGHTBRACE,     // *
    KEY_MOD_LSHIFT,     KEY_SLASH,          // +

    // 44, 0x2c
    KEY_NONE,           KEY_M,              // ,
    KEY_NONE,           KEY_EQUAL,          // -
    KEY_MOD_LSHIFT,     KEY_COMMA,          // .
    KEY_MOD_LSHIFT,     KEY_DOT,            // /

    // 48, 0x30
    KEY_MOD_LSHIFT,     KEY_0,              // 0
    KEY_MOD_LSHIFT,     KEY_1,              // 1
    KEY_MOD_LSHIFT,     KEY_2,              // 2
    KEY_MOD_LSHIFT,     KEY_3,              // 3

    // 52, 0x34
    KEY_MOD_LSHIFT,     KEY_4,              // 4
    KEY_MOD_LSHIFT,     KEY_5,              // 5
    KEY_MOD_LSHIFT,     KEY_6,              // 6
    KEY_MOD_LSHIFT,     KEY_7,              // 7

    // 56, 0x38
    KEY_MOD_LSHIFT,     KEY_8,              // 8
    KEY_MOD_LSHIFT,     KEY_9,              // 9
    KEY_NONE,           KEY_DOT,            // :
    KEY_NONE,           KEY_COMMA,          // ;

    // 60, 0x3c
    KEY_NONE,           KEY_102ND,          // <
    KEY_NONE,           KEY_SLASH,          // =
    KEY_MOD_LSHIFT,     KEY_102ND,          // >
    KEY_MOD_LSHIFT,     KEY_M,              // ?

    // 64, 0x40
    KEY_NONE,           KEY_GRAVE,          // @
    KEY_MOD_LSHIFT,     KEY_Q,              // A
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
    KEY_MOD_LSHIFT,     KEY_SEMICOLON,      // M
    KEY_MOD_LSHIFT,     KEY_N,              // N
    KEY_MOD_LSHIFT,     KEY_O,              // O

    // 80, 0x50
    KEY_MOD_LSHIFT,     KEY_P,              // P
    KEY_MOD_LSHIFT,     KEY_A,              // Q
    KEY_MOD_LSHIFT,     KEY_R,              // R
    KEY_MOD_LSHIFT,     KEY_S,              // S

    // 84, 0x54
    KEY_MOD_LSHIFT,     KEY_T,              // T
    KEY_MOD_LSHIFT,     KEY_U,              // U
    KEY_MOD_LSHIFT,     KEY_V,              // V
    KEY_MOD_LSHIFT,     KEY_Z,              // W

    // 88, 0x58
    KEY_MOD_LSHIFT,     KEY_X,              // X
    KEY_MOD_LSHIFT,     KEY_Y,              // Y
    KEY_MOD_LSHIFT,     KEY_W,              // Z
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_5,    // [

    // 92, 0x5c
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_DOT,  // bslash
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_MINUS,// ]
    KEY_NONE,           KEY_SPACE,          // ^
    KEY_MOD_LSHIFT,     KEY_EQUAL,          // _

    // 96, 0x60
    KEY_NONE,           KEY_BACKSLASH,      // `
    KEY_NONE,           KEY_Q,              // a
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
    KEY_NONE,           KEY_NONE,           // m
    KEY_NONE,           KEY_N,              // n
    KEY_NONE,           KEY_O,              // o

    // 112, 0x70
    KEY_NONE,           KEY_P,              // p
    KEY_NONE,           KEY_A,              // q
    KEY_NONE,           KEY_R,              // r
    KEY_NONE,           KEY_S,              // s

    // 116, 0x74
    KEY_NONE,           KEY_T,              // t
    KEY_NONE,           KEY_U,              // u
    KEY_NONE,           KEY_V,              // v
    KEY_NONE,           KEY_Z,              // w

    // 120, 0x78
    KEY_NONE,           KEY_X,              // x
    KEY_NONE,           KEY_Y,              // y
    KEY_NONE,           KEY_W,              // z
    KEY_MOD_LALT,       KEY_5,              // {

    // 124, 0x7c
    (KEY_MOD_LALT|KEY_MOD_LSHIFT),KEY_L,    // |
    KEY_MOD_LALT,       KEY_MINUS,          // }
    KEY_NONE,           KEY_SPACE,          // ~
    KEY_NONE,           KEY_DELETE          // DEL
};

const uint8_t utf8_be_mac[] = {
    0xC2, 0xA1, 0x00, 0x00, KEY_MOD_LALT,           KEY_8,              // ¡
    0xC2, 0xA2, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_C,       // ¢
    0xC2, 0xA3, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_BACKSLASH,      // £
    0xC2, 0xA5, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_RIGHTBRACE, // ¥
    0xC2, 0xA7, 0x00, 0x00, KEY_NONE,               KEY_6,              // §
    0xC2, 0xA9, 0x00, 0x00, KEY_MOD_LALT,           KEY_C,              // ©
    0xC2, 0xAA, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_U,       // ª
    0xC2, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_7,              // «
    0xC2, 0xAC, 0x00, 0x00, KEY_MOD_LALT,           KEY_L,              // ¬
    0xC2, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_R,              // ®
    0xC2, 0xB0, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_MINUS,          // °
    0xC2, 0xB1, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_SLASH,   // ±
    0xC2, 0xB5, 0x00, 0x00, KEY_MOD_LALT,           KEY_SEMICOLON,      // µ
    0xC2, 0xB6, 0x00, 0x00, KEY_MOD_LALT,           KEY_6,              // ¶
    0xC2, 0xB7, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_F,       // ·
    0xC2, 0xBA, 0x00, 0x00, KEY_MOD_LALT,           KEY_U,              // º
    0xC2, 0xBB, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_7,       // »
    0xC2, 0xBF, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_M,       // ¿
    0xC3, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_9,       // Á
    0xC3, 0x82, 0x00, 0x00, KEY_MOD_LALT,           KEY_W,              // Â
    0xC3, 0x85, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_W,       // Å
    0xC3, 0x86, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Q,       // Æ
    0xC3, 0x87, 0x00, 0x00, KEY_MOD_LALT,           KEY_9,              // Ç
    0xC3, 0x88, 0x00, 0x00, KEY_MOD_LALT,           KEY_K,              // È
    0xC3, 0x8A, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_E,       // Ê
    0xC3, 0x8B, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_K,       // Ë
    0xC3, 0x8C, 0x00, 0x00, KEY_MOD_LALT,           KEY_H,              // Ì
    0xC3, 0x8D, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_J,       // Í
    0xC3, 0x8E, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_H,       // Î
    0xC3, 0x8F, 0x00, 0x00, KEY_MOD_LALT,           KEY_J,              // Ï
    0xC3, 0x92, 0x00, 0x00, KEY_MOD_LALT,           KEY_S,              // Ò
    0xC3, 0x93, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_SEMICOLON, // Ó
    0xC3, 0x94, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_LEFTBRACE, // Ô
    0xC3, 0x98, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_0,       // Ø
    0xC3, 0x99, 0x00, 0x00, KEY_MOD_LALT,           KEY_APOSTROPHE,     // Ù
    0xC3, 0x9A, 0x00, 0x00, KEY_MOD_LALT,           KEY_Y,              // Ú
    0xC3, 0x9B, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_8,       // Û
    0xC3, 0x9F, 0x00, 0x00, KEY_MOD_LALT,           KEY_B,              // ß
    0xC3, 0xA0, 0x00, 0x00, KEY_NONE,               KEY_0,              // à
    0xC3, 0xA5, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_6,       // å
    0xC3, 0xA6, 0x00, 0x00, KEY_MOD_LALT,           KEY_Q,              // æ
    0xC3, 0xA7, 0x00, 0x00, KEY_NONE,               KEY_9,              // ç
    0xC3, 0xA8, 0x00, 0x00, KEY_NONE,               KEY_7,              // è
    0xC3, 0xA9, 0x00, 0x00, KEY_NONE,               KEY_2,              // é
    0xC3, 0xAA, 0x00, 0x00, KEY_MOD_LALT,           KEY_E,              // ê
    0xC3, 0xAB, 0x00, 0x00, KEY_MOD_LALT,           KEY_2,              // ë
    0xC3, 0xAE, 0x00, 0x00, KEY_MOD_LALT,           KEY_I,              // î
    0xC3, 0xAF, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_I,       // ï
    0xC3, 0xB4, 0x00, 0x00, KEY_MOD_LALT,           KEY_LEFTBRACE,      // ô
    0xC3, 0xB7, 0x00, 0x00, KEY_MOD_LALT,           KEY_DOT,            // ÷
    0xC3, 0xB8, 0x00, 0x00, KEY_MOD_LALT,           KEY_0,              // ø
    0xC3, 0xB9, 0x00, 0x00, KEY_NONE,               KEY_APOSTROPHE,     // ù
    0xC4, 0xB1, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_N,       // ı
    0xC5, 0x92, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_O,       // Œ
    0xC5, 0x93, 0x00, 0x00, KEY_MOD_LALT,           KEY_O,              // œ
    0xC5, 0xB8, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Y,       // Ÿ
    0xC6, 0x92, 0x00, 0x00, KEY_MOD_LALT,           KEY_F,              // ƒ
    0xCE, 0xA9, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_A,       // Ω
    0xCF, 0x80, 0x00, 0x00, KEY_MOD_LALT,           KEY_P,              // π
    0xE2, 0x80, 0x93, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_EQUAL,   // –
    0xE2, 0x80, 0x94, 0x00, KEY_MOD_LALT,           KEY_EQUAL,          // —
    0xE2, 0x80, 0x98, 0x00, KEY_MOD_LALT,           KEY_4,              // ‘
    0xE2, 0x80, 0x99, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_4,       // ’
    0xE2, 0x80, 0x9A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_R,       // ‚
    0xE2, 0x80, 0x9C, 0x00, KEY_MOD_LALT,           KEY_3,              // “
    0xE2, 0x80, 0x9D, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_3,       // ”
    0xE2, 0x80, 0x9E, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_2,       // „
    0xE2, 0x80, 0xA0, 0x00, KEY_MOD_LALT,           KEY_T,              // †
    0xE2, 0x80, 0xA1, 0x00, KEY_MOD_LALT,           KEY_A,              // ‡
    0xE2, 0x80, 0xA2, 0x00, KEY_MOD_LALT,           KEY_GRAVE,          // •
    0xE2, 0x80, 0xA6, 0x00, KEY_MOD_LALT,           KEY_COMMA,          // …
    0xE2, 0x80, 0xB0, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_APOSTROPHE, // ‰
    0xE2, 0x80, 0xB9, 0x00, KEY_MOD_LALT,           KEY_Z,              // ‹
    0xE2, 0x80, 0xBA, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_Z,       // ›
    0xE2, 0x81, 0x84, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_X,       // ⁄
    0xE2, 0x82, 0xAC, 0x00, KEY_MOD_LALT,           KEY_RIGHTBRACE,     // €
    0xE2, 0x84, 0xA2, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_T,       // ™
    0xE2, 0x88, 0x82, 0x00, KEY_MOD_LALT,           KEY_D,              // ∂
    0xE2, 0x88, 0x86, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_D,       // ∆
    0xE2, 0x88, 0x8F, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_P,       // ∏
    0xE2, 0x88, 0x91, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_S,       // ∑
    0xE2, 0x88, 0x9A, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_V,       // √
    0xE2, 0x88, 0x9E, 0x00, KEY_MOD_LALT,           KEY_M,              // ∞
    0xE2, 0x88, 0xAB, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_B,       // ∫
    0xE2, 0x89, 0x88, 0x00, KEY_MOD_LALT,           KEY_X,              // ≈
    0xE2, 0x89, 0xA0, 0x00, KEY_MOD_LALT,           KEY_SLASH,          // ≠
    0xE2, 0x89, 0xA4, 0x00, KEY_MOD_LALT,           KEY_102ND,          // ≤
    0xE2, 0x89, 0xA5, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_102ND,   // ≥
    0xE2, 0x97, 0x8A, 0x00, KEY_MOD_LALT,           KEY_V,              // ◊
    0xEF, 0xA3, 0xBF, 0x00, KEY_MOD_LALT,           KEY_1,              // 
    0xEF, 0xAC, 0x81, 0x00, KEY_MOD_LALT,           KEY_G,              // ﬁ
    0xEF, 0xAC, 0x82, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_G,       // ﬂ
};

const uint8_t combinations_be_mac[] = {
    0x5E, 0x00, 0x00, 0x00, KEY_NONE,               KEY_LEFTBRACE,      KEY_NONE,           KEY_SPACE,          // ^
    0x7E, 0x00, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_NONE,           KEY_SPACE,          // ~
    0xC2, 0xA8, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_NONE,           KEY_SPACE,          // ¨
    0xC2, 0xB4, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_NONE,           KEY_SPACE,          // ´
    0xC3, 0x80, 0x00, 0x00, KEY_NONE,               KEY_BACKSLASH,      KEY_MOD_LSHIFT,     KEY_Q,              // À
    0xC3, 0x83, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_MOD_LSHIFT,     KEY_Q,              // Ã
    0xC3, 0x84, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_MOD_LSHIFT,     KEY_Q,              // Ä
    0xC3, 0x89, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_MOD_LSHIFT,     KEY_E,              // É
    0xC3, 0x95, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_MOD_LSHIFT,     KEY_O,              // Õ
    0xC3, 0x96, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_MOD_LSHIFT,     KEY_O,              // Ö
    0xC3, 0x9C, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_MOD_LSHIFT,     KEY_U,              // Ü
    0xC3, 0xA1, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_NONE,           KEY_Q,              // á
    0xC3, 0xA2, 0x00, 0x00, KEY_NONE,               KEY_LEFTBRACE,      KEY_NONE,           KEY_Q,              // â
    0xC3, 0xA3, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_NONE,           KEY_Q,              // ã
    0xC3, 0xA4, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_NONE,           KEY_Q,              // ä
    0xC3, 0xAC, 0x00, 0x00, KEY_NONE,               KEY_BACKSLASH,      KEY_NONE,           KEY_I,              // ì
    0xC3, 0xAD, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_NONE,           KEY_I,              // í
    0xC3, 0xB2, 0x00, 0x00, KEY_NONE,               KEY_BACKSLASH,      KEY_NONE,           KEY_O,              // ò
    0xC3, 0xB3, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_NONE,           KEY_O,              // ó
    0xC3, 0xB5, 0x00, 0x00, KEY_MOD_LALT,           KEY_N,              KEY_NONE,           KEY_O,              // õ
    0xC3, 0xB6, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_NONE,           KEY_O,              // ö
    0xC3, 0xBA, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_NONE,           KEY_U,              // ú
    0xC3, 0xBB, 0x00, 0x00, KEY_NONE,               KEY_LEFTBRACE,      KEY_NONE,           KEY_U,              // û
    0xC3, 0xBC, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_NONE,           KEY_U,              // ü
    0xC3, 0xBF, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_LEFTBRACE,      KEY_NONE,           KEY_Y,              // ÿ
    0xCC, 0x81, 0x00, 0x00, (KEY_MOD_LALT|KEY_MOD_LSHIFT), KEY_1,       KEY_NONE,           KEY_J,              // ́
};

static hid_locale_t locale_be_mac {
    (uint8_t*)ascii_be_mac, 128,
    (uint8_t*)utf8_be_mac, sizeof(utf8_be_mac) / 6,
    (uint8_t*)combinations_be_mac, sizeof(combinations_be_mac) / 8,
};