#ifndef GAME_H
#define GAME_H

#include <vector>
#include "zombie_walk.h"

#include "graphics.h"
#include "System.h"
#include "World.h"
#include "Entity.h"
#include "input_state.h"

namespace {
    int kFPS = 60;
}

class Game 
{
    public:
        Game();
        ~Game();
        void init();

        void mainLoop();
        void update(const int deltaInMs);
        void render();
        void processInput();
    private:
        bool isRunning;
        std::vector<System *> *systemList;
        Graphics graphics;
        InputState inputState;
        World world;

};

#endif
