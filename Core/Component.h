#ifndef CHAOS_COMPONENT_H
#define CHAOS_COMPONENT_H

#include <string>

class Entity;

enum {
    COMPONENT_TRANSFORM     = 0x000000001,
    COMPONENT_PHYSICS       = 0x000000010,
    COMPONENT_COLLISION     = 0x000000100,
};

class Component
{
public:
    Entity *entity;
    unsigned long label;
};


#endif //CHAOS_COMPONENT_H
