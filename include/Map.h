#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

#include "../graphics.h"
#include "Layer.h"
#include "TileSprite.h"


class Map
{
    public:
        Map(const std::string mapName, Graphics &graphics);
        std::vector<Layer *> *getLayers() {return &layers;};
        TileData* tileForPosition(int x, int y, int layerNumber = 0);
        TileSprite *sprite;
    protected:
    private:
        std::vector<Layer *> layers;
};

#endif
