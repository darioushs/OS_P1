#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "PCB.h"

using namespace std;

void PCB::addJob(string jobControlCard)
{
	processID = jobControlCard.substr(7,jobControlCard.find(delimterPosition));
	wordCount = jobControlCard.substr(9, jobControlCard.find(delimterPosition));
	priority = jobControlCard.substr(12);
}

void PCB::addData(string dataControlCard)
{
	inputBufferSize = dataControlCard.substr(8, dataControlCard.find(delimterPosition));
	outputBufferSize = dataControlCard.substr(11, dataControlCard.find(delimterPosition));
	tempBufferSize = dataControlCard.substr(12);
}
