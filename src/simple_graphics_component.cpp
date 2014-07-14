#include "simple_graphics_component.h"

SimpleGraphicsComponent::SimpleGraphicsComponent(const std::string &file, Graphics &graphics) {
    std::string full_path = assetPath(file);
    texture = IMG_LoadTexture(graphics.getRenderer(), full_path.c_str());
}

SimpleGraphicsComponent::~SimpleGraphicsComponent() {
    SDL_DestroyTexture(texture);
}

void SimpleGraphicsComponent::update(GameObject &object, Graphics &graphics) {
    SDL_Rect loc;
    loc.x = object.x;
    loc.y = object.y;
    graphics.drawTexture(texture, &loc);
    
}

const std::string SimpleGraphicsComponent::assetPath(const std::string &file) {
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    return full_path;
}
