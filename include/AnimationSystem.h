#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include "System.h"

class AnimationSystem : public System
{
    public:
        AnimationSystem(int priority) : System(priority) {};
        void update(int elapsedTimeMS, World &world);
    protected:
    private:
};

#endif
