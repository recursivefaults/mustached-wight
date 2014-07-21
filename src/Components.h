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
        char *fileName;
        int xOffset, yOffset, width, height;
        SDL_Texture *texture;
        ~Sprite() {SDL_DestroyTexture(texture);};
};

#endif
