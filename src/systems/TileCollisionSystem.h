#ifndef TILECOLLISIONSYSTEM_H
#define TILECOLLISIONSYSTEM_H

#include "System.h"

class TileCollisionSystem : public System
{
    public:
        TileCollisionSystem(int priority) : System(priority) {};
        void update(int elapsedTimeMS, World &world);
    protected:
    private:
};

#endif
