#ifndef CHAOS_TILESET_H
#define CHAOS_TILESET_H

#include <vector>
#include <SDL2/SDL_rect.h>
#include "json/json.h"
#include "Core/vec2i.h"

class TileSet
{
private:
    Json::Value tileData_;
    std::vector<std::vector<int>> layers_;
    int height_, width_;

public:
    int getTileTypeAt(int layer, int x, int y);
    int getTileTypeAt(int layer, int i);
    int getHeight(int layer);
    int getWidth(int layer);
    int getLayerSize(int layer);
    int getNumLayers();
    vec2i tileSourcePosition(int tileSet, int tileType);
    vec2i tileSetSheetSize(int tileSet);
    vec2i tileSetTileSize(int tileSet);

    void setData(Json::Value value);
};


#endif //CHAOS_TILESET_H
