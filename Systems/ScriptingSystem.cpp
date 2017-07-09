#include "ScriptingSystem.h"
#include <Core/Game.h>
#include <Core/Script.h>
#include <Components/ScriptComponent.h>


/**
 *
 * @param timeElapsed
 * @param entities
 */
void ScriptingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (const auto entity: entities)
    {
        ScriptComponent *update = entity->getComponent<ScriptComponent>();
        for (const auto &script: update->scripts)
        {
            script->timeElapsed = timeElapsed;
            script->entity = entity;
            script->game = game;
            script->update();
        }
    }
}


/**
 *
 * @param game
 */
void ScriptingSystem::init()
{
    std::cout << "ScriptingSystem.init\n";

    for (const auto &entity: game->gameState_->filterEntitiesBySignature(signature))
    {
        for (const auto &script: entity->getScripts())
        {
            script->timeElapsed = 0;
            script->entity = entity;
            script->game = game;
            script->update();
            script->init(entity);
        }
    }
}
