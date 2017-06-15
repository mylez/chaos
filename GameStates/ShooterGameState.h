#ifndef CHAOS_SHOOTERGAMESTATE_H
#define CHAOS_SHOOTERGAMESTATE_H

#include <Core/GameState.h>
#include <Core/AssetLibrary.h>
#include <Core/UpdateProcedure.h>
#include <Core/Collision.h>

#include <Systems/MotionSystem.h>
#include <Systems/CollisionSystem.h>
#include <Systems/RenderingSystem.h>
#include <Systems/UpdateSystem.h>

#include <Components/ShapeComponent.h>
#include <Components/PhysicsComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/UpdateComponent.h>
#include <Components/BoxCollisionComponent.h>

/**
 *
 *
 *
 */
class OnBulletCollision:
    public CollisionEnterProcedure
{
public:
    void onCollisionEnter(Collision collision)
    {
        if (collision.entityB->name == "player")
        {
            std::cout << "you're dead.\n";
        }

        if (collision.entityA->name == "bullet" && collision.entityB->name != "bullet")
        {
            collision.entityA->destroy();
            collision.entityB->destroy();
        }
    }
};


class BulletUpdateProcedure:
    public UpdateProcedure
{
public:
    void update(Game *game, Entity *entity, double timeElapsed)
    {
        if (entity->transform.position.y < 0)
        {
            entity->destroy();
        }
    }
};


/**
 *
 * @param position
 * @param velocity
 * @return
 */
Entity *shootBullet(Vec2d position, Vec2d velocity)
{
    Entity *e = new Entity;
    e->transform.position = position.add(Vec2d(0, -30));

    //ShapeComponent *s = e->addComponent<ShapeComponent>();
    //s->color.b = 255;
    //s->color.a = 100;
    //s->size = Vec2d(20, 20);

    PhysicsComponent *p = new PhysicsComponent;
    p->velocity = velocity;

    BoxCollisionComponent *c = new BoxCollisionComponent;
    c->size = Vec2i(10, 10);

    OnBulletCollision *bc = new OnBulletCollision;
    c->collisionEnterProcedure = bc;

    UpdateComponent *u = new UpdateComponent;
    BulletUpdateProcedure *bu = new BulletUpdateProcedure;
    u->updateProcedure = bu;

    e->addComponent(p);
    e->addComponent(c);
    e->addComponent(u);
    e->addComponent(new RenderComponent);

    e->name = "bullet";

    return e;
}


/**
 *
 *
 *
 */
class PlayerUpdateProcedure:
    public UpdateProcedure
{
    ShapeComponent bulletShape;
    RenderComponent renderComponent;
    PhysicsComponent bulletPhysics;
    BoxCollisionComponent bulletCollision;
    OnBulletCollision onBulletCollision;
    UpdateComponent bulletUpdateComponent;
    BulletUpdateProcedure bulletUpdateProcedure;
public:

    double bulletFiredTimeElapsed = 0,
        bulletFireSpeed = .1;

    PlayerUpdateProcedure()
    {
        bulletShape.size = Vec2d(3, 5);
        bulletShape.color = Color(255, 255, 230);
        bulletCollision.collisionEnterProcedure = &onBulletCollision;
        bulletUpdateComponent.updateProcedure = &bulletUpdateProcedure;
    }

    void update(Game *game, Entity *entity, double timeElapsed)
    {


        const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

        PhysicsComponent *physics = entity->getComponent<PhysicsComponent>();
        TransformComponent transform = entity->transform;

        double v = 10;


        physics->acceleration = Vec2d(0, 0);


        if (keyboardState[SDL_SCANCODE_UP])
        {
            physics->acceleration.y = -v;
        }
        if (keyboardState[SDL_SCANCODE_DOWN])
        {
            physics->acceleration.y = v;
        }
        if (keyboardState[SDL_SCANCODE_RIGHT])
        {
            physics->acceleration.x = v;
        }
        if (keyboardState[SDL_SCANCODE_LEFT])
        {
            physics->acceleration.x = -v;
        }

        if (keyboardState[SDL_SCANCODE_SPACE] && bulletFiredTimeElapsed > bulletFireSpeed)
        {
            game->getGameState()->addEntity(shootBullet(entity->transform.position, Vec2d(-100, -400)));
            game->getGameState()->addEntity(shootBullet(entity->transform.position, Vec2d(-50, -400)));
            game->getGameState()->addEntity(shootBullet(entity->transform.position, Vec2d(  0, -400)));
            game->getGameState()->addEntity(shootBullet(entity->transform.position, Vec2d( 50, -400)));
            game->getGameState()->addEntity(shootBullet(entity->transform.position, Vec2d( 100, -400)));
            bulletFiredTimeElapsed = 0;
        }

        bulletFiredTimeElapsed += timeElapsed;
    }
};

