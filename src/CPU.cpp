#include <iostream>
#include "CPU.h"
#include "CpuMem.h"

CPU::CPU(RAM* Ram) {
    ram = Ram;
    alu = ALU(Ram, &cpuMemory);
    cu = CU(Ram, &alu);
}

m32 CPU::fetch() {
    return ram->getMemory(cpuMemory.programCounter);
}

void CPU::cycle() {
    cu.decode(fetch());
}