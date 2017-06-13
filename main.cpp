#include "Chaos/Chaos.h"
#include <Core/Entity.h>
#include <Core/Component.h>
#include <Core/System.h>
#include <Core/GameState.h>
#include <Components/PhysicsComponent.h>
#include <Components/TransformComponent.h>
#include <Systems/MotionSystem.h>
#include <iostream>
using namespace std;


int main()
{
    Entity
        ent0, ent1;
    std::vector<Entity*>
        entities = {&ent0, &ent1};
    TransformComponent
        tc0, tc1;
    PhysicsComponent
        pc0, pc1;
    MotionSystem
        ms;

    GameState
        gs;

    pc0.velocity = vec2d(1, 2);

    ent0.addComponent(&tc0);
    ent0.addComponent(&pc0);
    ent1.addComponent(&tc1);
    ent1.addComponent(&pc1);

    gs.addEntity(&ent0);
    gs.addEntity(&ent1);

    gs.addSystem(&ms);


    for (int i = 0; i < 10; i++) {
        double timeElapsed = 1;
        gs.update(timeElapsed);
        cout << tc0.position.x << ", " << tc0.position.y << "\n\n";
    }


    //Chaos chaos;
    //chaos.loop();
}


