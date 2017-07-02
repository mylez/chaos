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

struct PlayerScript: public Script
{
    TerrainLayerComponent *terrain = nullptr;

    double deltaT = 0;

    /**
     *
     * @param entity
     */
    void init(Entity *entity)
    {
        printf("PlayerScrpit.init!\n");
        terrain = gameState()->findEntity("terrain")->getComponent<TerrainLayerComponent>();
    }


    /**
     *
     * @param playerEntity
     */
    void update(Entity *playerEntity)
    {
        const Uint8 *keyStates = SDL_GetKeyboardState(NULL);
        double a = 200;
        Vec2d acceleration;

        if (keyStates[SDL_SCANCODE_RIGHT]) { acceleration.x +=  a; }
        if (keyStates[SDL_SCANCODE_LEFT])  { acceleration.x += -a; }
        if (keyStates[SDL_SCANCODE_UP])    { acceleration.y += -a; }
        if (keyStates[SDL_SCANCODE_DOWN])  { acceleration.y +=  a; }

        playerEntity->getComponent<PhysicsComponent>()->velocity = acceleration;

        deltaT += 1.0 / 60.0;

        if (deltaT > 1)
        {
            deltaT = 0;
            printf("tile type: %d\n", terrain->getTileInfoAtPosition(0, gameState()->findEntity("player")->transform.position));
        }

        gameState()->findEntityWithComponent<CameraComponent>()->transform.position = playerEntity->transform.position.scale(-1);
    }
};

class ShooterGameState:
    public GameState
{
public:

    RenderingSystem renderingSystem;
    MotionSystem motionSystem;
    ScriptingSystem scriptingSystem;

    TerrainLayerComponent terrain;
    ShapeComponent shape;
    PhysicsComponent physics;
    ScriptComponent script;
    RenderComponent render;
    SpriteComponent sprite;
    CameraComponent camera;

    PlayerScript playerScript;

    Entity
        cameraEntity,
        terrainEntity,
        playerEntity,
        centerEntity;

    /**
     *
     * @param game
     */
    void init(Game *game)
    {
        addSystem(&scriptingSystem);
        addSystem(&motionSystem);
        addSystem(&renderingSystem);

        cameraEntity.addComponent(&camera);

        game->getAssetLibrary()->loadTexture("Terrain", "media/tile-sheets/Terrain.png");

        terrain.loadTerrainData("media/tile-data/test.json");

        terrainEntity.addComponent(&terrain);
        terrainEntity.addComponent(&render);

        script.addScript(&playerScript);
        shape.color = Color(255, 0, 0);
        shape.size = Vec2d(3,3);

        centerEntity.addComponent(&shape);
        centerEntity.addComponent(&render);

        physics.friction = 0.97;

        terrainEntity.name = "terrain";
        playerEntity.name = "player";

        playerEntity.addComponent(&shape);
        playerEntity.addComponent(&physics);
        playerEntity.addComponent(&script);
        playerEntity.addComponent(&render);

        addEntity(&cameraEntity);
        addEntity(&terrainEntity);
        addEntity(&playerEntity);
        addEntity(&centerEntity);
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
