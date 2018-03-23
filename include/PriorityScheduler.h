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
    void loadNextProcess();
};


#endif
