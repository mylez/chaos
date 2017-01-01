#ifndef CHAOS_ASSETLIBRARY_H
#define CHAOS_ASSETLIBRARY_H

#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>


class AssetLibrary
{
public:
    void loadTexture(std::string name, std::string filePath);

    void loadIntTable(std::string name, std::string filePath);

    SDL_Texture *getTexture(std::string name);
    std::vector< std::vector < int > > getIntTable(std::string name);

    void setRenderer(SDL_Renderer *renderer);

private:
    std::unordered_map< std::string, SDL_Texture * > textures_;
    std::unordered_map< std::string, std::vector< std::vector < int > > > intTables_;

    SDL_Renderer *renderer_;

    const std::string basePath_ = "media/";
};


#endif //CHAOS_ASSETLIBRARY_H
