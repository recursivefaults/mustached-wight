#include "game.h"
#include <iostream>

Game::~Game() {
    SDL_Quit();
}


void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    graphics = Graphics();
    isRunning = true;

}

void Game::mainLoop() {

    int startTimeMs = SDL_GetTicks();
    while(isRunning) {
        const int elapsedTime = SDL_GetTicks() - startTimeMs;
        processInput();
        update(elapsedTime);
        render();
        int tick = 1000/kFPS;
        if(elapsedTime < tick) {
            SDL_Delay(tick - elapsedTime);
        }
        startTimeMs = SDL_GetTicks();
        
    }
}


void Game::update(const int deltaInMs) {
}

void Game::render() {
    graphics.clearRenderer();
    //graphics.drawTexture(tex, &rect);
    graphics.render();
}
void Game::processInput() {
        SDL_Event input;
        //Get an event
        SDL_PollEvent(&input);
        switch(input.type){
            case SDL_QUIT:
                std::cout << "Quit event!" << std::endl;
                isRunning = false;
                break;
        }
}

