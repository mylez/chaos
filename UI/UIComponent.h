#ifndef CHAOS_UICOMPONENT_H
#define CHAOS_UICOMPONENT_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Core/HasRender.h"
#include "Core/HasUpdate.h"

class UIComponent:
    public HasRender,
    public HasUpdate
{
private:
    vec2i
        size_,
        position_;

    std::vector<UIComponent *>
        children_;

    int
        red_ = rand() % 256,
        green_ = rand() % 256,
        blue_ = rand() % 256;

public:

    bool mouseOver_ = false;

    std::vector<UIComponent *> getChildren();

    vec2i getSize();

    vec2i getPosition();

    void setPosition(vec2i position);

    void setSize(vec2i size);

    void addComponent(UIComponent *component);

    void render(Graphics *g);

    virtual void onMouseMotion(SDL_Event *e)
    {};

    virtual void onMouseEnter(SDL_Event *e)
    {red_ = 255; green_ = 0; blue_ = 0;};

    virtual void onMouseLeave(SDL_Event *e)
    {red_ = 30; green_ = 30; blue_ = 30;};

    virtual void onMouseDown(SDL_Event *e)
    {red_ = 255; green_ = 0; blue_ = 255;};

    virtual void onMouseUp(SDL_Event *e)
    {red_ = 255; green_ = 255; blue_ = 0;};

};
#endif //CHAOS_UICOMPONENT_H
