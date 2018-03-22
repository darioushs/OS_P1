#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <assert.h>
#include "RAM.h"

using namespace std;

m32 RAM::getMemory(int index) {
    assert(index < 0 || index > 1023);
    return memory[index];
}

void RAM::setMemory(int index, int value) {
    assert(index < 0 || index > 2047);
    memory[index].SetHex(value);
}
