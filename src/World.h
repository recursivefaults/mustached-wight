#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Entity.h"
#include "Components.h"

class World
{
    public:
        std::vector<Entity>   entities;
        std::vector<Sprite>   sprites;
        std::vector<Position> positions;
        std::vector<Velocity> velocities;
    protected:
    private:
};

#endif
