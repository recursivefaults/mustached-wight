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
        std::vector<AABB>* getUpdatedBoxes(Collidable *c, int deltaX, int deltaY);
        bool didCollide(AABB &one, AABB &two);
};

#endif
