#include "Chaos/Chaos.h"
#include <GameStates/ShooterGameState.h>

#include <SDL2/SDL.h>
#include <SDL2/gfxPrimitives.h>
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

