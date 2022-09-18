#pragma once
#include "stdint.h"

struct byte {
    uint16_t seg;
    uint16_t off;
    uint8_t val; 
    byte(uint16_t seg, uint16_t off, uint8_t val);
};

struct word {
    uint16_t seg;
    uint16_t off;
    uint16_t val;
    word(uint16_t seg, uint16_t off, uint8_t val);
};
