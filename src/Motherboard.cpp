#include "Motherboard.h"
#include "CPU.h"

Motherboard::Motherboard() {
    ram = RAM();
    hdd = HDD();
    cpu = CPU(&ram);
}
