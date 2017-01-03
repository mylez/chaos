#ifndef CHAOS_TILEDATA_H
#define CHAOS_TILEDATA_H

#include "json/json.h"


class TileData
{
private:
    Json::Value tileData_;
public:
    int getTileTypeAt(int layer, int x, int y);
    int getTileTypeAt(int layer, int i);

    void setData(Json::Value value);
};


#endif //CHAOS_TILEDATA_H
