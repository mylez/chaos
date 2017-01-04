#ifndef CHAOS_SCENE_H
#define CHAOS_SCENE_H


#include <vector>
#include "Entity.h"
#include "HasInputEventListeners.h"
#include "HasTileData.h"
#include "AssetLibrary.h"
#include "HasCamera.h"


class Scene:
    public HasInputEventListeners,
    public HasTileData,
    public HasCamera
{
public:
    std::vector<Entity *> getEntities();
    void addEntity(Entity *entity);

private:
    std::vector<Entity *> entities_;
};


#endif //CHAOS_SCENE_H
