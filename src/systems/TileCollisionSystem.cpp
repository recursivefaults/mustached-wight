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

        AABB &player = collidable->boxes.front();
        int newX = player.cx;
        int newY = player.cy;

        int tileWidth = world.map->sprite->tileWidth;
        int tileHeight = world.map->sprite->tileHeight;

        TileData *myTile = world.map->tileForPosition(newX, newY, 2);
        TileData *downTile = world.map->tileForPosition(myTile->cx, myTile->cy + tileHeight, 2);

        if(myTile == nullptr)
        {
            std::cout << "No tile at " << newX << ", " << newY << std::endl;
            continue;
        }

        std::vector<TileData *> broadPhase; 

        //3 Above
        broadPhase.push_back(world.map->tileForPosition(myTile->cx - tileWidth, myTile->cy - tileHeight, 2));
        broadPhase.push_back(world.map->tileForPosition(myTile->cx, myTile->cy - tileHeight, 2));
        broadPhase.push_back(world.map->tileForPosition(myTile->cx + tileWidth, myTile->cy - tileHeight, 2));

        //Two on the side
        broadPhase.push_back(world.map->tileForPosition(myTile->cx + tileWidth, myTile->cy));


        broadPhase.push_back(world.map->tileForPosition(myTile->cx - tileWidth, myTile->cy));

        //2 Below
        broadPhase.push_back(world.map->tileForPosition(myTile->cx - tileWidth, myTile->cy + tileHeight, 2));
        broadPhase.push_back(world.map->tileForPosition(myTile->cx + tileWidth, myTile->cy + tileHeight, 2));
        broadPhase.push_back(downTile);

        //Last is my own tile
        broadPhase.push_back(myTile);

        Vector2d collision(0,0);

        for(auto tile : broadPhase) 
        {
            if(tile == nullptr)
            {
                continue;
            }
            AABB tileBox(tile->cx, tile->cy, tileWidth/2, tileHeight/2);
            if(myTile->tileId != 0 && collideWithTile(tileBox, collidable, collision))
            {
                if(v->velX != 0)
                {
                    std::cout << "Bumping in x by :" << collision._x << std::endl;
                    p->x -= collision._x;
                    player.cx -= collision._x;
                    v->velX = 0;
                }
                if(v->velY != 0)
                {
                    std::cout << "Bumping in y by : " << collision._y << std::endl;
                    p->y += collision._y;
                    player.cy += collision._y;
                    v->velY = 0;
                }

            }
            world.debugBoxes.push_back(new AABB(tileBox.cx, tileBox.cy, tileBox.rw, tileBox.rh));
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

