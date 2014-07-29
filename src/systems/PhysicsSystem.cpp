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

        p->x += (v->velX * elapsedTimeMs);
        p->y += (v->velY + ZombieWalk::kVelocityDown) * elapsedTimeMs;
    };

}
