#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "m32.h"
#include "RAM.h"

class CPU {

private:
    enum InstructionTypes {
        Arithmetic,
        Conditional,
        Unconditional,
        IO
    };
    enum OPCODES {
        RD,
        WR,
        ST,
        LW,
        MOV,
        ADD,
        SUB,
        MUL,
        DIV,
        AND,
        OR,
        MOVI,
        ADDI,
        MULI,
        DIVI,
        LDI,
        SLT,
        SLTI,
        HLT,
        NOP,
        JMP,
        BEQ,
        BNE,
        BEZ,
        BNZ,
        BGZ,
        BLZ
    };
	m32 registers[16];
	int PC; // The main program counter
    RAM* ram;
	OPCODES getOpCode(m32 InstructionTypes);
	InstructionTypes getInstructionType(m32 instruction);
	void resolveArithmetic(m32 instruction);
	void resolveConditional(m32 instruction);
	void resolveUnConditional(m32 instruction);
	void resolveIO(m32 instruction);
	void execute(m32 instruction);

public:
    void cycle();
    int getRegisterValue(int registerNumber); // Retrieves the value stored in a register for testing purpose
    void displayAllRegisters();
    void setProgramCounter(int location);
    void setRam(RAM* Ram) { ram = Ram; }
};


#endif
