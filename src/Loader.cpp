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
    try {
        inputPCB->Id = stoi(jobControlCard.substr(7, jobControlCard.find(static_cast<char>(delimterPosition))), 0, 16);
        inputPCB->codeSize = stoi(jobControlCard.substr(9, jobControlCard.find(static_cast<char>(delimterPosition))), 0 , 16);
        inputPCB->priority = stoi(jobControlCard.substr(12), 0, 16);
    } catch (invalid_argument ex) {
        cout << "Error " << ex.what() << " in " << jobControlCard << endl;
    } catch (exception ex) {
        cout << ex.what() << endl;
    }
}

void Loader::addData(string dataControlCard, PCB* inputPCB)
{
	inputPCB->inputBuffer = stoi(dataControlCard.substr(8, dataControlCard.find(delimterPosition)));
	//inputPCB->outputBufferSize = stoi(dataControlCard.substr(11, dataControlCard.find(delimterPosition)));
	inputPCB->outputBufferSize = 12; // Always set to 12
	inputPCB->tempBufferSize = 12; // Always set to 12
	//inputPCB->tempBufferSize = stoi(dataControlCard.substr(12));
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

void Loader::Load(string filename, HDD* Disk, PriorityScheduler* scheduler) {
    ifstream file(filename);
    string str;
    PCB *newPcb = nullptr;
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
                newPcb->startPositionOnDisk = lastJobEndLocation; // We put all the pcb's directly into the ready queue
                scheduler->addPcb(newPcb);
                addJob(str, newPcb);
                currentReading = "JOB";
            } else if (wildCard == "Dat") {
                currentReading = "Dat";
                addData(str, newPcb);
            } else if (wildCard == "END") {
                newPcb->dataSize = dataSize;
                newPcb->codeSize = codeSize;
                lastJobEndLocation = currentMemLocation;
                codeSize = 0;
                dataSize = 0;
            }
        } else {
            int newEntry;
            if (str == "") return;
            try {
                newEntry = stoi(str.substr(2, string::npos), nullptr, 16);
                Disk->setMemory(currentMemLocation, newEntry);
            } catch (invalid_argument ex) {
                cout << "ERROR: " << ex.what() << " In " << str << endl;
            } catch (out_of_range ex) {
                cout << "ERROR: " << ex.what() << " In " << str << endl;
            }

            if (currentReading == "JOB") codeSize++;
            if (currentReading == "Dat") dataSize++;
            currentMemLocation++;
        }
    }
}



















