#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "zombie_walk.h"

class Graphics {
    public:
    Graphics();
    ~Graphics();
    void drawTexture(SDL_Texture *texture,
            SDL_Rect*destination);

    private:
    SDL_Renderer *renderer;
    SDL_Window *window;
};

#endif
