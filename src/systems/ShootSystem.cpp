#include "ShootSystem.h"
#include "../Components.h"
#include "../EntityFactory.h"

#include <iostream>

void ShootSystem::update(int elapsedTimeMS, World &world)
{
    EntityFactory factory;
    for(auto entities : world.entities)
    {
        PlayerInput *input = world.playerInputs[entities.first];
        Collidable *collidable = world.collidables[entities.first];
        Ammunition *ammo = world.ammunitions[entities.first];
        WeaponStat *weapon = world.weaponStats[entities.first];

        if(ammo == nullptr || weapon == nullptr || input == nullptr)
        {
            continue;
        }

        //Pre-checks
        if(ammo->count == 0) {
            continue;
        }

        weapon->elapsedShotTimeMS += elapsedTimeMS;
        
        if(weapon->elapsedShotTimeMS < weapon->fireRateMS)
        {
            continue;
        }

        if(input->input[PlayerActions::shoot] == true)
        {
            Position *p = new Position();
            AABB player = collidable->boxes.front();
            p->x = player.cx + player.rw;
            p->y = player.cy;
            factory.createBullet(world, p, *weapon);
            weapon->elapsedShotTimeMS = 0;
        }
    }
    
}
