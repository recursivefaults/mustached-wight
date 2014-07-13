#ifndef STATIC_SPRITE_H
#define STATIC_SPRITE_H

#include "zombie_walk.h"
#include "graphics.h"


class StaticSprite {
    public:
        StaticSprite(const std::string &file, const SDL_Rect &sourceRect, const SDL_Rect &location, Graphics &graphics);
        ~StaticSprite();
        void draw(Graphics &graphics);

    private:
        SDL_Texture *texture;
        SDL_Rect location;
};

#endif
