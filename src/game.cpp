#include "game.h"
#include <iostream>

Game::~Game() {
    SDL_Quit();
}


Game::Game() {
    textures = std::vector<StaticSprite *>();
}



void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    graphics = Graphics();
    graphics.clearRenderer();
    isRunning = true;

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_Rect dest;
    dest.x = 100;
    dest.y = 100;
    dest.w = 100;
    dest.h = 100;
    textures.push_back(new StaticSprite("guy.png", src, dest, graphics));
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
    for(auto *sprite : textures) {
        sprite->draw(graphics);
    }
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

