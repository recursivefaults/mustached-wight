#include "game_object.h"

GameObject::~GameObject() {
    delete(input);
    delete(graphics);
}

void GameObject::update(int elapsedTime, Graphics &graphics, InputState &state) {
    input->update(*this, state);
    this->graphics->update(*this, graphics);

}
