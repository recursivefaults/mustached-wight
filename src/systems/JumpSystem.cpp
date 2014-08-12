#include "JumpSystem.h"
#include "PhysicsSystem.h"
#include <iostream>


void JumpSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        if(!ev.second->hasComponents(K_JUMP | K_PLAYER_INPUT)) {
            continue;
        }
        Entity *e = ev.second;
        Jump *j = static_cast<Jump *>(e->getComponentForType(K_JUMP));
        PlayerInput *input = static_cast<PlayerInput *>(e->getComponentForType(K_PLAYER_INPUT));
        if(j == nullptr)
        {
            continue;
        }

        if(input->input[PlayerActions::jump] != true)
        {
            continue;
        } else {
            j->jumpDuration = 0;
        }

        Velocity *v = world.velocities[ev.first];

        if(v->velY > 0 && j->jumpDuration == 0) {
            //Falling
            std::cout << "Falling, skipping the jump" << std::endl;
            continue;
        }

        j->jumpDuration += elapsedTimeMS;

        //If you're not on the ground and you have more time, keep jumping
        //If you have no more time, stop jumping and prepare to fall.
        if(j->jumpDuration < j->maxJumpTime) {
            v->velY = j->jumpVelocity;
        } 
        else
        {
            //No more jumping
            j->jumpDuration = 0;
            v->velY = 0;
        }

    }
}
