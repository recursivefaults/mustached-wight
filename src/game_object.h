#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "zombie_walk.h"


class Graphics;
class InputComponent;
class GraphicsComponent;
class InputState;

class GameObject {
    public:
        GameObject(GraphicsComponent *graphicsComponent,
                InputComponent *inputComponent):
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
