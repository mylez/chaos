#ifndef CHAOS_UPDATESYSTEM_H
#define CHAOS_UPDATESYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>
#include <iostream>

class ScriptingSystem:
    public System
{
public:
    Game *game;

    ScriptingSystem()
    { signature = COMPONENT_SCRIPT; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init(Game *game)
    {
        std::cout << "ScriptingSystem.init\n";
        this->game = game;
    }
};


#endif //CHAOS_UPDATESYSTEM_H
