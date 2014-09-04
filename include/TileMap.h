#ifndef TILEMAP_H
#define TILEMAP_H

#include <map>

#include "zombie_walk.h"
#include "asset_helper.h"
#include "graphics.h"
#include "tiles/Map.h"

class TileMap
{
    public:
        TileMap(Graphics &graphics);
        void render(Graphics &graphics);
        Map *getMap() {return &currentMap;};
        TileData* tileForPosition(int x, int y);
    protected:
    private:
        bool solidTest(int tileId);
        Map currentMap;
};


#endif

