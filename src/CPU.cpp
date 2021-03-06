#include <iostream>
#include "CPU.h"

CPU::CPU(RAM* Ram) {
    ram = Ram;
    cpuMemory = new CpuMem();
    alu = new ALU(Ram, cpuMemory);
    cu = CU(Ram, alu);
}

void CPU::setProgramCounter(int pc) {
    cpuMemory->programCounter = pc;
}

m32 CPU::fetch() {
    return ram->getMemory(cpuMemory->programCounter);
}

void CPU::cycle() {
    cu.decode(fetch());
    cpuMemory->programCounter += 4;
}

void CPU::configureRegisters(m32* registers) {
    for (int i = 0; i < 16; i++) {
        alu->setRegister(i, registers->GetDecimal(0,15));
        registers++;
    }
}

void CPU::displayAllRegisters()
{
    for (int i = 0; i < 16; i++)
    {
        cout << "R" << i << " = " << cpuMemory->get_general_purpose_register(i).GetDecimal(0, 31) << endl;
    }
}

CpuMem* CPU::getCpuMem() {
    return cpuMemory;
}
