#include <Core/GameState.h>
#include <Core/Entity.h>

/**
 *
 * @param timeElapsed
 */
void GameState::update(double timeElapsed)
{
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
    entity->gameState = this;
    entities_[entity->id] = entity;
    std::cout << "adding entity " << entity->id << ":\t" << entity << " to GameState\n";
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
    std::cout << "removing entity " << entityId << "\n";
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
 *
 */
GameState::~GameState()
{
    for (const auto &entity: entities_)
    {
        entity.second->destroy();
    }
    for (const auto &system: systems_)
    {
        if (system->managed_)
        {
            delete system;
        }
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