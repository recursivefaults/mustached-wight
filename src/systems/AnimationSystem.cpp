#include "AnimationSystem.h"
#include <iostream>


void AnimationSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        Entity *entity = ev.second;
        if(!entity->hasComponents(K_ANIMATION))
        {
            continue;
        }


        Animation *animation = static_cast<Animation *>(entity->getComponentForType(K_ANIMATION));
        Rendered *rendered = static_cast<Rendered *>(entity->getComponentForType(K_RENDERED));
        Sprite *s = world.manager.getNamedSprite(rendered->spriteName);

        SDL_assert(animation != nullptr);
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
