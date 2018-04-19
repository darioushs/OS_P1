#include "Driver.h"

Driver::Driver(PriorityScheduler* scheduler, Motherboard* mb) {
    Scheduler = scheduler;
    motherboard = mb;
}

void Driver::bootFromFile(string filename) {
    bool endReached = false;
    int currentPC = -1;
    loader.Load(filename, motherboard->getHDD(), Scheduler);
    Scheduler->printAllPcbs();
    try{
        while(endReached == false) {
            cout << "hi" << endl;
            currentPC = Scheduler->loadNextProcess();
            motherboard->getCPU()->setProgramCounter(currentPC);
            motherboard->getCPU()->cycle();
            cout << "Driver Loop" << endl;
        }
    } catch(exception ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}
