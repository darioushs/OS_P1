#include <bitset>
#include <string>

using namespace std;

#ifndef HDD_H
#define HDD_H

class HDD {
private:
    bitset<2048> memory;

public:
	HDD() {}
	HDD(int initialValue) {
		SetHex(initialValue);
	}
	void SetHex(int hex);
	int GetBit(int index);
	int GetDecimal(int lowerBit, int higherBit);
	string ToString();
	HDD operator+(HDD other);
	HDD operator-(HDD other);
	HDD operator*(HDD other);
	HDD operator/(HDD other);
	HDD operator=(HDD other);
};

#endif
