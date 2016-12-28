#include <SDL2/SDL_events.h>
#include "Dummy.h"

Dummy::Dummy()
{
    this->addInputEventListener(SDL_QUIT, nullptr);
}

