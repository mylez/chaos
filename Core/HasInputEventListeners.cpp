#include <SDL2/SDL.h>
#include <iostream>
#include "HasInputEventListeners.h"


void HasInputEventListeners::addInputEventListener(Uint32 eventType, InputEventListener *listener)
{
    this->inputEventListeners[eventType].push_back(listener);
}


std::vector<InputEventListener *> &HasInputEventListeners::getInputEventListeners(Uint32 eventType)
{
    return this->inputEventListeners[eventType];
}


void HasInputEventListeners::handleInputEvent(SDL_Event *event)
{
    std::vector< InputEventListener * > listeners = this->getInputEventListeners(event->type);
    for (const auto &inputEventListener: listeners)
    {
        if (inputEventListener == nullptr)
        {
            std::cout << "error: inputEventListener is nullptr" << std::endl;
        }
        else
        {
            inputEventListener->handleInputEvent(event);
        }
    }
}



