#ifndef CHAOS_SCENE_H
#define CHAOS_SCENE_H


#include <vector>
#include "AssetLibrary.h"
#include "HasInputEventListeners.h"
#include "HasTileSet.h"
#include "HasEntities.h"
#include "HasCamera.h"


class Scene:
    public HasInputEventListeners,
    public HasTileSet,
    public HasEntities,
    public HasCamera
{

};


#endif //CHAOS_SCENE_H
