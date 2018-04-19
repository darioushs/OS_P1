#include <iostream>
#include <string>
#include "m32.h"
#include "PCB.h"
#include "HDD.h"
#include "RAM.h"
#include "IScheduler.h"
#include "PriorityScheduler.h"

#ifndef LOADER_H
#define LOADER_H


class Loader {
private:
    int currentPID;
    string delimiter = " ";
    int delimterPosition, wordCount;
    void addJob(string jobControlCard, PCB* inputPCB);
	void addData(string dataControlCard, PCB* inputPCB);
	bool isWildCard(string input);

public:
    void Load(string filename, HDD* Disk, PriorityScheduler* scheduler);
};


#endif
