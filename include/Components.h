#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "zombie_walk.h"
#include <string>
#include <vector>
#include <map>

typedef uint32_t ComponentFlags;

enum class ComponentTypes
{
    K_PLAYER_ACTIONS,
    K_TILE_MAP_COLLISION,
    K_VECTOR2D,
    K_AABB,
    K_BULLET,
    K_AMMUNITION,
    K_WEAPON_STAT,          
    K_COLLIDABLE,
    K_POSITION,
    K_VELOCITY,
    K_PLAYER_INPUT_MAP,
    K_PLAYER_INPUT,
    K_JUMP,
    K_WALK_LEFT,
    K_WALK_RIGHT,
    K_DUCK,
    K_SHOOT,
    K_LOOT,
    K_BURN,
    K_ANIMATION,
    K_RENDERED,
    K_COLORMOD
};

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
