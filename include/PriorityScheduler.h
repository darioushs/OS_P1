#include "IScheduler.h"
#include <vector>

class PriorityScheduler : public IScheduler
{
    public:
        void LoadNextProcess();
        void addPCB(PCB* pcb);
        vector<PCB*> processTable;

    protected:

    private:
};

#endif
