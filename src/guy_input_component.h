#include "input_component.h"

class GuyInputComponent : public InputComponent {
    ~GuyInputComponent() {};
    virtual void update(GameObject &object, InputState &state);
};
