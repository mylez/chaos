#include <boost/algorithm/string.hpp>
#include <fstream>
#include "AssetLibrary.h"


void AssetLibrary::loadTexture(std::string name, std::string filePath)
{
    SDL_Texture *texture = IMG_LoadTexture(this->renderer, (this->basePath + filePath).c_str());
    this->textures[name] = texture;
}


void AssetLibrary::loadIntTable(std::string name, std::string filePath)
{
    std::ifstream intTableFile;
    intTableFile.open(filePath);

    this->intTables[name].empty();

    while (!intTableFile.eof())
    {
        std::string line;
        std::vector<std::string> elements;
        std::vector<int> tiles;

        getline(intTableFile, line);
        boost::split(elements, line, boost::is_any_of(","));

        for (unsigned long i = 0; i < elements.size(); i++)
        {
            std::string num = elements.at(i);
            if (num.length())
            {
                tiles.push_back(atoi(num.c_str()));
            }
        }

        if (tiles.size() > 0)
        {
            this->intTables[name].push_back(tiles);
        }
    }

    intTableFile.close();
}


SDL_Texture *AssetLibrary::getTextureAsset(std::string name)
{
    return this->textures[name];
}


std::vector< std::vector < int > > AssetLibrary::getIntTable(std::string name)
{
    return this->intTables[name];
}


void AssetLibrary::setRenderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

