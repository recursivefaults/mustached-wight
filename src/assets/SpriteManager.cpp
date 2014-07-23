#include "SpriteManager.h"

void SpriteManager::addNamedSprite(const std::string spriteName, const std::string textureName, int numFrames, SDL_Rect startDimensions) 
{
    Sprite s;
    s.numFrames = numFrames;
    s.sourceRect = startDimensions;
    s.texture = manager->getTextureForName(textureName);

    _spriteIndex.insert(std::pair<std::string, Sprite>(spriteName, s));
}
Sprite *SpriteManager::getNamedSprite(const std::string spriteName)
{
    std::map<std::string, Sprite>::iterator finder = _spriteIndex.find(spriteName);
    return &finder->second;
}
