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

    tileSet_.setData(root);
    tileFile.close();
}


/**
 *
 * @return
 */
TileSet *HasTileSet::getTileSet()
{
    return &tileSet_;
}


/**
 *
 * @return
 */
SDL_Texture *HasTileSet::getTileTexture()
{
    return tileTexture_;
}