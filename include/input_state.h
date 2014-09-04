#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#include "zombie_walk.h"
#include <map>

class InputState {
    public:
    void keyUpEvent(SDL_Event &event);
    void keyDownEvent(SDL_Event &event);
    bool wasKeyPressed(SDL_Keycode code);
    bool wasKeyReleased(SDL_Keycode code);
    void reset();
    private:
    std::map<SDL_Keycode, bool> released;
    std::map<SDL_Keycode, bool> pressed;
    std::map<SDL_Keycode, bool> held;
};


#endif
