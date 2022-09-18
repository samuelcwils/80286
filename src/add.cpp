#include "cpu.h"

template <typename T, typename D>
void ADD(T &dest, D &src){
    temp = dest + src;
    cf8(temp);
    pf8(temp);
    af8(dest, src, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, src);
    dest = temp;
}

template <typename T, typename D>
void ADD(uint16_t &dest, uint16_t &src){
    temp = dest + src;
    cf16(dest);
    pf16(dest);
    af16(dest, src, temp);
    zf16(dest);
    sf16(dest);
    of16(dest, src);
    dest = temp;
}

template <typename T, typename D>
void ADC(uint8_t &dest, uint8_t src){
    src = src + msw.cf;
    temp = dest + src;
    cf8(temp);
    pf8(temp);
    af8(dest, src, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, src);
    dest = temp;
}

template <typename T, typename D>
void ADC(uint16_t &dest, uint16_t src){
    src = src + msw.cf;
    temp = dest + src;
    cf16(temp);
    pf16(temp);
    af16(dest, src, temp);
    zf16(temp);
    sf16(temp);
    of16(dest, src);
    dest = temp;
}

template <typename T, typename D>
void INC(uint8_t &dest){
    temp = dest + 1;
    cf8(temp);
    pf8(temp);
    af8(dest, 1, temp);
    zf8(temp);
    sf8(temp);
    of8(dest, 1);
    dest = temp;
}

template <typename T, typename D>
void INC(uint16_t &dest){
    temp = dest + 1;
    cf16(temp);
    pf16(temp);
    af16(dest, 1, temp);
    zf16(temp);
    sf16(temp);
    of16(dest, 1);
    dest = temp;
}

void AAA(){
    if(msw.af || (ax.bytes.l & 0x0f > 9)){
        msw.af = 1;
        msw.cf = 1;
        (ax.bytes.l += 6) &= 0x0f;
        ax.bytes.h += 1;
    } else {
        msw.af = 0;
        msw.cf = 0;
        ax.bytes.l = ax.bytes.l & 0x0f;
    }
}

void DAA(){
    bool oldcf = msw.cf;
    uint16_t oldAL = ax.bytes.l;

    if((ax.bytes.l & 0x0f) > 9 || msw.af){
        msw.cf = oldcf || ((unsigned int) ax.bytes.l + 6) > 0xff;
        msw.af = 1;
    } else {
        msw.af = 0;
    } 
    
    if(oldcf || (oldAL > 0x99)){
        msw.cf = 1;
        ax.bytes.l += 0x60;
    } else {
        msw.cf = 0;
    }
}
