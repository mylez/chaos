//
// Created by Miles on 12/22/16.
//

#ifndef CHAOS_RENDERABLE_H
#define CHAOS_RENDERABLE_H


class Renderable
{
public:
    virtual void render(SDL_Renderer *) = 0;
};


#endif //CHAOS_RENDERABLE_H
