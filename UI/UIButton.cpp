#include "UIButton.h"
#include "SDL2/SDL_ttf.h"


/**
 *
 * @param g
 */
void UIButton::render(Graphics *g)
{
    g->setColor(30, 20, 220);
    g->drawRect(getPosition(), getSize());
}