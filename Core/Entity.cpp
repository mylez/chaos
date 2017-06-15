#include "Entity.h"
#include <Core/GameState.h>

unsigned int genEntityId()
{
    static unsigned int id_;
    return ++id_;
}

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
