#ifndef ALU_H
#define ALU_H

#include "m32.h"
#include "CpuMem.h"
#include "RAM.h"

class ALU {
public:
    ALU();
    ALU(RAM* Ram, CpuMem* CpuMemory);
    // Arhitmetic Instructions
    int ADD(int sReg, int dReg);
    int SUB(int sReg, int dReg);
    int MUL(int sReg, int dReg);
    int DIV(int sReg, int dReg);
    int MOV(int sReg, int dReg);

    // Conditional Instructions


    void displayAllRegisters();


private:
    int numberOfRegisters = 16;
    RAM* ram;
    CpuMem* memory; // Holds all the registers and flags
};



#endif