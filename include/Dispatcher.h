#ifndef DISPATCHER_H
#define DISPATCHER_H


#include "HDD.h"
#include "RAM.h"
#include "PCB.h"

class Dispatcher {
private:
    RAM* ram;
    HDD* hdd;
    bool firstRun = true;
    PCB* currentPcbInMemory; // If this is the same as the one we are swapping in then return

public:
    void swapInProcess(PCB* pcb);
};


#endif
