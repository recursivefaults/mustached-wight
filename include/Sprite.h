#ifndef SPRITE_H
#define SPRITE_H

#include <vector>
#include "Texture.h"

#include "zombie_walk.h"

struct Sprite
{
    int numFrames;
    int fps = 0;
    std::vector<SDL_Rect> frames;
    Texture *texture;
};
#endif
