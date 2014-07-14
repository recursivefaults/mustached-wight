#ifndef STATICSPRITE_H
#define STATICSPRITE_H

#include "sprite.h"
#include "graphics.h"

class StaticSprite : public Sprite {
    public:
        StaticSprite(const std::string &fileName, Graphics &graphics, SDL_Rect location);
        void update(int deltaInMs, SDL_Rect &updatedLocation);
        void render(Graphics &graphics);
    protected:
    private:
};

#endif
