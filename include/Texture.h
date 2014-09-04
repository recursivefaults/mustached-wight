#ifndef TEXTURE_H
#define TEXTURE_H

#include "zombie_walk.h"
#include <iostream>

class Texture
{
    public:
        Texture(SDL_Texture *tex) : texture(tex) {};
        ~Texture() {SDL_DestroyTexture(texture); };
        SDL_Texture *getTexture() {return texture;};
    protected:
    private:
        SDL_Texture *texture;
};

#endif
