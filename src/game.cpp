#include <iostream>
#include "Game.h"
#include "TileMap.h"
#include "SystemFactory.h"

#include "EntityFactory.h"
#include "TextureManager.h"

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
    Entity guy = factory.createGuy(world);
    Position p;
    p.x = 600;
    p.y = 20;
    ColorMod c;
    c.r = 10;
    c.g = 170;
    c.b = 40;
    
    Entity *z = factory.createZombie(world, p, c);

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
    ColorMod *mod;
    Position *p;
    Sprite *s;
    SDL_Rect destRect;
    for(auto kv = world.entities.begin(); kv != world.entities.end(); kv++) {
        if(!kv->second->hasComponents(ComponentTypes::K_RENDERED) || !kv->second->hasComponents(ComponentTypes::K_POSITION)) {
            continue;
        }
        render = static_cast<Rendered *>(kv->second->getComponentForType(ComponentTypes::K_RENDERED));
        p = static_cast<Position *>(kv->second->getComponentForType(ComponentTypes::K_POSITION));
        mod = static_cast<ColorMod *>(kv->second->getComponentForType(ComponentTypes::K_COLORMOD));
        destRect.x = p->x;
        destRect.y = p->y; 
        destRect.w = render->w;
        destRect.h = render->h;


        if(render->spriteName.length() == 0 && mod != nullptr)
        {
            //Draw as a box;
            graphics.drawRect(&destRect, mod->r, mod->g, mod->b);
        } else {

            s = world.manager.getNamedSprite(render->spriteName);
            SDL_assert(s->texture->getTexture() != nullptr);

            //ColorMod if it exists
            if(mod != nullptr)
            {
                SDL_SetTextureColorMod(s->texture->getTexture(), mod->r, mod->g, mod->b);
            } else {
                SDL_SetTextureColorMod(s->texture->getTexture(), 255, 255 , 255);
            }

            //We have the sprite and the position, RENDER
            graphics.drawTexture(s->texture->getTexture(), &destRect, &s->frames[render->currentFrame]);
        }
    }

    /**
     * Draw debug boxes
     */
    for(auto box : world.debugBoxes)
    {
        destRect.x = box->cx - box->rw;
        destRect.y = box->cy - box->rh;
        destRect.h = 2 * box->rh;
        destRect.w = 2 * box->rw;
        graphics.drawRect(&destRect, 0, 0, 255);
    }

    
    graphics.render();
    world.debugBoxes.clear();
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

