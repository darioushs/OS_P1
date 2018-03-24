#ifndef PROCESSPOOL_H
#define PROCESSPOOL_H

#include "PCB.h"


class ProcessPool
{
    public:
        void addProcess(PCB* pcb, int position);
        int getProcessPosition(int PID);

    private:
        struct Segment {
            int startingPosition;
            PCB* pcb;
        };
        vector<Segment> segmentPool; // Holds the position of each PCB
};

#endif // PROCESSPOOL_H
