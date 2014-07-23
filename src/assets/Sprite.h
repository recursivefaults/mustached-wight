#ifndef SPRITE_H
#define SPRITE_H

#include "../zombie_walk.h"

class Sprite
{
    public:
        Sprite(SDL_Texture *tex) : texture(tex) {};
        ~Sprite() {SDL_DestroyTexture(texture); };
        SDL_Texture *getTexture() {return texture;};
    protected:
    private:
        SDL_Texture *texture;
};

#endif
