#ifndef GUYGRAPHICSCOMPONENT_H
#define GUYGRAPHICSCOMPONENT_H

#include <string>

#include "zombie_walk.h"

#include "graphics.h"
#include "game_object.h"
#include "StaticSprite.h"
#include "AnimatedSprite.h"

class GuyGraphicsComponent : public GraphicsComponent {
    public:
        GuyGraphicsComponent(Graphics &graphics);
        ~GuyGraphicsComponent();
        void update(int deltaInMS, GameObject &object, Graphics &graphics);

    private:
        StaticSprite *guySprite;
        AnimatedSprite *walkLeft;
        AnimatedSprite *walkRight;

};

#endif
