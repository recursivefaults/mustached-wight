#include "AnimatedSprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite(const std::string &fileName, Graphics &graphics, SDL_Rect startLocation, int fps, int numFrames)
{
    texture = assetHelper.loadNamedTexture(fileName, graphics);
    locationInSheet = startLocation;
    currentLocation.w = startLocation.w;
    currentLocation.h = startLocation.h;

    totalFrames = numFrames;
    currentFrame = 0;
    tick = 1000 / fps;
    std::cout << "Starting y position: " << locationInSheet.y << std::endl;

    std::cout << "Tick for animation is " << tick << "ms." << std::endl;

}
void AnimatedSprite::update(int deltaInMs, SDL_Rect &updatedLocation)
{
    elapsedTime += deltaInMs;
    if(elapsedTime > tick) {
        //Advance the frame;
        currentFrame++;
        elapsedTime = 0;
    }
    if(currentFrame > totalFrames - 1) {
        currentFrame = 0;
    }

    currentLocation.x = updatedLocation.x;
    currentLocation.y = updatedLocation.y;

    locationInSheet.x = currentFrame * locationInSheet.w;
}
