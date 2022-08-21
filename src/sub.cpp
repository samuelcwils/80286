#include "cpu.h"

//arithmetic
void SUB(uint8_t &dest, uint8_t &src){
    temp = dest - src;
    cf8(temp);
    pf8(temp);
    af8(dest, src, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, src);
    dest = temp;
}

void SUB(uint16_t &dest, uint16_t &src){
    temp = dest - src;
    cf16(dest);
    pf16(dest);
    af16(dest, src, temp);
    zf16(dest);
    sf16(dest);
    of16(dest, src);
    dest = temp;
}

void SBB(uint8_t &dest, uint8_t src){
    src = src - msw.cf;
    temp = dest - src;
    cf8(temp);
    pf8(temp);
    af8(dest, src, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, src);
    dest = temp;
}

void SBB(uint16_t &dest, uint16_t src){
    src = src - msw.cf;
    temp = dest - src;
    cf16(temp);
    pf16(temp);
    af16(dest, src, temp);
    zf16(temp);
    sf16(temp);
    of16(dest, src);
    dest = temp;
}

void DEC(uint8_t &dest){
    temp = dest - 1;
    cf8(temp);
    pf8(temp);
    af8(dest, -1, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, -1);
    dest = temp;
}

void DEC(uint16_t &dest){
    temp = dest - 1;
    cf16(temp);
    pf16(temp);
    af16(dest, -1, temp);
    zf16(temp);
    sf16(temp);
    of16(dest, -1);
    dest = temp;
}

void NEG(uint8_t &dest){
    temp = 0 - dest;
    msw.cf = dest;
    pf8(temp);
    af8(0, dest, temp);
    zf8(temp);
    sf8(temp);
    of8(0, dest);
    dest = temp;
}

void NEG(uint16_t &dest){
    temp = 0 - dest;
    msw.cf = dest;
    pf16(temp);
    af16(0, dest, temp);
    zf16(temp);
    sf16(temp);
    of16(0, dest);
    dest = temp;
}

void CMP(uint8_t &dest, uint8_t &src){
    temp = dest - src;
    cf8(temp);
    pf8(temp);
    af8(dest, src, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, src);
}

void CMP(uint16_t &dest, uint16_t &src){
    temp = dest - src;
    cf16(temp);
    pf16(temp);
    af16(dest, src, temp);
    zf16(temp);
    sf16(temp);
    of16(dest, src);
}

void AAS(){
    if(msw.af || (ax.bytes.l & 0x0f > 9)){
        msw.af = 1;
        msw.cf = 1;
        (ax.bytes.l -= 6) &= 0x0f;
        ax.bytes.h -= 1;
    } else {
        msw.af = 0;
        msw.cf = 0;
        ax.bytes.l = ax.bytes.l & 0x0f;
    }
}

void DAS(){
    bool oldcf = msw.cf;
    uint16_t oldAL = ax.bytes.l;

    if((ax.bytes.l & 0x0f) > 9 || msw.af){
        msw.cf = oldcf || ((unsigned int) ax.bytes.l - 6) > 0xff;
        msw.af = 1;
    } else {
        msw.af = 0;
    } 
    
    if(oldcf || (oldAL > 0x99)){
        msw.cf = 1;
        ax.bytes.l -= 0x60;
    } else {
        msw.cf = 0;
    }
}