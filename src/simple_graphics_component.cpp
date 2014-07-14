#include "simple_graphics_component.h"
#include <iostream>
#include <cassert>

namespace {
    int kTileWidth = 25;
    int kTileHeight = 24;
    int kTileX = 17;
    int kTileY = 6;
}

SimpleGraphicsComponent::SimpleGraphicsComponent(const std::string &file, Graphics &graphics) {
    std::string full_path = assetPath(file);
    surface = IMG_Load(full_path.c_str());
    assert(surface != nullptr);
    Uint32 map;

    if(isTransparentBlue(kTileX, kTileY)) {
        std::cout << "Blue tile at (" << kTileX << ", " << kTileY << ")" << std::endl;
        map = SDL_MapRGB(surface->format, 33, 255, 255);
    }
    else {
        map = SDL_MapRGB(surface->format, 251, 0, 254);
    }

    SDL_SetColorKey(surface, 1, map);
    texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), surface);
    SDL_FreeSurface(surface);
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
    SDL_Rect srcRect = getTileAt(kTileX, kTileY);
    graphics.drawTexture(texture, &currentLocation, &srcRect);
}
bool SimpleGraphicsComponent::isTransparentBlue(int x, int y) {
    int magentaFirst = y % 2;
    if(magentaFirst == 0 && x % 2 !=0) {
        return true;
    }
    if(magentaFirst != 0 && x%2 == 0) {
        return true;
    }
    return false;

}

const std::string SimpleGraphicsComponent::assetPath(const std::string &file) {
    std::string full_path = std::string(SDL_GetBasePath()); 
    full_path += "assets/" + file;
    return full_path;
}

SDL_Rect SimpleGraphicsComponent::getTileAt(int x, int y) {
    SDL_Rect location;
    location.w = kTileWidth;
    location.h = kTileHeight;
    location.x = x * kTileWidth;
    location.y = y * kTileHeight;
    return location;
}
