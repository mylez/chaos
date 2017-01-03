#include "GameState.h"

AssetLibrary *GameState::getAssetLibrary()
{
    return assetLibrary_;
}

void GameState::setAssetLibrary(AssetLibrary *assetLibrary)
{
    assetLibrary_ = assetLibrary;
}
