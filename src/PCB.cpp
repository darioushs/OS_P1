#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "PCB.h"

using namespace std;

int PCB::getOutputBufferStart() {
    return codeSize + dataSize + 1;
}

int PCB::getTempBufferStart() {
    return getOutputBufferStart() + outputBufferSize + 1;
}

void PCB::display() {
    cout << "ID: " << Id << endl;
    cout << "Code Size: " << codeSize << endl;
    cout << "Data Size: " << dataSize << endl;
    cout << "Input buffer: " << inputBuffer << endl;
    cout << "Output buffer size: " << outputBufferSize << endl;
    cout << "Temp buffer size: " << tempBufferSize << endl;
    cout << "Output buffer start: " << getOutputBufferStart() << endl;
    cout << "Temp buffer start: " << getTempBufferStart() << endl;
    cout << "Priority: " << priority << endl;
}
