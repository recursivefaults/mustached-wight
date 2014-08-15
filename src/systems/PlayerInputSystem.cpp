#include "PlayerInputSystem.h"
#include <iostream>


void PlayerInputSystem::update(int elapsedTimeMs, World &world) {
    for (auto ev: world.entities) {
        Entity *entity = ev.second;
        if(!entity->hasComponents(ComponentTypes::K_PLAYER_INPUT_MAP))
        {
            continue;
        }

        SDL_assert(entity->getId() == 0);

        Velocity *v = static_cast<Velocity *>(entity->getComponentForType(ComponentTypes::K_VELOCITY));
        PlayerInputMap *inputMap = static_cast<PlayerInputMap *>(entity->getComponentForType(ComponentTypes::K_PLAYER_INPUT_MAP));
        PlayerInput *input = static_cast<PlayerInput *>(entity->getComponentForType(ComponentTypes::K_PLAYER_INPUT));


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
        Rendered *render = static_cast<Rendered *>(entity->getComponentForType(ComponentTypes::K_RENDERED));
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
            entity->removeComponent(ComponentTypes::K_ANIMATION);
            v->velX = 0;
        }
    }
}
