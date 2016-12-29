#ifndef CHAOS_GAMEOBJECT_H
#define CHAOS_GAMEOBJECT_H

#include "HasProperties.h"
#include "HasPosition.h"

class GameObject:
    public HasProperties,
    public HasPosition
{

};


#endif //CHAOS_GAMEOBJECT_H
