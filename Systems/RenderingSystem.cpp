#include <Components/TransformComponent.h>
#include <Core/Entity.h>
#include <Core/vec2d.h>
#include <Core/vec2i.h>
#include <Systems/RenderingSystem.h>

void RenderingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    vec2i window = graphics->getWindowSize();
    for (const auto &entity: entities) {
        TransformComponent *transform = entity->getComponent<TransformComponent>();
        vec2i
            position = transform->position.entryMult(vec2d(1, -1)).asVec2i().add(vec2i(5, window.y)),
            size = vec2i(5, 5);
        graphics->setColor(255, 0, 0);
        graphics->fillRect(position, size);
    }
}
