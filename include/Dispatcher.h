#ifndef DISPATCHER_H
#define DISPATCHER_H


#include "HDD.h"
#include "RAM.h"
#include "PCB.h"
#include "CPU.h"

class Dispatcher {
private:
    RAM* ram;
    HDD* hdd;
    bool firstRun = true;
    PCB* currentPcbInMemory; // If this is the same as the one we are swapping in then return

public:
    Dispatcher() {};
    Dispatcher(RAM* Ram, HDD* Hdd);
    int swapInProcess(PCB* pcb);
    void setRam(RAM* Ram) { ram = Ram; }
    void setHdd(HDD* Hdd) { hdd = Hdd; }
};


#endif
