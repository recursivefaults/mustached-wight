#ifndef LAYER_H
#define LAYER_H

#include "TileSprite.h"
#include <vector>

struct TileData
{
    int tileId;
    int x, y, w, h;
};

struct Layer
{
        int priority;
        int widthInTiles;
        int heightInTiles;
        std::vector<TileData *> data;
};


#endif
