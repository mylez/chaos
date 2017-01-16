#ifndef CHAOS_UI_H
#define CHAOS_UI_H

#include <vector>
#include "Core/vec2i.h"
#include "Core/HasRender.h"
#include "Core/HasUpdate.h"
#include "Core/InputEventListener.h"
#include "Core/Graphics.h"
#include "UIComponent.h"

class UI:
    public HasRender,
    public HasUpdate,
    public InputEventListener
{
private:
    UIComponent
        rootComponent_,
        *focusComponent_;

    void renderComponents(Graphics *g, UIComponent *root);
    void dispatchInputEvent(SDL_Event *e, UIComponent *root, vec2i prevTopLeft);

public:
    virtual void render(Graphics *g);
    UIComponent *getRootComponent();
    void handleInputEvent(SDL_Event *e);
};


#endif //CHAOS_UI_H
