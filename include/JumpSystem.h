#ifndef JUMPSYSTEM_H
#define JUMPSYSTEM_H

#include "System.h"

class JumpSystem : public System
{
    public:
        JumpSystem(int priority) : System(priority) {};
        void update(int elapsedTimeMS, World &world);
};

#endif
