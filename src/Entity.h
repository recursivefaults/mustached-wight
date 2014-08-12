#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

static int STATIC_COUNTER = 0;
#include <map>
#include "Components.h"

class Entity
{
    public:
        Entity(int id) : _id(id) {};
        Entity(): _id(STATIC_COUNTER++) {};
        ~Entity() {};
        void addComponent(ComponentFlags type, Component *component);
        bool hasComponents(ComponentFlags mask);
        Component* getComponentForType(ComponentFlags type);
        void removeComponent(ComponentFlags type);
        int getId() {return _id;};
    protected:
        std::map<ComponentFlags, Component*> components;
        int _id;
    private:
        ComponentFlags componentMask;
};

#endif
