#include "guy_input_component.h"
#include "zombie_walk.h"

void GuyInputComponent::update(GameObject &object) {
    SDL_Event event;
    switch(SDL_PollEvent(&event)) {
        case SDL_KEYUP:
            break;
        case SDL_KEYDOWN:
            
            break;

    }

}
