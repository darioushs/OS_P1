#ifndef ISCHEDULER_H
#define ISCHEDULER_H

#include "PCB.h"

class IScheduler
{
    public:
        IScheduler();
        virtual int loadNextProcess() = 0;
        virtual void addPCB(PCB* pcb) = 0;
        virtual void signalProcessEnd() = 0;
        virtual ~IScheduler();

    protected:

    private:
};

#endif // ISCHEDULER_H
