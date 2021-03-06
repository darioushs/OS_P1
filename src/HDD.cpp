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

int HDD::getProcessStartLocationOnDisk(int PID) {
    return processPool.getProcessPosition(PID);
}

void HDD::addProcessToPool(PCB* pcb, int position) {
    processPool.addProcess(pcb, position);
}

void HDD::printHDD() {
    for (int i = 0; i < 2047; i++) {
        cout << i << "----" << memory[i].ToString() << endl;
    }
}
