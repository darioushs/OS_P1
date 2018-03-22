#ifndef ISCHEDULER_H
#define ISCHEDULER_H

#include "PCB.h"

class IScheduler
{
    public:
        virtual void loadNextProcess() = 0;
        virtual void addPCB(PCB* pcb);
        virtual ~IScheduler();

    protected:

    private:
};

#endif // ISCHEDULER_H
