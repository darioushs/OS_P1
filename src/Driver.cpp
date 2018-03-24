#include "Driver.h"

Driver::Driver(IScheduler* scheduler) {
    Scheduler = scheduler;
}

void Driver::boot() {
    bool endReached = false;
    int currentPC = -1;
    loader.Load("ProgramFiles", motherboard.getRAM(), motherboard.getHDD(), Scheduler);
    while(!endReached) {
        currentPC = Scheduler->loadNextProcess();
        motherboard.getCPU()->setProgramCounter(currentPC);
        motherboard.getCPU()->cycle();
    }
}
