#include "static_sprite.h"

StaticSprite::StaticSprite(const std::string &file, const SDL_Rect &sourceRect, const SDL_Rect &location, Graphics &graphics) {
    this->location.x = location.x;
    this->location.y = location.y;
    this->location.w = location.w;
    this->location.h = location.h;
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    texture = IMG_LoadTexture(graphics.getRenderer(), full_path.c_str());
}

StaticSprite::~StaticSprite() {
    SDL_DestroyTexture(texture);
}
void StaticSprite::draw(Graphics &graphics) {
    graphics.drawTexture(texture, &location);
}
