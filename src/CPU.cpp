#include <iostream>
#include "CPU.h"
#include "CpuMem.h"

CPU::CPU(RAM* Ram) {
    ram = Ram;
    alu = ALU(Ram, &cpuMemory);
    cu = CU(Ram, &alu);
}

void CPU::setProgramCounter(int pc) {
    cpuMemory.programCounter = pc;
}

m32 CPU::fetch() {
    return ram->getMemory(cpuMemory.programCounter);
}

void CPU::cycle() {
    cu.decode(fetch());
    cpuMemory.programCounter++;
}

void CPU::configureRegisters(m32* registers) {
    for (int i = 0; i < 16; i++) {
        alu.setRegister(i, registers->GetDecimal(0,15));
        registers++;
    }
}
