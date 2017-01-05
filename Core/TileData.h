#ifndef CHAOS_TILEDATA_H
#define CHAOS_TILEDATA_H

#include <vector>
#include <SDL2/SDL_rect.h>
#include "json/json.h"
#include "Core/Vec2I.h"

class TileData
{
private:
    Json::Value tileData_;
    std::vector<std::vector<int>> layers_;

public:
    int getTileTypeAt(int layer, int x, int y);
    int getTileTypeAt(int layer, int i);
    int getHeight(int layer);
    int getWidth(int layer);
    int getLayerSize(int layer);
    int getNumLayers();
    Vec2I tileSourcePosition(int tileSet, int tileType);
    Vec2I tileSetSheetSize(int tileSet);
    Vec2I tileSetTileSize(int tileSet);

    void setData(Json::Value value);
};


#endif //CHAOS_TILEDATA_H
