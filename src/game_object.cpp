#include "game_object.h"

GameObject::~GameObject() {
    delete(input);
    delete(graphics);
}

void GameObject::update(int elapsedTime, const Graphics &graphics) {
    input->update(*this);
    this->graphics->update(*this, graphics);

}
