#include "Chaos/Chaos.h"
#include <Core/Entity.h>
#include <Core/Component.h>
#include <Core/System.h>
#include <Core/GameState.h>
#include <Components/PhysicsComponent.h>
#include <Components/TransformComponent.h>
#include <Components/RenderComponent.h>
#include <Systems/MotionSystem.h>
#include <Systems/RenderingSystem.h>
#include <iostream>
#include <Components/ShapeComponent.h>

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

    gs.addSystem(&ms);
    gs.addSystem(&rs);


    for (int i = 0; i < 5000; i++)
    {
        Entity *e = new Entity();
        ShapeComponent *pc = new ShapeComponent();
        //PhysicsComponent *ph = new PhysicsComponent();
        RenderComponent *rc = new RenderComponent();

        //ph->velocity = Vec2d((rand()%2560)/100.0, (rand()%2560)/100.0);
        pc->color = Color(rand()%128 + 127, rand()%128 + 127, rand()%128 + 127, 255);
        pc->size = Vec2d(rand()%80, rand()%80);
        e->getComponent<TransformComponent>()->position = Vec2d(rand()%1000, rand()%1000);

        e->addComponent(pc);
        //e->addComponent(ph);
        e->addComponent(rc);

        gs.addEntity(e);
    }

    gs.init();

    chaos.setGameState(&gs);

    chaos.loop();
    //
    //
}


