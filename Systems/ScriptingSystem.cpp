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
    std::vector<SDL_Event> events;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        events.push_back(event);
        // todo - this is a hard quit right now
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q))
        {
            game->setIsRunning(false);
        }
    }

    for (const auto entity: entities)
    {
        ScriptComponent *update = entity->getComponent<ScriptComponent>();
        for (const auto &script: update->scripts)
        {
            script->timeElapsed = timeElapsed;
            script->entity = entity;
            script->game = game;
            script->update();

            for (const auto &event: events)
            {
                script->onInputEvent(event);
            }
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
            script->performInit(game, entity);
        }
    }
}

/**
 *
 */
void ScriptingSystem::deinit()
{
    std::cout << "ScriptingSystem.deinit\n";

    std::unordered_map<Script *, bool> deletedScripts;

    for (const auto &entity: game->gameState_->filterEntitiesBySignature(signature))
    {
        for (const auto &script: entity->getScripts())
        {
            script->performDeinit();
            if (!deletedScripts[script])
            {
                if (script->managed_)
                {
                    std::cout << "deleting script: " << script << "\n";
                    delete script;
                }
            }
        }
    }
}
