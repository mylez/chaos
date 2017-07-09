#ifndef CHAOS_UPDATESYSTEM_H
#define CHAOS_UPDATESYSTEM_H

#include <Core/System.h>
#include <Core/Component.h>
#include <iostream>

class Game;

class ScriptingSystem:
    public System
{
public:

    ScriptingSystem()
    { signature = COMPONENT_SCRIPT; }

    void update(double timeElapsed, std::vector<Entity *> entities);

    void init();
};


#endif //CHAOS_UPDATESYSTEM_H
