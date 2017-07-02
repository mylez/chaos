#include "ScriptingSystem.h"
#include <Core/Game.h>
#include <Core/Entity.h>
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
            script->update(game, entity, timeElapsed);
            script->update(entity);
        }
    }
}


/**
 *
 * @param game
 */
void ScriptingSystem::init(Game *game)
{
    std::cout << "ScriptingSystem.init";

    for (const auto &entity: game->gameState_->filterEntitiesBySignature(signature))
    {
        for (const auto &script: entity->getScripts())
        {
            script->game = game;
            script->init(entity);
        }
    }
}
