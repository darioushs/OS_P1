#include <iostream>
#include "ALU.h"
#include "m32.h"


ALU::ALU(RAM* Ram, CpuMem* CpuMemory) {
    ram = Ram;
    memory = CpuMemory;
}

int ALU::ADD(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) + memory->get_general_purpose_register(dReg));
    return true;
}

int ALU::SUB(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) - memory->get_general_purpose_register(dReg));
    return true;
}

int ALU::MUL(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) * memory->get_general_purpose_register(dReg));
}

int ALU::DIV(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) / memory->get_general_purpose_register(dReg));
}

int ALU::MOV(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg));
}

void ALU::displayAllRegisters()
{
    for (int i = 0; i < 16; i++)
    {
        cout << "R" << i << " = " << memory->get_general_purpose_register(i).GetDecimal(0, 31) << endl;
    }
}