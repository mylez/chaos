#ifndef CHAOS_UPDATESYSTEM_H
#define CHAOS_UPDATESYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>
#include <iostream>

class UpdateSystem:
    public System
{
public:
    Game *game;

    UpdateSystem()
    { signature = COMPONENT_UPDATE; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init(Game *game)
    {
        std::cout << "UpdateSystem.init\n";
        this->game = game;
    }
};


#endif //CHAOS_UPDATESYSTEM_H
