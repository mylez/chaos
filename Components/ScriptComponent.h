#ifndef CHAOS_SCRIPTCOMPONENT_H
#define CHAOS_SCRIPTCOMPONENT_H

#include <Core/Component.h>
#include <vector>
#include <Core/Script.h>

class Script;

class ScriptComponent:
    public Component
{
public:
    std::vector<Script *> scripts;

    ScriptComponent()
    { label = COMPONENT_SCRIPT; }

    void addScript(Script *script)
    {
        script->entity = this->entity;
        scripts.push_back(script);
    }

    void removeScript(int id);
};


#endif //CHAOS_SCRIPTCOMPONENT_H
