#ifndef CHAOS_COMPONENT_H
#define CHAOS_COMPONENT_H

#include <string>

class Entity;


enum {
    COMPONENT_TRANSFORM     = 0x00000001,
    COMPONENT_PHYSICS       = 0x00000002,
    COMPONENT_COLLISION     = 0x00000004,
    COMPONENT_SHAPE         = 0x00000008,
    COMPONENT_RENDER        = 0x00000010,
};


class Component
{
public:
    Entity *entity;
    unsigned long label;
    virtual ~Component(){}
};


#endif //CHAOS_COMPONENT_H
