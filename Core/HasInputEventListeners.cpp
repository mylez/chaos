#include <SDL2/SDL.h>
#include <iostream>
#include "HasInputEventListeners.h"


void HasInputEventListeners::addInputEventListener(Uint32 eventType, InputEventListener *listener)
{
    inputEventListeners_[eventType].push_back(listener);
}


std::vector<InputEventListener *> &HasInputEventListeners::getInputEventListeners_(Uint32 eventType)
{
    return inputEventListeners_[eventType];
}


void HasInputEventListeners::handleInputEvent(SDL_Event *event)
{
    std::vector< InputEventListener * > listeners = getInputEventListeners_(event->type);
    for (const auto &inputEventListener: listeners)
    {
        if (inputEventListener == nullptr)
        {
            std::cout << "warning: inputEventListener is nullptr for event type: " << event->type << std::endl;
        }
        else
        {
            inputEventListener->handleInputEvent(event);
        }
    }
}



