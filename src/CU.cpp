#include <iostream>
#include <bitset>
#include "CU.h"

using namespace std;

CU::CU() {

}

CU::CU(RAM* Ram, ALU* Alu) {
    ram = Ram;
    alu = Alu;
}

void CU::resolveArithmetic(m32 instruction)
{
    int s1Reg = instruction.GetDecimal(20, 23);
    int s2Reg = instruction.GetDecimal(16, 19);
    int dReg = instruction.GetDecimal(12, 15);
    int OPCode = getOpCode(instruction);
    switch (OPCode) {
        case OPCODES::ADD:
            operationResult = alu->ADD(s1Reg, s2Reg, dReg);
            break;
        case OPCODES::SUB:
            operationResult = alu->SUB(s1Reg, s2Reg, dReg);
            break;
        case OPCODES::MUL:
            operationResult = alu->MUL(s1Reg, s2Reg, dReg);
            break;
        case OPCODES::DIV:
            operationResult = alu->DIV(s1Reg, s2Reg, dReg);
            break;
        case OPCODES::MOV:
            operationResult = alu->MOV(s1Reg, dReg);
            break;
        case OPCODES::SLT:   //Load content of address into reg
            break;
        case OPCODES::AND:
            operationResult = alu->AND(s1Reg, s2Reg, dReg);
            break;
        case OPCODES::OR:
            operationResult = alu->OR(s1Reg, s2Reg, dReg);
        default:
            cout << "Unrecognized OPCODE" << endl;
    }
}

void CU::resolveConditional(m32 instruction) {
    int bReg = instruction.GetDecimal(20, 23);
    int dReg = instruction.GetDecimal(16, 19);
    int dataDecimal = instruction.GetDecimal(0, 15);
    m32 data(dataDecimal);
    OPCODES Opcode = getOpCode(instruction);
    switch (Opcode) {
        case MOVI:  //Transfers address/data directly into register
            if(dataDecimal == 0) {
                operationResult = alu->MOVI(dReg, bReg);
            }
            else {
                operationResult = alu->MOVI(dReg, dataDecimal);
            }
            break;
        case ADDI:  //Add data value directly with content of register
            operationResult = alu->ADDI(bReg, dataDecimal);
            break;
        case ST:    //Stores content of reg into address
            //setAddress(CpuMem.get_general_purpose_register(bReg), address);
            break;
        case LW:    //Load content of address into reg
            //ALUsetRegister(bReg, dataDecimal);
            break;
        case MULI:  //Multiplies data value directly with content of register
            operationResult = alu->MULI(bReg, dataDecimal);
            break;
        case DIVI:  //Divides data value directly with content of register
            operationResult = alu->DIVI(bReg, dataDecimal);
            break;
        case LDI:
            //ALU.setRegister(bReg, dataDecimal);
            break;
        case SLTI:
            //if(bReg < data)
            //dReg = 1;
            //else
            //dReg = 0;
            break;
        case BEQ:
            operationResult = alu->BEQ(bReg, dReg, dataDecimal);
            break;
        case BNE:
            operationResult = alu->BNE(bReg, dReg, dataDecimal);
            break;
        case BEZ:
            operationResult = alu->BEZ(bReg, dataDecimal);
            break;
        case BNZ:
            operationResult = alu->BNZ(bReg, dataDecimal);
            break;
        case BGZ:
            operationResult = alu->BGZ(bReg, dataDecimal);
            break;
        case BLZ:
            operationResult = alu->BLZ(bReg, dataDecimal);
            break;
        default:
            cout << "Unrecognized OPCODE" << endl;
    }
}

void CU::resolveIO(m32 instruction) {
    int reg1 = instruction.GetDecimal(20, 23);
    int reg2 = instruction.GetDecimal(16, 19);
    int data = instruction.GetDecimal(0, 15);
    OPCODES Opcode = getOpCode(instruction);

    switch (Opcode) {
        case RD:    //Input buffer written to accumulator
            //ALU.setRegister(0, data);
            break;
        case WR:
            //Accumulator written to output buffer
            //outputBuffer = CpuMem.get_general_purpose_register(0);
            break;
        default:
            cout << "Unrecognized OPCODE" << endl;
    }
}

void CU::resolveUnConditional(m32 instruction) {
    int address = instruction.GetDecimal(0, 23);
    OPCODES Opcode = getOpCode(instruction);
    switch (Opcode) {
        case HLT:
            //Program is donezo. Set program's process state to terminated.
            operationResult = alu->HLT();
            break;
        case NOP:
            // Literally do nothing
            break;
        case JMP:
            //jump to address. this isn't in the first 4 programs in AssemblyLanguageCode
            alu->JMP(address);
            break;
        default:
            cout << "Unrecognized OPCODE" << endl;
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
    return static_cast<OPCODES>(instruction.GetDecimal(24, 29));
}

void CU::decode(m32 instruction)
{
    CU::InstructionTypes instructionType = getInstructionType(instruction);
    if (instructionType == CU::InstructionTypes::Arithmetic)
    {
        resolveArithmetic(instruction);
        //cout << "Arithmetic" << endl;
    }
    else if (instructionType == CU::InstructionTypes::Conditional)
    {
        resolveConditional(instruction);
        //cout << "Conditional" << endl;
    }
    else if (instructionType == CU::InstructionTypes::IO)
    {
        //cout << "IO" << endl;
    }
    else if (instructionType == CU::InstructionTypes::Unconditional)
    {
        resolveUnConditional(instruction);
        //cout << "Unconditional Love!! " << endl;
    }
}