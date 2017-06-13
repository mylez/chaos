#include "GameState.h"


/**
 *
 * @param timeElapsed
 */
void GameState::update(double timeElapsed) {
    for (const auto &system: systems_) {
        system->update(timeElapsed, filterBySignature(system->signature));
    }
}


/**
 *
 * @param entity
 */
void GameState::addEntity(Entity *entity) {
    entities_.push_back(entity);
}


/**
 *
 * @param system
 */
void GameState::addSystem(System *system) {
    systems_.push_back(system);
}


/**
 *
 * @param signature
 * @return
 */
std::vector<Entity *> GameState::filterBySignature(unsigned long signature) {
    std::vector<Entity *> entities;
    for (const auto& entity: entities_) {
        if ((entity->signature & signature) == signature) {
            entities.push_back(entity);
        }
    }
    return entities;
}