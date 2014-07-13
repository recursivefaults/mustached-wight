#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "zombie_walk.h"

class EntityFactory {
    public:
        GameObject *createGuy(Graphics &graphics);
};

#endif
