<<<<<<< HEAD
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
=======
#include "IScheduler.h"
#include <vector>

class PriorityScheduler : public IScheduler
{
    public:
        void LoadNextProcess();
        void addPCB(PCB* pcb);
        vector<PCB*> processTable;

    protected:

    private:
};

#endif
>>>>>>> 7218e800a6879b4063e549697cb835c5f71c7b5a
