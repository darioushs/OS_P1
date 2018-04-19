#ifndef DRIVER_H
#define DRIVER_H

#include "Motherboard.h"
#include "PriorityScheduler.h"
#include "Loader.h"

class Driver
{
private:
    Motherboard* motherboard;
    Loader loader;
    PriorityScheduler* Scheduler;


public:
    Driver(PriorityScheduler* Scheduler, Motherboard* mb);
    void bootFromFile(string filename);

};

#endif // DRIVER_H
