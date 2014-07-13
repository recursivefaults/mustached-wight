#include "main.h"
#include <iostream>

ZombieWalk::~ZombieWalk() {
    if(render == nullptr)
        SDL_DestroyRenderer(render);
    if(window == nullptr)
        SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture* ZombieWalk::loadTexture(const std::string &file, SDL_Renderer *renderer) {
    //TODO: Deal with asset pathing
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    std::cout << "Path for asset: " << full_path << std::endl;
    return IMG_LoadTexture(renderer, full_path.c_str());
    
}

/**
 * Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
 * width and height
 * @param tex The source texture we want to draw
 * @param ren The renderer we want to draw to
 * @param x The x coordinate to draw to
 * @param y The y coordinate to draw to
 * @param w The width of the texture to draw
 * @param h The height of the texture to draw
 * */
void ZombieWalk::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h) {
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, tex, NULL, &dst);
    SDL_RenderPresent(ren);
}

void ZombieWalk::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Zombie Walk", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void ZombieWalk::mainLoop() {
    assert(window != nullptr);
    assert(render != nullptr);
    SDL_Texture *tex = loadTexture("guy.png", render);
    assert(tex != nullptr);
    bool running = true;
    renderTexture(tex, render, 100, 100, 100, 100);
    SDL_Delay(2000);
    SDL_DestroyTexture(tex);
}


int main() {
    ZombieWalk z = ZombieWalk();
    z.init();
    z.mainLoop();
    return 0;
}
