#include <iostream>
#include "UI.h"

/**
 *
 * @param g
 */
void UI::render(Graphics *g)
{
    renderComponents(g, getRootComponent());
}


/**
 *
 * @param g
 * @param root
 */
void UI::renderComponents(Graphics *g, UIComponent *root)
{
    std::vector<UIComponent *> childComponents = root->getChildren();

    g->pushOffset(root->getPosition());
    root->render(g);

    for (const auto &child: childComponents)
    {
        renderComponents(g, child);
    }

    g->popTransform();
}


/**
 *
 * @return
 */
UIComponent *UI::getRootComponent()
{
    return &rootComponent_;
}


/**
 *
 * @param e
 */
void UI::handleInputEvent(SDL_Event *e)
{
    dispatchInputEvent(e, &rootComponent_, Vec2I(0, 0));
}


/**
 *
 * @param e
 * @param root
 * @param prevTopLeft
 */
void UI::dispatchInputEvent(SDL_Event *e, UIComponent *root, Vec2I prevTopLeft)
{
    Vec2I
        topLeft = prevTopLeft.add(root->getPosition()),
        bottomRight = topLeft.add(root->getSize());

    // this is a keyboard event on the
    if ((root == focusComponent_) && (e->type == SDL_KEYDOWN || e->type == SDL_KEYUP))
    {

    }
    else if (
        e->motion.x > topLeft.x &&
        e->motion.y > topLeft.y &&
        e->motion.x < bottomRight.x &&
        e->motion.y < bottomRight.y)
    {
        switch (e->type)
        {
            case SDL_MOUSEMOTION:
            {
                if (!root->mouseOver_)
                {
                    root->onMouseEnter(e);
                }
                root->mouseOver_ = true;
                root->onMouseMotion(e);
            } break;

            case SDL_MOUSEBUTTONDOWN:
            {
                root->onMouseDown(e);
            } break;

            case SDL_MOUSEBUTTONUP:
            {
                root->onMouseUp(e);
            } break;

            default:
                break;
        }
    }
    else if (e->type == SDL_MOUSEMOTION && root->mouseOver_)
    {
        root->mouseOver_ = false;
        root->onMouseLeave(e);
    }

    for (const auto &child: root->getChildren())
    {
        dispatchInputEvent(e, child, topLeft);
    }
}
