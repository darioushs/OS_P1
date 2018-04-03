#ifndef CU_H
#define CU_H


#include <stdint.h>
#include "m32.h"
#include "RAM.h"
#include "ALU.h"

class CU {

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
	int PC; // The main program counter
    int operationResult;
    RAM* ram;
    ALU* alu;
    CpuMem* cpuMemory;
	OPCODES getOpCode(m32 InstructionTypes);
	InstructionTypes getInstructionType(m32 instruction);
	void resolveArithmetic(m32 instruction);
	void resolveConditional(m32 instruction);
	void resolveUnConditional(m32 instruction);
	void resolveIO(m32 instruction);

public:
    CU();
    CU(RAM* ram, ALU* alu);
	void decode(m32 instruction);
    int getRegisterValue(int registerNumber); // Retrieves the value stored in a register for testing purpose
    void setProgramCounter(int location);
    void setRam(RAM* Ram) { ram = Ram; }
};

#endif // ALU_H
