#ifndef CHAOS_PLATFORMERGAMESTATE_H
#define CHAOS_PLATFORMERGAMESTATE_H

#include <Core/GameState.h>
#include <Core/Game.h>
#include <Core/Script.h>
#include <Core/Entity.h>

#include <Systems/CollisionSystem.h>
#include <Systems/MotionSystem.h>
#include <Systems/ScriptingSystem.h>

#include <Components/TransformComponent.h>
#include <Components/ScriptComponent.h>
#include <Components/BoxCollisionComponent.h>
#include <Components/PhysicsComponent.h>
#include <Components/SpriteComponent.h>
#include <Components/RenderComponent.h>


class PlatformerGameState:
    public GameState
{
public:
    ScriptComponent scriptComponent;
    BoxCollisionComponent collisionComponent;
    PhysicsComponent physicsComponent1, physicsComponent2;

    Entity entity1, entity2, entity3;

    Sprite dirtSprite;

    /**
     *
     * @param game
     */
    void init(Game *game)
    {
        loadAssets(game);

        entity1.transform.position = Vec2d(10, 200);

        addSystem<ScriptingSystem>();
        addSystem<CollisionSystem>();
        addSystem<MotionSystem>();
        addSystem<RenderingSystem>();

        entity1.transform.position = Vec2d(100, 100);
        entity2.transform.position = Vec2d(132, 116);

        addEntity(&entity1);
        addEntity(&entity2);
    }


    /**
     *
     * @param game
     */
    void loadAssets(Game *game)
    {
        entity1.addComponent<RenderComponent>();
        entity2.addComponent<RenderComponent>();
        auto
            dirtSpriteComponent1 = entity1.addComponent<SpriteComponent>(),
            dirtSpriteComponent2 = entity2.addComponent<SpriteComponent>();
        SDL_Texture *t = game->getAssetLibrary()->loadTexture("dirtTile", "media/image/dirt-tile.png");
        dirtSprite.setTexture(t);
        dirtSprite.setSourceSize(Vec2i(64, 32));
        dirtSprite.setSourcePosition(Vec2i(0, 0));
        dirtSprite.setTargetSize(Vec2d(64, 32));
        dirtSpriteComponent1->sprite = dirtSprite;
        dirtSpriteComponent2->sprite = dirtSprite;
    }
};

#endif //CHAOS_PLATFORMERGAMESTATE_H
