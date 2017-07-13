#ifndef CHAOS_PLAYERSCRIPT_H
#define CHAOS_PLAYERSCRIPT_H

#include <Core/Script.h>
#include <Components/ShapeComponent.h>
#include <SDL2/SDL.h>


class PlayerScript:
    public Script
{
    double t = 0;

    SpriteComponent *sprite = nullptr;
    PhysicsComponent *physics = nullptr;

    /**
     *
     *
     */
    void update()
    {
        const Uint8 *key = SDL_GetKeyboardState(NULL);

        double a = 20;

        if(physics)physics->velocity = Vec2d(0, 0);


        if (key[SDL_SCANCODE_UP])       { physics->velocity.y =  a; }
        if (key[SDL_SCANCODE_DOWN])     { physics->velocity.y = -a; }
        if (key[SDL_SCANCODE_RIGHT])    { physics->velocity.x =  a; }
        if (key[SDL_SCANCODE_LEFT])     { physics->velocity.x = -a; }
    }


    /**
     *
     */
    void init()
    {
        sprite = entity->getComponent<SpriteComponent>();
        physics = entity->getComponent<PhysicsComponent>();
    }
};


#endif //CHAOS_PLAYERSCRIPT_H
