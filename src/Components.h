#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "zombie_walk.h"
#include <vector>
#include <map>

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


struct AABB
{
    AABB() {};
    AABB(int mx, int my, int Mx, int My) : minX(mx),
        minY(my),
        maxX(Mx),
        maxY(My) {};
    int minX, minY, maxX, maxY;
};

struct Collidable
{
    std::vector<AABB> boxes;
};

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

struct Animation
{
    int elapsed = 0;
    bool isLooping = false;
};

struct Rendered
{
    std::string spriteName;
    int currentFrame = 0;
    int w, h;

};

#endif
