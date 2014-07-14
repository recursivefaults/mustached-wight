#include "game.h"
#include "entity_factory.h"
#include "TileMap.h"
#include <iostream>

Game::~Game() {
    SDL_Quit();
}


Game::Game() {
    entities = std::vector<GameObject *>();
}

void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    EntityFactory factory;
    graphics = Graphics();
    graphics.clearRenderer();
    isRunning = true;

    entities.push_back(factory.createGuy(graphics));
}

void Game::mainLoop() {

    TileMap map = TileMap(graphics);
    int previousTimeMs = SDL_GetTicks();
    while(isRunning) {
        int current = SDL_GetTicks();
        const int elapsedTime = current - previousTimeMs;
        processInput();
        graphics.clearRenderer();
        map.render(graphics);
        update(elapsedTime);
        render();

        int tick = 1000/kFPS;
        if(elapsedTime < tick) {
            SDL_Delay(tick - elapsedTime);
        }
        previousTimeMs = current;
    }
}


void Game::update(const int deltaInMs) {
    for(auto *entity : entities) {
        entity->update(deltaInMs, graphics, inputState);
    }
}

void Game::render() {
    graphics.render();
}
void Game::processInput() {

        inputState.reset();

        SDL_Event input;
        //Get an event
        SDL_PollEvent(&input);
        switch(input.type){
            case SDL_QUIT:
                std::cout << "Quit event!" << std::endl;
                isRunning = false;
                break;
            case SDL_KEYUP:
                inputState.keyUpEvent(input);
                break;
            case SDL_KEYDOWN:
                inputState.keyDownEvent(input);
                break;
        }
}

