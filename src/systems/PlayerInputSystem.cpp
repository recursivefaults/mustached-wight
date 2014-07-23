#include "PlayerInputSystem.h"
#include <iostream>

namespace {
    float kHorizontalVelocity = 0.5;
}

void PlayerInputSystem::update(int elapsedTimeMs, World &world) {
    for (auto ev: world.entities) {
        Velocity *v = world.velocities[ev.first];
        PlayerInput *input = world.playerInputs[ev.first];
        std::string animationName;
        SDL_assert(v != nullptr);
        SDL_assert(input != nullptr);
        
        //Default state 
        v->velX = 0.0;
        v->velY = 0.0;
        bool dirty = false;
        for(auto im : input->keyMap) {
            if(keyboardState[im.first])
            {
                switch(im.second)
                {
                    case PlayerActions::moveLeft:
                        v->velX = -kHorizontalVelocity;
                        animationName = "playerWalkLeft";
                        dirty = true;
                        break;
                    case PlayerActions::moveRight:
                        v->velX = kHorizontalVelocity;
                        animationName = "playerWalkRight";
                        dirty = true;
                        break;
                    default:
                        break;
                }
            }
        }
        Rendered *render = world.renders[ev.first];
        if(dirty == false)
        {
            //No keys touched, default to standing
            render->spriteName = "playerStandLeft";
            render->currentFrame = 0;
            world.animations.erase(ev.first);
        }
        if(animationName.length() > 0)
        {
            Animation *a = world.animations[ev.first];
            if(a == nullptr)
            {
                a = new Animation();
                world.animations[ev.first] = a;
            }
            render->spriteName = animationName;
        }
    }
}
