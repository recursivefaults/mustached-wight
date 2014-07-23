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


        if(animation->elapsed > tick)
        {
            rendered->currentFrame++;
            animation->elapsed = 0;
        }

        //Reset the current animation if we've gone over
        if(rendered->currentFrame >= s->numFrames || s->numFrames == 0)
        {
            rendered->currentFrame = 0;
        }
    }
}
