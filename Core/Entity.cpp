#include "Entity.h"
#include <Core/GameState.h>

unsigned int Entity::nextId_ = 0;

void Entity::destroy()
{
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
