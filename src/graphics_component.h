#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include "game_object.h"
#include "graphics.h"


class GameObject;
class Graphics;

class GraphicsComponent {
    public:
    virtual ~GraphicsComponent() {};
    virtual void update(GameObject &object, Graphics &graphics) = 0;
};

#endif
