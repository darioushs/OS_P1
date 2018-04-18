#include <iostream>
#include "ALU.h"
#include "m32.h"

ALU::ALU() {

}

int ALU::RD(int tReg1, int tReg2, int tAddr) {

}

int ALU::WR(int tReg1, int tReg2, int tAddr) {

}


int ALU::ADD(int sReg1, int sReg2, int dReg) {
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 + value2);
    return 1;
}

int ALU::SUB(int sReg1, int sReg2, int dReg) {
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 - value2);
    return 1;
}

int ALU::MUL(int sReg1, int sReg2, int dReg) {
    m32 value1 = memory->get_general_purpose_register(sReg1);
    m32 value2 = memory->get_general_purpose_register(sReg2);
    memory->set_general_purpose_register(dReg, value1 * value2);
    return 1;
}

int ALU::DIV(int sReg1, int sReg2, int dReg) {
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

int ALU::ADDI(int dReg, int data) {
    int currentValue = memory->get_general_purpose_register(dReg).ToInt();
    memory->set_general_purpose_register(dReg, currentValue + data);
    return 1;
}

int ALU::MULI(int dReg, int data) {
    int currentValue = memory->get_general_purpose_register(dReg).ToInt();
    memory->set_general_purpose_register(dReg, currentValue * data);
    return 1;
}

int ALU::MOVI(int dReg, int data) {
    memory->set_general_purpose_register(dReg, data);
    return 1;
}

int ALU::DIVI(int dReg, int data) {
    int currentValue = memory->get_general_purpose_register(dReg).ToInt();
    memory->set_general_purpose_register(dReg, currentValue / data);
    return 0;
}

int ALU::LDI(int dReg, int data) {
    memory->set_general_purpose_register(dReg, ram->getMemory(data));
}

int ALU::SLTI(int bReg,int dReg, int data) {
    if (bReg < data)
    {
        memory->set_general_purpose_register(dReg, 1);

    }
    else {
        memory->set_general_purpose_register(dReg, 0);
    }
}

int ALU::ST(int sReg, int memLocation) {
    ram->setMemory(memLocation, memory->get_general_purpose_register(sReg).ToInt());
}

int ALU::LW(int memLocation, int sReg) {
    memory->set_general_purpose_register(sReg, ram->getMemory(memLocation));
}

//void decode(m32 instruction); idk who added this so im commenting it out for now

void ALU::setRegister(int registerNumber, int value) {
    memory->set_general_purpose_register(registerNumber, value);
}

// **Conditional Jump Instructions**

int ALU::BEQ(int bReg, int dReg, int jmpTo) {
    if (memory->get_general_purpose_register(bReg).ToInt() == memory->get_general_purpose_register(dReg).ToInt()) {
        memory->programCounter = jmpTo;
    }
    return 1;
}

int ALU::BLZ(int bReg, int jmpTo) {
    if (memory->get_general_purpose_register(bReg).ToInt() < 0) {
        memory->programCounter = jmpTo;
    }
    return 1;
}

int ALU::BGZ(int bReg, int jmpTo) {
    if (memory->get_general_purpose_register(bReg).ToInt() > 0) {
        memory->programCounter = jmpTo;
    }
    return 1;
}

int ALU::BNZ(int bReg, int jmpTo) {
    if (memory->get_general_purpose_register(bReg).ToInt() != 0) {
        memory->programCounter = jmpTo;
    }
    return 1;
}

int ALU::BEZ(int bReg, int jmpTo) {
    if (memory->get_general_purpose_register(bReg).ToInt() == 0) {
        memory->programCounter = jmpTo;
    }
    return 1;
}

int ALU::BNE(int bReg, int dReg, int jmpTo) {
    if (memory->get_general_purpose_register(bReg).ToInt() != memory->get_general_purpose_register(dReg).ToInt()) {
        memory->programCounter = jmpTo;
    }
}

// **Unconditional Jump**

int ALU::JMP(int address) {
    memory->programCounter = address;
    return 1;
}

int ALU::HLT() {
    return 0;
}






