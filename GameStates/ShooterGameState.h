#ifndef CHAOS_SHOOTERGAMESTATE_H
#define CHAOS_SHOOTERGAMESTATE_H

#include <Core/GameState.h>
#include <Core/AssetLibrary.h>
#include <Components/SpriteComponent.h>

class ShooterGameState:
    public GameState
{
private:
    AssetLibrary *assetLibrary;

public:
    RenderingSystem renderingSystem;
    MotionSystem motionSystem;

    Entity entity1, entity2, entity3;
    SpriteComponent spriteComponent;
    PhysicsComponent physicsComponent;
    ShapeComponent shapeComponent;

    RenderComponent renderComponent;

    void init(Game *game)
    {
        addSystem(&renderingSystem);
        addSystem(&motionSystem);

    }


};


#endif //CHAOS_SHOOTERGAMESTATE_H