class ShooterGameState:
    public GameState
{

private:
    AssetLibrary *assetLibrary;

public:
    CollisionSystem
        collisionSystem;

    RenderingSystem
        renderingSystem;

    MotionSystem
        motionSystem;

    UpdateSystem
        updateSystem;

    Entity
        entity1,
        entity2,
        entity3;

    PhysicsComponent
        physicsComponent1,
        physicsComponent2;

    ShapeComponent
        shapeComponent1,
        shapeComponent2;

    BoxCollisionComponent
        boxCollisionComponent1,
        boxCollisionComponent2;

    UpdateComponent
        updateComponent;

    PlayerUpdateProcedure
        playerUpdateProcedure;

    RenderComponent renderComponent;

    /**
     *
     * @param game
     */
    void init(Game *game)
    {
        addSystem(&updateSystem);
        addSystem(&collisionSystem);
        addSystem(&motionSystem);
        addSystem(&renderingSystem);

        updateComponent.updateProcedure = &playerUpdateProcedure;

        entity1.name = "player";

        entity1.addComponent(&physicsComponent1);
        entity1.addComponent(&boxCollisionComponent1);
        entity1.addComponent(&updateComponent);
        entity1.addComponent(&shapeComponent1);
        entity1.addComponent(&renderComponent);

        entity2.addComponent(&physicsComponent2);
        entity2.addComponent(&boxCollisionComponent2);

        Vec2d size(25, 25);

        entity1.transform.position = Vec2d(100, 100);
        physicsComponent1.velocity.x = 20;
        physicsComponent1.friction = 0.99;
        physicsComponent1.useGravity = false;

        boxCollisionComponent1.size = size;
        boxCollisionComponent1.debugDraw = false;
        shapeComponent1.size = size;
        shapeComponent1.color.r = 255;

        entity2.transform.position = Vec2d(400, 140);
        physicsComponent2.velocity.x = -20;
        physicsComponent2.useGravity = true;
        boxCollisionComponent2.size = size;
        boxCollisionComponent2.debugDraw = true;
        shapeComponent2.size = size;
        shapeComponent2.color.b = 255;

        for (int i = 0; i < 2; i++)
        {
            Entity *e = new Entity;
            e->transform.position = Vec2d(rand() % 2000, rand() % 200);

            e->addComponent(i % 2 ? &physicsComponent1 : &physicsComponent2);

            e->addComponent(&renderComponent);
            ShapeComponent *s = new ShapeComponent;
            s->color.a = 80;
            s->color.g = 255;
            auto p = new PhysicsComponent;
            p->velocity = Vec2d((rand() % 1) / 10, (rand() % 1) / 1);
            e->addComponent(p);
            e->addComponent(s);
            auto c = new BoxCollisionComponent;
            c->size = s->size.add(Vec2d(rand() % 100, rand() % 100));
            s->size = c->size;
            c->debugDraw = true;
            e->addComponent(c);
            addEntity(e);
        }

        addEntity(&entity1);
        addEntity(&entity2);
    }
};


#endif //CHAOS_SHOOTERGAMESTATE_H
