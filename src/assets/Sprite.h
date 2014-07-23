#ifndef SPRITE_H
#define SPRITE_H

#include "Texture.h"
#include "../zombie_walk.h"

struct Sprite
{
    int numFrames;
    SDL_Rect sourceRect;
    Texture *texture;
};
#endif
