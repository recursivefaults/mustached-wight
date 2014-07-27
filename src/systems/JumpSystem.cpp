#include "JumpSystem.h"
#include "PhysicsSystem.h"


void JumpSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        Jump *j = world.jumps[ev.first];
        if(j == nullptr)
        {
            continue;
        }
        if(!j->isJumping) {
            continue;
        }
        Velocity *v = world.velocities[ev.first];
        Position *p = world.positions[ev.first];

        //If you're on the ground, jump
        if(p->y == ZombieWalk::kMagicFloor) {

        }
        //If you're not on the ground and you have more time, keep jumping
        //If you have no more time, stop jumping and prepare to fall.

        j->jumpDuration += elapsedTimeMS;

        if(j->jumpDuration > j->maxJumpTime) {
            //No more jumping
            j->isJumping = false;
            j->jumpDuration = 0;
            v->velY = 0;
            continue;
        }

        //TODO Only jump when appropriate.
        //Jump!
        v->velY = j->jumpVelocity;


    }
}
