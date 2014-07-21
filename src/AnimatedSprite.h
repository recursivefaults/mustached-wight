#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

class AnimatedSprite {
    public:
        AnimatedSprite(const std::string &fileName, Graphics &graphics, SDL_Rect startLocation, int fps, int numFrames);
        void update(int deltaInMs, SDL_Rect &updatedLocation);
    protected:
    private:
        SDL_Rect currentLocation, locationInSheet;
        SDL_Texture *texture;
        int elapsedTime;
        int tick;
        int totalFrames;
        int currentFrame;
    
};

#endif
