#ifndef PLAYERINPUTSYSTEM_H 
#define PLAYERINPUTSYSTEM_H

#include "zombie_walk.h"
#include "System.h"


class PlayerInputSystem : public System
{
    public:
        PlayerInputSystem(int priority) : System(priority) {keyboardState = SDL_GetKeyboardState(nullptr);};
        void update(int elapsedTimeMs, World &world);
    private:
    protected:
        const Uint8 *keyboardState;
};

#endif
