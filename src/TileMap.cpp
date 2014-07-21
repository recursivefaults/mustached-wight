#include "TileMap.h"
#include <iostream>

namespace 
{
    int kTileSize = 16;
    int kTileBoundary = 128/kTileSize;
}


int TileMap::mapData[30][60] = {
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 4, 4, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 4, 4, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56},
        {56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56,56, 56, 56, 56, 56, 56, 56, 56, 56, 56}
};

TileMap::TileMap(Graphics &graphics)
{
    texture = assetHelper.loadNamedTexture("mininicular.png", graphics);
    int counter = 0;
    for(int i = 0; i < kTileBoundary; ++i) {
        for(int j = 0; j < kTileBoundary; ++j) {
            MapIndex d;
            d.xOffset = kTileSize * j;
            d.yOffset = kTileSize * i;
            
            idData[counter++] = d;
            std::cout << "Set id: " << counter << std::endl;
        }
    }
}
TileMap::~TileMap()
{
    SDL_DestroyTexture(texture);
}
void TileMap::render(Graphics &graphics)
{
    SDL_Rect tileLocation;
    tileLocation.w = kTileSize;
    tileLocation.h = kTileSize;
    SDL_Rect sourceLocation;
    sourceLocation.w = kTileSize;
    sourceLocation.h = kTileSize;
    for(int i = 0; i < 30; ++i) {
        for(int j = 0; j < 60; ++j) {
            tileLocation.x = kTileSize * j;
            tileLocation.y = kTileSize * i;
            MapIndex index = idData[mapData[i][j]];
            sourceLocation.x = index.xOffset;
            sourceLocation.y = index.yOffset;
            graphics.drawTexture(texture, &tileLocation, &sourceLocation);
        }
    }
}