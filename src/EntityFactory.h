#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"
#include "graphics.h"
#include "World.h"
#include "asset_helper.h"

class EntityFactory
{
    public:
        Entity createGuy(World &world, Graphics &grahpics);
    protected:
    private:
        AssetHelper helper;
};

#endif
