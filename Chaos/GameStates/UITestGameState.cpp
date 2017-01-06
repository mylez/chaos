#include "UITestGameState.h"


UITestGameState::UITestGameState()
{
    c1.setPosition(Vec2I(10, 10));
    c1.setSize(Vec2I(50, 20));

    c2.setPosition(Vec2I(70, 10));
    c2.setSize(Vec2I(50, 20));

    c3.setPosition(Vec2I(130, 10));
    c3.setSize(Vec2I(50, 20));

    for (int i = 0; i < 100; i++)
    {
        UIComponent *uiComponent = new UIComponent();
        uiComponent->setPosition(Vec2I(
            rand() % 1000 + 100,
            rand() % 1000 + 100
        ));
        uiComponent->setSize(Vec2I(
            rand() % 100 + 20,
            rand() % 100 + 20
        ));
        for (int i = 0; i < 10; i++)
        {

            UIComponent *uiComponent2 = new UIComponent();
            uiComponent2->setPosition(Vec2I(
                rand() % 50 + 100,
                rand() % 50 + 100
            ));
            uiComponent2->setSize(Vec2I(
                rand() % 10 + 20,
                rand() % 10 + 20
            ));
            uiComponent->addComponent(uiComponent2);
        }
        ui.getRootComponent()->addComponent(uiComponent);
    }

    ui.getRootComponent()->addComponent(&c1);
    ui.getRootComponent()->addComponent(&c2);
    c2.addComponent(&c3);
}


/**
 *
 * @param g
 */
void UITestGameState::render(Graphics *g)
{
    ui.render(g);
}

void UITestGameState::handleInputEvent(SDL_Event *e)
{
    ui.handleInputEvent(e);
}