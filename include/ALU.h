#ifndef ALU_H
#define ALU_H

#include "m32.h"
#include "CpuMem.h"
#include "RAM.h"

class ALU {
public:
    ALU();
    ALU(RAM* Ram, CpuMem* CpuMemory) {
        memory = CpuMemory;
        ram = Ram;
    }
    // Arhitmetic Instructions
    int ADD(int sReg, int dReg);
    int SUB(int sReg, int dReg);
    int MUL(int sReg, int dReg);
    int DIV(int sReg, int dReg);
    int MOV(int sReg, int dReg);
    int AND(int sReg1, int sReg2, int dReg);
    int OR (int sReg1, int sReg2, int dReg);

    // Conditional Instructions

    // Immediate & Unconditional Instructions
    int MOVI(int sReg, int dReg);
    int ADDI(int sReg, int value);
    int ST(int sReg, int memLocation);
    int LD(int memLocation, int sReg);

    void setRegister(int registerNumber, int value);

private:
    int numberOfRegisters = 16;
    RAM* ram;
    CpuMem* memory; // Holds all the registers and flags
};



#endif
