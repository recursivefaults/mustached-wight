
#include "Entity.h"

void Entity::addComponent(ComponentFlags type, Component *component)
{
    components[type] = component;
    componentMask |= type;
}
bool Entity::hasCompoenents(ComponentFlags mask)
{
    return componentMask & mask;
}
Component* Entity::getComponentForType(ComponentFlags type)
{
    
    std::map<ComponentFlags, Component*>::iterator item = components.find(type);
    if(item == components.end()) {
        return nullptr;
    }
    return item->second;

}

void Entity::removeComponent(ComponentFlags type)
{
    std::map<ComponentFlags, Component*>::iterator item = components.find(type);

    if(item == components.end()) {
        return;
    }

    if(item->second != nullptr) {
        delete(item->second);
    }
    components.erase(item);
    
    componentMask |= ~type;
}
