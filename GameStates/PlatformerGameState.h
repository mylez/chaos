#ifndef CHAOS_PLATFORMERGAMESTATE_H
#define CHAOS_PLATFORMERGAMESTATE_H

#include <Core/GameState.h>
#include <Core/Game.h>
#include <Core/Script.h>
#include <Core/Entity.h>

#include <Systems/CollisionSystem.h>
#include <Systems/MotionSystem.h>
#include <Systems/ScriptingSystem.h>

#include <Components/TransformComponent.h>
#include <Components/ScriptComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/PhysicsComponent.h>

struct MyScript:
    public Script
{
public:
    void update(Game *game, Entity *entity)
    {
        static int t;
        t ++;

        std::cout << "whatever...\n";

        if (t % 180)
        {
            entity->getComponent<PhysicsComponent>()->velocity.x *= -1;
        }
    }

    void onCollisionEnter(Collision c)
    {
        //std::cout << "collision enter, entity id: " << c.entityA->id << "\n";
        Vec2d x = c.entityA->getComponent<PhysicsComponent>()->velocity;
        c.entityA->getComponent<PhysicsComponent>()->velocity = c.entityB->getComponent<PhysicsComponent>()->velocity;
        c.entityB->getComponent<PhysicsComponent>()->velocity = x;
    }

    void onCollisionExit(Collision c)
    {
        //std::cout << "collision exit, entity id:  " << c.entityA->id << "\n";
    }
};



class PlatformerGameState:
    public GameState
{
public:

    ScriptingSystem
        scriptingSystem;

    CollisionSystem
        collisionSystem;

    MotionSystem
        motionSystem;

    ScriptComponent
        scriptComponent;

    BoxCollisionComponent
        collisionComponent;

    PhysicsComponent
        physicsComponent1,
        physicsComponent2;

    MyScript
        myScript;

    Entity
        entity1,
        entity2,
        entity3;

    /**
     *
     * @param game
     */
    void init(Game *game)
    {

        scriptComponent.addScript(&myScript);

        collisionComponent.size = Vec2d(30, 30);
        collisionComponent.debugDraw = true;

        entity1.addComponent(&collisionComponent);
        entity1.addComponent(&physicsComponent1);
        entity1.addComponent(&scriptComponent);

        entity1.transform.position = Vec2d(10, 200);
        physicsComponent1.velocity = Vec2d(300, 0);
        physicsComponent1.friction = 0.999;

        entity2.addComponent(&collisionComponent);
        entity2.addComponent(&physicsComponent2);
        entity2.transform.position = Vec2d(200, 200);
        physicsComponent2.velocity = Vec2d(-100, 0);

        entity3.addComponent(&collisionComponent);
        entity3.addComponent(&scriptComponent);
        entity3.addComponent(&physicsComponent1);
        entity3.transform.position = Vec2d(300, 200);

        addSystem(&scriptingSystem);
        addSystem(&collisionSystem);
        addSystem(&motionSystem);

        addEntity(&entity1);
        addEntity(&entity2);
        addEntity(&entity3);
    }
};

#endif //CHAOS_PLATFORMERGAMESTATE_H
