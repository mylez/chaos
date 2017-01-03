#include "TileData.h"


/**
 *
 * @param layer
 * @param x
 * @param y
 * @return
 */
int TileData::getTileTypeAt(int layer, int x, int y)
{
    return -1;
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
 * @param tileData
 * @return
 */
void TileData::setData(Json::Value tileData)
{
    tileData_ = tileData;
}