#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "HDD.h"

using namespace std;

m32 HDD::getMemory(int index) {
    if (index < 0 || index > 2047) {
        cout << "Error! Trying to access invalid memory address" << endl;
        return m32();
    }
    return memory[index];
}

void HDD::setMemory(int index, int value) {
    if (index < 0 || index > 2047) {
        cout << "Error! Trying to access invalid memory address" << endl;
        return;
    }
    memory[index] = value;
}
