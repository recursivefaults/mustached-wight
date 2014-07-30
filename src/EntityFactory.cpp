#include "EntityFactory.h"
#include "Components.h"

#include <iostream>

Entity EntityFactory::createGuy(World &world, Graphics &graphics) {
    Entity *g = new Entity();

    Position *p = new Position();
    p->x = 100;
    p->y = 100;

    Velocity *v = new Velocity();

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

    PlayerInputMap *i = new PlayerInputMap();
    i->keyMap = {{SDL_SCANCODE_W, PlayerActions::jump}, {SDL_SCANCODE_A, PlayerActions::moveLeft}, {SDL_SCANCODE_D, PlayerActions::moveRight}};

    Collidable *collidable = new Collidable();
    AABB box(p->x + rendered->w/2, p->y + rendered->h/2, rendered->w/2 - 2, rendered->h/2 - 2);
    collidable->boxes.push_back(box);


    int id = g->getId();

    world.playerInputMaps[id] = i;
    world.playerInputs[id] = new PlayerInput();
    world.positions[id] =  p;
    world.velocities[id] =  v;
    world.renders[id] = rendered;
    world.entities[id] =  g;
    world.tileMapCollisions[id] = new TileMapCollision();
    world.jumps[id] = new Jump();
    world.walkRights[id] = new WalkRight();
    world.walkLefts[id] = new WalkLeft();
    world.collidables[id] = collidable;

    return *g;
}
