#ifndef CHAOS_SCRIPTCOMPONENT_H
#define CHAOS_SCRIPTCOMPONENT_H

#include <Core/Component.h>
#include <vector>

class Script;

class ScriptComponent:
    public Component
{
public:
    std::vector<Script *> scripts;

    ScriptComponent()
    { label = COMPONENT_UPDATE; }

    void addScript(Script *script)
    {
        scripts.push_back(script);
    }

    void removeScript(int id);
};


#endif //CHAOS_SCRIPTCOMPONENT_H
