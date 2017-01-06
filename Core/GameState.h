#ifndef CHAOS_GAMESTATE_H
#define CHAOS_GAMESTATE_H

#include <SDL2/SDL.h>
#include "InputEventListener.h"
#include "HasUpdate.h"
#include "HasRender.h"
#include "AssetLibrary.h"


class GameState:
    public InputEventListener,
    public HasUpdate,
    public HasRender
{
private:
    AssetLibrary *assetLibrary_;
    
public:
    virtual void willEnter() {};
    virtual void willExit() {};

    void setAssetLibrary(AssetLibrary *assetLibrary);
    AssetLibrary *getAssetLibrary();
};


#endif //CHAOS_GAMESTATE_H
