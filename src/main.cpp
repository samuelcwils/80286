#include "cpu.h"
#include <chrono>

#define instruction1(num, func, op1) \
    case num: \
        func(op1); \
        break; \

#define instruction2(num, func, op1, op2) \
    case num: \
        func(op1, op2); \
        break; \

//add word and byte structs with templates in functions

int main()
{
    mem[7997] = 1;
    mem[7998] = 0;
    mem[7999] = 0;

    init();

    int i = 0;
    while(i != 1000000000)
    {

        opcode = getMem8(cs, ip);
        switch(opcode)
        {
            instruction2(0, MOV, ax.ax, ax.ax)
            instruction1(1, JMP, getMem16(cs, ip))
    
            default:
               break;
        }

        i++;
    }
    return 0;
}