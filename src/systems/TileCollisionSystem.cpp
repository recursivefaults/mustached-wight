#include "TileCollisionSystem.h"
#include "Layer.h"
#include <set>
#include <cmath>

#include <iostream>

void TileCollisionSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        Entity *entity = ev.second;
        if(!entity->hasComponents(ComponentTypes::K_TILE_MAP_COLLISION)) {
            continue;
        }
        TileMapCollision *tc = static_cast<TileMapCollision *>(entity->getComponentForType(ComponentTypes::K_TILE_MAP_COLLISION));
        Position *p = static_cast<Position *>(entity->getComponentForType(ComponentTypes::K_POSITION));
        Velocity *v = static_cast<Velocity *>(entity->getComponentForType(ComponentTypes::K_VELOCITY));
        Collidable *collidable = static_cast<Collidable *>(entity->getComponentForType(ComponentTypes::K_COLLIDABLE));

        /**
         * 1. Adjust player movement
         * 2. Check 9 tiles around AABB
         * 3. Adjust for collision X then Y
         */

        AABB &player = collidable->boxes.front();
        int newX = player.cx;
        int newY = player.cy;

        int tileWidth = world.map->sprite->tileWidth;
        int tileHeight = world.map->sprite->tileHeight;

        std::vector<TileData *> *broadPhase = getBroadPhaseTiles(newX, newY, world);
        TileData *myTile = world.map->tileForPosition(newX, newY, 2);
        TileData *downTile = world.map->tileForPosition(myTile->cx, myTile->cy + tileHeight, 2);

        Vector2d collision(0,0);

        for(auto tile : *broadPhase) 
        {
            if(tile == nullptr)
            {
                continue;
            }
            AABB tileBox(tile->cx, tile->cy, tileWidth/2, tileHeight/2);
            if(myTile->tileId != 0 && collideWithTile(tileBox, collidable, collision))
            {
                int mod = -1;
                if(v->velX != 0)
                {
                    if(v->velX > 0)
                    {
                        mod *= -1;
                    } 

                    p->x += collision._x * mod;
                    player.cx += collision._x * mod;
                    v->velX = 0;
                }
                mod = -1;
                if(v->velY != 0)
                {
                    if(v->velY > 0)
                    {
                        mod *= -1;
                    }
                    p->y += collision._y * mod;
                    player.cy += collision._y * mod;
                    v->velY = 0;
                }

                world.debugBoxes.push_back(new AABB(tileBox.cx, tileBox.cy, tileBox.rw, tileBox.rh));
            }
        }

        if(downTile->tileId == 0)
        {
            //Fall!
            v->velY = ZombieWalk::kVelocityDown;
        }
        
        /**
         * Push aabbs to debug drawing
         */
        world.debugBoxes.push_back(new AABB(player.cx, player.cy, player.rw, player.rh));
    }

}

bool TileCollisionSystem::collideWithTile(AABB &t, Collidable *c, Vector2d &collision)
{
            AABB &player = c->boxes.front();
            return player.didSimpleCollide(t, collision);
}


std::vector<TileData *>* TileCollisionSystem::getBroadPhaseTiles(int x, int y, World &world) {
        std::vector<TileData *> *broadPhase = new std::vector<TileData *>();

        int tileWidth = world.map->sprite->tileWidth;
        int tileHeight = world.map->sprite->tileHeight;

        TileData *myTile = world.map->tileForPosition(x, y, 2);
        TileData *downTile = world.map->tileForPosition(myTile->cx, myTile->cy + tileHeight, 2);

        //3 Above
        broadPhase->push_back(world.map->tileForPosition(myTile->cx - tileWidth, myTile->cy - tileHeight, 2));
        broadPhase->push_back(world.map->tileForPosition(myTile->cx, myTile->cy - tileHeight, 2));
        broadPhase->push_back(world.map->tileForPosition(myTile->cx + tileWidth, myTile->cy - tileHeight, 2));

        //Two on the side
        broadPhase->push_back(world.map->tileForPosition(myTile->cx + tileWidth, myTile->cy));


        broadPhase->push_back(world.map->tileForPosition(myTile->cx - tileWidth, myTile->cy));

        //2 Below
        broadPhase->push_back(world.map->tileForPosition(myTile->cx - tileWidth, myTile->cy + tileHeight, 2));
        broadPhase->push_back(world.map->tileForPosition(myTile->cx + tileWidth, myTile->cy + tileHeight, 2));
        broadPhase->push_back(downTile);

        //Last is my own tile
        broadPhase->push_back(myTile);
        return broadPhase;
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

