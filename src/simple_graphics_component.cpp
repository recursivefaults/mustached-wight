#include "simple_graphics_component.h"
#include <iostream>
#include <cassert>

SimpleGraphicsComponent::SimpleGraphicsComponent(const std::string &file, Graphics &graphics) {
    std::string full_path = assetPath(file);
    texture = IMG_LoadTexture(graphics.getRenderer(), full_path.c_str());
    assert(texture != nullptr);
}

SimpleGraphicsComponent::~SimpleGraphicsComponent() {
    SDL_DestroyTexture(texture);
}

void SimpleGraphicsComponent::update(GameObject &object, Graphics &graphics) {
    currentLocation.x = object.x;
    currentLocation.y = object.y;
    currentLocation.w = 25;
    currentLocation.h = 24;
    graphics.drawTexture(texture, &currentLocation);
}

const std::string SimpleGraphicsComponent::assetPath(const std::string &file) {
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    return full_path;
}
