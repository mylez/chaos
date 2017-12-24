#ifndef CHAOS_TERRAINLAYERCOMPONENT_H
#define CHAOS_TERRAINLAYERCOMPONENT_H

#include <Core/Component.h>
#include <Core/Sprite.h>
#include <Core/include/jsoncpp/dist/json/json.h>
#include <Core/Error.h>
#include <Core/include/base64/base64.h>
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

struct TileInfo
{
    int type, x, y, layer;
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

    std::string
        name,
        image;
};

class TerrainLayerComponent:
    public Component
{
public:
    int height,
        width,
        numLayers,
        tileHeight,
        tileWidth,
        version;

    bool drawDebugGrid = false;

    //tmx::Map
    //    tmxMap;

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

        Error::predicate(file.is_open(), "unable to open terrain data: " + path);
        file >> terrainData;
        parseJsonValue(terrainData);
        file.close();
        terrainData.clear();
    }

    /**
     *
     * @param l
     * @param x
     * @param y
     * @return
     */
    TileInfo getTileInfoAtIndex(int l, int x, int y)
    {
        int i, s, type, w = layers[l].width, h = layers[l].height;

        if (x < 0 || y < 0 || x > w || y > h)
        {
            return TileInfo{
                -1,
                x < 0 ? 0 : (x > w ? w : x),
                y < 0 ? 0 : (x > w ? w : y),
                l
            };
        }
        else
        {
            i = width * y + x;
            s = layers[l].data.size();
            type = layers[l].data[i] - 1;
            return TileInfo{type, x, y, l};
        }
    }


    /**
     *
     * @param l
     * @param x
     * @param y
     * @return
     */
    TileInfo getTileInfoAtPosition(int l, Vec2d position)
    {
        double  th = tileSets[0].tileHeight,
                tw = tileSets[0].tileWidth;

        position.y *= -1;

        Vec2i
            tileSize(tileSets[0].tileWidth, tileSets[0].tileHeight),
            p = position
                .add(entity->transform.position)
                .add(Vec2i((width)*tileSize.x/2, (height)*tileSize.y/2))
                .divide(tw, th)
                .add(Vec2d(1, 1))
                .asVec2i()
                .add(Vec2i(-1, -1));

        //printf("%d %d\n", p.x, p.y);
        return getTileInfoAtIndex(l, p.x, p.y);
    }




    /**
     *
     * @param root
     */
    void parseJsonValue(Json::Value root)
    {

        height          = root["height"]        .asInt();
        width           = root["width"]         .asInt();
        tileHeight      = root["tileHeight"]    .asInt();
        tileWidth       = root["tileWidth"]     .asInt();
        orientation     = root["orientation"]   .asString();
        renderOrder     = root["renderorder"]   .asString();

        for (int i = 0; i < root["layers"].size(); i++)
        {
            TerrainLayer terrainLayer;
            Json::Value raw = root["layers"][i];

            terrainLayer.height     = raw["height"]     .asInt();
            terrainLayer.width      = raw["width"]      .asInt();
            terrainLayer.name       = raw["name"]       .asString();
            terrainLayer.opacity    = raw["opacity"]    .asDouble();
            terrainLayer.visible    = raw["visible"]    .asBool();
            terrainLayer.width      = raw["width"]      .asInt();
            terrainLayer.x          = raw["x"]          .asInt();
            terrainLayer.y          = raw["y"]          .asInt();

            for (int j = 0; j < raw["data"].size(); j++)
            {
                terrainLayer.data.push_back(raw["data"][j].asInt());
            }

            layers.push_back(terrainLayer);
        }

        for (int i = 0; i < root["tilesets"].size(); i++)
        {
            TileSet tileSet;
            Json::Value raw = root["tilesets"][i];

            tileSet.columns         = raw["columns"]        .asInt();
            tileSet.image           = raw["image"]          .asString();
            tileSet.imageHeight     = raw["imageheight"]    .asInt();
            tileSet.imageWidth      = raw["imagewidth"]     .asInt();
            tileSet.margin          = raw["margin"]         .asInt();
            tileSet.name            = raw["name"]           .asString();
            tileSet.spacing         = raw["spacing"]        .asInt();
            tileSet.tileCount       = raw["tilecount"]      .asInt();
            tileSet.tileHeight      = raw["tileheight"]     .asInt();
            tileSet.tileWidth       = raw["tilewidth"]      .asInt();

            tileSets.push_back(tileSet);
        }


        numLayers = layers.size();
    }


};


#endif //CHAOS_TERRAINLAYERCOMPONENT_H
