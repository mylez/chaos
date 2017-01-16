#include "WorldGameState.h"

void WorldGameState::willEnter()
{
    std::cout << "WGS::willEnter\n";
    addInputEventListener(0, 0);
    getInputEventListeners(0);


}