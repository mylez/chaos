#ifndef CHAOS_SCENE_H
#define CHAOS_SCENE_H


#include <vector>
#include "AssetLibrary.h"
#include "HasInputEventListeners.h"
#include "HasTileSet.h"
#include "HasEntities.h"
#include "HasCamera.h"

/*
 * 1920 x 1200  pixels
 *  60  x 37.5  tiles
 */

class Scene:
    public HasInputEventListeners,
    public HasTileSet,
    public HasEntities
{

};


#endif //CHAOS_SCENE_H
