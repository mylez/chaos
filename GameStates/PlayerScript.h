#ifndef CHAOS_PLAYERSCRIPT_H
#define CHAOS_PLAYERSCRIPT_H

#include <Core/Script.h>
#include <Components/ShapeComponent.h>

template <int U, int D, int R, int L>
class PlayerScript:
    public Script
{
    double t = 0;
    void update()
    {
        handleMovement();

        t += timeElapsed;

        if (entity->hasSpatialCacheKey(0, 1) || entity->hasSpatialCacheKey(-1, -1))
        {
            entity->getComponent<ShapeComponent>()->setColor(Color(255, 0, 0));
        }
        else
        {
            entity->getComponent<ShapeComponent>()->setColor(Color(0, 0, 255));
        }
    }

    void handleMovement()
    {
        double a = 500;

        PhysicsComponent *ph = entity->getComponent<PhysicsComponent>();

        const Uint8 *keys = SDL_GetKeyboardState(NULL);

        ph->acceleration = Vec2d(0, 0);

        if (keys[U])    { ph->acceleration.y =  a; }
        if (keys[D])    { ph->acceleration.y = -a; }
        if (keys[R])    { ph->acceleration.x =  a; }
        if (keys[L])    { ph->acceleration.x = -a; }
    }
};


#endif //CHAOS_PLAYERSCRIPT_H
