#include <iostream>
#include "CPU.h"
#include "m32.h"
#include "Motherboard.h"


using namespace std;

Motherboard m;

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
    m.getRAM()->setMemory(0, 52340000);
    m.getCPU()->cycle();
    cout << "Register 4 is = " <<  m.getCPU()->getCpuMem()->get_general_purpose_register(4).ToInt() << endl;
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
    test_cpu_memory();
}
