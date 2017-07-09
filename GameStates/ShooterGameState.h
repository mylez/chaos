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

#include "PlayerScript.h"


class ShooterGameState:
    public GameState
{
public:

    RenderingSystem renderingSystem;
    MotionSystem motionSystem;
    ScriptingSystem scriptingSystem;

    TerrainLayerComponent terrain;
    ShapeComponent shape1, shape2;
    PhysicsComponent physics1, physics2, camPhysics;
    ScriptComponent script1, script2;
    RenderComponent render;
    SpriteComponent sprite;
    CameraComponent camera;

    PlayerScript<SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_RIGHT, SDL_SCANCODE_LEFT> player1Script;
    PlayerScript<SDL_SCANCODE_W,  SDL_SCANCODE_S,    SDL_SCANCODE_D,     SDL_SCANCODE_A> player2Script;

    Entity
        cameraEntity,
        terrainEntity,
        player1Entity,
        player2Entity;

    /**
     *
     * @param game
     */
    void init()
    {
        addSystem(&motionSystem);
        addSystem(&scriptingSystem);
        addSystem(&renderingSystem);
        setupCamera();
        setupPlayers();
        setupTerrain();
    }

    /**
     *
     */
    void setupCamera()
    {
        cameraEntity.addComponent(&camera);
        addEntity(&cameraEntity);
    }

    /**
     *
     * @param game
     */
    void setupTerrain()
    {
        game->getAssetLibrary()->loadTexture("Terrain", "media/tile-sheets/Terrain.png");

        terrainEntity.addComponent(&render);
        terrainEntity.addComponent(&terrain);

        terrain.loadTerrainData("media/tile-data/level.json");
        terrain.drawDebugGrid = false;
        addEntity(&terrainEntity);
    }

    /**
     *
     */
    void setupPlayers()
    {
        player1Entity.addComponent(&script1);
        player1Entity.addComponent(&shape1);
        player1Entity.addComponent(&physics1);
        player1Entity.addComponent(&render);
        script1.addScript(&player1Script);
        shape1.setSize(Vec2d(500, 20));
        shape1.setColor(Color(255, 0, 0));
        physics1.friction = 0.99;
        player1Entity.name = "player 1";
        addEntity(&player1Entity);

        //

        //player2Entity.addComponent(&script2);
        //player2Entity.addComponent(&shape2);
        //player2Entity.addComponent(&physics2);
        //player2Entity.addComponent(&render);
        //script2.addScript(&player2Script);
        //shape2.setSize(Vec2d(5, 5));
        //shape2.setColor(Color(0, 0, 255));
        //physics2.friction = 0.99;
        //player2Entity.name = "player 2";
        //addEntity(&player2Entity);
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
