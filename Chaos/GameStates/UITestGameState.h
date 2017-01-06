#ifndef CHAOS_UITESTGAMESTATE_H
#define CHAOS_UITESTGAMESTATE_H

#include "Core/GameState.h"
#include "Core/Graphics.h"
#include "UI/UI.h"

class UITestGameState:
    public GameState
{
private:
    UIComponent c1, c2, c3;

public:
    UI ui;

    UITestGameState();

    void render(Graphics *g);

    void handleInputEvent(SDL_Event *e);
};


#endif //CHAOS_UITESTGAMESTATE_H
