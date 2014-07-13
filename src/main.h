#ifndef MAIN_H
#define MAIN_H

#include "zombie_walk.h"

class ZombieWalk {
    SDL_Window *window;
    SDL_Renderer *render;

    SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *renderer);
    void renderTexture(SDL_Texture*, SDL_Renderer*, int, int, int, int);
    
public:
    ~ZombieWalk();
    void init();

    void mainLoop();

};

#endif
