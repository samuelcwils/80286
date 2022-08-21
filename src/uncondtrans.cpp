#include "cpu.h"

//unconditional transfers
void JMP(uint16_t addr){
    ip = addr;
}