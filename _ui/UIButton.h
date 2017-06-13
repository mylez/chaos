#ifndef CHAOS_UIBUTTON_H
#define CHAOS_UIBUTTON_H

#include <string>
#include "Core/Graphics.h"
#include "UIComponent.h"


class UIButton:
    public UIComponent
{
public:
    std::string text;
    void render(Graphics *g);
};


#endif //CHAOS_UIBUTTON_H
