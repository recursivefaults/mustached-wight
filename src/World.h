#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "Entity.h"
#include "tiles/Map.h"
#include "Components.h"

class World
{
    public:
        std::map<int, Entity *>   entities;
        std::map<int, PlayerInput *> playerInputs;
        std::map<int, Sprite *>   sprites;
        std::map<int, Position *> positions;
        std::map<int, Velocity *> velocities;
        std::map<int, TileMapCollision *> tileMapCollisions;
        std::map<int, Collidable *> collidables;
        Map *map;
    protected:
    private:
};

#endif
