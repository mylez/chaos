#ifndef CHAOS_GAMEOBJECT_H
#define CHAOS_GAMEOBJECT_H

#include "HasProperties.h"
#include "HasPosition.h"
#include "HasUpdate.h"
#include "HasRender.h"
#include "Sprite.h"

class Entity:
    public HasProperties,
    public HasPosition
{
public:
    Sprite sprite;
};


#endif //CHAOS_GAMEOBJECT_H
