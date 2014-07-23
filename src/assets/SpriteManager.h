#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <string>
#include <map>


#include "../graphics.h"
#include "Sprite.h"

class SpriteManager
{
    public:
        SpriteManager(Graphics &graphics) : _graphics(&graphics) {};
        Sprite *getSpriteForName(const std::string &name);
    private:
        void loadSpriteWithName(const std::string &name);
    protected:
        Graphics *_graphics;
        std::map<std::string, Sprite> _spriteIndex;
};

#endif
