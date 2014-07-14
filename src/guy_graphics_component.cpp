#include "guy_graphics_component.h"


GuyGraphicsComponent::GuyGraphicsComponent(Graphics &graphics) {
    SDL_Rect locationInSprite;
    locationInSprite.x = 0;
    locationInSprite.y = 140;
    locationInSprite.w = 32;
    locationInSprite.h = 20;
    guySprite = new StaticSprite("guy.png", graphics, locationInSprite);
    locationInSprite.y = 160;
    walkLeft = new AnimatedSprite("guy.png", graphics, locationInSprite, 15, 6);
    locationInSprite.y = 180;
    walkRight = new AnimatedSprite("guy.png", graphics, locationInSprite, 15, 6);
}

GuyGraphicsComponent::~GuyGraphicsComponent() {
    delete(guySprite);
    delete(walkRight);
    delete(walkLeft);
}

void GuyGraphicsComponent::update(int deltaInMS, GameObject &guy, Graphics &graphics) {
    SDL_Rect currentLocation;
    currentLocation.x = guy.x;
    currentLocation.y = guy.y;
    Sprite *selectedSprite = guySprite;

    if(guy.velocity > 0) {
        selectedSprite = walkRight;
    }
    if(guy.velocity < 0) {
        selectedSprite = walkLeft;
    }
    selectedSprite->update(deltaInMS, currentLocation);
    selectedSprite->render(graphics);
}
