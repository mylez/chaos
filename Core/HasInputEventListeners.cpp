#include <SDL2/SDL.h>
#include "HasInputEventListeners.h"

void HasInputEventListeners::addInputEventListener(Uint32 eventType, InputEventListener *listener)
{
    this->inputEventListeners[eventType].push_back(listener);
}

std::vector<InputEventListener *> &HasInputEventListeners::getInputEventListeners(Uint32 eventType)
{
    return this->inputEventListeners[eventType];
}

