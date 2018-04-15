#include <iostream>
#include "CPU.h"
#include "m32.h"
#include "Motherboard.h"

using namespace std;

Motherboard m;

void test_cpu() {
    m.getRAM()->setMemory(0, 0x4B060000);
    m.getRAM()->printRam();
    //int retval = m.getRAM()->getMemory(0).ToInt();
    //cout << retval << endl;
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
    test_cpu();
}
