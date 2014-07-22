#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "zombie_walk.h"

struct Position
{
    int x, y;
};

struct Velocity
{
    float velX, velY;
};

class Sprite
{
    public:
        SDL_Rect sourceRect;
        SDL_Rect destinationRect;
        SDL_Texture *texture;
        ~Sprite() {SDL_DestroyTexture(texture);};
};

#endif
