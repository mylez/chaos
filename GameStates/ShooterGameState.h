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
     * todo - get this function to run?
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
        double a = 800;
        double cv = 1000;
        Vec2d acceleration, camVelocity = Vec2d(0, 0);

        if (keyStates[SDL_SCANCODE_RIGHT])  { acceleration.x +=  a; }
        if (keyStates[SDL_SCANCODE_LEFT])   { acceleration.x += -a; }
        if (keyStates[SDL_SCANCODE_UP])     { acceleration.y +=  a; }
        if (keyStates[SDL_SCANCODE_DOWN])   { acceleration.y += -a; }

        if (keyStates[SDL_SCANCODE_D])      { camVelocity.x =  cv; }
        if (keyStates[SDL_SCANCODE_A])      { camVelocity.x = -cv; }
        if (keyStates[SDL_SCANCODE_W])      { camVelocity.y =  cv; }
        if (keyStates[SDL_SCANCODE_S])      { camVelocity.y = -cv; }

        playerEntity->getComponent<PhysicsComponent>()->acceleration = acceleration;
        gameState()->findEntityWithComponent<CameraComponent>()->transform.position = playerEntity->transform.position;
        //gameState()->findEntityWithComponent<CameraComponent>()->getComponent<PhysicsComponent>()->acceleration = camVelocity;

        Vec2d p = gameState()->findEntityWithComponent<CameraComponent>()->transform.position;


        deltaT += 1.0 / 60.0;

        if (deltaT > 1)
        {
            Vec2d c = gameState()->findEntityWithComponent<CameraComponent>()->transform.position;
            Vec2d p = playerEntity->transform.position;
            deltaT = 0;
            std::cout << "camera: " << c.x << " " << c.y << "\n";
            std::cout << "player: " << p.x << " " << p.y << "\n";
            std::cout << terrain->getTileInfoAtPosition(0, playerEntity->transform.position).type << "\n\n";
        }

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
    PhysicsComponent physics, camPhysics;
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
        addSystem(&motionSystem);
        addSystem(&scriptingSystem);
        addSystem(&renderingSystem);


        playerEntity.transform.position = Vec2d(50, 50);

        camPhysics.friction = 0.95;

        cameraEntity.addComponent(&camera);
        cameraEntity.addComponent(&camPhysics);

        game->getAssetLibrary()->loadTexture("Terrain", "media/tile-sheets/Terrain.png");

        terrain.loadTerrainData("media/tile-data/test-5x5.json");

        terrainEntity.addComponent(&terrain);
        terrainEntity.addComponent(&render);

        script.addScript(&playerScript);
        shape.color = Color(255, 0, 0);
        shape.size = Vec2d(10, 10);

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
