#include "WalkSystem.h"
#include "../Constants.h"
#include "../Components.h"

#include <iostream>

void WalkSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        Entity *entity = ev.second;
        if(!entity->hasComponents(K_WALK_LEFT | K_WALK_RIGHT))
        {
            continue;
        }
        WalkRight *right = static_cast<WalkRight *>(entity->getComponentForType(K_WALK_RIGHT));
        WalkLeft *left = static_cast<WalkLeft *>(entity->getComponentForType(K_WALK_LEFT));
        Velocity *v = static_cast<Velocity *>(entity->getComponentForType(K_VELOCITY));
        PlayerInput *input = static_cast<PlayerInput *>(entity->getComponentForType(K_PLAYER_INPUT));
        Rendered *render = static_cast<Rendered *>(entity->getComponentForType(K_RENDERED));
        Animation *a = static_cast<Animation *>(entity->getComponentForType(K_ANIMATION));


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
                entity->addComponent(K_ANIMATION, new Animation());
            }
        }

        v->velX = vel;
    }
}
