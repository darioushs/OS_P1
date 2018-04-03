#ifndef CPUMEM_H
#define CPUMEM_H

#include "m32.h"

class CpuMem {
public:
    m32 baseRegister;
    m32 I_Register;
    int programCounter;
    m32 get_general_purpose_register(int regNumber);
    void set_general_purpose_register(int regNumber, m32 value);

private:
    m32 registers[16];
    
};


#endif
