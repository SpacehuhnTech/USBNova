/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include "../usb_hid_keys.h"

// Modifier(s), Key
const uint8_t ascii_gr_win[] = {
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
    KEY_MOD_LSHIFT,     KEY_3,              // #

    // 36, 0x24
    KEY_MOD_LSHIFT,     KEY_4,              // $
    KEY_MOD_LSHIFT,     KEY_5,              // %
    KEY_MOD_LSHIFT,     KEY_7,              // &
    KEY_NONE,           KEY_APOSTROPHE,     // '

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
    KEY_MOD_LSHIFT,     KEY_Q,              // :
    KEY_NONE,           KEY_Q,              // ;

    // 60, 0x3c
    KEY_NONE,           KEY_102ND,          // <
    KEY_NONE,           KEY_EQUAL,          // =
    KEY_MOD_LSHIFT,     KEY_DOT,            // >
    KEY_MOD_LSHIFT,     KEY_SLASH,          // ?

    // 64, 0x40
    KEY_MOD_LSHIFT,     KEY_2,              // @
    KEY_NONE,           KEY_NONE,           // A
    KEY_NONE,           KEY_NONE,           // B
    KEY_NONE,           KEY_NONE,           // C

    // 68, 0x44
    KEY_NONE,           KEY_NONE,           // D
    KEY_NONE,           KEY_NONE,           // E
    KEY_NONE,           KEY_NONE,           // F
    KEY_NONE,           KEY_NONE,           // G

    // 72, 0x48
    KEY_NONE,           KEY_NONE,           // H
    KEY_NONE,           KEY_NONE,           // I
    KEY_NONE,           KEY_NONE,           // J
    KEY_NONE,           KEY_NONE,           // K

    // 76, 0x4c
    KEY_NONE,           KEY_NONE,           // L
    KEY_NONE,           KEY_NONE,           // M
    KEY_NONE,           KEY_NONE,           // N
    KEY_NONE,           KEY_NONE,           // O

    // 80, 0x50
    KEY_NONE,           KEY_NONE,           // P
    KEY_NONE,           KEY_NONE,           // Q
    KEY_NONE,           KEY_NONE,           // R
    KEY_NONE,           KEY_NONE,           // S

    // 84, 0x54
    KEY_NONE,           KEY_NONE,           // T
    KEY_NONE,           KEY_NONE,           // U
    KEY_NONE,           KEY_NONE,           // V
    KEY_NONE,           KEY_NONE,           // W

    // 88, 0x58
    KEY_NONE,           KEY_NONE,           // X
    KEY_NONE,           KEY_NONE,           // Y
    KEY_NONE,           KEY_NONE,           // Z
    KEY_NONE,           KEY_LEFTBRACE,      // [

    // 92, 0x5c
    KEY_NONE,           KEY_BACKSLASH,      // bslash
    KEY_NONE,           KEY_RIGHTBRACE,     // ]
    KEY_MOD_LSHIFT,     KEY_6,              // ^
    KEY_MOD_LSHIFT,     KEY_MINUS,          // _

    // 96, 0x60
    KEY_NONE,           KEY_GRAVE,          // `
    KEY_NONE,           KEY_NONE,           // a
    KEY_NONE,           KEY_NONE,           // b
    KEY_NONE,           KEY_NONE,           // c

    // 100, 0x64
    KEY_NONE,           KEY_NONE,           // d
    KEY_NONE,           KEY_NONE,           // e
    KEY_NONE,           KEY_NONE,           // f
    KEY_NONE,           KEY_NONE,           // g

    // 104, 0x68
    KEY_NONE,           KEY_NONE,           // h
    KEY_NONE,           KEY_NONE,           // i
    KEY_NONE,           KEY_NONE,           // j
    KEY_NONE,           KEY_NONE,           // k

    // 108, 0x6c
    KEY_NONE,           KEY_NONE,           // l
    KEY_NONE,           KEY_NONE,           // m
    KEY_NONE,           KEY_NONE,           // n
    KEY_NONE,           KEY_NONE,           // o

    // 112, 0x70
    KEY_NONE,           KEY_NONE,           // p
    KEY_NONE,           KEY_NONE,           // q
    KEY_NONE,           KEY_NONE,           // r
    KEY_NONE,           KEY_NONE,           // s

    // 116, 0x74
    KEY_NONE,           KEY_NONE,           // t
    KEY_NONE,           KEY_NONE,           // u
    KEY_NONE,           KEY_NONE,           // v
    KEY_NONE,           KEY_NONE,           // w

    // 120, 0x78
    KEY_NONE,           KEY_NONE,           // x
    KEY_NONE,           KEY_NONE,           // y
    KEY_NONE,           KEY_NONE,           // z
    KEY_MOD_LSHIFT,     KEY_LEFTBRACE,      // {

    // 124, 0x7c
    KEY_MOD_LSHIFT,     KEY_BACKSLASH,      // |
    KEY_MOD_LSHIFT,     KEY_RIGHTBRACE,     // }
    KEY_MOD_LSHIFT,     KEY_GRAVE,          // ~
    KEY_NONE,           KEY_DELETE          // DEL
};

