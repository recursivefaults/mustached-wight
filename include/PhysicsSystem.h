#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "System.h"

class PhysicsSystem : public System
{
    public:
        PhysicsSystem(int priority) : System(priority) {};
        void update(int elapsedTimeMs, World &world);
    protected:
    private:
};



#endif
