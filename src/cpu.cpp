#include "cpu.h"

uint8_t mem[8000] = {0};

ax_t ax = {.ax = 0};
bx_t bx = {.bx = 0};
cx_t cx = {.cx = 0};
dx_t dx = {.dx = 0};

uint16_t bp = 0; //base registers

uint16_t si = 0;
uint16_t di = 0;//index registers

uint16_t sp = 0;

uint16_t cs = 0;//code  segment selector
uint16_t ds = 0;//data  segment selector
uint16_t ss = 0;//stack segment selector
uint16_t es = 0;//extra segment selector

msw_t msw = {.cf = false, .pf = false, .af = false, .zf = false, .sf = false, .of = false, .tf = false, .iff = false, .df = false};
uint16_t ip = 0; //instruction pointer

int bytes = 0;
unsigned int temp = 0;
uint8_t opcode = 0;
bool* parity_table = new bool[256];

uint8_t getMem8(uint16_t seg, uint16_t off){
    return mem[seg * 16 + off];
}

uint16_t getMem16(uint16_t seg, uint16_t off){
    return (getMem8(seg, off) << 8) | getMem8(seg, off + 1);
}

void putMem8(uint16_t seg, uint16_t off, uint8_t val){
    mem[seg * 16 + off] = val;
}

void putMem16(uint16_t seg, uint16_t off, uint16_t val){
    putMem8(seg, off, val >> 8);
    putMem8(seg, off + 1, val & 0xff);
}

void putMem8(byte b){
    mem[b.seg * 16 + b.off] = b.val;
}

void putMem16(word w){
    mem[w.seg * 16 + w.off] = w.val;
}

uint8_t* getRM(){
    uint8_t temp = getMem8(cs, ip);
    switch (temp)
    {
    case 0x00:
        return getMem8(bx.bx, si);
        break;
    
    default:
        break;
    }

}

void init()
{
    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            int numOnes = 0;
            int mask = 1 << j;
            if(i & mask)
            {
                numOnes++;
            }
            parity_table[i] = numOnes % 2 == 0;
        }
    }
}
