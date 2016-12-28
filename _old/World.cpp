#include <SDL2/SDL_image.h>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "World.h"


void World::render(SDL_Renderer *renderer)
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            SDL_Rect
                srcRect = this->tileRect(this->mapData.at(j).at(i)),
                dstRect = {32 * i, 32 * j, 32, 32};
            SDL_RenderCopy(renderer, this->tileTexture, &srcRect, &dstRect);
        }
    }
}


World::World(SDL_Renderer *renderer)
{
    this->tileTexture = IMG_LoadTexture(renderer, "media/level-png/map-tile-island-8x8.png");
    this->loadMapData("media/level-csv/island-terrain.csv", this->mapData);
}


SDL_Rect World::tileRect(int tile)
{
    int width = TILESET_WIDTH,
        xPos = tile % width,
        yPos = (1 + tile - xPos) / width;
    return SDL_Rect {xPos * TILE_SIZE, yPos * TILE_SIZE, TILE_SIZE, TILE_SIZE};
}


void World::loadMapData(const char *filename, std::vector< std::vector< int > > &vec)
{
    std::ifstream mapDataFile;
    mapDataFile.open(filename);

    assert(mapDataFile.is_open());

    vec.empty();

    while (!mapDataFile.eof())
    {
        std::string line;
        std::vector<std::string> elements;
        std::vector<int> tiles;

        getline(mapDataFile, line);
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
            vec.push_back(tiles);
        }
    }

    mapDataFile.close();
}

