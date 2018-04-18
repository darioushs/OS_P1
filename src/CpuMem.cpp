#include "CpuMem.h"
#include "m32.h"

m32 CpuMem::get_general_purpose_register(int regNumber) {
    return registers[regNumber];
}

void CpuMem::set_general_purpose_register(int regNumber, m32 value) {
    registers[regNumber] = value;
}

void CpuMem::set_general_purpose_register(int regNumber, int value) {
    registers[regNumber].SetHex(value);
}
