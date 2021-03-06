#ifndef LAYER_H
#define LAYER_H

#include "TileSprite.h"
#include <vector>

struct TileData
{
    int tileId;
    int x, y, w, h, cx, cy;

};

struct Layer
{
        int priority;
        int widthInTiles;
        int heightInTiles;
        std::vector< std::vector< TileData *> > data;
};


#endif
