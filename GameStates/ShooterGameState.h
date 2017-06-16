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


class ShooterGameState:
    public GameState
{
public:
    CollisionSystem         collisionSystem;
    RenderingSystem         renderingSystem;
    MotionSystem            motionSystem;
    ScriptingSystem         scriptingSystem;

    Entity                  entity1, entity2, entity3;

    PhysicsComponent        physicsComponent1, physicsComponent2;
    ShapeComponent          shapeComponent1, shapeComponent2;
    BoxCollisionComponent   boxCollisionComponent1, boxCollisionComponent2;
    RenderComponent         renderComponent;

    /**
     *
     * @param game
     */
    void init(Game *game)
    {
        addSystem(&collisionSystem);
        addSystem(&motionSystem);
        addSystem(&renderingSystem);

        entity1.addComponent(&boxCollisionComponent1);

        entity2.addComponent(&boxCollisionComponent2);

        boxCollisionComponent1.size = Vec2d(70, 20);
        boxCollisionComponent1.debugDraw = true;

        boxCollisionComponent2.size = Vec2d(10, 100);
        boxCollisionComponent2.debugDraw = true;

        entity1.transform.position = Vec2d(0, 400);
        physicsComponent1.velocity = Vec2d(100, 0);
        entity1.addComponent(&physicsComponent1);

        entity2.transform.position = Vec2d(300, 400);
        physicsComponent2.velocity = Vec2d(15, 0);
        entity2.addComponent(&physicsComponent2);

        entity3.transform.position = Vec2d(400, 400);
        entity3.addComponent(&boxCollisionComponent1);

        addEntity(&entity1);
        addEntity(&entity2);
        addEntity(&entity3);
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
