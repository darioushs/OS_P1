#include "Driver.h"

Driver::Driver(PriorityScheduler* scheduler, Motherboard* mb) {
    Scheduler = scheduler;
    motherboard = mb;
}

void Driver::bootFromFile(string filename) {
    bool endReached = false;
    int currentPC = -1;
    loader.Load(filename, motherboard->getHDD(), Scheduler);
    motherboard->getHDD()->printHDD();
    while(!endReached) {
        currentPC = Scheduler->loadNextProcess();
        motherboard->getCPU()->setProgramCounter(currentPC);
        motherboard->getCPU()->cycle();
    }
}
