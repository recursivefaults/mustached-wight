#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "graphics.h"
#include "graphics_component.h"
#include "input_component.h"

class Graphics;

class GameObject {
    public:
        GameObject(GraphicsComponent *graphicsComponent,
                InputComponent *inputComponent):
            graphics(graphicsComponent), 
            input(inputComponent) {};
        ~GameObject();

        void update(int elapsedTime, const Graphics &graphics);

    private:
        int x, y;
        float velocity;
        //PhysicsComponent *physics;
        GraphicsComponent *graphics;
        InputComponent *input;
};

#endif
