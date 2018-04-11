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
}

int ALU::AND(int sReg1, int sReg2, int dReg) {
    int arg1 = memory->get_general_purpose_register(sReg1).ToInt();
    int arg2 = memory->get_general_purpose_register(sReg2).ToInt();
    memory->set_general_purpose_register(dReg, (arg1 & arg2));
}

int ALU::OR(int sReg1, int sReg2, int dReg) {
    int arg1 = memory->get_general_purpose_register(sReg1).ToInt();
    int arg2 = memory->get_general_purpose_register(sReg2).ToInt();
    memory->set_general_purpose_register(dReg, (arg1 | arg2));
}

int ALU::ST(int sReg, int memLocation) {
    ram->setMemory(memLocation, memory->get_general_purpose_register(sReg).ToInt());
}

int ALU::LD(int memLocation, int sReg) {
    memory->set_general_purpose_register(sReg, ram->getMemory(memLocation));
}

void decode(m32 instruction);

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
