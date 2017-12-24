#include "Chaos/Chaos.h"
#include <Components/PhysicsComponent.h>
#include <Components/RenderComponent.h>
#include <Components/ShapeComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/StateMachineComponent.h>
#include <Systems/MotionSystem.h>
#include <Systems/CollisionSystem.h>
#include <GameStates/ShooterGameState.h>

using namespace std;

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

