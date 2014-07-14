#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H


#include "graphics.h"
#include "game_object.h"

class EntityFactory {
    public:
        GameObject *createGuy(Graphics &graphics);
};

#endif
