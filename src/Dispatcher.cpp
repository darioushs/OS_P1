#include "Dispatcher.h"
#include "PCB.h"
#include "HDD.h"
#include "RAM.h"

Dispatcher::Dispatcher(RAM* Ram, HDD* Hdd, CPU* Cpu) {
    ram = Ram;
    hdd = Hdd;
    cpu = Cpu;
}

int Dispatcher::swapInProcess(PCB* pcb) {
    if (pcb == currentPcbInMemory) return currentPcbInMemory->PC;
    int locationOnHDD = pcb->startPositionOnDisk;
    for (int i = locationOnHDD; i < pcb->codeSize + pcb->dataSize; i++) {
        ram->setMemory(i - locationOnHDD, hdd->getMemory(i).GetDecimal(0, 32));
    }
    cpu->configureRegisters(pcb->registers.acumulatorRegisters);
    return pcb->PC;
    // return pcb->PC + some time of offset;   we would use this if we had more than one process in ram
}
