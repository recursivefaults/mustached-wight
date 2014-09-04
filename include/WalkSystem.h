#ifndef WALKSYSTEM_H
#define WALKSYSTEM_H

#include "System.h"

class WalkSystem : public System
{
    public:
        WalkSystem(int priority) : System(priority) {};
        void update(int elapsedInMs, World &world);
    protected:
    private:
};

#endif
