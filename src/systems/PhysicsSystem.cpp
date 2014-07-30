#include "PhysicsSystem.h"
#include "../Components.h"
#include "../zombie_walk.h"


#include <iostream>

void PhysicsSystem::update(int elapsedTimeMs, World &world)
{
    for(auto ev : world.entities)
    {
        //Position and Velocity
        Velocity *v = world.velocities[ev.first];
        Position *p = world.positions[ev.first];
        if(v == nullptr || p == nullptr)
        {
            continue;
        }

        int newX = (v->velX * elapsedTimeMs);
        int newY = (v->velY + ZombieWalk::kVelocityDown) * elapsedTimeMs;

        p->x += newX;
        p->y += newY;

        Collidable *c = world.collidables[ev.first];
        if(c != nullptr)
        {
            for(auto &box : c->boxes)
            {
                box.cx += newX;
                box.cy += newY;
            }
        }
    };

}
