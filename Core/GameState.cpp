#include <Core/GameState.h>

/**
 *
 * @param timeElapsed
 */
void GameState::performUpdate(double timeElapsed)
{
    this->timeElapsed = timeElapsed;

    updateSpatialCache();

    update();

    for (const auto &system: systems_)
    {
        std::vector<Entity *> entities = filterEntitiesBySignature(system->signature);
        system->game = game;
        system->update(timeElapsed, entities);
    }
}


/**
 *
 * @param entity
 */
void GameState::addEntity(Entity *entity)
{
    entity->gameState = this;
    entities[entity->id] = entity;
    std::cout << "adding entity " << entity->id << ":\t" << entity << "\t to GameState\n";
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
std::vector<Entity *> GameState::filterEntitiesBySignature(unsigned long signature)
{
    std::vector<Entity *> filtered;
    for (const auto &entity: entities)
    {
        if ((entity.second->signature & signature) == signature)
        {
            filtered.push_back(entity.second);
        }
    }
    return filtered;
}

/**
 *
 * @param entityId
 */
void GameState::removeEntity(unsigned int entityId)
{
    std::cout << "removing entity " << entityId << "\n";
    entities.erase(entityId);
}


/**
 *
 * @param game
 */
void GameState::performInit(Game *game)
{
    this->game = game;

    init();

    for (const auto &system: systems_)
    {
        system->game = game;
        system->init();
    }
}


/**
 *
 */
GameState::~GameState()
{
    for (const auto &entity: entities)
    {
        entity.second->destroy();
    }
    for (const auto &system: systems_)
    {
        if (system->managed_)
        {
            //delete system;
        }
    }
}


/**
 *
 * @param name
 * @return
 */
Entity *GameState::findEntityByName(std::string name)
{
    for (const auto &e: entities)
    {
        if (e.second->name == name)
        {
            return e.second;
        }
    }

    return nullptr;
}

std::vector<Entity *> GameState::filterEntitiesByPosition(Vec2d position)
{
    std::vector<Entity *> filtered;

    return filtered;
}


/**
 *
 */
void GameState::updateSpatialCache()
{
    spatialCache.clear();
    for (const auto &e: entities)
    {
        Vec2d
            entityPosition = e.second->transform.position,
            boundingPosition = e.second->boundingBox.position,
            boundingSize = e.second->boundingBox.size;

        Vec2i
            topRight = entityPosition.add(boundingPosition.add(boundingSize.scale(.5)))
            .divide(spatialCacheGridSize).floor(0).asVec2i(),
            bottomLeft = entityPosition.add(boundingPosition.add(boundingSize.scale(-.5)))
            .divide(spatialCacheGridSize).floor(0).asVec2i();

        e.second->spatialCacheKeys.clear();

        for (int x = bottomLeft.x; x <= topRight.x; x++)
        {
            for (int y = bottomLeft.y; y <= topRight.y; y++)
            {
                std::pair<int, int> cacheKey(x, y);
                e.second->spatialCacheKeys.push_back(cacheKey);
                spatialCache[cacheKey].push_back(e.second);
            }
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

