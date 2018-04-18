#ifndef ALU_H
#define ALU_H

#include <iostream>
#include "m32.h"
#include "CpuMem.h"
#include "RAM.h"

class ALU {
public:
    ALU();
    ALU(RAM* Ram, CpuMem* CpuMemory) {
        memory = CpuMemory;
        ram = Ram;
        std::cout << memory << endl;
    }
    // Arhitmetic Instructions
    int ADD(int sReg1, int sReg2, int dReg);
    int SUB(int sReg1, int sReg2, int dReg);
    int MUL(int sReg1, int sReg2, int dReg);
    int DIV(int sReg1, int sReg2, int dReg);
    int MOV(int sReg, int dReg);
    int AND(int sReg1, int sReg2, int dReg);
    int OR (int sReg1, int sReg2, int dReg);

    // Conditional Instructions
    int BEQ(int bReg, int dReg, int jmpTo);
    int BNE(int bReg, int dReg, int jmpTo);
    int BEZ(int bReg, int jmpTo);
    int BNZ(int bReg, int jmpTo);
    int BGZ(int bReg, int jmpTo);
    int BLZ(int bReg, int jmpTo);

    // Immediate & Unconditional Instructions
    int MOVI(int sReg, int data);
    int ADDI(int sReg, int data);
    int MULI(int sReg, int data);
    int DIVI(int sReg, int data);
    int ST(int sReg, int memLocation);
    int LD(int memLocation, int sReg);

    // Conditional jump
    int JMP(int address);
    int HLT();


    void setRegister(int registerNumber, int value);
    CpuMem* getMemory() { return memory; } // For testing

private:
    int numberOfRegisters = 16;
    RAM* ram;
    CpuMem* memory; // Holds all the registers and flags
};



#endif
