#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "zombie_walk.h"

enum class PlayerActions
{
    moveLeft,
    moveRight,
    duck,
    jump,
    shoot,
    loot,
    burn
};

struct TileMapCollision {};

struct Position
{
    int x, y;
};


struct PlayerInput {
    std::map<SDL_Keycode, PlayerActions> keyMap;
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
