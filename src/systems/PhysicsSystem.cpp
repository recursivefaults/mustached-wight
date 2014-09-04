#include "PhysicsSystem.h"
#include "Components.h"
#include "zombie_walk.h"


#include <iostream>

void PhysicsSystem::update(int elapsedTimeMs, World &world)
{
    for(auto ev : world.entities)
    {
        Entity *entity = ev.second;

        if(!entity->hasComponents(ComponentTypes::K_POSITION) || !entity->hasComponents(ComponentTypes::K_VELOCITY)) 
        {
            continue;
        }
        //Position and Velocity
        Velocity *v = static_cast<Velocity *>(entity->getComponentForType(ComponentTypes::K_VELOCITY));
        Position *p = static_cast<Position *>(entity->getComponentForType(ComponentTypes::K_POSITION));

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

        Collidable *c = static_cast<Collidable *>(entity->getComponentForType(ComponentTypes::K_COLLIDABLE));
        if(c != nullptr)
        {
            for(auto &box : c->boxes)
            {
                box.cx += newX;
                box.cy += newY;
            }
        }
    }

}
