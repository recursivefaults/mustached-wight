#ifndef WORLD_H
#define WORLD_H

#include <map>

#include "Entity.h"
#include "Components.h"

class World
{
    public:
        std::map<int, Entity *>   entities;
        std::map<int, Sprite *>   sprites;
        std::map<int, Position *> positions;
        std::map<int, Velocity *> velocities;
    protected:
    private:
};

#endif
