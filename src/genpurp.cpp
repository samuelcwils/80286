#include "cpu.h"

void MOV(uint8_t &dest, uint8_t &src){
    dest = src;
}

void MOV(uint16_t &dest, uint16_t &src){
    dest = src;
}

void PUSH(uint8_t &src){
    sp -= 1;
    mem[sp] = src;
}

void PUSH(uint16_t &src){
    sp -= 2;
    putMem16(ss, sp, src);
}

void POP(uint8_t &dest){
    dest = mem[sp];
    sp += 1;
}

void POP(uint16_t &dest){
    dest = getMem16(ss, sp);
    sp += 2;
}

void PUSHA(){
    PUSH(ax.ax);
    PUSH(cx.cx);
    PUSH(dx.dx);
    PUSH(bx.bx);
    PUSH(sp);
    PUSH(bp);
    PUSH(si);
    PUSH(di);
}

void POPA(){
    POP(di);
    POP(si);
    POP(bp);
    POP(sp);
    POP(bx.bx);
    POP(dx.dx);
    POP(cx.cx);
    POP(ax.ax);
}

void XCHG(uint16_t &dest, uint16_t &src){
    uint16_t temp = dest;
    dest = src;
    src = temp;
}

void XLAT(){
    ax.bytes.l = getMem8(ds, bx.bx + ax.bytes.l);
}