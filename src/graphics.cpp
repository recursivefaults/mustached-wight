#include "graphics.h"

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

void Graphics::drawTexture(SDL_Texture *texture,
            SDL_Rect *destination) {
    //Clear things out
    SDL_RenderClear(renderer);
    //Copy the texture to the rendererer
    SDL_RenderCopy(renderer, texture, NULL, destination);
    //Present the rendererer
    SDL_RenderPresent(renderer);
}
