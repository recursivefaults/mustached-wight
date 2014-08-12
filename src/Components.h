#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "zombie_walk.h"
#include <string>
#include <vector>
#include <map>

typedef uint32_t ComponentFlags;

#define K_PLAYER_ACTIONS       (1 << 0)
#define K_TILE_MAP_COLLISION   (1 << 1)
#define K_VECTOR2D             (1 << 2)
#define K_AABB                 (1 << 3)
#define K_BULLET               (1 << 4)
#define K_AMMUNITION           (1 << 5)
#define K_WEAPON_STAT          (1 << 6)
#define K_COLLIDABLE           (1 << 7)
#define K_POSITION             (1 << 8)
#define K_VELOCITY             (1 << 9)
#define K_PLAYER_INPUT_MAP     (1 << 10)
#define K_PLAYER_INPUT         (1 << 11)
#define K_JUMP                 (1 << 12)
#define K_WALK_LEFT            (1 << 13)
#define K_WALK_RIGHT           (1 << 14)
#define K_DUCK                 (1 << 15)
#define K_SHOOT                (1 << 16)
#define K_LOOT                 (1 << 17)
#define K_BURN                 (1 << 18)
#define K_ANIMATION            (1 << 19)
#define K_RENDERED             (1 << 20)
#define K_COLORMOD             (1 << 21)

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

class Component
{
    public:
        Component() {};
        virtual ~Component(){};
    protected:
    private:
};

struct TileMapCollision: public Component {};

struct Vector2d : public Component
{
    public:
        Vector2d(float x, float y): _x(x), _y(y) {};
        float _x, _y;
};

struct AABB: public Component
{
    public:
        AABB() {};
        AABB(int x, int y, int w, int h) : cx(x),
        cy(y),
        rw(w),
        rh(h) {};
        int cx, cy, rw, rh;

        bool didSimpleCollide(AABB &other, Vector2d &collision);
        bool didMinkowskiCollide(AABB &other);

};

struct Bullet : public Component
{
    public:
        int damage = 0;
};
struct Ammunition: public Component
{
    public:
        int count = 10;
};
struct WeaponStat: public Component
{
    public:
        int damage = 100;
        int fireRateMS = 350;
        int elapsedShotTimeMS = 0;
};


struct Collidable: public Component
{
    public:
        std::vector<AABB> boxes;
};

struct Position: public Component
{
    public:
        int x, y;
};


struct PlayerInputMap: public Component {
    public:
        std::map<SDL_Keycode, PlayerActions> keyMap;
};

struct PlayerInput: public Component
{
    public:
        std::map<PlayerActions, bool> input;
};

struct Jump: public Component
{
    public:
        float jumpVelocity = -0.325;
        int jumpDuration = 0;
        int maxJumpTime = 525;
};

struct WalkRight: public Component { };
struct WalkLeft: public Component { };
struct Duck: public Component { };
struct Shoot: public Component { };
struct Loot: public Component { };
struct Burn : public Component{ };

struct Velocity: public Component
{
    public:
        float velX, velY = 0.0;
};

struct Animation: public Component
{
    public:
        int elapsed = 0;
        bool isLooping = false;
};

struct Rendered: public Component
{
    public:
        std::string spriteName = "";
        int currentFrame = 0;
        int w, h;
};

struct ColorMod : public Component
{
    public:
        int r, g, b;
};

#endif
