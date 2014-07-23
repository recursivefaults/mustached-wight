#ifndef LAYER_H
#define LAYER_H

#include "TileSprite.h"

struct Layer
{
        int priority;
        int widthInTiles;
        int heightInTiles;
        int *data;
};

#endif
