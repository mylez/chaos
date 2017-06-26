#ifndef CHAOS_TERRAINLAYERCOMPONENT_H
#define CHAOS_TERRAINLAYERCOMPONENT_H

#include <Core/Component.h>
#include <Core/Sprite.h>
#include <Core/include/jsoncpp/dist/json/json.h>
#include <fstream>

struct TerrainLayer
{
    int
        height,
        width;

    double
        x,
        y,
        opacity;

    std::string
        name,
        type;

    bool
        visible;

    std::vector<int> data;
};

struct Tile
{
    // not done yet
};

struct TileSet
{
    int
        columns,
        firstGid,
        imageHeight,
        imageWidth,
        margin,
        spacing,
        tileCount,
        tileHeight,
        tileWidth;

    std::unordered_map<int, Tile>
        tileSets;
};

class TerrainLayerComponent:
    public Component
{
public:
    int height,
        width,
        tileHeight,
        tileWidth,
        version;

    std::string
        orientation,
        renderOrder;

    std::vector<Sprite>
        sprites;

    std::vector<TerrainLayer>
        layers;

    std::vector<TileSet>
        tileSets;

    TerrainLayerComponent()
    { label = COMPONENT_TERRAIN_LAYER; }


    /**
     *
     * @param path
     */
    void loadTerrainData(std::string path)
    {
        Json::Value terrainData;
        std::ifstream file(path);
        file >> terrainData;
        parseJsonValue(terrainData);
        file.close();
        terrainData.clear();
    }


    /**
     *
     * @param root
     */
    void parseJsonValue(Json::Value root)
    {

        height          = root["height"].asInt();
        width           = root["width"].asInt();
        tileHeight      = root["tileHeight"].asInt();
        tileWidth       = root["tileWidth"].asInt();
        orientation     = root["orientation"].asString();
        renderOrder     = root["renderorder"].asString();

        for (int i = 0; i < root["layers"].size(); i++)
        {
            TerrainLayer terrainLayer;
            Json::Value raw = root["layers"][i];

            terrainLayer.height     = raw["height"].asInt();
            terrainLayer.width      = raw["width"].asInt();
            terrainLayer.name       = raw["name"].asString();
            terrainLayer.opacity    = raw["opacity"].asDouble();
            terrainLayer.visible    = raw["visible"].asBool();
            terrainLayer.width      = raw["width"].asInt();
            terrainLayer.x          = raw["x"].asInt();
            terrainLayer.y          = raw["y"].asInt();

            for (int j = 0; j < raw["data"].size(); j++)
            {
                terrainLayer.data.push_back(raw["data"][i].asInt());
            }
        }

        for (int i = 0; i < root["tilesets"].size(); i++)
        {
            TileSet tileSet;
            Json::Value raw = root["tilesets"][i];

            tileSet.columns         = raw["columns"].asInt();
            tileSet.imageHeight     = raw["imageheight"].asInt();
            tileSet.imageWidth      = raw["imagewidth"].asInt();
            tileSet.margin          = raw["margin"].asInt();
            tileSet.spacing         = raw["spacing"].asInt();
            tileSet.tileCount       = raw["tilecount"].asInt();
            tileSet.tileHeight      = raw["tileheight"].asInt();
            tileSet.tileWidth       = raw["tilewidth"].asInt();
            //tileSet.tiles

            tileSets.push_back(tileSet);
        }
    }
};


#endif //CHAOS_TERRAINLAYERCOMPONENT_H
