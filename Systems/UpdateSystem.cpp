#include "UpdateSystem.h"
#include <Core/Entity.h>
#include <Components/UpdateComponent.h>

void UpdateSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    for (const auto &entity: entities)
    {
        UpdateComponent *update = entity->getComponent<UpdateComponent>();
        update->updateProcedure->update(game, entity, timeElapsed);
    }
}