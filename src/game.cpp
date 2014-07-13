#include "game.h"
#include "graphics.h"
#include <iostream>

Game::~Game() {
    SDL_Quit();
}

SDL_Texture* Game::loadTexture(const std::string &file, SDL_Renderer *renderer) {
    //TODO: Deal with asset pathing
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    std::cout << "Path for asset: " << full_path << std::endl;
    return IMG_LoadTexture(renderer, full_path.c_str());
    
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

    SDL_Texture *tex = loadTexture("guy.png", render);
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


