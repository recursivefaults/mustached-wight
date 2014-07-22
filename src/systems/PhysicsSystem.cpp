#include "PhysicsSystem.h"
#include "../Components.h"

void PhysicsSystem::update(int elapsedTimeMs, World &world)
{
    for(auto ev : world.entities)
    {
        //Position and Velocity
        Velocity *v = world.velocities[ev.first];
        Position *p = world.positions[ev.first];

        p->x += (v->velX * elapsedTimeMs);
        p->y += (v->velY * elapsedTimeMs);
    };

}
