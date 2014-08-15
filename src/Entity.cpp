
#include "Entity.h"
#include <iostream>

void Entity::addComponent(ComponentTypes type, Component *component)
{
    components[type] = component;
}
bool Entity::hasComponents(ComponentTypes mask)
{
    return components.find(mask) != components.end();
}
Component* Entity::getComponentForType(ComponentTypes type)
{
    
    std::map<ComponentTypes, Component*>::iterator item = components.find(type);
    if(item == components.end()) {
        return nullptr;
    }
    return item->second;

}

void Entity::removeComponent(ComponentTypes type)
{
    std::map<ComponentTypes, Component*>::iterator item = components.find(type);

    if(item == components.end()) {
        return;
    }

    if(item->second != nullptr) {
        delete(item->second);
    }
    components.erase(item);
}
