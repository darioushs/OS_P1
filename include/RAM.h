#include <bitset>
#include <string>
#include "m32.h"

using namespace std;

#ifndef RAM_H
#define RAM_H

class RAM {
private:
    m32 memory[1024];
    int used = 0; // Amount of used memory

public:
	RAM() {}
	m32 getMemory(int index);
	void setMemory(int index, int value);
	void printRam();
};

#endif
