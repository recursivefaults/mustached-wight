#include "game.h"
#include "graphics.h"
#include <iostream>

Game::~Game() {
    SDL_Quit();
}


void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

}

void Game::mainLoop() {
    Graphics graphics;
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = 100;
    rect.h = 100;

    SDL_Texture *tex = graphics.loadTexture("guy.png");
    assert(tex != nullptr);

    SDL_Event input;
    bool running = true;
    while(running) {
        //Get an event
        SDL_PollEvent(&input);
        switch(input.type){
            case SDL_QUIT:
                std::cout << "Quit event!" << std::endl;
                running = false;
                break;
        }
        graphics.drawTexture(tex, &rect);

    }
    SDL_DestroyTexture(tex);
}


