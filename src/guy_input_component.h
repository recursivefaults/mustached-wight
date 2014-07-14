#include "input_component.h"

class GuyInputComponent : public InputComponent {
    ~GuyInputComponent() {};
    void update(GameObject &object, InputState &state);
};
