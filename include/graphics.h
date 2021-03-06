#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "zombie_walk.h"

class Graphics {
    public:
    Graphics();
    ~Graphics();
    void drawTexture(SDL_Texture *texture,
            const SDL_Rect *destination,
            const SDL_Rect *sourceRect = nullptr);
    void drawRect(const SDL_Rect *rect, int r, int g, int b, bool fill=false);
    void clearRenderer() { SDL_RenderClear(renderer); };
    void render() { SDL_RenderPresent(renderer);};
    SDL_Renderer *getRenderer() { return renderer;}

    private:
    SDL_Renderer *renderer;
    SDL_Window *window;
};

#endif
