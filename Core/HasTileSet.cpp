#include <fstream>
#include <iostream>
#include "HasTileSet.h"
#include "Err.h"
#include "AssetLibrary.h"
#include "Sprite.h"


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

    Err::predicate(!root.isNull(), "HasTileSet: cannot parse tile set");

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


/**
 *
 * @param texture
 */
void HasTileSet::setTileTexture(SDL_Texture *texture)
{
    tileTexture_ = texture;
}


