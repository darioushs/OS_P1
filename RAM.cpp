#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "RAM.h"

using namespace std;

m32 RAM::getMemory(int index) {
    if (index < 0 || index > 1023) {
        cout << "Error! Trying to access invalid memory address" << endl;
        return;
    }
    return memory[index];
}

void RAM::setMemory(int index, int value) {
    if (index < 0 || index > 2047) {
        cout << "Error! Trying to access invalid memory address" << endl;
        return;
    }
    memory[index].SetHex(value);
}
