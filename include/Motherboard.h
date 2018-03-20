#include "../CPU.h"
#include "../HDD.h"
#include "../RAM.h"

#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H


class Motherboard
{
    public:
        Motherboard();
        virtual ~Motherboard();

    protected:

    private:
        RAM ram;
        HDD hdd;
        CPU cpu;
};

#endif // MOTHERBOARD_H
