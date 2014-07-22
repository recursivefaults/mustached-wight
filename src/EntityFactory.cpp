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

    world.positions[g->getId()] =  p;
    world.velocities[g->getId()] =  v;
    world.sprites[g->getId()] =  s;
    world.entities[g->getId()] =  g;

    return *g;
}
