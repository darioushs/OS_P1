#include <string>
#include <vector>
#include <iostream>
using namespace std;
class PCB
{
public:
	vector<PCB> pcbVector;
	string processID, wordCount, priority, inputBufferSize, outputBufferSize, tempBufferSize;
	string delimiter = " ";
	void addJob(string jobControlCard);
	void addData(string dataControlCard);
	int startDisk, endDisk, startRam, endRam;
	bool isInRam;
};


