#include <bitset>
#include <string>

using namespace std;

#ifndef RAM_H
#define RAM_H

class RAM {
private:
    bitset<1024> memory;

public:
	RAM() {}
	RAM(int initialValue) {
		SetHex(initialValue);
	}
	void SetHex(int hex);
	int GetBit(int index);
	int GetDecimal(int lowerBit, int higherBit);
	string ToString();
	RAM operator+(RAM other);
	RAM operator-(RAM other);
	RAM operator*(RAM other);
	RAM operator/(RAM other);
	RAM operator=(RAM other);
};

#endif
