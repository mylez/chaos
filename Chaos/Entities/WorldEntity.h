#ifndef CHAOS_WORLDENTITY_H
#define CHAOS_WORLDENTITY_H

#include <Core/HasInputEventListeners.h>
#include <Core/InputEventListener.h>
#include <Core/HasProperties.h>
#include <Core/HasUpdate.h>
#include <Core/HasRender.h>

/**
 *
 *
 */
class WorldEntity:
    public HasProperties,
    public InputEventListener,
    public HasUpdate,
    public HasRender
{
public:
    vec2i tile = vec2i(0, 0);
    vec2d pos = vec2d(0, 0);
    Sprite sprite;
};

#endif