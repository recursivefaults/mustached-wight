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
        int newY = (v->velY * elapsedTimeMs);

        int newPX = p->x + newX;
        int newPY = p->y + newY;
        if(newPX < 0 || newPX > 640)
        {
            newX = 0;
        }
        if(newPY < 0 || newPY > 480)
        {
            newY = 0;
        }

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
