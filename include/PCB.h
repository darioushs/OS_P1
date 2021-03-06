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
    int PC; // Program Counter
    int startPositionOnDisk; // Used for loading form disk
    int codeStartPosition; // Starting position of the code segment
    int codeSize = 0;
    int dataSize = 0;
    ProcessStates state;
    int priority;
    int inputBuffer; // The input buffer register for this process
    int outputBufferSize;
    int tempBufferSize;
    struct RegStruct {
        int baseRegister;
        int indexRegister;
        m32 acumulatorRegisters[16]; // State of the resister
    };
    RegStruct registers;
	int startDisk, endDisk, startRam, endRam;
	bool isInRam;

	int getPID() { return Id; }

	int getOutputBufferStart();
	int getTempBufferStart();
	void display();
};

#endif
