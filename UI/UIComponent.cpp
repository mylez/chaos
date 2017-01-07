#include "UIComponent.h"


void UIComponent::addComponent(UIComponent *component)
{
    children_.push_back(component);
}


/**
 *
 * @return
 */
std::vector<UIComponent *> UIComponent::getChildren()
{
    return children_;
}


/**
 *
 * @return
 */
Vec2I UIComponent::getSize()
{
    return size_;
}


/**
 *
 * @return
 */
Vec2I UIComponent::getPosition()
{
    return position_;
}


/**
 *
 * @return
 */
void UIComponent::setPosition(Vec2I position)
{
    position_ = position;
}


/**
 *
 * @return
 */
void UIComponent::setSize(Vec2I size)
{
    size_ = size;
}


/**
 *
 * @param g
 */
void UIComponent::render(Graphics *g)
{
    g->setColor(red_, green_, blue_);
    g->fillRect(Vec2I(0, 0), getSize());
    g->setColor(255, 255, 255);
    g->drawRect(Vec2I(0, 0), getSize());
}
