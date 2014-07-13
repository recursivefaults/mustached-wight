#include "main.h"
#include <iostream>

ZombieWalk::~ZombieWalk() {
    if(render == nullptr)
        SDL_DestroyRenderer(render);
    if(window == nullptr)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

void ZombieWalk::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Zombie Walk", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void ZombieWalk::mainLoop() {
    assert(window != nullptr);
    assert(render != nullptr);
}


int main() {
    ZombieWalk z = ZombieWalk();
    z.init();
    z.mainLoop();
    return 0;
}
