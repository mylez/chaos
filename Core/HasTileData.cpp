#include <fstream>
#include <iostream>
#include "HasTileData.h"


/**
 *
 * @param filePath
 */
void HasTileData::loadTileData(std::string filePath)
{
    Json::Value root;
    Json::Reader reader;
    std::ifstream tileFile(filePath);

    reader.parse(tileFile, root);

    tileData_.setData(root);
    tileFile.close();
}


/**
 *
 * @return
 */
TileData *HasTileData::getTileData()
{
    return &tileData_;
}


/**
 *
 * @return
 */
SDL_Texture *HasTileData::getTileTexture()
{
    return tileTexture_;
}