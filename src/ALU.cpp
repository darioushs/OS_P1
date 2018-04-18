#include <iostream>
#include "ALU.h"
#include "m32.h"

ALU::ALU() {

}


int ALU::ADD(int sReg1, int sReg2, int dReg) {
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 + value2);
    return 1;
}

int ALU::SUB(int sReg1, int sReg2, int dReg) {
    cout << "YPPOOKOIPO{AISPD";
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 - value2);
    return 1;
}

int ALU::MUL(int sReg1, int sReg2, int dReg) {
    //memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) * memory->get_general_purpose_register(dReg));
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 * value2);
    return 1;
}

int ALU::DIV(int sReg1, int sReg2, int dReg) {
    //memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg) / memory->get_general_purpose_register(dReg));
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 / value2);
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

int ALU::ADDI(int sReg, int value) {
    memory->set_general_purpose_register(sReg, m32(value));
    return 1;
}

int ALU::MOVI(int sReg, int dReg) {
    memory->set_general_purpose_register(dReg, memory->get_general_purpose_register(sReg));
    return 1;
}

int ALU::ST(int sReg, int memLocation) {
    ram->setMemory(memLocation, memory->get_general_purpose_register(sReg).ToInt());
}

int ALU::LD(int memLocation, int sReg) {
    memory->set_general_purpose_register(sReg, ram->getMemory(memLocation));
}

//void decode(m32 instruction); idk who added this so im commenting it out for now

void ALU::setRegister(int registerNumber, int value) {
    memory->set_general_purpose_register(registerNumber, value);
}
