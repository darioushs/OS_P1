#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "RAM.h"

using namespace std;

RAM RAM::operator+(RAM other) {
	int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<1024> bset(num1 + num2);
    memory = bset;
    return *this;
}

RAM RAM::operator-(RAM other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<1024> bset(num1 - num2);
    memory = bset;
    return *this;
}

RAM RAM::operator*(RAM other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<1024> bset(num1 * num2);
    memory = bset;
    return *this;
}

RAM RAM::operator/(RAM other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<1024> bset(num1 / num2);
    memory = bset;
    return *this;
}

RAM RAM::operator=(RAM other) {
    if (this == &other)
        return *this;
    memory = other.memory;
    return *this;
}

void RAM::SetHex(int hex) {
    stringstream ss;
    unsigned n;
    ss << hex;
    ss >> n;
    bitset<1024> b(n);
    memory = b;
    cout << "binary is: " << b << endl;
}

int RAM::GetBit(int index) {
    return memory[index];
}

int RAM::GetDecimal(int lowerBit, int higherBit) {
    int retval = 0;
    int counter = 0;
    for (int i = lowerBit; i <= higherBit; i++) {
        retval += memory[i] * pow(2, counter);
        counter++;
    }
    return retval;
}

string RAM::ToString() {
    return memory.to_string();
}
