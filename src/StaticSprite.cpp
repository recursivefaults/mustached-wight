#include "StaticSprite.h"

StaticSprite::StaticSprite(const std::string &fileName, Graphics &graphics, SDL_Rect location) 
{
    currentLocation.w = location.w;
    currentLocation.h = location.h;
    locationInSheet = location;
    texture = assetHelper.loadNamedTexture(fileName, graphics);
    SDL_assert(texture != nullptr);
}
void StaticSprite::update(int deltaInMs, SDL_Rect &updatedLocation) 
{
    currentLocation.x = updatedLocation.x;
    currentLocation.y = updatedLocation.y;
    
}
void StaticSprite::render(Graphics &graphics)
{
    graphics.drawTexture(texture, &currentLocation, &locationInSheet);
}
