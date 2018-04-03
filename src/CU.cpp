#include <iostream>
#include <string>
#include <bitset>
#include "CU.h"
#include "CPU.h"
#include "m32.h"

using namespace std;

void CU::resolveArithmetic(m32 instruction)
{
    int s1Reg = instruction.GetDecimal(20, 23);
    int s2Reg = instruction.GetDecimal(16, 19);
    int dReg = instruction.GetDecimal(12, 15);
    int OPCode = getOpCode(instruction);
    switch (OPCode)
    {
    case OPCODES::ADD:
        operationResult = alu->ADD(s1Reg, dReg);
        break;
    case OPCODES::SUB:
        operationResult = alu->SUB(s1Reg, dReg);
        break;
    case OPCODES::MUL:
        operationResult = alu->MUL(s1Reg, dReg);
        break;
    case OPCODES::DIV:
        operationResult = alu->DIV(s1Reg, dReg);
        break;
    case OPCODES::MOV:
        operationResult = alu->MOV(s1Reg, dReg);
        break;
    }
}

void CU::resolveConditional(m32 instruction)
{
    int bReg = instruction.GetDecimal(20, 23);
    int dReg = instruction.GetDecimal(16, 19);
    cout << "B-Register: " << bReg << endl;
    cout << "D-Register: " << dReg << endl;
    int dataDecimal = instruction.GetDecimal(0, 15);
    cout << "Data is: " << dataDecimal << endl;
    m32 data(dataDecimal);
    OPCODES Opcode = getOpCode(instruction);
    if (dReg == 0)
    {
        cout << "OPCODE: " << Opcode << endl;
        switch (Opcode)
        {
        case MOVI:
            //registers[bReg] = data;
        }
    }
}

CU::InstructionTypes CU::getInstructionType(m32 instruction)
{
    if (instruction.GetBit(31) == 1 && instruction.GetBit(30) == 1)
    {
        return CU::IO;
    }
    if (instruction.GetBit(31) == 1 && instruction.GetBit(30) == 0)
    {
        return CU::Unconditional;
    }
    if (instruction.GetBit(31) == 0 && instruction.GetBit(30) == 1)
    {
        return CU::Conditional;
    }
    if (instruction.GetBit(31) == 0 && instruction.GetBit(30) == 0)
    {
        return CU::Arithmetic;
    }
}

CU::OPCODES CU::getOpCode(m32 instruction)
{
    return static_cast<OPCODES>(instruction.GetDecimal(24, 29) - 1);
}

void CU::decode(m32 instruction)
{
    CU::InstructionTypes instructionType = getInstructionType(instruction);
    if (instructionType == CU::InstructionTypes::Arithmetic)
    {
        resolveArithmetic(instruction);
    }
    else if (instructionType == CU::InstructionTypes::Conditional)
    {
        resolveConditional(instruction);
    }
    else if (instructionType == CU::InstructionTypes::IO)
    {
        cout << "IO" << endl;
    }
    else if (instructionType == CU::InstructionTypes::Unconditional)
    {
        cout << "Unconditional Love!! " << endl;
    }
}

void CU::setProgramCounter(int input) {
    cpuMemory->programCounter = input;
}
