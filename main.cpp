#include "Chaos/Chaos.h"
#include <Components/PhysicsComponent.h>
#include <Components/RenderComponent.h>
#include <Components/ShapeComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Systems/MotionSystem.h>
#include <Systems/CollisionSystem.h>
#include <GameStates/ShooterGameState.h>

using namespace std;

void bench(Chaos *, int);

void shooter(Chaos *);

int main()
{
    Chaos chaos;
    shooter(&chaos);
    //bench(&chaos, 150);
}


/**
 *
 * @param chaos
 */
void shooter(Chaos *chaos)
{
    ShooterGameState shooterGameState;
    chaos->setGameState(&shooterGameState);
    chaos->loop();
}


/**
 *
 * @param chaos
 * @param numEntities
 */
void bench(Chaos *chaos, int numEntities)
{
    GameState *gameState = new GameState;

    gameState->addSystem(new MotionSystem);
    gameState->addSystem(new RenderingSystem);
    gameState->addSystem(new CollisionSystem);

    for (int i = 0; i < numEntities; i++)
    {
        Entity *entity = new Entity();

        ShapeComponent *shapeComponent = new ShapeComponent();
        PhysicsComponent *physicsComponent = new PhysicsComponent();
        RenderComponent *renderComponent = new RenderComponent();
        BoxCollisionComponent *boxCollisionComponent = new BoxCollisionComponent();

        physicsComponent->velocity = Vec2d((rand() % 1000) / 50.0, (rand() % 1000) / 50.0);
        shapeComponent->setColor(Color(rand() % 128 + 127, rand() % 128 + 127, rand() % 128 + 127, rand() % 256));
        shapeComponent->setSize(Vec2d(rand() % 80, rand() % 80));
        boxCollisionComponent->setSize(shapeComponent->getSize());
        entity->transform.position = Vec2d(rand() % 2000, rand() % 1000);

        entity->addComponent(shapeComponent);
        entity->addComponent(physicsComponent);
        entity->addComponent(boxCollisionComponent);
        entity->addComponent(renderComponent);

        gameState->addEntity(entity);
    }

    chaos->setGameState(gameState);
    chaos->loop();
}