#include "PlayerInputSystem.h"
#include <iostream>

namespace {
    float kHorizontalVelocity = 0.5;
}

void PlayerInputSystem::update(int elapsedTimeMs, World &world) {
    for (auto ev: world.entities) {
        Velocity *v = world.velocities[ev.first];
        PlayerInput *input = world.playerInputs[ev.first];
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
                        break;
                    case PlayerActions::moveRight:
                        v->velX = kHorizontalVelocity;
                        break;
                }
            }
        }
    }
}
