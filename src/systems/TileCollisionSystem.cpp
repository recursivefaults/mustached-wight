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
        //tiles.insert(world.map->tileForPosition(data->cx - tileWidth, data->cy - tileHeight, 2));
        //tiles.insert(world.map->tileForPosition(data->cx,             data->cy - tileHeight, 2));
        //tiles.insert(world.map->tileForPosition(data->cx + tileWidth, data->cy - tileHeight, 2));

        //Two around
        //tiles.insert(world.map->tileForPosition(data->cx - tileWidth, data->cy, 2));
        //tiles.insert(world.map->tileForPosition(data->cx + tileWidth, data->cy, 2));
        
        //Three below
        //tiles.insert(world.map->tileForPosition(data->cx - tileWidth, data->cy + tileHeight, 2));
        //tiles.insert(world.map->tileForPosition(data->cx,             data->cy + tileHeight, 2));
        //tiles.insert(world.map->tileForPosition(data->cx + tileWidth, data->cy + tileHeight, 2));


        for(auto tile : tiles)
        {
            if(tile == nullptr)
                continue;
            if(tile->tileId == 0)
                continue;
            AABB tileBox(tile->cx, tile->cy, tileWidth/2, tileHeight/2);

            AABB &player = collidable->boxes.front();

            SDL_assert(player.cx == p->x + 16);
            SDL_assert(player.cy == p->y + 10);

            Vector2d collision(0, 0);

            if(player.didSimpleCollide(tileBox, collision))
            {
                if(deltaX > 0)
                {
                    p->x += collision._x;
                    collidable->boxes.front().cx += collision._x;
                }
                if(deltaY > 0)
                {
                    std::cout << "Adjusting p->y by : " << collision._y << std::endl;
                    p->y += collision._y - player.rh;
                    collidable->boxes.front().cy += collision._y - player.rh;
                    v->velY = -ZombieWalk::kVelocityDown;
                }

            }
        }

    }

}

std::vector<AABB>* TileCollisionSystem::getUpdatedBoxes(Collidable *c, int deltaX, int deltaY)
{
        std::vector<AABB> *updatedBoxes = new std::vector<AABB>();
        for(auto box : c->boxes)
        {
            AABB updated = box;
            
            //Down
//            if(deltaY > 0)
//            {
//                updated.maxY = deltaY + box.maxY;
//            }
//
//            //Up
//            if(deltaY < 0)
//            {
//                updated.minY = deltaY + box.minY;
//            }
//
//            //Left
//            if(deltaX < 0)
//            {
//                updated.minX = deltaX + box.minX;
//            }
//
//            //Right
//            if(deltaX > 0)
//            {
//                updated.maxX = deltaX + box.maxX;
//            }
//            updatedBoxes->push_back(updated);
        }

        return updatedBoxes;
}

