#ifndef SYSTEM_H
#define SYSTEM_H

#include "../World.h"

class System
{
    public:
        System(int priority) : _priority(priority) {};
        virtual ~System() {};
        int getPriority() {return _priority;};
        virtual void update(int elapsedTimeMS, World &world) = 0;
    protected:
        int _priority;
    private:
};

#endif
