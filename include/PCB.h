#include <string>
#include <vector>
#include <iostream>
#include "m32.h"

#ifndef PCB_H
#define PCB_H

using namespace std;

class PCB
{
private:


public:

    enum ProcessStates {
        Ready,
        Running,
        Blocked,
        New
    };

    int Id; // Process ID
    int PC; // Program Counter.
    int programStartPointer; // The memory location where the program starts in the ram
    int CodeSize;
    int dataStartPointer; // The memory location where the data segment begins
    int dataSize;
    m32 RegisterStates[16]; // State of the resister
    ProcessStates State;
    int priority;
    int inputBuffer; // The input buffer register for this process
    int outputBufferSize;
    int tempBufferSize;

	int startDisk, endDisk, startRam, endRam;
	bool isInRam;

	int getPID() { return Id; }
};

#endif
