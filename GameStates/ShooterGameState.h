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
#include <Components/RenderComponent.h>


class PlayerScript:
        public Script
{
    double t = 0;

    SpriteComponent *sprite = nullptr;
    PhysicsComponent *physics = nullptr;


    /**
     *
     *
     */
    void update()
    {
        const Uint8 *key = SDL_GetKeyboardState(NULL);
        double a = 10;

        Vec2d force(0, 0);

        if (key[SDL_SCANCODE_UP])       { force.y = a; }
        if (key[SDL_SCANCODE_RIGHT])    { force.x = a; }
        if (key[SDL_SCANCODE_DOWN])     { force.y = -a; }
        if (key[SDL_SCANCODE_LEFT])     { force.x = -a; }

        physics->applyForce(force);
    }


    /**
     *
     */
    void init()
    {
        sprite = entity->getComponent<SpriteComponent>();
        physics = entity->getComponent<PhysicsComponent>();
    }
};


class ShooterGameState:
    public GameState
{
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
        physics->mass = 1;
        playerEntity->addComponent<RenderComponent>();
        playerEntity->name = "player";
        script->addScript<PlayerScript>();
        playerEntity->transform.position = Vec2d(0, 0);
        shape->setSize(Vec2d(1, 1));
        shape->setColor(Color(255, 0, 0));
        physics->friction = 0.999;
        playerEntity->name = "player 1";
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
