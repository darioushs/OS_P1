#include <iostream>
#include <string>
#include <bitset>
#include "CPU.h"
#include "m32.h"

using namespace std;

void CPU::resolveArithmetic(m32 instruction) {
    int s1Reg   = instruction.GetDecimal(20, 23);
    int s2Reg   = instruction.GetDecimal(16, 19);
    int dReg    = instruction.GetDecimal(12, 15);
    int OPCode  = getOpCode(instruction);
    switch (OPCode) {
    case OPCODES::ADD:
        registers[dReg] = registers[s1Reg] + registers[s2Reg];
        break;
    case OPCODES::SUB:
        registers[dReg] = registers[s1Reg] - registers[s2Reg];
        break;
    case OPCODES::MUL:
        registers[dReg] = registers[s1Reg] * registers[s2Reg];
        break;
    case OPCODES::DIV:
        registers[dReg] = registers[s1Reg] / registers[s2Reg];
        break;
    case OPCODES::MOV:
        //registers[dReg] = registers[sReg];
        break;
    }
}

void CPU::resolveConditional(m32 instruction) {
    int bReg = instruction.GetDecimal(20, 23);
    int dReg = instruction.GetDecimal(16, 19);
    cout << "B-Register: " << bReg << endl;
    cout << "D-Register: " << dReg << endl;
    int dataDecimal = instruction.GetDecimal(0, 15);
    cout << "Data is: " << dataDecimal << endl;
    m32 data(dataDecimal);
    OPCODES Opcode = getOpCode(instruction);
    if (dReg == 0) {
        cout << "OPCODE: " << Opcode << endl;
        switch (Opcode) {
        case MOVI:
            registers[bReg] = data;
        }
    }
}

CPU::InstructionTypes CPU::getInstructionType(m32 instruction) {
    if (instruction.GetBit(31) == 1 && instruction.GetBit(30) == 1) {
        return CPU::IO;
    }
    if (instruction.GetBit(31) == 1 && instruction.GetBit(30) == 0) {
        return CPU::Unconditional;
    }
    if (instruction.GetBit(31) == 0 && instruction.GetBit(30) == 1) {
        return CPU::Conditional;
    }
    if (instruction.GetBit(31) == 0 && instruction.GetBit(30) == 0) {
        return CPU::Arithmetic;
    }
}

CPU::OPCODES CPU::getOpCode(m32 instruction) {
    return static_cast<OPCODES>(instruction.GetDecimal(24, 29) - 1);
}

void CPU::execute(m32 instruction) {
    CPU::InstructionTypes instructionType = getInstructionType(instruction);
    if (instructionType == CPU::InstructionTypes::Arithmetic) {
        resolveArithmetic(instruction);
    } else if (instructionType == CPU::InstructionTypes::Conditional) {
        resolveConditional(instruction);
    } else if (instructionType == CPU::InstructionTypes::IO) {
        cout << "IO" << endl;
    } else if (instructionType == CPU::InstructionTypes::Unconditional) {
        cout << "Unconditional Love!! " << endl;
    }
}

int CPU::getRegisterValue(int registerNumber) {
    return registers[registerNumber].GetDecimal(0, 31);
}

void CPU::displayAllRegisters() {
    for (int i = 0; i < 16; i++) {
        cout << "R" << i << " = " << registers[i].GetDecimal(0,31) << endl;
    }
}

void CPU::setProgramCounter(int location) {
     PC = location;
}

















