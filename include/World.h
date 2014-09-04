#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "Entity.h"
#include "Map.h"
#include "Components.h"
#include "SpriteManager.h"

class World
{
    public:
        std::map<int, Entity *> entities;
        std::vector<AABB *> debugBoxes;
        Map *map;
        SpriteManager manager;
    protected:
    private:
};

#endif
