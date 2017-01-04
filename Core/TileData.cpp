#include "TileData.h"
#include <iostream>
#include <SDL2/SDL.h>


/**
 *
 * @param layer
 * @param x
 * @param y
 * @return
 */
int TileData::getTileTypeAt(int layer, int x, int y)
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
int TileData::getTileTypeAt(int layer, int i)
{
    return tileData_["layers"][layer]["data"][i].asInt();
}


/**
 *
 * @param layer
 * @return
 */
int TileData::getLayerSize(int layer)
{
    return tileData_["layers"][layer]["data"].size();
}


/**
 *
 * @param tileData
 * @return
 */
void TileData::setData(Json::Value tileData)
{
    if (tileData.isNull())
    {
        std::cout << "error: TileData::setData was passed null tileData" << std::endl;
    }
    tileData_ = tileData;
}


/**
 *
 * @return
 */
int TileData::getHeight(int layer)
{
    return tileData_["layers"][layer]["height"].asInt();
}

/**
 *
 * @return
 */
int TileData::getWidth(int layer)
{
    return tileData_["layers"][layer]["data"].size() / tileData_["layers"][layer]["height"].asInt();
}


/**
 *
 * @param layer
 * @param tileType
 * @return
 */
Vec2I TileData::tileSrcRectPosition(int tileSet, int tileType)
{
    Vec2I sheetSize = tileSetSheetSize(tileSet);
    return Vec2I(
        32 * ((tileType - 1) % sheetSize.x),
        32 * ((tileType - 1) / sheetSize.x)
    );
}





Vec2I TileData::tileSetTileSize(int tileSet)
{
    return Vec2I(
        tileData_["tilesets"][tileSet]["tilewidth"].asInt(),
        tileData_["tilesets"][tileSet]["tileheight"].asInt()
    );
}




Vec2I TileData::tileSetSheetSize(int tileSet)
{
    int columns = tileData_["tilesets"][tileSet]["columns"].asInt(),
        tileCount = tileData_["tilesets"][tileSet]["tilecount"].asInt(),
        rows = tileCount / columns;
    return Vec2I(columns, rows);
}



