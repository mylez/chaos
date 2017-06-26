#include "Entity.h"
#include <Core/GameState.h>
#include <Components/ScriptComponent.h>

unsigned int Entity::nextId_ = 0;

const std::vector<Script *> emptyScriptVector;


/**
 *
 */
void Entity::destroy()
{
    return;

    gameState->removeEntity(id);

    for (const auto &element: components_)
    {
        if (element.second->managed_)
        {
            std::cout << "deleting managed component\n";
            delete element.second;
        }
    }
}


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
