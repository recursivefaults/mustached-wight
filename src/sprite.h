#ifndef SPRITE_H
#define SPRITE_H

#include "zombie_walk.h"
#include "asset_helper.h"
#include "graphics.h"

class Sprite {
    public:
        virtual ~Sprite() {SDL_DestroyTexture(texture);};
        virtual void update(int deltaInMs, SDL_Rect &updatedLocation) = 0;
        virtual void render(Graphics &graphics) { graphics.drawTexture(texture, &currentLocation, &locationInSheet); };
    protected:
        SDL_Texture *texture;
        SDL_Rect locationInSheet;
        SDL_Rect currentLocation;
        AssetHelper assetHelper;
};

#endif
