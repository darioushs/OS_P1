#include <iostream>
#include "CPU.h"
#include "Motherboard.h"


using namespace std;

Motherboard m;

void printCpuMemory() {
    cout << "------------------------------------------------" << endl;
    m.getCPU()->displayAllRegisters();
}

void printRam() {
    m.getRAM()->printRam();
}

void test_cpu() {
    m.getCPU()->setProgramCounter(4);
    //m.getRAM()->setMemory(0, 0x4B060000);
    m.getRAM()->setMemory(4, 0x4B340000);
    cout << m.getRAM()->getMemory(4).ToString() << endl;
    //m.getRAM()->setMemory(8, 0x4B250000);
    m.getCPU()->cycle();
    //m.getCPU()->cycle();
    //m.getCPU()->cycle();
    m.getCPU()->displayAllRegisters();
    //m.getRAM()->printRam();
}

void test_cpu_memory() {
    m.getCPU()->getCpuMem()->set_general_purpose_register(2, m32(5));
    cout << "ALU Register 2 is = " << m.getCPU()->getAlu()->getMemory()->get_general_purpose_register(2).ToInt() << endl;
    cout << "CPU register 2 is = " << m.getCPU()->getCpuMem()->get_general_purpose_register(2).ToInt() << endl;
    m.getCPU()->getCpuMem()->set_general_purpose_register(3, m32(7));
    m.getRAM()->setMemory(0, 0x5234000);
    cout << m.getCPU()->getCpuMem() << endl;
    m.getCPU()->cycle();
    cout << "Register 4 is = " <<  m.getCPU()->getCpuMem()->get_general_purpose_register(4).ToInt() << endl;
}

void test_alu_subtract() {
    m.getCPU()->getCpuMem()->set_general_purpose_register(2, m32(5));
    m.getCPU()->getCpuMem()->set_general_purpose_register(3, m32(3));
    m.getRAM()->setMemory(0, 0x6234000);
    m.getCPU()->cycle();
    cout << "Register 4 = " << m.getCPU()->getCpuMem()->get_general_purpose_register(4).ToInt() << endl;
    m.getCPU()->displayAllRegisters();
}

void test_alu_MOVI() {
    m.getRAM()->setMemory(0, 0x4B0A0004);
    m.getCPU()->cycle();
    cout << "Register 7 is = " << m.getCPU()->getCpuMem()->get_general_purpose_register(7).ToInt() << endl;
    printCpuMemory();
}

void test_alu_ADDI() {
    m.getRAM()->setMemory(0, 0x4C070004);
    m.getCPU()->cycle();
    printCpuMemory();
}

void test_alu_MULI() {
m.getRAM()->setMemory(4, 0x4D070006);
    m.getCPU()->cycle();
    printCpuMemory();
}

void test_alu_DIVI() {
    m.getRAM()->setMemory(4, 0x4e700002);
    m.getCPU()->cycle();
    printCpuMemory();
}

int main() {
    //m32 i;
    //CPU cpu;
    //i.SetHex(0x4CC00006);
    //cpu.execute(i);
    //cpu.displayAllRegisters();
    //cout << "Register is set to: " << cpu.getRegisterValue(6) << endl;
    /*i.SetHex(0xc050005c);
    cpu.execute(i);
    m32 m1 = m32();
    m1.SetHex(15);
    m32 m2 = m32();
    m2.SetHex(5);
    m32 m3 = m1/m2;
    cout << "Result: " << m3.GetDecimal(0,31) << endl;*/
    //test_cpu();
    //test_cpu_memory();
    //test_alu_subtract();
    //test_alu_MOVI();
    test_alu_ADDI();
    //test_alu_MULI();
    //test_alu_DIVI();
}
