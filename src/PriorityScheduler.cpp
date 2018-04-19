#include "PriorityScheduler.h"
#include "PCB.h"

PriorityScheduler::PriorityScheduler() {

}

PriorityScheduler::PriorityScheduler(RAM* ram, HDD* hdd, CPU* Cpu) {
    cpu = Cpu;
    dispatcher.setHdd(hdd);
    dispatcher.setRam(ram);
}

/*
void PriorityScheduler::LoadNextProcess() {
    PCB priority;
    int availRAM;   //the starting index of the available RAM after finding space
    if(processTable.empty())
        cout >> "The process table is empty";
    else {
        for(int i = 0; i < processTable.size(); i++){   //start scanning the table for highest priority process
            if(processTable[i].priority > priority.priority){
                if(!processTable[i].isInRam) {          //check if the process is already in ram or not; proceed if false
                    //TODO: REALLY in need of optimization; I'm sorry your eyes had to see this
                    int consecutiveAvailRAM = 0;        //used as a counter
                    while(availRAM = null) {            //look for continuous space in the ram equal to (number of words + input buffer + output buffer + temp buffer)
                        for(int j = 0; j < 1024; j++) {
                            if(RAM.getMemory(j) = null) //add 1 to the counter if the scanned space in RAM is null
                                consecutiveAvailRAM++;
                            else                        //reset the counter to 0 if it finds something in the space
                                consecutiveAvailRAM = 0;
                            if(consecutiveAvailRAM == priority.inputBuffer + priority.outputBufferSize + priority.tempBufferSize) { //if the counter == space needed,
                                availRAM = j - (priority.inputBuffer + priority.outputBufferSize + priority.tempBufferSize);
                                j = 1025;
                            }
                        }
                    }
                }
            }
        }
        if(priority != null){
            for(int i = priority.startDisk; i <= priority.endDisk; i++){    //write winner to ram
                //TODO: find a way to set startRAM and endRAM
                RAM.setMemory(availRAM, HDD.getMemory(i));
            }
        }
    }
}

void PriorityScheduler::addPCB(PCB* pcb) {
    processTable.push_back(pcb);
}
*/

int PriorityScheduler::getHighestPriorityProcessIndex() {
    cout << "SIZE: " << readyQueue.size() << endl;
    int currentHighestIndex = -1;
    int currentHighestPriority = -1;
    for (int i = 0; i < readyQueue.size(); i++) {
        //if (readyQueue[i].state == PCB::ProcessStates::Ready) { // If process state is ready
            if (readyQueue[i]->priority > currentHighestPriority) { // If it has the highest priority
                currentHighestIndex = i;
            }
        //}
    }
    return currentHighestIndex;
}

void PriorityScheduler::addPcb(PCB* pcb) {
    readyQueue.push_back(pcb);
}

int PriorityScheduler::loadNextProcess() {
    int highestPriorityProcess;
    highestPriorityProcess = getHighestPriorityProcessIndex();
    PCB* processToLoad = readyQueue[highestPriorityProcess];
    cout << "highest priority = " << readyQueue[highestPriorityProcess]->Id << endl;
    if (processToLoad->PC == processToLoad->codeSize) { // If the process is finished, removed it from the ready queue and call this function again
        readyQueue.erase(readyQueue.begin() + highestPriorityProcess);
        return loadNextProcess();
    }
    dispatcher.swapInProcess(processToLoad);
	return processToLoad->PC;
}

void PriorityScheduler::signalProcessEnd() {

}

void PriorityScheduler::printAllPcbs() {
    for (auto &i : readyQueue) {
        i->display();
        cout << "---------------------------------" << endl;
    }
}

int PriorityScheduler::getNumberOfPcbs() {
    return readyQueue.size();
}




















