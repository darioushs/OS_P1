#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "m32.h"
#include "RAM.h"
#include "ALU.h"
#include "CU.h"

class CPU {
private:
    ALU alu;
    CU cu;
    RAM* ram;
    CpuMem cpuMemory;

public:
    CPU() {};
    CPU(RAM* Ram);
    void cycle();
    m32 fetch();
    void setProgramCounter(int pc);
    void configureRegisters(m32* registers);
    void displayAllRegisters();
};


#endif
