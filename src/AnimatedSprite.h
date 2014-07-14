#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "sprite.h"

class AnimatedSprite : public Sprite {
    public:
        AnimatedSprite(const std::string &fileName, Graphics &graphics, SDL_Rect startLocation, int fps, int numFrames);
        void update(int deltaInMs, SDL_Rect &updatedLocation);
    protected:
    private:
        int elapsedTime;
        int tick;
        int totalFrames;
        int currentFrame;
    
};

#endif
