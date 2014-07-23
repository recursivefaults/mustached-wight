#include "SpriteManager.h"
#include "../asset_helper.h"

Sprite *SpriteManager::getSpriteForName(const std::string &name)
{
    std::map<std::string, Sprite>::iterator finder = _spriteIndex.find(name);
    if(finder == _spriteIndex.end())
    {
        loadSpriteWithName(name);
    }
    return &_spriteIndex.at(name);
    
}
void SpriteManager::loadSpriteWithName(const std::string &name)
{
    AssetHelper helper;
    Sprite s(helper.loadNamedTexture(name, *_graphics));
    _spriteIndex.insert(std::pair<std::string, Sprite>(name, s));
}
