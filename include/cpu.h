#pragma once 
#include "stdint.h"
#include "stdbool.h"
#include "types.h"

extern uint8_t mem[8000];

typedef union{
    struct{
        uint8_t l;
        uint8_t h;
    }bytes;
    uint16_t ax;
}ax_t;

extern ax_t ax;

typedef union{
    struct{
        uint8_t l;
        uint8_t h;
    }bytes;
    uint16_t dx;
}dx_t;

extern dx_t dx;

typedef union{
    struct{
        uint8_t l;
        uint8_t h;
    }bytes;
    uint16_t cx;
}cx_t; //loop / shift repeat counter

extern cx_t cx;


typedef union{
    struct{
        uint8_t l;
        uint8_t h;
    }bytes;
    uint16_t bx;
}bx_t;

extern bx_t bx;
extern uint16_t bp; //base registers

extern uint16_t si;
extern uint16_t di;//index registers

extern uint16_t sp;

extern uint16_t cs;//code  segment selector
extern uint16_t ds;//data  segment selector
extern uint16_t ss;//stack segment selector
extern uint16_t es;//extra segment selector

extern uint16_t ip; //instruction pointer
extern int bytes;

typedef struct{
    bool cf;
    bool pf;
    bool af;
    bool zf;
    bool sf;
    bool of;
    bool tf;
    bool iff;
    bool df;
}msw_t;

extern msw_t msw;

extern bool* parity_table;
extern unsigned int temp;
extern uint8_t opcode;

void init(void);

uint8_t getMem8(uint16_t seg, uint16_t off);
uint16_t getMem16(uint16_t seg, uint16_t off);

void putMem8(uint16_t seg, uint16_t off, uint8_t val);
void putMem16(uint16_t seg, uint16_t off, uint16_t val);
void putMem8(byte b);
void putMem16(word w);

//flags
void cf8(unsigned int a);
void cf16(unsigned int a);
void pf8(uint8_t a);
void pf16(uint16_t a);
void af8(unsigned int a, uint8_t b, uint8_t c);
void af16(unsigned int a, uint16_t b, uint16_t c);
void zf8(uint8_t a);
void zf16(uint16_t a);
void sf8(uint8_t a);
void sf16(uint16_t a);
void of8(uint8_t a, uint8_t b);
void of16(uint16_t a, uint16_t b);
void tf(bool set);
void iff(bool set);
void df(bool set);

//add
void ADD(uint8_t &dest, uint8_t &src);
void ADD(uint16_t &dest, uint16_t &src);
void ADC(uint8_t &dest, uint8_t src);
void ADC(uint16_t &dest, uint16_t src);
void INC(uint8_t &dest);
void INC(uint16_t &dest);
void AAA();
void DAA();

//sub
void SUB(uint8_t &dest, uint8_t &src);
void SUB(uint16_t &dest, uint16_t &src);
void SBB(uint8_t &dest, uint8_t src);
void SBB(uint16_t &dest, uint16_t src);
void DEC(uint8_t &dest);
void DEC(uint16_t &dest);
void AAS();

//general purpose
void MOV(uint8_t &dest, uint8_t &src);
void MOV(uint16_t &dest, uint16_t &src);

//unconditional transfers
void JMP(uint16_t addr);

