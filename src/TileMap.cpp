#include "TileMap.h"
#include <iostream>

TileMap::TileMap(Graphics &graphics) : currentMap("Map1.json", graphics)
{
}

bool TileMap::solidTest(int tileId)
{
    int column =  tileId % 8;
    int row = tileId / 8;
    if(row < 6 && column < 4)
        return true;

    return false;
}

void TileMap::render(Graphics &graphics)
{
    SDL_Rect tileLocation;
    SDL_Rect sourceLocation;
    tileLocation.w = currentMap.sprite->tileWidth;
    tileLocation.h = currentMap.sprite->tileHeight;
    sourceLocation.w = currentMap.sprite->tileWidth;
    sourceLocation.h = currentMap.sprite->tileHeight;
    int row, column = 0;
    int rowInSpriteSheet, columnInSpriteSheet = 0;
    int layerW = 0;
    int layerH = 0;
    for(auto layer : *currentMap.getLayers())
    {
        layerW = layer->widthInTiles;
        layerH = layer->heightInTiles;
        for(int i = 0; i < layerW * layerH; ++i)
        {
            TileData *tile = layer->data[i];
            int id = tile->tileId;
            if(id > 0) {
                --id;
            } else {
                continue;
            }

            columnInSpriteSheet = id % 8;
            rowInSpriteSheet = id / 8;

            tileLocation.x = tile->x;
            tileLocation.y = tile->y;
            sourceLocation.x = columnInSpriteSheet * tileLocation.w;
            sourceLocation.y = rowInSpriteSheet * tileLocation.h;

            graphics.drawTexture(currentMap.sprite->texture, &tileLocation, &sourceLocation);
        }
    }
}

