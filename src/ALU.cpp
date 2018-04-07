#include <iostream>
#include "ALU.h"
#include "m32.h"

ALU::ALU() {

}

ALU::ALU(RAM* Ram, CpuMem* CpuMemory) {
    ram = Ram;
    memory = CpuMemory;
}

int ALU::ADD(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) + memory->get_general_purpose_register(dReg));
    return 1;
}

int ALU::SUB(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) - memory->get_general_purpose_register(dReg));
    return 1;
}

int ALU::MUL(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) * memory->get_general_purpose_register(dReg));
    return 1;
}

int ALU::DIV(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) / memory->get_general_purpose_register(dReg));
    return 1;
}

int ALU::MOV(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg));
    return 1;
}void decode(m32 instruction);

void ALU::setRegister(int registerNumber, int value) {
    memory->set_general_purpose_register(registerNumber, value);
}

void ALU::displayAllRegisters()
{
    for (int i = 0; i < 16; i++)
    {
        cout << "R" << i << " = " << memory->get_general_purpose_register(i).GetDecimal(0, 31) << endl;
    }
}
