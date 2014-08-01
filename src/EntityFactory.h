#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"
#include "World.h"
#include "Components.h"

class EntityFactory
{
    public:
        Entity createGuy(World &world);
        Entity* createZombie(World &world, Position &p, ColorMod &color);
    protected:
    private:
        void addBasicZombieShapes(int entityId, Position &p, World &world);
};

#endif
