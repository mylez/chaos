#include "Entity.h"

unsigned int genEntityId()
{
    static unsigned int id_;
    return ++id_;
}