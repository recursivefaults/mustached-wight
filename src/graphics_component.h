#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "asset_helper.h"
#include "graphics.h"
#include "game_object.h"

class GameObject;

class GraphicsComponent {
    public:
        virtual ~GraphicsComponent() {};
        virtual void update(int deltaInMS, GameObject &object, Graphics &graphics) = 0;

    protected:
        AssetHelper assetHelper;
};

#endif
