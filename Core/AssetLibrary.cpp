#include <boost/algorithm/string.hpp>
#include <fstream>
#include "AssetLibrary.h"
#include "Error.h"


/**
 *
 * @param name
 * @param filePath
 */
void AssetLibrary::loadTexture(std::string name, std::string filePath)
{
    SDL_Texture *texture = IMG_LoadTexture(renderer_, (basePath_ + filePath).c_str());

    Error::predicate(texture != NULL, "AssetLibrary: cannot load texture");

    textures_[name] = texture;
}


/**
 *
 * @param name
 * @return
 */
SDL_Texture *AssetLibrary::getTexture(std::string name)
{
    return textures_[name];
}


/**
 * set pointer to the renderer, used with loading textures and such
 *
 * @param renderer
 */
void AssetLibrary::setRenderer(SDL_Renderer *renderer)
{
    renderer_ = renderer;
}

