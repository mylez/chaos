#include <boost/algorithm/string.hpp>
#include <fstream>
#include "AssetLibrary.h"


/**
 *
 * @param name
 * @param filePath
 */
void AssetLibrary::loadTexture(std::string name, std::string filePath)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer_, (basePath_ + filePath).c_str());
    this->textures_[name] = texture;
}


/**
 *
 * @param name
 * @param filePath
 */
void AssetLibrary::loadIntTable(std::string name, std::string filePath)
{
    // no csv
}

/**
 *
 * @param name
 * @return
 */
SDL_Texture *AssetLibrary::getTextureAsset(std::string name)
{
    return textures_[name];
}


/**
 *
 * @param name
 * @return
 */
std::vector< std::vector < int > > AssetLibrary::getIntTable(std::string name)
{
    return intTables_[name];
}


/**
 *
 * @param renderer
 */
void AssetLibrary::setRenderer(SDL_Renderer *renderer)
{
    renderer_ = renderer;
}

