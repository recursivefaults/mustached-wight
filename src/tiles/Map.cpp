#include "Map.h"
#include "json/json.h"
#include "../asset_helper.h"
#include <fstream>

#include <iostream>

Map::Map(const std::string mapName, Graphics &graphics)
{

    AssetHelper h;
    Json::Value document;
    Json::Reader r;
    std::ifstream stream(h.fullAssetPathForFile(mapName), std::ifstream::in);
    SDL_assert(r.parse(stream, document) == true);

    //We have the base document, lets build the sprite.
    sprite = new TileSprite();
    sprite->tileWidth = document["tilewidth"].asInt();
    sprite->tileHeight = document["tileheight"].asInt();
    sprite->texture = h.loadNamedTexture(document["tilesets"][0]["image"].asString(), graphics);

    //Now for layers
    int count = 0;
    for(auto blob : document["layers"])
    {
        Layer *l = new Layer();
        l->widthInTiles = blob["width"].asInt();
        l->heightInTiles = blob["height"].asInt();
        l->priority = count++;
        int dataCounter = 0;
        for(auto id : blob["data"])
        {
            TileData *tile = new TileData();
            tile->tileId = id.asInt();
            tile->x = sprite->tileWidth * (dataCounter % l->widthInTiles);
            tile->y = sprite->tileHeight * (dataCounter / l->widthInTiles);
            tile->cx = tile->x + sprite->tileWidth/2;
            tile->cy = tile->y + sprite->tileHeight/2;
            tile->h = sprite->tileHeight;
            tile->w = sprite->tileWidth;
            l->data.push_back(tile);
            dataCounter++;
        }

        layers.push_back(l);
    }
}

TileData* Map::tileForPosition(int x, int y, int layerNumber)
{
    if(x < 0 || y < 0 || x > 640 || y > 480) {
        return nullptr;
    }
    Layer *layer = layers[layerNumber];

    //Convert x and y into tile offset
    //
    int column = x / sprite->tileWidth;
    int row = y / sprite->tileHeight * layer->widthInTiles;

    TileData *d = layer->data[column + row];
    SDL_assert(d->cx - sprite->tileWidth/2 <= x);
    SDL_assert(d->cx + sprite->tileWidth/2 >= x);
    SDL_assert(d->cy - sprite->tileHeight/2 <= y);
    SDL_assert(d->cy + sprite->tileHeight/2 >= y);

    return d;
}
