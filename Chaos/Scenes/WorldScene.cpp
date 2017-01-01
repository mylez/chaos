#include <Chaos/GameObjects/PlayerGameObject.h>
#include <Chaos/GameObjects/EnemyGameObject.h>
#include "WorldScene.h"

WorldScene::WorldScene()
{
    for (int i = 0; i < 10000; i++)
    {
        addGameObject(new PlayerGameObject());
    }

}
