#include "EntityFactory.h"
#include "Components.h"

Entity EntityFactory::createGuy(World &world, Graphics &graphics) {
    Entity g;
    Position p;
    p.x = 100;
    p.y = 100;
    Velocity v;

    Sprite s;
    s.texture = helper.loadNamedTexture("guy.png", graphics);
    s.width = 32;
    s.height = 20;
    s.xOffset = 0;
    s.yOffset = 60;

    world.positions.assign(g.getId(), p);
    world.velocities.assign(g.getId(), v);
    world.sprites.assign(g.getId(), s);

    return g;
}
