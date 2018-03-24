#include "Dispatcher.h"
#include "PCB.h"
#include "HDD.h"
#include "RAM.h"

Dispatcher::Dispatcher(RAM* Ram, HDD* Hdd, CPU* Cpu) {
    ram = Ram;
    cpu = Cpu;
    hdd = Hdd;
}

void Dispatcher::swapInProcess(PCB* pcb) {
    if (pcb == currentPcbInMemory) return;
    int locationOnHDD = hdd->getProcessStartLocationOnDisk(pcb->Id);
    for (int i = locationOnHDD; i < pcb->codeSize + pcb->dataSize; i++) {
        ram->setMemory(i - locationOnHDD, hdd->getMemory(i).GetDecimal(0, 32));
    }
    cpu->setProgramCounter(pcb->PC);
    // cpu->setProgramCounter(pcb->PC + some time of offset);   we would use this if we had more than one process in ram
}
