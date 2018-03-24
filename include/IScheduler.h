#ifndef ISCHEDULER_H
#define ISCHEDULER_H

#include "PCB.h"

class IScheduler
{
    public:
        virtual int loadNextProcess() = 0;
        virtual void addPCB(PCB* pcb) = 0;
        virtual ~IScheduler();

    protected:

    private:
};

#endif // ISCHEDULER_H
