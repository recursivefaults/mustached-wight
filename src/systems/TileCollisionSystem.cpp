#include "TileCollisionSystem.h"
#include "../tiles/Layer.h"
#include <iostream>

void TileCollisionSystem::update(int elapsedTimeMS, World &world)
{
    for(auto ev : world.entities)
    {
        TileMapCollision *tc = world.tileMapCollisions[ev.first];
        Position *p = world.positions[ev.first];
        Velocity *v = world.velocities[ev.first];
        Collidable *collidable = world.collidables[ev.first];
        if(tc == nullptr) {
            continue;
        }

        int tileW = world.map->sprite->tileWidth;
        int tileH = world.map->sprite->tileHeight;

        Layer *foreGround = world.map->getLayers()->back();

        int layerWidthInTiles = foreGround->widthInTiles;
        int layerHeightInTiles = foreGround->heightInTiles;

        //Off by one error
        int newX = p->x + (elapsedTimeMS * v->velX);
        int newY = p->y + (elapsedTimeMS * v->velY);
        
        //Check tiles in a large area where we will be
        int currentXTile = p->x / tileW;
        int currentYTile = p->y / tileH;


        int mapIndex = layerWidthInTiles * currentYTile + currentXTile;

        SDL_assert(mapIndex < layerWidthInTiles * layerHeightInTiles);

        //Player has a velocity need to see if it hits the map
        bool hit = foreGround->data[mapIndex] != 0;

        std::cout << "Player is hitting the ground: " << hit << std::endl;



    }

}