const uint8_t utf8_gr_win[] = {
    0xC2, 0xA3, 0x00, 0x00, KEY_MOD_RALT,           KEY_4,              // £
    0xC2, 0xA4, 0x00, 0x00, KEY_MOD_RALT,           KEY_8,              // ¤
    0xC2, 0xA5, 0x00, 0x00, KEY_MOD_RALT,           KEY_Y,              // ¥
    0xC2, 0xA6, 0x00, 0x00, KEY_MOD_RALT,           KEY_9,              // ¦
    0xC2, 0xA7, 0x00, 0x00, KEY_MOD_RALT,           KEY_5,              // §
    0xC2, 0xA9, 0x00, 0x00, KEY_MOD_RALT,           KEY_C,              // ©
    0xC2, 0xAB, 0x00, 0x00, KEY_MOD_RALT,           KEY_LEFTBRACE,      // «
    0xC2, 0xAC, 0x00, 0x00, KEY_MOD_RALT,           KEY_BACKSLASH,      // ¬
    0xC2, 0xAE, 0x00, 0x00, KEY_MOD_RALT,           KEY_R,              // ®
    0xC2, 0xB0, 0x00, 0x00, KEY_MOD_RALT,           KEY_0,              // °
    0xC2, 0xB1, 0x00, 0x00, KEY_MOD_RALT,           KEY_MINUS,          // ±
    0xC2, 0xB2, 0x00, 0x00, KEY_MOD_RALT,           KEY_2,              // ²
    0xC2, 0xB3, 0x00, 0x00, KEY_MOD_RALT,           KEY_3,              // ³
    0xC2, 0xB6, 0x00, 0x00, KEY_MOD_RALT,           KEY_6,              // ¶
    0xC2, 0xBB, 0x00, 0x00, KEY_MOD_RALT,           KEY_RIGHTBRACE,     // »
    0xC2, 0xBD, 0x00, 0x00, KEY_MOD_RALT,           KEY_EQUAL,          // ½
    0xCE, 0x91, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_A,              // Α
    0xCE, 0x92, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_B,              // Β
    0xCE, 0x93, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_G,              // Γ
    0xCE, 0x94, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_D,              // Δ
    0xCE, 0x95, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_E,              // Ε
    0xCE, 0x96, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_Z,              // Ζ
    0xCE, 0x97, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_H,              // Η
    0xCE, 0x98, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_U,              // Θ
    0xCE, 0x99, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_I,              // Ι
    0xCE, 0x9A, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_K,              // Κ
    0xCE, 0x9B, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_L,              // Λ
    0xCE, 0x9C, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_M,              // Μ
    0xCE, 0x9D, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_N,              // Ν
    0xCE, 0x9E, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_J,              // Ξ
    0xCE, 0x9F, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_O,              // Ο
    0xCE, 0xA0, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_P,              // Π
    0xCE, 0xA1, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_R,              // Ρ
    0xCE, 0xA3, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_S,              // Σ
    0xCE, 0xA4, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_T,              // Τ
    0xCE, 0xA5, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_Y,              // Υ
    0xCE, 0xA6, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_F,              // Φ
    0xCE, 0xA7, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_X,              // Χ
    0xCE, 0xA8, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_C,              // Ψ
    0xCE, 0xA9, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_V,              // Ω
    0xCE, 0xB1, 0x00, 0x00, KEY_NONE,               KEY_A,              // α
    0xCE, 0xB2, 0x00, 0x00, KEY_NONE,               KEY_B,              // β
    0xCE, 0xB3, 0x00, 0x00, KEY_NONE,               KEY_G,              // γ
    0xCE, 0xB4, 0x00, 0x00, KEY_NONE,               KEY_D,              // δ
    0xCE, 0xB5, 0x00, 0x00, KEY_NONE,               KEY_E,              // ε
    0xCE, 0xB6, 0x00, 0x00, KEY_NONE,               KEY_Z,              // ζ
    0xCE, 0xB7, 0x00, 0x00, KEY_NONE,               KEY_H,              // η
    0xCE, 0xB8, 0x00, 0x00, KEY_NONE,               KEY_U,              // θ
    0xCE, 0xB9, 0x00, 0x00, KEY_NONE,               KEY_I,              // ι
    0xCE, 0xBA, 0x00, 0x00, KEY_NONE,               KEY_K,              // κ
    0xCE, 0xBB, 0x00, 0x00, KEY_NONE,               KEY_L,              // λ
    0xCE, 0xBC, 0x00, 0x00, KEY_NONE,               KEY_M,              // μ
    0xCE, 0xBD, 0x00, 0x00, KEY_NONE,               KEY_N,              // ν
    0xCE, 0xBE, 0x00, 0x00, KEY_NONE,               KEY_J,              // ξ
    0xCE, 0xBF, 0x00, 0x00, KEY_NONE,               KEY_O,              // ο
    0xCF, 0x80, 0x00, 0x00, KEY_NONE,               KEY_P,              // π
    0xCF, 0x81, 0x00, 0x00, KEY_NONE,               KEY_R,              // ρ
    0xCF, 0x82, 0x00, 0x00, KEY_NONE,               KEY_W,              // ς
    0xCF, 0x83, 0x00, 0x00, KEY_NONE,               KEY_S,              // σ
    0xCF, 0x84, 0x00, 0x00, KEY_NONE,               KEY_T,              // τ
    0xCF, 0x85, 0x00, 0x00, KEY_NONE,               KEY_Y,              // υ
    0xCF, 0x86, 0x00, 0x00, KEY_NONE,               KEY_F,              // φ
    0xCF, 0x87, 0x00, 0x00, KEY_NONE,               KEY_X,              // χ
    0xCF, 0x88, 0x00, 0x00, KEY_NONE,               KEY_C,              // ψ
    0xCF, 0x89, 0x00, 0x00, KEY_NONE,               KEY_V,              // ω
    0xE2, 0x82, 0xAC, 0x00, KEY_MOD_RALT,           KEY_E,              // €
};

