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
        void addComponent(int type, Component *component);
        bool hasCompoenents(int mask);
        Component* getComponentForType(int type);
        int getId() {return _id;};
    protected:
        std::map<int, Component*> components;
        int _id;
};

#endif
