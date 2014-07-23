#include "EntityFactory.h"
#include "Components.h"

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

    start.y = 160;
    world.manager.addNamedSprite("playerWalkLeft", "guy.png", 6, start, 15);

    start.y = 180;
    world.manager.addNamedSprite("playerWalkRight", "guy.png", 6, start, 15);

    PlayerInput *i = new PlayerInput();
    i->keyMap = {{SDL_SCANCODE_W, PlayerActions::jump}, {SDL_SCANCODE_A, PlayerActions::moveLeft}, {SDL_SCANCODE_D, PlayerActions::moveRight}};

    Collidable *collidable = new Collidable();
    AABB box;
    box.minX = p->x + 2;
    box.minY = p->y + 2;
    box.maxX = p->x + rendered->w - 2;
    box.maxY = p->y + rendered->h - 2;
    collidable->boxes.push_back(box);


    int id = g->getId();

    world.playerInputs[id] = i;
    world.positions[id] =  p;
    world.velocities[id] =  v;
    world.renders[id] = rendered;
    world.entities[id] =  g;
    world.tileMapCollisions[id] = new TileMapCollision();
    world.collidables[id] = collidable;

    return *g;
}
