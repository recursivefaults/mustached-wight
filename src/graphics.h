#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "zombie_walk.h"

class Graphics {
    public:
    Graphics();
    ~Graphics();
    void drawTexture(SDL_Texture *texture,
            SDL_Rect *destination,
            SDL_Rect *sourceRect = nullptr);
    SDL_Texture *loadTexture(const std::string&);

    private:
    SDL_Renderer *renderer;
    SDL_Window *window;
};

#endif
