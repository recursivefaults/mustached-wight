#include "SystemFactory.h"
#include "PlayerInputSystem.h"
#include "PhysicsSystem.h"
#include "TileCollisionSystem.h"

std::vector<System *> *SystemFactory::createSystems()
{
    std::vector<System *> *systems = new std::vector<System *>();
    systems->push_back(new PlayerInputSystem(1));
    systems->push_back(new TileCollisionSystem(2));
    systems->push_back(new PhysicsSystem(3));
    return systems;
}
