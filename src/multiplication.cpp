#include "cpu.h"

void MUL(uint8_t &src)
{
    ax.bytes.al *= src;
    msw.cf = ax.bytes.al & 0xf0;
    msw.of = msw.cf;
}

void MUL(uint16_t &src)
{
    ax.ax *= src;
    msw.cf = ax.ax & 0xff00;
    msw.of = msw.cf;
}

void IMUL1(int8_t &src)
{
    uint16_t temp = ax.bytes.l * src;
    msw.cf = temp & 0xff00;
    msw.of = msw.cf;
    
}

void IMUL1(int16_t &src)
{
    ax.ax = (int16_t) ax.ax * src;
    msw.cf = ax.ax & 0xff00;
    msw.of = msw.cf;
}