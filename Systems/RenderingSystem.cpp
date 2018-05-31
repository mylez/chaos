#include <Core/Entity.h>
#include <Core/Game.h>
#include <Core/SpriteSheet.h>
#include <Components/ShapeComponent.h>
#include <Components/SpriteComponent.h>

const double
        i_p_cm = 0.3937007874,  // disp in per disp cm
        cm_p_m = 1,             // disp cm,
        d = i_p_cm * cm_p_m;    // disp in per world meter


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
 * @param timeElapsed
 * @param entity
 * @param entities
 */
void RenderingSystem::update(double timeElapsed, std::vector<Entity *> entities)
{
    windowSize_i_ = graphics_->getWindowSize();
    windowSize_d_ = Vec2d(windowSize_i_.x, windowSize_i_.y);

    for (const auto &entity:entities)
    {
        if (entity->hasComponent<SpriteComponent>())
        {
            renderSprite(entity, timeElapsed);
        }

        if (entity->hasComponent<ShapeComponent>())
        {
            renderShape(entity);
        }
    }

    // cursor stuff todo - do right then move
    Vec2i mouse_pos = game->getMousePosition();
    graphics_->setColor(Color(255, 255, 255));
    graphics_->fillRect(mouse_pos, Vec2i(4, 4));
    graphics_->setColor(Color(30, 30, 30));
    graphics_->drawRect(mouse_pos, Vec2i(5, 5));
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
    auto *transform = entity->getComponent<TransformComponent>();
    auto *shape = entity->getComponent<ShapeComponent>();
    Vec2i
            p_ = worldToDisp(transform->position.add(shape->getSize().hadamard(-.5, .5))),
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
    auto sprite = spriteComponent->getSprite();

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
 * @param s_
 * @return
 */
Vec2d RenderingSystem::scale_dispToWorld(Vec2i s_)
{
    double  dh = d*game->dispHDPI,
            dv = d*game->dispVDPI;
    return Vec2d(s_.x/dh, s_.y/dv);
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
    return Vec2i(s.x*dh, s.y*dv);
}
