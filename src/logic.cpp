#include "cpu.h"

void NOT(uint8_t *dest) {
    *dest = ~*dest;
}

void NOT16(uint16_t *dest) {
    *dest = ~*dest;
}

void AND(uint8_t &dest, uint8_t &src)
{
    uint8_t temp = dest & src;
    msw.cf = 0;
    pf16(temp);
    zf16(temp);
    sf16(temp);
    msw.of = 0;
    dest = temp;
}

void AND(uint16_t &dest, uint16_t &src)
{
    uint16_t temp = dest & src;
    msw.cf = 0;
    pf16(temp);
    zf16(temp);
    sf16(temp);
    msw.of = 0;
    dest = temp;
}

void OR(uint8_t &dest, uint8_t &src)
{
    uint8_t temp = dest | src;
    msw.cf = 0;
    pf16(temp);
    zf16(temp);
    sf16(temp);
    msw.of = 0;
    dest = temp;
}

void OR(uint16_t &dest, uint16_t &src)
{
    uint16_t temp = dest | src;
    msw.cf = 0;
    pf16(temp);
    zf16(temp);
    sf16(temp);
    msw.of = 0;
    dest = temp;
}

void XOR(uint8_t &dest, uint8_t &src)
{
    uint8_t temp = dest ^ src;
    msw.cf = 0;
    pf16(temp);
    zf16(temp);
    sf16(temp);
    msw.of = 0;
    dest = temp;
}

void XOR(uint16_t &dest, uint16_t &src)
{
    uint16_t temp = dest ^ src;
    msw.cf = 0;
    pf16(temp);
    zf16(temp);
    sf16(temp);
    msw.of = 0;
    dest = temp;
}
