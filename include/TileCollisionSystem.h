#ifndef TILECOLLISIONSYSTEM_H
#define TILECOLLISIONSYSTEM_H

#include "System.h"

class TileCollisionSystem : public System
{
    public:
        TileCollisionSystem(int priority) : System(priority) {};
        void update(int elapsedTimeMS, World &world);
        std::vector<TileData *>* getBroadPhaseTiles(int x, int y, World &world);
    protected:
    private:
        bool collideWithTile(AABB &t, Collidable *c, Vector2d &collision);
        std::vector<AABB>* getUpdatedBoxes(Collidable *c, int deltaX, int deltaY);
        bool didCollide(AABB &one, AABB &two);
};

#endif
