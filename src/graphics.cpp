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

void Graphics::drawTexture(SDL_Texture *texture,
            const SDL_Rect *destination,
            const SDL_Rect *sourceRect) {
    SDL_RenderCopy(renderer, texture, sourceRect, destination);
}
