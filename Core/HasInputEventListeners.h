#ifndef CHAOS_HASINPUTEVENTLISTENERS_H
#define CHAOS_HASINPUTEVENTLISTENERS_H

#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include "InputEventListener.h"

class HasInputEventListeners
{
public:
    void addInputEventListener(Uint32 eventType, InputEventListener *listener);
    std::vector< InputEventListener * > &getInputEventListeners(Uint32 eventType);
private:
    std::map< Uint32, std::vector< InputEventListener * > > inputEventListeners;
};


#endif //CHAOS_HASINPUTEVENTLISTENERS_H
