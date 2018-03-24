#ifndef PIORITYSCHEDULER_H
#define PIORITYSCHEDULER_H

#include "IScheduler.h"
#include "PCB.h"


class PriorityScheduler : public IScheduler {
private:
    vector<PCB*> readyQueue;
    int getHighestPriorityProcessIndex();

public:
    void addPcb(PCB* pcb);
    int loadNextProcess(); // Return a program counter to tell CPU where to start executing code from
};


#endif
