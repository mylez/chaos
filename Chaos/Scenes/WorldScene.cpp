#include <Chaos/GameObjects/PlayerGameObject.h>
#include "WorldScene.h"

WorldScene::WorldScene()
{
    for (int i = 0; i < 400000; i++)
    {
        addGameObject(new PlayerGameObject());
    }

}
