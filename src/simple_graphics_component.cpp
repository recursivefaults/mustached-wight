#include <iostream>
#include <cassert>
#include "simple_graphics_component.h"

namespace {
    int kTileWidth = 30;
    int kTileHeight = 20;
    int kTileX = 0;
    int kTileY = 7;
}

SimpleGraphicsComponent::SimpleGraphicsComponent(const std::string &file, Graphics &graphics) {
    texture = assetHelper.loadNamedTexture(file, graphics);
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

SDL_Rect SimpleGraphicsComponent::getTileAt(int x, int y) {
    SDL_Rect location;
    location.w = kTileWidth;
    location.h = kTileHeight;
    location.x = x * kTileWidth;
    location.y = y * kTileHeight;
    return location;
}
