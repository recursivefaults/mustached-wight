#include "TileCollisionSystem.h"
#include "../tiles/Layer.h"
#include <set>
#include <cmath>

#include <iostream>

void TileCollisionSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        TileMapCollision *tc = world.tileMapCollisions[ev.first];
        if(tc == nullptr) {
            continue;
        }

        Position *p = world.positions[ev.first];
        Velocity *v = world.velocities[ev.first];
        Collidable *collidable = world.collidables[ev.first];

        /**
         * 1. Adjust player movement
         * 2. Check 9 tiles around AABB
         * 3. Adjust for collision X then Y
         */
        int deltaX = elapsedTimeMS * v->velX;
        int deltaY = elapsedTimeMS * (v->velY + ZombieWalk::kVelocityDown);
        
         
        int newX = p->x;
        int newY = p->y;

        int tileWidth = world.map->sprite->tileWidth;
        int tileHeight = world.map->sprite->tileHeight;

        std::set<TileData*> tiles;

        TileData *data = world.map->tileForPosition(newX, newY, 2);
        tiles.insert(data);

        //Three above
        tiles.insert(world.map->tileForPosition(newX - tileWidth, newY - tileHeight, 2));
        tiles.insert(world.map->tileForPosition(newX,             newY - tileHeight, 2));
        tiles.insert(world.map->tileForPosition(newX + tileWidth, newY - tileHeight, 2));

        //Two around
        tiles.insert(world.map->tileForPosition(newX - tileWidth, newY, 2));
        tiles.insert(world.map->tileForPosition(newX + tileWidth, newY, 2));
        
        //Three below
        tiles.insert(world.map->tileForPosition(newX - tileWidth, newY + tileHeight, 2));
        tiles.insert(world.map->tileForPosition(newX,             newY + tileHeight, 2));
        tiles.insert(world.map->tileForPosition(newX + tileWidth, newY + tileHeight, 2));


        for(auto tile : tiles)
        {
            if(tile == nullptr)
                continue;
            if(tile->tileId == 0)
                continue;
            AABB tileBox;
            tileBox.minX = tile->x;
            tileBox.maxX = tile->x + tileWidth;
            tileBox.minY = tile->y;
            tileBox.maxY = tile->y + tileHeight;

            AABB player = collidable->boxes.front();

            player.minX += newX;
            player.maxX += newX;
            player.minY += newY;
            player.maxY += newY;

            if(didCollide(player, tileBox))
            {
                if(deltaX > 0)
                {
                    p->x = tileBox.minX - (player.maxX - player.minX + 1);
                    v->velX = 0;
                }
                if(deltaX < 0)
                {
                    p->x = tileBox.maxX + (player.maxX - player.minX + 1);
                    v->velX = 0;
                }
                if(deltaY > 0)
                {
                    p->y = tileBox.minY - (player.maxY - player.minY + 1);
                    v->velY = 0;
                }
                if(deltaY < 0)
                {
                    p->y = tileBox.maxY + (player.maxY - player.minY + 1);
                    v->velY = 0;
                }
            }
        }

    }

}


bool TileCollisionSystem::didCollide(AABB &one, AABB &two)
{
    if((two.minX > one.minX && two.minX < one.maxX) ||
            (two.maxX > one.minX && two.maxX < one.maxX))
    {
        if((two.minY > one.minY && two.minY < one.maxY) ||
                (two.maxY > one.minY && two.maxY < one.maxY))
        {
            std::cout << "Collide" << std::endl;
            return true;
        }
    }
    return false;
}

std::vector<AABB>* TileCollisionSystem::getUpdatedBoxes(Collidable *c, int deltaX, int deltaY)
{
        std::vector<AABB> *updatedBoxes = new std::vector<AABB>();
        for(auto box : c->boxes)
        {
            AABB updated = box;
            
            //Down
            if(deltaY > 0)
            {
                updated.maxY = deltaY + box.maxY;
            }

            //Up
            if(deltaY < 0)
            {
                updated.minY = deltaY + box.minY;
            }

            //Left
            if(deltaX < 0)
            {
                updated.minX = deltaX + box.minX;
            }

            //Right
            if(deltaX > 0)
            {
                updated.maxX = deltaX + box.maxX;
            }
            updatedBoxes->push_back(updated);
        }

        return updatedBoxes;
}

