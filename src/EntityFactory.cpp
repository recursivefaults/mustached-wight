#include "EntityFactory.h"
#include "Components.h"

Entity EntityFactory::createGuy(World &world, Graphics &graphics) {
    Entity *g = new Entity();

    Position *p = new Position();
    p->x = 100;
    p->y = 100;
    Velocity *v = new Velocity();

    Sprite *s = new Sprite();
    s->texture = helper.loadNamedTexture("guy.png", graphics);
    s->sourceRect.x = 0;
    s->sourceRect.y = 60;
    s->sourceRect.w = 32;
    s->sourceRect.h = 20;
    s->destinationRect.w = 32;
    s->destinationRect.h = 20;

    PlayerInput *i = new PlayerInput();
    i->keyMap = {{SDL_SCANCODE_W, PlayerActions::jump}, {SDL_SCANCODE_A, PlayerActions::moveLeft}, {SDL_SCANCODE_D, PlayerActions::moveRight}};

    Collidable *collidable = new Collidable();
    AABB box;
    box.minX = p->x + 2;
    box.minY = p->y + 2;
    box.maxX = p->x + s->destinationRect.w - 2;
    box.maxY = p->y + s->destinationRect.h - 2;
    collidable->boxes.push_back(box);


    world.playerInputs[g->getId()] = i;
    world.positions[g->getId()] =  p;
    world.velocities[g->getId()] =  v;
    world.sprites[g->getId()] =  s;
    world.entities[g->getId()] =  g;
    world.tileMapCollisions[g->getId()] = new TileMapCollision();
    world.collidables[g->getId()] = collidable;

    return *g;
}
