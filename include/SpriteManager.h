#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <string>
#include <map>
#include "Sprite.h"
#include "TextureManager.h"
#include "zombie_walk.h"

class SpriteManager
{
    public:
        void addNamedSprite(const std::string spriteName, const std::string textureName, int numFrames, SDL_Rect startDimensions, int fps = 0);
        Sprite *getNamedSprite(const std::string spriteName);
        void setTextureManager(TextureManager *m) {manager = m;};
    protected:
    private:
        TextureManager *manager;
        std::map<std::string, Sprite> _spriteIndex;
};

#endif
