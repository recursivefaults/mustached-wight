#ifndef GAME_H
#define GAME_H

#include "zombie_walk.h"
#include "graphics.h"
#include "static_sprite.h"

namespace {
    int kFPS = 60;
}

class Game {
private:
    bool isRunning;
    Graphics graphics;
    std::vector<StaticSprite*> textures;
    InputState inputState;
public:
    Game();
    ~Game();
    void init();

    void mainLoop();
    void update(const int deltaInMs);
    void render();
    void processInput();

};

#endif
