#include "JumpSystem.h"
#include "PhysicsSystem.h"


void JumpSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        Jump *j = world.jumps[ev.first];
        PlayerInput *input = world.playerInputs[ev.first];
        if(j == nullptr)
        {
            continue;
        }

        if(input->input[PlayerActions::jump] != true)
        {
            continue;
        }

        Velocity *v = world.velocities[ev.first];

        //If you're falling, continue to fall
        if(v->velY > 0)
        {
            continue;
        }

        j->jumpDuration += elapsedTimeMS;

        //If you're not on the ground and you have more time, keep jumping
        //If you have no more time, stop jumping and prepare to fall.
        if(j->jumpDuration < j->maxJumpTime) {
            v->velY = j->jumpVelocity;
        } else
        {
            //No more jumping
            j->jumpDuration = 0;
            v->velY = 0;
        }

    }
}
