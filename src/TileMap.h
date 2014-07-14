#ifndef TILEMAP_H
#define TILEMAP_H

#include <map>

#include "zombie_walk.h"
#include "asset_helper.h"
#include "graphics.h"

struct MapIndex {
    int xOffset;
    int yOffset;
};

class TileMap
{
    public:
        TileMap(Graphics &graphics);
        ~TileMap();
        void render(Graphics &graphics);
    protected:
    private:
        SDL_Texture *texture;
        AssetHelper assetHelper;
        std::map<int, MapIndex> idData;
        static int mapData[30][60];
};


#endif

