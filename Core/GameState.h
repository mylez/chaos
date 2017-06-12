#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H


#include <SDL2/SDL.h>
#include "AssetLibrary.h"
#include "InputEventListener.h"
#include "HasUpdate.h"
#include "HasRender.h"
#include "HasAssets.h"

class GameState:
    public InputEventListener,
    public HasUpdate,
    public HasRender,
    public HasAssets
{

public:
    virtual void willEnter(AssetLibrary *assetLibrary) {};
    virtual void willExit() {};
};



#endif //CHAOS_GAMESTATE_H
