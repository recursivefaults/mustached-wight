#ifndef MAIN_H
#define MAIN_H

#include "zombie_walk.h"

class ZombieWalk {
    SDL_Window *window;
    SDL_Renderer *render;
    
public:
    ~ZombieWalk();
    void init();

    void mainLoop();

};

#endif
