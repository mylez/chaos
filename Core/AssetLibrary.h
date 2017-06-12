#ifndef CHAOS_ASSETLIBRARY_H
#define CHAOS_ASSETLIBRARY_H

#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include "Graphics.h"

class AssetLibrary
{
public:
    void loadTexture(std::string name, std::string filePath);

    SDL_Texture *getTexture(std::string name);

    void setRenderer(SDL_Renderer *renderer);

    SDL_Renderer *renderer_;
private:
    std::unordered_map< std::string, SDL_Texture * > textures_;
    const std::string basePath_ = "";
};


#endif //CHAOS_ASSETLIBRARY_H
