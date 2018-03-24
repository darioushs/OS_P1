#include "ProcessPool.h"
#include "PCB.h"

void ProcessPool::addProcess(PCB* pcb, int position) {
    Segment s;
    s.pcb = pcb;
    s.startingPosition = position;
    segmentPool.push_back(s);
}

int ProcessPool::getProcessPosition(int PID) {
    for (int i = 0; i <= segmentPool.size(); i++) {
        if (segmentPool[i].pcb->Id == PID) {
            return i;
        }
    }
    return -1;
}
