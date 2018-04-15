#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <assert.h>
#include "RAM.h"

using namespace std;

m32 RAM::getMemory(int index) {
    assert(index < 0 || index > 1023);
    return memory[index / 4]; // divide by 4 because memory addresses go up 4 by 4
}

void RAM::setMemory(int index, int value) {
    assert(index < 0 || index > 2047);
    memory[index / 4].SetHex(value);
}
