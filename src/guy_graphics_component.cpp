#include "guy_graphics_component.h"


GuyGraphicsComponent::GuyGraphicsComponent(Graphics &graphics) {
    SDL_Rect locationInSprite;
    locationInSprite.x = 0;
    locationInSprite.y = 140;
    locationInSprite.w = 30;
    locationInSprite.h = 20;
    guySprite = new StaticSprite("guy.png", graphics, locationInSprite);
}

GuyGraphicsComponent::~GuyGraphicsComponent() {
    delete(guySprite);
}

void GuyGraphicsComponent::update(GameObject &guy, Graphics &graphics) {
    SDL_Rect currentLocation;
    currentLocation.x = guy.x;
    currentLocation.y = guy.y;
    guySprite->update(0, currentLocation);
    guySprite->render(graphics);
}
