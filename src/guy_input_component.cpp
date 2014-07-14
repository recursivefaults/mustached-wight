#include "guy_input_component.h"
#include "zombie_walk.h"

namespace {
    int kVertical = 10;
    int kHorizontal = 20;
    
}

void GuyInputComponent::update(GameObject &object, InputState &state) {
    if(state.wasKeyPressed(SDLK_d)) {
        //object.x += kHorizontal;
        object.velocity += kHorizontal;
    }
    if(state.wasKeyPressed(SDLK_a)) {
        //object.x -= kHorizontal;
        object.velocity -= kHorizontal;
    }
    if(state.wasKeyPressed(SDLK_w)) {
        //object.y -= kVertical;
        object.velocity = 0;
    }
    if(state.wasKeyPressed(SDLK_s)) {
        //object.y += kVertical;
        object.velocity = 0;
    }


}
