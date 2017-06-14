#include <Core/GameState.h>
#include <Core/System.h>
#include <Core/Entity.h>

/**
 *
 * @param timeElapsed
 */
void GameState::update(double timeElapsed)
{
    static int i;
    if (i++ % 20 == 0) {

    }
    for (const auto &system: systems_)
    {
        system->update(timeElapsed, filterBySignature(system->signature));
    }
}


/**
 *
 * @param entity
 */
void GameState::addEntity(Entity *entity)
{
    entities_[entity->id] = entity;
    //entities_.push_back(entity);
}


/**
 *
 * @param system
 */
void GameState::addSystem(System *system)
{
    systems_.push_back(system);
}


/**
 *
 * @param signature
 * @return
 */
std::vector<Entity *> GameState::filterBySignature(unsigned long signature)
{
    std::vector<Entity *> entities;
    for (const auto &entity: entities_)
    {
        if ((entity.second->signature & signature) == signature)
        {
            entities.push_back(entity.second);
        }
    }
    return entities;
}


/**
 *
 * @param entityId
 */
void GameState::removeEntity(unsigned int entityId)
{
    entities_.erase(entityId);
}


/**
 *
 * @param game
 */
void GameState::performInit(Game *game)
{
    init(game);

    for (const auto &system: systems_)
    {
        system->init(game);
    }
}








/**
 * todo - find out why this is slow
 *
 * @param timeElapsed
 *
void GameState::update(double timeElapsed)
{
    for (const auto &system: systems_)
    {
        for (const auto &entity: entities_)
        {
            if ((entity->signature & system->signature) == system->signature)
            {
                system->update(timeElapsed, entity, entities_);
            }
        }
    }
}
*/