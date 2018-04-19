#ifndef PIORITYSCHEDULER_H
#define PIORITYSCHEDULER_H

#include "IScheduler.h"
#include "PCB.h"
#include "Dispatcher.h"


class PriorityScheduler {
private:
    vector<PCB*> readyQueue;
    CPU* cpu;
    int getHighestPriorityProcessIndex();
    Dispatcher dispatcher;

public:
    PriorityScheduler();
    PriorityScheduler(RAM* ram, HDD* hdd, CPU* cpu);
    void addPcb(PCB* pcb);
    int loadNextProcess(); // Return a program counter to tell CPU where to start executing code from
    void signalProcessEnd();
    void printAllPcbs();
    int getNumberOfPcbs();
};


#endif
