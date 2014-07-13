#include "game_object.h"

GameObject::~GameObject() {
    delete(input);
    delete(graphics);
}

void GameObject::update(int elapsedTime, const Graphics &graphics, const InputState &state) {
    input->update(*this, state);
    this->graphics->update(*this, graphics);

}
