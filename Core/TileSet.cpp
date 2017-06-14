#include "TileSet.h"
#include <iostream>
#include <SDL2/SDL.h>


/**
 *
 * @param layer
 * @param x
 * @param y
 * @return
 */
int TileSet::getTileTypeAt(int layer, int x, int y)
{
    int height = getHeight(layer),
        layerSize = getLayerSize(layer),
        i = x + (layerSize / height) * y;

    return getTileTypeAt(layer, i);
}


/**
 *
 * @param layer
 * @param i
 * @return
 */
int TileSet::getTileTypeAt(int layer, int i)
{
    if (i >= 0)
    {
        return layers_
            .at((unsigned long) layer)
            .at((unsigned long) i);
    }
    return 207;
}


/**
 *
 * @param layer
 * @return
 */
int TileSet::getLayerSize(int layer)
{
    return tileData_["layers"][layer]["data"].size();
}


/**
 *
 * @param tileData
 * @return
 */
void TileSet::setData(Json::Value tileData)
{
    if (tileData.isNull())
    {
        std::cout << "error: TileSet::setData was passed null tileData" << std::endl;
    }

    tileData_ = tileData;

    layers_.clear();

    std::cout << "loaded tile data with " << getNumLayers() << " layers" << std::endl;

    for (int l = 0; l < getNumLayers(); l++)
    {
        layers_.push_back(std::vector<int>());
        for (int i = 0; i < getLayerSize(l); i++)
        {
            layers_.at((unsigned long) (l)).push_back(tileData_["layers"][l]["data"][i].asInt());
        }
    }
}


/**
 *
 * @return
 */
int TileSet::getHeight(int layer)
{
    return tileData_["layers"][layer]["height"].asInt();
}

/**
 *
 * @return
 */
int TileSet::getWidth(int layer)
{
    return tileData_["layers"][layer]["data"].size() / tileData_["layers"][layer]["height"].asInt();
}


/**
 *
 * @param layer
 * @param tileType
 * @return
 */
Vec2i TileSet::tileSourcePosition(int tileSet, int tileType)
{
    Vec2i sheetSize = tileSetSheetSize(tileSet);
    return Vec2i(
        32 * ((tileType - 1) % sheetSize.x),
        32 * ((tileType - 1) / sheetSize.x)
    );
}


Vec2i TileSet::tileSetTileSize(int tileSet)
{
    return Vec2i(
        tileData_["tilesets"][tileSet]["tilewidth"].asInt(),
        tileData_["tilesets"][tileSet]["tileheight"].asInt()
    );
}


Vec2i TileSet::tileSetSheetSize(int tileSet)
{
    int columns = tileData_["tilesets"][tileSet]["columns"].asInt(),
        tileCount = tileData_["tilesets"][tileSet]["tilecount"].asInt(),
        rows = tileCount / columns;
    return Vec2i(columns, rows);
}

int TileSet::getNumLayers()
{
    return tileData_["layers"].size();
}



