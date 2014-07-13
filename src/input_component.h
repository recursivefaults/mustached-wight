#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include "game_object.h"

class InputComponent {
    public:
    virtual ~InputComponent();
    virtual void update(GameObject &object) = 0;
};

#endif
