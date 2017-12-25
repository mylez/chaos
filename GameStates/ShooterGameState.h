#ifndef CHAOS_SHOOTERGAMESTATE_H
#define CHAOS_SHOOTERGAMESTATE_H

#include <Core/GameState.h>
#include <Core/AssetLibrary.h>
#include <Core/Script.h>
#include <Core/Collision.h>

#include <Systems/MotionSystem.h>
#include <Systems/CollisionSystem.h>
#include <Systems/RenderingSystem.h>
#include <Systems/ScriptingSystem.h>

#include <Components/ShapeComponent.h>
#include <Components/SpriteComponent.h>
#include <Components/PhysicsComponent.h>
#include <Components/ScriptComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/TerrainLayerComponent.h>
#include <Components/RenderComponent.h>

#include "PlayerScript.h"

class ShooterGameState:
    public GameState
{
private:
    Entity *cameraEntity;
public:

    /**
     *
     * @param game
     */
    void init()
    {
        addSystem<MotionSystem>();
        addSystem<ScriptingSystem>();
        addSystem<RenderingSystem>();

        setupPlayers();
        setupTerrain();
        setupCamera();
    }

    /**
     *
     */
    void setupCamera()
    {
        cameraEntity = addEntity();
        auto camera = cameraEntity->addComponent<CameraComponent>();
        cameraEntity->name = "camera";
        camera->backgroundColor = Color(255, 255, 255);
    }

    /**
     *
     * @param game
     */
    void setupTerrain()
    {
        auto terrainEntity = addEntity();
        auto terrain = terrainEntity->addComponent<TerrainLayerComponent>();

        terrainEntity->name = "terrain";
        game->getAssetLibrary()->loadTexture("Terrain", "media/tile-sheets/Terrain.png");
        terrainEntity->addComponent<RenderComponent>();
        terrain->loadTerrainData("media/tile-data/level.json");
    }

    /**
     *
     */
    void setupPlayers()
    {
        auto playerEntity = addEntity();
        auto shape = playerEntity->addComponent<ShapeComponent>();
        auto physics = playerEntity->addComponent<PhysicsComponent>();
        auto script = playerEntity->addComponent<ScriptComponent>();
        physics->mass = .1;
        playerEntity->addComponent<RenderComponent>();
        playerEntity->name = "player";
        script->addScript<PlayerScript>();
        playerEntity->transform.position = Vec2d(0, 0);
        shape->setSize(Vec2d(5, 5));
        shape->setColor(Color(255, 0, 0));
        physics->friction = 0.9;
        playerEntity->name = "player 1";
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
