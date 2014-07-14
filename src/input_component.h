#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "input_state.h"
#include "game_object.h"

class InputComponent {
    public:
    virtual ~InputComponent() {};
    virtual void update(GameObject &object, const InputState &state) = 0;
};

#endif
