#include "Entity.h"
#include <Core/GameState.h>
#include <Components/ScriptComponent.h>

unsigned int Entity::nextId_ = 0;

const std::vector<Script *> emptyScriptVector;


/**
 *
 * @return
 */
std::vector<Script *> Entity::getScripts()
{
    ScriptComponent *scriptComponent = getComponent<ScriptComponent>();

    if (scriptComponent == nullptr)
    {
        return emptyScriptVector;
    }

    return scriptComponent->scripts;
}
