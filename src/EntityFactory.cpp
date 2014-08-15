#include "EntityFactory.h"


Entity EntityFactory::createGuy(World &world) {
    Entity *g = new Entity();

    Position *p = new Position();
    p->x = 100;
    p->y = 0;

    Velocity *v = new Velocity();

    PlayerInputMap *i = new PlayerInputMap();
    i->keyMap = {{SDL_SCANCODE_W, PlayerActions::jump}, {SDL_SCANCODE_A, PlayerActions::moveLeft}, {SDL_SCANCODE_D, PlayerActions::moveRight}, {SDL_SCANCODE_LSHIFT, PlayerActions::shoot}};


    int id = g->getId();
    addBasicZombieShapes(g, *p, world);

    g->addComponent(ComponentTypes::K_PLAYER_INPUT_MAP, i);
    g->addComponent(ComponentTypes::K_PLAYER_INPUT, new PlayerInput());
    g->addComponent(ComponentTypes::K_WEAPON_STAT, new WeaponStat());
    g->addComponent(ComponentTypes::K_AMMUNITION, new Ammunition());
    g->addComponent(ComponentTypes::K_JUMP, new Jump());
    g->addComponent(ComponentTypes::K_WALK_LEFT, new WalkLeft());
    g->addComponent(ComponentTypes::K_WALK_RIGHT, new WalkRight());
    g->addComponent(ComponentTypes::K_TILE_MAP_COLLISION, new TileMapCollision());
    g->addComponent(ComponentTypes::K_POSITION, p);
    g->addComponent(ComponentTypes::K_VELOCITY, v);
    world.entities[id] =  g;

    return *g;
}

Entity *EntityFactory::createBullet(World &world, Position *origin, WeaponStat &weapon)
{
    Entity *b = new Entity();
    int id = b->getId();
    Velocity *v = new Velocity();
    v->velX = ZombieWalk::kBulletVelocity;
    v->velY = 0;
    Bullet *bullet = new Bullet();
    bullet->damage = weapon.damage;
    Collidable *c = new Collidable();
    AABB box;
    box.cx = origin->x + 2;
    box.cy = origin->y + 1;
    box.rh = 1;
    box.rw = 2;
    c->boxes.push_back(box);

    ColorMod *color = new ColorMod();
    color->r = 255;
    color->g = 0;
    color->b = 0;

    Rendered *r = new Rendered();
    r->w = 4;
    r->h = 2;
    

    world.entities[id] = b;
    b->addComponent(ComponentTypes::K_COLORMOD, color);
    b->addComponent(ComponentTypes::K_RENDERED, r);
    b->addComponent(ComponentTypes::K_POSITION, origin);
    b->addComponent(ComponentTypes::K_VELOCITY, v);
    b->addComponent(ComponentTypes::K_COLLIDABLE, c);
    b->addComponent(ComponentTypes::K_BULLET, bullet);

    return b;
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
    addBasicZombieShapes(z, p, world);
    world.entities[id] = z;
    z->addComponent(ComponentTypes::K_COLORMOD, c);
    z->addComponent(ComponentTypes::K_POSITION, pos);
    z->addComponent(ComponentTypes::K_VELOCITY, new Velocity());

    return z;
}

void EntityFactory::addBasicZombieShapes(Entity *entity, Position &p, World &world)
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

    entity->addComponent(ComponentTypes::K_RENDERED, rendered);
    entity->addComponent(ComponentTypes::K_COLLIDABLE, collidable);
}
