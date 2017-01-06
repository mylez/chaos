#include <fstream>
#include <iostream>
#include "HasTileSet.h"


/**
 *
 * @param filePath
 */
void HasTileSet::loadTileSet(std::string filePath)
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
TileSet *HasTileSet::getTileSet()
{
    return &tileData_;
}


/**
 *
 * @return
 */
SDL_Texture *HasTileSet::getTileTexture()
{
    return tileTexture_;
}