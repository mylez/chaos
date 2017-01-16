#ifndef CHAOS_WORLDGAMESTATE_H
#define CHAOS_WORLDGAMESTATE_H

#include <Core/Scene.h>
#include <Core/GameState.h>

class WorldGameState:
    public Scene,
    public GameState
{
public:
    void willEnter();
};


#endif //CHAOS_WORLDGAMESTATE_H
