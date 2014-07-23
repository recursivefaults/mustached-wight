#include <iostream>
#include "Game.h"
#include "TileMap.h"
#include "systems/SystemFactory.h"

#include "EntityFactory.h"
#include "assets/TextureManager.h"

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

    TextureManager *manager = new TextureManager(graphics);
    manager->loadTextureWithName("guy.png");
    world.manager.setTextureManager(manager);

    EntityFactory factory;
    Entity guy = factory.createGuy(world, graphics);

}

void Game::mainLoop() {

    TileMap map = TileMap(graphics);
    world.map = map.getMap();
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
    Rendered *render;
    Position *p;
    Sprite *s;
    SDL_Rect destRect;
    for(auto kv = world.renders.begin(); kv != world.renders.end(); kv++) {
        std::map<int, Position *>::iterator pv = world.positions.find(kv->first);
        if(pv == world.positions.end()) {
            continue;
        }
        render = kv->second;
        p = pv->second;
        destRect.x = p->x;
        destRect.y = p->y; 
        destRect.w = render->w;
        destRect.h = render->h;


        s = world.manager.getNamedSprite(render->spriteName);
        SDL_assert(s->texture->getTexture() != nullptr);

        //We have the sprite and the position, RENDER
        graphics.drawTexture(s->texture->getTexture(), &destRect, &s->frames[render->currentFrame]);
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

