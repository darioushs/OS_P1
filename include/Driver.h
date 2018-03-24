#ifndef DRIVER_H
#define DRIVER_H

#include "Motherboard.h"
#include "PriorityScheduler.h"
#include "Loader.h"

class Driver
{
private:
    Motherboard motherboard;
    Loader loader;
    IScheduler* Scheduler;


public:
    Driver(IScheduler* Scheduler);
    void boot();

};

#endif // DRIVER_H
