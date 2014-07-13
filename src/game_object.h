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

        void update(int elapsedTime, const Graphics &graphics, const InputState &state);

    private:
        int x, y;
        float velocity;
        //PhysicsComponent *physics;
        GraphicsComponent *graphics;
        InputComponent *input;
};

#endif
