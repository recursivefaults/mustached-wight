#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "input_state.h"
#include "game_object.h"

class InputComponent {
    public:
    virtual ~InputComponent() {};
    virtual void update(GameObject &object, InputState &state) = 0;
};

#endif
