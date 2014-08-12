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
        void addComponent(uint type, Component *component);
        bool hasCompoenents(uint mask);
        Component* getComponentForType(uint type);
        void removeComponent(uint type);
        int getId() {return _id;};
    protected:
        std::map<uint, Component*> components;
        int _id;
    private:
        uint componentMask;
};

#endif
