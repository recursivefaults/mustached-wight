#include "SpriteManager.h"

void SpriteManager::addNamedSprite(const std::string spriteName, const std::string textureName, int numFrames, SDL_Rect startDimensions, int fps) 
{
    SDL_assert(numFrames > 0);
    Sprite s;
    s.numFrames = numFrames;
    s.fps = fps;
    //TODO make this handle non-horizontal frames
    for(int i = 0; i < numFrames; ++i)
    {
        SDL_Rect frame;
        frame.x = i * startDimensions.w + startDimensions.x;
        frame.y = startDimensions.y;
        frame.w = startDimensions.w;
        frame.h = startDimensions.h;
        s.frames.push_back(frame);
    }
    s.texture = manager->getTextureForName(textureName);

    _spriteIndex.insert(std::pair<std::string, Sprite>(spriteName, s));
}
Sprite *SpriteManager::getNamedSprite(const std::string spriteName)
{
    std::map<std::string, Sprite>::iterator finder = _spriteIndex.find(spriteName);
    return &finder->second;
}
