#include "SystemFactory.h"
#include "PlayerInputSystem.h"
#include "PhysicsSystem.h"
#include "TileCollisionSystem.h"
#include "AnimationSystem.h"
#include "JumpSystem.h"
#include "WalkSystem.h"
#include "ShootSystem.h"

std::vector<System *> *SystemFactory::createSystems()
{
    std::vector<System *> *systems = new std::vector<System *>();
    systems->push_back(new PlayerInputSystem(1));
    //systems->push_back(new JumpSystem(2));
    systems->push_back(new WalkSystem(2));
    //systems->push_back(new ShootSystem(2));
    systems->push_back(new AnimationSystem(3));
    //systems->push_back(new PhysicsSystem(5));
    //systems->push_back(new TileCollisionSystem(4));
    return systems;
}
