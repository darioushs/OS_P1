#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "HDD.h"

using namespace std;

HDD HDD::operator+(HDD other) {
	int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<2048> bset(num1 + num2);
    memory = bset;
    return *this;
}

HDD HDD::operator-(HDD other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<2048> bset(num1 - num2);
    memory = bset;
    return *this;
}

HDD HDD::operator*(HDD other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<2048> bset(num1 * num2);
    memory = bset;
    return *this;
}

HDD HDD::operator/(HDD other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<2048> bset(num1 / num2);
    memory = bset;
    return *this;
}

HDD HDD::operator=(HDD other) {
    if (this == &other)
        return *this;
    memory = other.memory;
    return *this;
}

void HDD::SetHex(int hex) {
    stringstream ss;
    unsigned n;
    ss << hex;
    ss >> n;
    bitset<2048> b(n);
    memory = b;
    cout << "binary is: " << b << endl;
}

int HDD::GetBit(int index) {
    return memory[index];
}

int HDD::GetDecimal(int lowerBit, int higherBit) {
    int retval = 0;
    int counter = 0;
    for (int i = lowerBit; i <= higherBit; i++) {
        retval += memory[i] * pow(2, counter);
        counter++;
    }
    return retval;
}

string HDD::ToString() {
    return memory.to_string();
}
