#include <iostream>
#include <string>
#include <fstream>
#include "Loader.h"
#include "m32.h"
#include "PCB.h"
#include "IScheduler.h"

using namespace std;

void Loader::addJob(string jobControlCard, PCB* inputPCB)
{
    inputPCB->Id =  stoi(jobControlCard.substr(7,jobControlCard.find(delimterPosition)));
	inputPCB->codeSize = stoi(jobControlCard.substr(9, jobControlCard.find(delimterPosition)));
    inputPCB->priority = stoi(jobControlCard.substr(12));
}

void Loader::addData(string dataControlCard, PCB* inputPCB)
{
	inputPCB->inputBuffer = stoi(dataControlCard.substr(8, dataControlCard.find(delimterPosition)));
	inputPCB->outputBufferSize = stoi(dataControlCard.substr(11, dataControlCard.find(delimterPosition)));
	inputPCB->tempBufferSize = stoi(dataControlCard.substr(12));
}

bool Loader::isWildCard(string input) {
    return input.substr(0, 2) == "//";
}

bool isEndCard(string input) {
    return input == "//END";
}

/*void Loader::Load(string filename, RAM* Ram, HDD* Disk, IScheduler* scheduler ) {
    ifstream file(filename);
    string str;
    int readData = true; // When this is set to false the next control card we read is instruction, then we set this to true.
    PCB *newPcb = nullptr;
    int CurrentHddLocation = 0;
    // TODO: The loader need to create a new pcb in the pcb table of the HDD when it loads a new process
    while (std::getline(file, str))
    {
        if (isWildCard(str)) {
            if (isEndCard(str)) break;
            if (readData) {
                if (newPcb != nullptr) {
                    scheduler->addPCB(newPcb);
                    Disk->addProcessToPool(newPcb, CurrentHddLocation);
                }
                newPcb = new PCB();
                addJob(str, newPcb);
                readData = false;
            } else {
                addData(str, newPcb);
                readData = true;
            }
        } else {
            Disk->getMemory(CurrentHddLocation).SetHex(stoi(str));
        }
    }
}*/

void Loader::Load(string filename, RAM* Ram, HDD* Disk, IScheduler scheduler) {
    ifstream file(filename);
    string str;
	PCB* newPcb = nullptr;
	bool endLoop = false;
	string currentReading = "JOB";
	int codeSize = 0;
	int dataSize = 0;
	int currentMemLocation = 0;
	int lastJobEndLocation = 0;
    while (std::getline(file, str)) {
		if (isWildCard(str)) {
			string wildCard = str.substr(3, 3);
			if (wildCard == "JOB") {
				newPcb = new PCB();
				Disk->addProcessToPool(newPcb, lastJobEndLocation);
				addJob(str, newPcb);
			} else if (wildCard == "DAT") {
				newPcb->codeSize = codeSize;
				currentReading = "DATA";
			} else if (wildCard == "END") {
				newPcb->dataSize = dataSize;
				lastJobEndLocation = currentMemLocation;
				currentReading = "JOB";
			}
		} else {
			Disk->getMemory(currentMemLocation).SetHex(stoi(str));
			if (currentReading == "JOB") codeSize++;
			if (currentReading == "DAT") dataSize++;
			currentMemLocation++;
		}
    }
}



















