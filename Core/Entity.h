#ifndef CHAOS_GAMEOBJECT_H
#define CHAOS_GAMEOBJECT_H

#include "HasProperties.h"
#include "HasPosition.h"
#include "HasUpdate.h"
#include "HasRender.h"

class Entity:
    public HasProperties,
    public HasPosition,
    public HasUpdate,
    public HasRender
{

};


#endif //CHAOS_GAMEOBJECT_H
