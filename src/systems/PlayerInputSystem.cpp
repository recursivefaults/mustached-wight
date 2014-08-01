#include "PlayerInputSystem.h"
#include <iostream>


void PlayerInputSystem::update(int elapsedTimeMs, World &world) {
    for (auto ev: world.entities) {
        Velocity *v = world.velocities[ev.first];
        PlayerInputMap *inputMap = world.playerInputMaps[ev.first];
        PlayerInput *input = world.playerInputs[ev.first];

        if(inputMap == nullptr)
        {
            continue;
        }

        SDL_assert(v != nullptr);
        SDL_assert(inputMap != nullptr);
        SDL_assert(input != nullptr);
        
        bool dirty = false;
        input->input.clear();
        for(auto im : inputMap->keyMap) {
            if(keyboardState[im.first])
            {
                switch(im.second)
                {
                    case PlayerActions::moveLeft:
                        input->input[PlayerActions::moveLeft] = true;
                        dirty = true;
                        break;
                    case PlayerActions::moveRight:
                        input->input[PlayerActions::moveRight] = true;
                        dirty = true;
                        break;
                    case PlayerActions::jump:
                        input->input[PlayerActions::jump] = true;
                        dirty = true;
                        break;
                    case PlayerActions::shoot:
                        //Fire!
                        input->input[PlayerActions::shoot] = true;
                        break;
                    default:
                        dirty = false;
                        break;
                }
            }
        }

        //This feels weird here
        Rendered *render = world.renders[ev.first];
        if(dirty == false)
        {
            if(v->velX > 0.0) {
                render->spriteName = "playerStandLeft";
            } 
            if(v->velX < 0.0) {
                render->spriteName = "playerStandRight";
            }
            //No keys touched, default to standing
            render->currentFrame = 0;
            world.animations.erase(ev.first);
            v->velX = 0;
        }
    }
}
