#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"
#include "graphics.h"
#include "World.h"

class EntityFactory
{
    public:
        Entity createGuy(World &world, Graphics &grahpics);
    protected:
    private:
};

#endif
