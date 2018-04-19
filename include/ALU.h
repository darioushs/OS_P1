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

    // I/O Instructions
    int RD(int tReg1, int tReg2, int tAddr);
    int WR(int tReg1, int tReg2, int tAddr);


    // Arhitmetic Instructions
    int ADD(int sReg1, int sReg2, int dReg);
    int SUB(int sReg1, int sReg2, int dReg);
    int MUL(int sReg1, int sReg2, int dReg);
    int DIV(int sReg1, int sReg2, int dReg);
    int MOV(int sReg1, int sReg2, int dReg);
    int AND(int sReg1, int sReg2, int dReg);
    int OR (int sReg1, int sReg2, int dReg);
    int SLT (int sReg1, int sReg2, int dReg); //todo

    // Immediate & Conditional Instructions
    int MOVI(int dReg, int data);
    int ADDI(int dReg, int data);
    int MULI(int dReg, int data);
    int DIVI(int dReg, int data);
    //todo
    int LDI(int dReg, int data);
    //todo
    // Conditional Instructions
    int BEQ(int bReg, int dReg, int jmpTo);
    int BNE(int bReg, int dReg, int jmpTo);
    int BEZ(int bReg, int jmpTo);
    int BNZ(int bReg, int jmpTo);
    int BGZ(int bReg, int jmpTo);
    int BLZ(int bReg, int jmpTo);
    int SLTI(int bReg, int dReg, int data);

    int ST(int dReg, int memLocation); // ?
    int LW(int memLocation, int sReg); // ?

    // Unconditional jump
    int JMP(int address);
    int HLT();

    // No operation
    int NOP();

    void setRegister(int registerNumber, int value);
    CpuMem* getMemory() { return memory; } // For testing

private:
    int numberOfRegisters = 16;
    RAM* ram;
    CpuMem* memory; // Holds all the registers and flags
};



#endif
