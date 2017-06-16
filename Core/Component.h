#ifndef CHAOS_COMPONENT_H
#define CHAOS_COMPONENT_H

#include <string>

class Entity;


const unsigned long

    COMPONENT_TRANSFORM = 0x00000001,
    COMPONENT_PHYSICS = 0x00000002,
    COMPONENT_COLLISION = 0x00000004,
    COMPONENT_SHAPE = 0x00000008,
    COMPONENT_RENDER = 0x00000010,
    COMPONENT_SPRITE = 0x00000020,
    COMPONENT_UPDATE = 0x00000040;


class Component
{

public:
    Entity *entity = nullptr;
    unsigned long label = 0;
    bool managed_ = false;

    virtual ~Component()
    {}
};


#endif //CHAOS_COMPONENT_H
