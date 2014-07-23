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
        for(auto im : input->keyMap) {
            if(keyboardState[im.first])
            {
                switch(im.second)
                {
                    case PlayerActions::moveLeft:
                        v->velX = -kHorizontalVelocity;
                        animationName = "playerWalkLeft";
                        break;
                    case PlayerActions::moveRight:
                        v->velX = kHorizontalVelocity;
                        animationName = "playerWalkRight";
                        break;
                    default:
                        //Remove animation
                        std::cout << "DELETING new animation for: " << ev.first << std::endl;
                        //world.animations.erase(ev.first);
                        break;
                }
            }
        }
        if(animationName.length() > 0)
        {
            Animation *a = world.animations[ev.first];
            if(a == nullptr)
            {
                a = new Animation();
                world.animations[ev.first] = a;
            }
            Rendered *render = world.renders[ev.first];
            render->spriteName = animationName;
        }
    }
}
