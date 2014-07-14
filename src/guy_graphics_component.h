#ifndef GUYGRAPHICSCOMPONENT_H
#define GUYGRAPHICSCOMPONENT_H

#include <string>

#include "zombie_walk.h"

#include "graphics.h"
#include "game_object.h"
#include "StaticSprite.h"

class GuyGraphicsComponent : public GraphicsComponent {
    public:
        GuyGraphicsComponent(Graphics &graphics);
        ~GuyGraphicsComponent();
        void update(GameObject &object, Graphics &graphics);

    private:
        StaticSprite *guySprite;

};

#endif
