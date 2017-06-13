#include "Chaos/Chaos.h"
#include <Core/Entity.h>
#include <Core/Component.h>
#include <Core/System.h>
#include <Core/GameState.h>
#include <Components/PhysicsComponent.h>
#include <Components/TransformComponent.h>
#include <Systems/MotionSystem.h>
#include <Systems/RenderingSystem.h>
#include <iostream>

using namespace std;


int main()
{
    Chaos chaos;

    MotionSystem
        ms;

    RenderingSystem
        rs(&chaos.graphics_);

    GameState
        gs;

    for (int i = 0; i < 100; i++) {
        TransformComponent *t = new TransformComponent();
        PhysicsComponent *p = new PhysicsComponent();
        Entity *e = new Entity();

        p->velocity = vec2d(
            75*((double)(rand()%1000))/1000.0,
            75*((double)(rand()%1000))/1000.0
        );

        t->position = vec2d(
            ((double)(rand()%1000)),
            ((double)(rand()%1000))
        );

        e->addComponent(p);
        e->addComponent(t);
        gs.addEntity(e);
    }


    gs.addSystem(&ms);
    gs.addSystem(&rs);

    gs.init();

    chaos.setGameState(&gs);

    chaos.loop();
    //
    //
}


