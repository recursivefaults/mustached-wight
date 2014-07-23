#include "AnimationSystem.h"
#include <iostream>


void AnimationSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        Animation *animation = world.animations[ev.first];
        if(animation == nullptr)
        {
            continue;
        }


        Rendered *rendered = world.renders[ev.first];
        Sprite *s = world.manager.getNamedSprite(rendered->spriteName);
        SDL_assert(s != nullptr);
        SDL_assert(s->fps > 0);
        int tick = 1000 / s->fps;

        animation->elapsed += elapsedTimeMS;

        std::cout << "Elapsed: " << animation->elapsed << "\tTick: " << tick << std::endl;

        if(animation->elapsed > tick)
        {
            animation->currentFrame++;
            animation->elapsed = 0;
            std::cout << "Tick" << std::endl;
        }

        //Reset the current animation if we've gone over
        if(animation->currentFrame > s->numFrames || s->numFrames == 0)
        {
            animation->currentFrame = 0;
        }

        //Update the sprite location
        s->sourceRect.x = animation->currentFrame * s->sourceRect.w;
    }
}
