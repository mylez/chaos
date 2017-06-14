#ifndef CHAOS_ASSETLIBRARY_H
#define CHAOS_ASSETLIBRARY_H

#include <Core/Vec2i.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include "Graphics.h"

class AssetLibrary
{
private:
    std::unordered_map<std::string, SDL_Texture *> textures_;

    const std::string basePath_ = "";

public:
    void loadTexture(std::string name, std::string filePath);

    SDL_Texture *getTexture(std::string name);

    Vec2i getTextureSize(std::string name);

    void setRenderer(SDL_Renderer *renderer);

    SDL_Renderer *renderer_;
};


#endif //CHAOS_ASSETLIBRARY_H
