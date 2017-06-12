#ifndef CHAOS_SCENE_H
#define CHAOS_SCENE_H


#include <vector>
#include "HasInputEventListeners.h"
#include "HasTileSet.h"

/*
 * 1920 x 1200  pixels
 *  60  x 37.5  tiles
 */

class Scene:
    public HasInputEventListeners,
    public HasTileSet
{

};


#endif //CHAOS_SCENE_H
