#include <iostream>
#include "CPU.h"
#include "CpuMem.h"

CPU::CPU(RAM* Ram) {
    ram = Ram;
    cpuMemory = new CpuMem();
    alu = ALU(Ram, cpuMemory);
    cu = CU(Ram, &alu);
}

void CPU::setProgramCounter(int pc) {
    cpuMemory->programCounter = pc;
}

m32 CPU::fetch() {
    //cout << "At program counter " << cpuMemory.programCounter << " fetched instruction = " << ram->getMemory(cpuMemory.programCounter).ToString() << endl;;
    return ram->getMemory(cpuMemory->programCounter);
}

void CPU::cycle() {
    cu.decode(fetch());
    cpuMemory->programCounter++;
    cout << "Program counter at: " << cpuMemory->programCounter << endl;
}

void CPU::configureRegisters(m32* registers) {
    for (int i = 0; i < 16; i++) {
        alu.setRegister(i, registers->GetDecimal(0,15));
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
