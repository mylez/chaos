#include "Chaos/Chaos.h"
#include <Core/Entity.h>
#include <Components/PhysicsComponent.h>
#include <Components/RenderComponent.h>
#include <Components/ShapeComponent.h>
#include <Systems/MotionSystem.h>
#include <Systems/RenderingSystem.h>
#include <GameStates/ShooterGameState.h>

using namespace std;

void bench(Chaos *, int);

void shooter(Chaos *);


int main()
{
    Chaos chaos;
    shooter(&chaos);
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

    for (int i = 0; i < numEntities; i++)
    {
        Entity *entity = new Entity();

        ShapeComponent *shapeComponent = new ShapeComponent();
        PhysicsComponent *physicsComponent = new PhysicsComponent();
        RenderComponent *renderComponent = new RenderComponent();

        physicsComponent->velocity = Vec2d((rand() % 1000) / 50.0, (rand() % 1000) / 50.0);
        shapeComponent->color = Color(rand() % 128 + 127, rand() % 128 + 127, rand() % 128 + 127, rand() % 256);
        shapeComponent->size = Vec2d(rand() % 80, rand() % 80);
        entity->transformComponent.position = Vec2d(rand() % 2000, rand() % 1000);

        if (i % 1 == 0) entity->addComponent(shapeComponent);
        if (i % 1 == 0) entity->addComponent(physicsComponent);
        if (i % 1 == 0) entity->addComponent(renderComponent);

        gameState->addEntity(entity);
        chaos->loop();
    }

    chaos->setGameState(gameState);
}