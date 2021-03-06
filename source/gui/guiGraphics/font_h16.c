/*****************************************************
    Font generation template
*****************************************************/

#include <stdint.h>
#include "guiFonts.h"

static const uint8_t font_h16_data [] =
{
    // symbol 0x20
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,

    // symbol 0x2D
    0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    // symbol 0x2E
    0x00, 0x00, 0x00, 0xE0, 0xE0, 0x00,

    // symbol 0x30
    0xFE, 0xFF, 0x7F, 0x07, 0x07, 0x07, 0x7F, 0xFF,
    0xFE, 0x00, 0x7F, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0,
    0xFF, 0xFF, 0x7F, 0x00,

    // symbol 0x31
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0xFE,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3F, 0x7F, 0xFF, 0x00,

    // symbol 0x32
    0x81, 0xC3, 0xC7, 0xC7, 0xC7, 0xC7, 0xFF, 0xFF,
    0xFE, 0x00, 0x7F, 0xFF, 0xFF, 0xE1, 0xE1, 0xE1,
    0xE1, 0xC1, 0x80, 0x00,

    // symbol 0x33
    0x01, 0x83, 0xC7, 0xC7, 0xC7, 0xC7, 0xFF, 0xFF,
    0x7E, 0x00, 0x80, 0xC0, 0xE1, 0xE1, 0xE1, 0xE1,
    0xFF, 0xFF, 0x7F, 0x00,

    // symbol 0x34
    0xFF, 0xFE, 0xFC, 0xC0, 0xC0, 0xC0, 0xFC, 0xFE,
    0x7F, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x3F, 0x7F, 0xFF, 0x00,

    // symbol 0x35
    0xFE, 0xFF, 0xFF, 0xC7, 0xC7, 0xC7, 0xC7, 0xC3,
    0x81, 0x00, 0x80, 0xC1, 0xE1, 0xE1, 0xE1, 0xE1,
    0xFF, 0xFF, 0x7F, 0x00,

    // symbol 0x36
    0x7E, 0xFF, 0xFF, 0xC7, 0xC7, 0xC7, 0xC7, 0xC3,
    0x81, 0x00, 0x7F, 0xFF, 0xFF, 0xE1, 0xE1, 0xE1,
    0xFF, 0xFF, 0x7F, 0x00,

    // symbol 0x37
    0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x7F, 0xFF,
    0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3F, 0x7F, 0xFF, 0x00,

    // symbol 0x38
    0x7E, 0xFF, 0xFF, 0xC7, 0xC7, 0xC7, 0xFF, 0xFF,
    0x7E, 0x00, 0x7F, 0xFF, 0xFF, 0xE1, 0xE1, 0xE1,
    0xFF, 0xFF, 0x7F, 0x00,

    // symbol 0x39
    0xFE, 0xFF, 0xFF, 0xC7, 0xC7, 0xC7, 0xFF, 0xFF,
    0x7E, 0x00, 0x80, 0xC1, 0xE1, 0xE1, 0xE1, 0xE1,
    0xFF, 0xFF, 0x7F, 0x00,

    // symbol 0x3A
    0x00, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,

    // symbol 0x61
    0x00, 0x00, 0x80, 0xF0, 0x70, 0xF0, 0x80, 0x00,
    0x00, 0x00, 0xE0, 0xFC, 0x3F, 0x33, 0x30, 0x33,
    0x3F, 0xFC, 0xE0, 0x00,

    // symbol 0x65
    0xF0, 0xF0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x00, 0xFF, 0xFF, 0xC6, 0xC6, 0xC6, 0xC6, 0xC6,
    0xC6, 0x00,

    // symbol 0x73
    0xF0, 0xF0, 0x30, 0x30, 0x30, 0x30, 0x70, 0x70,
    0x00, 0xE7, 0xE7, 0xC6, 0xC6, 0xC6, 0xC6, 0xFE,
    0xFE, 0x00,

    // symbol 0x74
    0x30, 0x30, 0x30, 0xF0, 0xF0, 0x30, 0x30, 0x30,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00,

    // symbol 0x76
    0x70, 0xF0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xF0,
    0x70, 0x00, 0x00, 0x03, 0x1F, 0xFC, 0xE0, 0xFC,
    0x1F, 0x03, 0x00, 0x00,

};



static const uint8_t font_h16_code_table[19] =
{
    0x20,
    0x2D,
    0x2E,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A,
    0x61,
    0x65,
    0x73,
    0x74,
    0x76,
};

static const uint8_t font_h16_width_table[19] =
{
    10,
    8,
    3,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    10,
    8,
    10,
    9,
    9,
    9,
    10,
};

static const uint16_t font_h16_offset_table[19] =
{
    0,
    20,
    36,
    42,
    62,
    82,
    102,
    122,
    142,
    162,
    182,
    202,
    222,
    242,
    258,
    278,
    296,
    314,
    332,
};

const tFont font_h16 =
{
    16,          // font height
    0,                      // font width - not used with variable width
    19,          // total chars count
    0,                      // spacing
    0,                      // bytesPerChar - not used with variable width
    0,                      // firstCharCode - not used with char table
    font_h16_code_table,    // character code table
    font_h16_width_table,	// character width table
    font_h16_offset_table,	// offset table
    font_h16_data           // font data
};

