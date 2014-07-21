#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "asset_helper.h"
#include "graphics.h"
#include "Entity.h"

class Entity;

class GraphicsComponent {
    public:
        virtual ~GraphicsComponent() {};
        virtual void update(int deltaInMS, Entity &object, Graphics &graphics) = 0;

    protected:
        AssetHelper assetHelper;
};

#endif
