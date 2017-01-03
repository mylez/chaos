#ifndef CHAOS_CHAOS_H
#define CHAOS_CHAOS_H

#include "Core/Game.h"
#include "Core/AssetLibrary.h"

class Chaos: public Game
{
private:
    AssetLibrary assetLibrary_;
public:
    Chaos();
};


#endif //CHAOS_CHAOS_H
