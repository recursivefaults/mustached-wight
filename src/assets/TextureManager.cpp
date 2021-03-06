#include "TextureManager.h"
#include "asset_helper.h"
#include <iostream>

Texture *TextureManager::getTextureForName(const std::string &name)
{
    std::map<std::string, Texture *>::iterator finder = _spriteIndex.find(name);
    if(finder == _spriteIndex.end())
    {
        std::cout << "Texture: " << name << " isn't loaded, loading now." << std::endl;
        loadTextureWithName(name);
    }
    return _spriteIndex.at(name);
    
}
void TextureManager::loadTextureWithName(const std::string &name)
{
    AssetHelper helper;
    SDL_assert(_graphics != nullptr);
    Texture *s = new Texture(helper.loadNamedTexture(name, *_graphics));
    _spriteIndex.insert(std::pair<std::string, Texture *>(name, s));
    std::cout << "Loaded: " << name << " to the texture library" << std::endl;
}
