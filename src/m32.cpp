#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "m32.h"

using namespace std;

m32 m32::operator+ (m32 other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<32> bset(num1 + num2);
    memory = bset;
    return *this;
}

m32 m32::operator-(m32 other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<32> bset(num1 - num2);
    memory = bset;
    return *this;
}

m32 m32::operator*(m32 other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<32> bset(num1 * num2);
    memory = bset;
    return *this;
}

m32 m32::operator/(m32 other) {
    // TODO: Due for optimization
    int num1 = GetDecimal(0, 31);
    int num2 = other.GetDecimal(0, 31);
    bitset<32> bset(num1 / num2);
    memory = bset;
    return *this;
}

m32 m32::operator=(const m32 other) {
    if (this == &other)
        return *this;
    memory = other.memory;
    return *this;
}

void m32::SetHex(int hex) {
    stringstream ss;
    unsigned n;
    ss << hex;
    ss >> n;
    bitset<32> b(n);
    memory = b;
    cout << "binary is: " << b << endl;
}

int m32::GetBit(int index) {
    return memory[index];
}

int m32::GetDecimal(int lowerBit, int higherBit) {
    int retval = 0;
    int counter = 0;
    for (int i = lowerBit; i <= higherBit; i++) {
        retval += memory[i] * pow(2, counter);
        counter++;
    }
    return retval;
}

int m32::ToInt() {
    return (int)(memory.to_ulong());
    //return GetDecimal(0, 15);
}

string m32::ToString() {
    return memory.to_string();
}
