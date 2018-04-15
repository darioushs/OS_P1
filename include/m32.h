#include <bitset>
#include <string>

using namespace std;

#ifndef M32_H
#define M32_H

class m32 {

private:
    bitset<31> memory;

public:
    m32() {}
    m32(int initialValue) {
        SetHex(initialValue);
    }
	void SetHex(int hex); // Sets the value of the bitset to a hex number
    int GetBit(int index); // Retrieves an individual bit
    int GetDecimal(int lowerBit, int higherBit); // Gets the decimal value of a range of bits
    int ToInt();
    string ToString();
    m32 operator+(m32 other);
    m32 operator-(m32 other);
    m32 operator*(m32 other);
    m32 operator/(m32 other);
    m32 operator=(m32 other);
};

#endif // M32_H
