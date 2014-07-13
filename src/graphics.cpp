#include "graphics.h"
#include <iostream>

Graphics::Graphics() {
    window = SDL_CreateWindow("Zombie Walk", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

Graphics::~Graphics() {
    if(renderer == nullptr)
        SDL_DestroyRenderer(renderer);
    if(window == nullptr)
        SDL_DestroyWindow(window);
}

SDL_Texture* Graphics::loadTexture(const std::string &file) {
    //TODO: Deal with asset pathing
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    std::cout << "Path for asset: " << full_path << std::endl;
    return IMG_LoadTexture(renderer, full_path.c_str());
    
}

void Graphics::drawTexture(SDL_Texture *texture,
            SDL_Rect *destination,
            SDL_Rect *sourceRect) {
    //Clear things out
    SDL_RenderClear(renderer);
    //Copy the texture to the rendererer
    SDL_RenderCopy(renderer, texture, sourceRect, destination);
    //Present the rendererer
    SDL_RenderPresent(renderer);
}
