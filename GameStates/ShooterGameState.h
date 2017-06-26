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
#include <Components/PhysicsComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/ScriptComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/TerrainLayerComponent.h>


class ShooterGameState:
    public GameState
{
public:


    /**
     *
     * @param game
     */
    void init(Game *game)
    {
        TerrainLayerComponent terrain;

        terrain.loadTerrainData("media/tile-data/level.json");

        std::cout << "loaded terrain: " << terrain.height << "x" <<terrain.width << "\n";
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
