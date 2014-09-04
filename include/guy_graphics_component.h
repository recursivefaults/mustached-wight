#ifndef GUYGRAPHICSCOMPONENT_H
#define GUYGRAPHICSCOMPONENT_H

#include <string>

#include "zombie_walk.h"

#include "graphics_component.h"

#include "graphics.h"
#include "Entity.h"
#include "AnimatedSprite.h"

class GuyGraphicsComponent : public GraphicsComponent {
    public:
        GuyGraphicsComponent(Graphics &graphics);
        ~GuyGraphicsComponent();
        void update(int deltaInMS, Entity &object, Graphics &graphics);

    private:
        StaticSprite *guySprite;
        AnimatedSprite *walkLeft;
        AnimatedSprite *walkRight;

};

#endif
