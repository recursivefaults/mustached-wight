#ifndef TILESPRITE_H
#define TILESPRITE_H

#include "../zombie_walk.h"
class TileSprite
{

    public:
        ~TileSprite() {SDL_DestroyTexture(texture);}
        int tileWidth;
        int tileHeight;
        SDL_Texture *texture;
};

#endif
