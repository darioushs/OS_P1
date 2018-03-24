#include <bitset>
#include <string>
#include "m32.h"
#include "ProcessPool.h"

using namespace std;

#ifndef HDD_H
#define HDD_H

class HDD {
private:
    m32 memory[2018];
     ProcessPool processPool;

public:
	HDD() {}
	m32 getMemory(int index);
	void setMemory(int index, int value);
	int getProcessStartLocationOnDisk(int PID);
	int addProcessToPool(int PID, int location);
};

#endif
