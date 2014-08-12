
#include "Entity.h"

void Entity::addComponent(uint type, Component *component)
{
    components[type] = component;
    componentMask |= type;
}
bool Entity::hasCompoenents(uint mask)
{
    return componentMask & mask;
}
Component* Entity::getComponentForType(uint type)
{
    
    std::map<uint, Component*>::iterator item = components.find(type);
    if(item == components.end()) {
        return nullptr;
    }
    return item->second;

}

void Entity::removeComponent(uint type)
{
    std::map<uint, Component*>::iterator item = components.find(type);

    if(item == components.end()) {
        return;
    }

    if(item->second != nullptr) {
        delete(item->second);
    }
    components.erase(item);
    
    componentMask |= ~type;
}
