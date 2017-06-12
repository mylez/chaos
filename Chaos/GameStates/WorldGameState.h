#ifndef CHAOS_WORLDGAMESTATE_H
#define CHAOS_WORLDGAMESTATE_H

#include <map>
#include <Core/Scene.h>
#include <Core/ObjectPool.h>
#include <Core/GameState.h>
#include <Core/HasProperties.h>
#include <Core/HasInputEventListeners.h>
#include <Core/HasUpdate.h>
#include <Core/HasRender.h>
#include <Core/Err.h>
#include <Chaos/Entities/WorldEntity.h>



class Character:
    public HasProperties,
    public InputEventListener {
public:
    vec2d position = vec2d(0, 0),
          velocity = vec2d(0, 0);

    void handleInputEvent(SDL_Event *e) {
        switch (e->type) {
        case SDL_KEYUP:
            handle_keyUp(e->key.keysym.sym);
            break;
        case SDL_KEYDOWN:
            handle_keyDown(e->key.keysym.sym);
            break;
        default: break;
        }
    }

    void handle_keyDown(SDL_Keycode code) {
        switch (code) {
        case SDLK_LEFT:
            velocity.x = -1;
            break;
        case SDLK_RIGHT:
            velocity.x = 1;
            break;
        case SDLK_UP:
            velocity.y = 1;
            break;
        case SDLK_DOWN:
            velocity.y = -1;
            break;
        default: break;
        }
    }

    void handle_keyUp(SDL_Keycode code) {
        switch (code) {
        case SDLK_LEFT:
        case SDLK_RIGHT:
            velocity.x = 0;
            break;
        case SDLK_UP:
        case SDLK_DOWN:
            velocity.y = 0;
            break;
        default: break;
        }
    }
};



class WorldGameState:
    public Scene,
    public GameState
{
public:

    Character player;

    WorldGameState() {
        player.setProperty("name", "Puppy");
        printf("shit!\n");
        addInputEventListener(SDL_KEYDOWN, &player);
        addInputEventListener(SDL_KEYUP, &player);
    }

    void handleInputEvent(SDL_Event *event);
    void willEnter(AssetLibrary *assetLibrary);
    void update(double timeElapsed);
    void render(Graphics *g);
};




/**
 *
 *
 *

class WorldSegment
{
private:
    std::vector<std::vector<WorldEntity>> entities_;


public:
    vec2i pos, size;

    void loadSegment(TileSet *tileSet, vec2i segPos, vec2i segSize, SDL_Texture *texture)
    {
        entities_.clear();

        pos = segPos;
        size = segSize;

        int
            tileSetSize = tileSet->getLayerSize(0),
            tileSetWidth = tileSet->getWidth(0);

        for (unsigned long i = 0; i < segSize.x * segSize.y; i++)
        {
            entities_.push_back(std::vector<WorldEntity>());
        }

        for (int x = 0;  x < segSize.x; x++)
        {
            for (int y = 0; y < segSize.y; y++)
            {
                int tileType = tileSet->getTileTypeAt(0, x + segPos.x, y + segPos.y);
                addEntityByTileType(vec2i(x, y), tileSet, tileType, texture);
            }
        }
    }


    void addEntityByTileType(vec2i pos, TileSet *tileSet, int tileType, SDL_Texture *texture)
    {
        WorldEntity worldEntity;

        worldEntity.sprite.setTexture(texture);
        worldEntity.sprite.setSourcePosition(tileSet->tileSourcePosition(0, tileType));
        worldEntity.sprite.setSourceSize(vec2i(32, 32));

        worldEntity.pos = pos;

        entities_[pos.x + pos.x * pos.y].push_back(worldEntity);
    }


    std::vector<WorldEntity> getEntity(vec2i pos)
    {
        return entities_[pos.x + pos.x * pos.y];
    }

};
*/

#endif //CHAOS_WORLDGAMESTATE_H
