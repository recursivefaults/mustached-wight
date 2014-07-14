#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "graphics.h"
#include "graphics_component.h"
#include "input_component.h"
#include "input_state.h"

class GraphicsComponent;
class InputComponent;

class GameObject {
    public:
        GameObject(GraphicsComponent *graphicsComponent,
                InputComponent *inputComponent):
            x(100), y(100), velocity(0.0),
            graphics(graphicsComponent), 
            input(inputComponent) {};
        ~GameObject();
        int x, y;
        float velocity;

        void update(int elapsedTime, Graphics &graphics, InputState &state);

    private:
        //PhysicsComponent *physics;
        GraphicsComponent *graphics;
        InputComponent *input;
};

#endif
