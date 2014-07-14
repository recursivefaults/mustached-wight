#include "input_state.h"

void InputState::keyUpEvent(SDL_Event &event) {
    released[event.key.keysym.sym] = true;
    held[event.key.keysym.sym] = false;
}
void InputState::keyDownEvent(SDL_Event &event) {
    pressed[event.key.keysym.sym] = true;
    held[event.key.keysym.sym] = true;
}
bool InputState::wasKeyPressed(SDL_Keycode code) {
    return pressed[code];
}
bool InputState::wasKeyReleased(SDL_Keycode code) {
    return released[code];
}
void InputState::reset() {
    released.clear();
    held.clear();
    pressed.clear();
}
