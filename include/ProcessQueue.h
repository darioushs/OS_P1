#ifndef PROCESSQUEUE_H
#define PROCESSQUEUE_H

#include "PCB.h"


class ProcessQueue {
private:
    struct node {
        PCB* pcb;
        node* nextNode;
    };
    node* startPtr;
    node* endPtr;

public:

};


#endif
