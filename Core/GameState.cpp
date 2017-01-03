#include "GameState.h"

AssetLibrary *GameState::getAssetLibrary()
{
    std::cout << " something " << assetLibrary_ << "\n\n";
    return assetLibrary_;
}

void GameState::setAssetLibrary(AssetLibrary *assetLibrary)
{
    std::cout << "ass hole " << assetLibrary << "\n\n";
    assetLibrary_ = assetLibrary;
}
