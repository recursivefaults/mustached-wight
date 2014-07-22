#include <iostream>
#include "Game.h"
#include "TileMap.h"
#include "systems/SystemFactory.h"

#include "EntityFactory.h"

Game::~Game() {
    SDL_Quit();
}


Game::Game() {
    delete(systemList);
}

void Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    systemList = SystemFactory().createSystems();


    graphics = Graphics();
    graphics.clearRenderer();
    isRunning = true;

    EntityFactory factory;
    Entity guy = factory.createGuy(world, graphics);
}

void Game::mainLoop() {

    TileMap map = TileMap(graphics);
    int previousTimeMs = SDL_GetTicks();
    while(isRunning) {
        int current = SDL_GetTicks();
        const int elapsedTime = current - previousTimeMs;
        graphics.clearRenderer();
        // Run through Systems
        processInput();
        update(elapsedTime);

        map.render(graphics);

        render();

        int tick = 1000/kFPS;
        if(elapsedTime < tick) {
            SDL_Delay(tick - elapsedTime);
        }
        previousTimeMs = current;
    }
}


void Game::update(const int deltaInMs) {
    for(auto system : *systemList) {
        system->update(deltaInMs, world);
    }
}

void Game::render() {
    Sprite *s;
    Position *p;
    for(auto kv = world.sprites.begin(); kv != world.sprites.end(); kv++) {
        std::map<int, Position *>::iterator pv = world.positions.find(kv->first);
        if(pv == world.positions.end()) {
            continue;
        }
        s = kv->second;
        p = pv->second;
        s->destinationRect.x = p->x;
        s->destinationRect.y = p->y;
        
        //We have the sprite and the position, RENDER
        graphics.drawTexture(s->texture, &s->destinationRect, &s->sourceRect);
    }
    
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

