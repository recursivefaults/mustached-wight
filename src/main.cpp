#include "main.h"
#include <iostream>

void ZombieWalk::init() {
}

void ZombieWalk::mainLoop() {
}


int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Quit();
    ZombieWalk z = ZombieWalk();
    return 0;
}
