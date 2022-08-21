#include "cpu.h"

void cf8(unsigned int a)
{
    msw.cf = a >> 8;
}

void cf16(unsigned int a)
{
    msw.cf = a >> 15;
}

void pf8(uint8_t a)
{
    msw.pf = parity_table[a];
}

void pf16(uint16_t a)
{
    msw.pf = parity_table[a & 0xff];
}

void af8(unsigned int a, uint8_t b, uint8_t c)
{
    msw.af = (a ^ b ^ c) & 0x10 ? true : false;
}

void af16(unsigned int a, uint16_t b, uint16_t c)
{
    msw.af = (a ^ b ^ c) & 0x1000 ? true : false;
}

void zf8(uint8_t a)
{
    msw.zf = !(uint8_t(a));
}

void zf16(uint16_t a)
{
    msw.zf = !(uint16_t(a));
}

void sf8(uint8_t a)
{
    msw.sf = a >> 7;
}

void sf16(uint16_t a)
{
    msw.sf = a >> 15;
}

void of8(uint8_t a, uint8_t b)
{
    msw.of = (a ^ b) & 0x80 ? true : false;
}

void of16(uint16_t a, uint16_t b)
{
    msw.of = (a ^ b) & 0x8000 ? true : false;
}

void tf(bool set)
{
    msw.tf = set;
}

void iff(bool set)
{
    msw.iff = set;
}

void df(bool set)
{
    msw.df = set;
}