const uint8_t combinations_gr_win[] = {
    0xC2, 0xA8, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      KEY_NONE,           KEY_SPACE,          // ¨
    0xCE, 0x84, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_SPACE,          // ΄
    0xCE, 0x85, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_W,              KEY_NONE,           KEY_SPACE,          // ΅
    0xCE, 0x86, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_A,              // Ά
    0xCE, 0x88, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_E,              // Έ
    0xCE, 0x89, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_H,              // Ή
    0xCE, 0x8A, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_I,              // Ί
    0xCE, 0x8C, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_O,              // Ό
    0xCE, 0x8E, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_Y,              // Ύ
    0xCE, 0x8F, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_V,              // Ώ
    0xCE, 0x90, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_W,              KEY_NONE,           KEY_I,              // ΐ
    0xCE, 0xAA, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_I,              // Ϊ
    0xCE, 0xAB, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      KEY_MOD_LSHIFT,     KEY_Y,              // Ϋ
    0xCE, 0xAC, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_A,              // ά
    0xCE, 0xAD, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_E,              // έ
    0xCE, 0xAE, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_H,              // ή
    0xCE, 0xAF, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_I,              // ί
    0xCE, 0xB0, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_W,              KEY_NONE,           KEY_Y,              // ΰ
    0xCF, 0x8A, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      KEY_NONE,           KEY_I,              // ϊ
    0xCF, 0x8B, 0x00, 0x00, KEY_MOD_LSHIFT,         KEY_SEMICOLON,      KEY_NONE,           KEY_Y,              // ϋ
    0xCF, 0x8C, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_O,              // ό
    0xCF, 0x8D, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_Y,              // ύ
    0xCF, 0x8E, 0x00, 0x00, KEY_NONE,               KEY_SEMICOLON,      KEY_NONE,           KEY_V,              // ώ
};

static hid_locale_t locale_gr_win {
    (uint8_t*)ascii_gr_win, 128,
    (uint8_t*)utf8_gr_win, sizeof(utf8_gr_win) / 6,
    (uint8_t*)combinations_gr_win, sizeof(combinations_gr_win) / 8,
};