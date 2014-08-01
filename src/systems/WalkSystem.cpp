#include "WalkSystem.h"
#include "../Constants.h"
#include "../Components.h"

#include <iostream>

void WalkSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        WalkRight *right = world.walkRights[ev.first];
        WalkLeft *left = world.walkLefts[ev.first];
        Velocity *v = world.velocities[ev.first];
        PlayerInput *input = world.playerInputs[ev.first];
        Rendered *render = world.renders[ev.first];
        Animation *a = world.animations[ev.first];

        if(right == nullptr || left == nullptr)
        {
            continue;
        }

        SDL_assert(v != nullptr);
        SDL_assert(input != nullptr);

        float vel = 0;

        if(right != nullptr)
        {
            if(input->input[PlayerActions::moveRight] == true)
            {
                vel = ZombieWalk::kHorizontalVelocity;
                render->spriteName = "playerWalkRight";
            }
        }

        if(left != nullptr)
        {
            if(input->input[PlayerActions::moveLeft] == true)
            {
                vel = -ZombieWalk::kHorizontalVelocity;
                render->spriteName = "playerWalkLeft";

            }
        }

        if(vel != 0)
        {
            if(a == nullptr)
            {
                world.animations[ev.first] = new Animation();
            }
        }

        v->velX = vel;
    }
}
