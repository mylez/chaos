#ifndef CHAOS_SPRITECOMPONENT_H
#define CHAOS_SPRITECOMPONENT_H

#include <Core/Component.h>
#include <Core/Sprite.h>

class SpriteComponent:
    public Component
{
public:
    Sprite sprite;
    SpriteComponent()
    { label = COMPONENT_SPRITE; }
};


#endif //CHAOS_SPRITECOMPONENT_H
