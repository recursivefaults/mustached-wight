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
        void addComponent(ComponentTypes type, Component *component);
        bool hasComponents(ComponentTypes mask);
        Component* getComponentForType(ComponentTypes type);
        void removeComponent(ComponentTypes type);
        int getId() {return _id;};
    protected:
        std::map<ComponentTypes, Component*> components;
        int _id;
    private:
};

#endif
