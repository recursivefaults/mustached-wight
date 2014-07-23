#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "Entity.h"
#include "tiles/Map.h"
#include "Components.h"
#include "assets/SpriteManager.h"

class World
{
    public:
        std::map<int, Entity *>   entities;
        std::map<int, PlayerInput *> playerInputs;
        std::map<int, Rendered *>   renders;
        std::map<int, Position *> positions;
        std::map<int, Velocity *> velocities;
        std::map<int, TileMapCollision *> tileMapCollisions;
        std::map<int, Collidable *> collidables;
        Map *map;
        SpriteManager manager;
    protected:
    private:
};

#endif
