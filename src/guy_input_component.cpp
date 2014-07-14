#include "guy_input_component.h"
#include <iostream>
#include "zombie_walk.h"

namespace {
    int kVertical = 10;
    int kHorizontal = 20;
    
}

void GuyInputComponent::update(GameObject &object, InputState &state) {
    if(state.wasKeyPressed(SDLK_d)) {
        object.x += kHorizontal;
        std::cout << "D Pressed" << std::endl;
    }
    if(state.wasKeyPressed(SDLK_a)) {
        object.x -= kHorizontal;
        std::cout << "A Pressed" << std::endl;
    }
    if(state.wasKeyPressed(SDLK_w)) {
        object.y -= kVertical;
        std::cout << "W Pressed" << std::endl;
    }
    if(state.wasKeyPressed(SDLK_s)) {
        object.y += kVertical;
        std::cout << "S Pressed" << std::endl;
    }


}
