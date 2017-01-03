#include <fstream>
#include "HasTileData.h"


void HasTileData::loadTileData(std::string filePath)
{
    Json::Value root;
    Json::Reader reader;
    std::ifstream tileFile(filePath);
    reader.parse(tileFile, root);

    tileData_.setData(root);
    tileFile.close();
}

TileData *HasTileData::getTileData()
{
    return &tileData_;
}

SDL_Texture *HasTileData::getTileTexture()
{
    return tileTexture_;
}