#ifndef CHAOS_INPUTEVENTLISTENER_H
#define CHAOS_INPUTEVENTLISTENER_H


#include <SDL2/SDL.h>

class InputEventListener
{
public:
    virtual void handleInputEvent(SDL_Event *event)
    {};
};


#endif //CHAOS_INPUTEVENTLISTENER_H
