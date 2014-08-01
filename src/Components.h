#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "zombie_walk.h"
#include <string>
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

struct Vector2d
{
    Vector2d(float x, float y): _x(x), _y(y) {};
    float _x, _y;
};

struct AABB
{
    AABB() {};
    AABB(int x, int y, int w, int h) : cx(x),
        cy(y),
        rw(w),
        rh(h) {};
    int cx, cy, rw, rh;

    bool didSimpleCollide(AABB &other, Vector2d &collision);
    bool didMinkowskiCollide(AABB &other);

};

struct Bullet 
{
    int damage = 0;
};
struct Ammunition
{
    int count = 10;
};
struct WeaponStat
{
    int damage = 100;
    int fireRateMS = 350;
    int elapsedShotTimeMS = 0;
};


struct Collidable
{
    std::vector<AABB> boxes;
};

struct Position
{
    int x, y;
};


struct PlayerInputMap {
    std::map<SDL_Keycode, PlayerActions> keyMap;
};

struct PlayerInput
{
    std::map<PlayerActions, bool> input;
};

struct Jump
{
    float jumpVelocity = -0.325;
    int jumpDuration = 0;
    bool isJumping = false;
    int maxJumpTime = 525;
};

struct WalkRight { };
struct WalkLeft { };
struct Duck { };
struct Shoot { };
struct Loot { };
struct Burn { };

struct Velocity
{
    float velX, velY = 0.0;
};

struct Animation
{
    int elapsed = 0;
    bool isLooping = false;
};

struct Rendered
{
    std::string spriteName = "";
    int currentFrame = 0;
    int w, h;
};

struct ColorMod 
{
    int r, g, b;
};

#endif
