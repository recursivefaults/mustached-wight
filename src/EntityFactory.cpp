#include "EntityFactory.h"


Entity EntityFactory::createGuy(World &world) {
    Entity *g = new Entity();

    Position *p = new Position();
    p->x = 100;
    p->y = 0;

    Velocity *v = new Velocity();

    PlayerInputMap *i = new PlayerInputMap();
    i->keyMap = {{SDL_SCANCODE_W, PlayerActions::jump}, {SDL_SCANCODE_A, PlayerActions::moveLeft}, {SDL_SCANCODE_D, PlayerActions::moveRight}};


    int id = g->getId();
    addBasicZombieShapes(id, *p, world);

    world.playerInputMaps[id] = i;
    world.playerInputs[id] = new PlayerInput();
    world.positions[id] =  p;
    world.velocities[id] =  v;
    world.entities[id] =  g;
    world.tileMapCollisions[id] = new TileMapCollision();
    world.jumps[id] = new Jump();
    world.walkRights[id] = new WalkRight();
    world.walkLefts[id] = new WalkLeft();

    return *g;
}

Entity* EntityFactory::createZombie(World &world, Position &p, ColorMod &color)
{
    Entity *z = new Entity();
    Position *pos = new Position();
    pos->x = p.x;
    pos->y = p.y;
    ColorMod *c = new ColorMod();
    c->r = color.r;
    c->g = color.g;
    c->b = color.b;
    int id = z->getId();
    addBasicZombieShapes(id, p, world);
    world.colorMods[id] = c;
    world.positions[id] = pos;
    world.velocities[id] = new Velocity();

    return z;
}

void EntityFactory::addBasicZombieShapes(int entityId, Position &p, World &world)
{
    Rendered *rendered = new Rendered();
    rendered->spriteName = "playerStandLeft";
    rendered->w = 32;
    rendered->h = 20;

    //Create the corresponding sprite
    SDL_Rect start;
    start.x = 0;
    start.y = 60;
    start.w = rendered->w;
    start.h = rendered->h;
    world.manager.addNamedSprite("playerStandLeft", "guy.png", 1, start);

    start.y = 40;
    world.manager.addNamedSprite("playerStandRight", "guy.png", 1, start);

    start.y = 160;
    world.manager.addNamedSprite("playerWalkLeft", "guy.png", 6, start, 15);

    start.y = 180;
    world.manager.addNamedSprite("playerWalkRight", "guy.png", 6, start, 15);

    Collidable *collidable = new Collidable();
    AABB box(p.x + rendered->w/2, p.y + rendered->h/2, 8, 8);
    collidable->boxes.push_back(box);

    world.renders[entityId] = rendered;
    world.collidables[entityId] = collidable;
}
