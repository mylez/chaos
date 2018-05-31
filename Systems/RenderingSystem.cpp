#include <Core/Entity.h>
#include <Core/Game.h>
#include <Core/SpriteSheet.h>
#include <Components/ShapeComponent.h>
#include <Components/SpriteComponent.h>
#include <Components/ScriptComponent.h>

/**
 *
 * @param timeElapsed
 * @param entity
 * @param entities
 */
void RenderingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    // update the window size in case
    windowSize_i_ = graphics_->getWindowSize();
    windowSize_d_ = Vec2d(windowSize_i_.x, windowSize_i_.y);
    updateCursor();

    for (const auto &entity:entities)
    {
        if (entity->hasComponent<SpriteComponent>())
        { renderSprite(entity, timeElapsed); }

        if (entity->hasComponent<ShapeComponent>())
        { renderShape(entity); }
    }

    renderCursor();
}


/**
 * Create a fresh RenderingSystem object after being added to a GameState
 *
 */
void RenderingSystem::init()
{
    // references (not works cited!)
    assetLibrary_ = game->getAssetLibrary();
    graphics_ = game->getGraphics();

    // hide system cursor
    SDL_ShowCursor(SDL_DISABLE);
}


/**
 * Draw a square with a center at the transform position of the entity.
 *
 * @param entity
 */
void RenderingSystem::renderShape(Entity *entity)
{
    auto transform = entity->transform;
    auto shape = entity->getComponent<ShapeComponent>();
    Vec2i
            p_ = worldToDisp(transform.position.add(shape->getSize().hadamard(-.5, .5))),
            s_ = scale_worldToDisp(shape->getSize());

    graphics_->setColor(shape->getColor());
    graphics_->fillRect(p_, s_);
}


/**
 *q
 * @param entity
 */
void RenderingSystem::renderSprite(Entity *entity, double timeElapsed)
{
    auto transform = entity->getComponent<TransformComponent>();
    auto spriteComponent = entity->getComponent<SpriteComponent>();

    Sprite sprite = spriteComponent->getSprite();

    Vec2i p_ = worldToDisp(transform->position);

    graphics_->drawSprite(
        &sprite,
        sprite.getTargetSize()
            .asVec2i(),
        p_
    );
}





/**
 *
 */
void RenderingSystem::updateCursor()
{
    mousePosition = game->getMousePosition();
    auto p = dispToWorld(mousePosition);
    auto entities = game->gameState_->filterEntitiesByPosition(p);

    for (auto entity: entities)
    {

        if (!cursorHover[entity->id])
        {
            std::cout << "onCursorEnter\n";
            // onCursorEnter
        }
        // onCursorHover
        cursorHover[entity->id] = true;
        currentHover[entity->id] = true;
    }

    std::vector<unsigned int> toDelete;
    for (const auto& e: cursorHover)
    {
        if (e.second != currentHover[e.first])
        {
            std::cout << "onCursorExit\n";
            // onCursorExit
            toDelete.push_back(e.first);
        }
    }

    for (const auto id: toDelete)
    {
        cursorHover.erase(id);
    }

    currentHover.clear();
}

/*
        for (auto script: entity->getComponent<ScriptComponent>()->scripts)
        {
            if (!entity->cursorHover_)
            {
                script->onCursorEnter();
            }
            script->onCursorHover();
        }
 */

/**
 *
 */
void RenderingSystem::renderCursor()
{
    graphics_->setColor(Color(255, 255, 255));
    graphics_->fillRect(mousePosition, Vec2i(4, 4));
    graphics_->setColor(Color(30, 30, 30));
    graphics_->drawRect(mousePosition, Vec2i(5, 5));
}



/**
 *
 * @param p_
 * @return
 */
Vec2d RenderingSystem::dispToWorld(Vec2i p_){
    double  dh = d*game->dispHDPI,  // hrz dots,
            dv = d*game->dispVDPI;  // vrt dots per world meter

    return {
            +(p_.x - windowSize_d_.x/2)/dh,
            -(p_.y - windowSize_d_.y/2)/dv
    };
}


/**
 *
 * @param p
 * @return
 */
Vec2i RenderingSystem::worldToDisp(Vec2d p)
{
    double  dh = d*game->dispHDPI,
            dv = d*game->dispVDPI;

    return Vec2d(
            +dh*p.x + windowSize_d_.x/2,
            -dv*p.y + windowSize_d_.y/2
    ).asVec2i();
}


/**
 *
 * @param s_
 * @return
 */
Vec2d RenderingSystem::scale_dispToWorld(Vec2i s_)
{
    double  dh = d*game->dispHDPI,
            dv = d*game->dispVDPI;
    return {s_.x/dh, s_.y/dv};
}


/**
 *
 * @param s
 * @return
 */
Vec2i RenderingSystem::scale_worldToDisp(Vec2d s)
{
    double  dh = d*game->dispHDPI,
            dv = d*game->dispVDPI;
    return Vec2d(s.x*dh, s.y*dv).asVec2i();
}