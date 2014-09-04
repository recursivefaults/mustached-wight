#include "ShootSystem.h"
#include "Components.h"
#include "EntityFactory.h"

#include <iostream>

void ShootSystem::update(int elapsedTimeMS, World &world)
{
    EntityFactory factory;
    for(auto entities : world.entities)
    {
        Entity *entity = entities.second;
        if(!entity->hasComponents(ComponentTypes::K_AMMUNITION) || 
                !entity->hasComponents(ComponentTypes::K_WEAPON_STAT) || 
                !entity->hasComponents(ComponentTypes::K_PLAYER_INPUT)) {
                continue;
        }
        PlayerInput *input = static_cast<PlayerInput *>(entity->getComponentForType(ComponentTypes::K_PLAYER_INPUT));
        Collidable *collidable = static_cast<Collidable *>(entity->getComponentForType(ComponentTypes::K_COLLIDABLE));
        Ammunition *ammo = static_cast<Ammunition *>(entity->getComponentForType(ComponentTypes::K_AMMUNITION));
        WeaponStat *weapon = static_cast<WeaponStat *>(entity->getComponentForType(ComponentTypes::K_WEAPON_STAT));


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
