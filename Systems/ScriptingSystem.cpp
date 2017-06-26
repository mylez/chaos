#include "ScriptingSystem.h"
#include <Core/Entity.h>
#include <Core/Script.h>
#include <Components/ScriptComponent.h>

void ScriptingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (const auto &entity: entities)
    {
        ScriptComponent *update = entity->getComponent<ScriptComponent>();
        for (const auto &script: update->scripts)
        {
            script->update(game, entity, timeElapsed);
            script->update(entity);
        }
    }
}