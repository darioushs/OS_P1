#include <iostream>
#include <cassert>
#include "RAM.h"

using namespace std;

m32 RAM::getMemory(int index) {
    assert(index >= 0 || index <= 1023);
    return memory[index / 4]; // divide by 4 because memory addresses go up 4 by 4
}

void RAM::setMemory(int index, int value) {
    assert(index >= 0 || index <= 1023);
    memory[index / 4].SetHex(value);
}

void RAM::printRam() {
    for (int i = 0; i < 1024; i++) {
        cout << i * 4 << "-----" << memory[i].ToString() << endl;
    }
}
