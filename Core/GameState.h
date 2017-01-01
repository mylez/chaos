#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <SDL2/SDL.h>
#include "InputEventListener.h"
#include "HasUpdate.h"
#include "HasRender.h"


class GameState:
    public InputEventListener,
    public HasUpdate,
    public HasRender
{

};


#endif //CHAOS_GAMESTATE_H
