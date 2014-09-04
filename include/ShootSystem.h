#ifndef SHOOTSYSTEM_H
#define SHOOTSYSTEM_H

#include "System.h"

class ShootSystem : public System
{
    public:
        ShootSystem(int priority) : System(priority) {};
        ~ShootSystem(){};
        void update(int elapsedTimeMS, World &world);
    protected:
    private:
};

#endif
