#ifndef FCFS_SCHEDULER_H
#define FCFS_SCHEDULER_H

#include "IScheduler.h"


class FCFS_Scheduler : public IScheduler
{
    public:
        void LoadNextProcess();
        void addPCB(PCB* pcb);

    protected:

    private:
};

#endif // FCFS_SCHEDULER_H
