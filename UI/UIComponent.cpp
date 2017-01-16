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
vec2i UIComponent::getSize()
{
    return size_;
}


/**
 *
 * @return
 */
vec2i UIComponent::getPosition()
{
    return position_;
}


/**
 *
 * @return
 */
void UIComponent::setPosition(vec2i position)
{
    position_ = position;
}


/**
 *
 * @return
 */
void UIComponent::setSize(vec2i size)
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
    g->fillRect(vec2i(0, 0), getSize());
    g->setColor(255, 255, 255);
    g->drawRect(vec2i(0, 0), getSize());
}
