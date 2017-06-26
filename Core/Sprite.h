#ifndef CHAOS_SPRITE_H
#define CHAOS_SPRITE_H

#include <Core/Vec2i.h>
#include <SDL2/SDL.h>

class Sprite
{
    SDL_Texture *texture_;
    SDL_Rect srcRect_;
    Vec2i
        sourcePos_,
        sourceSize_;

    Vec2d targetSize_;
public:
    Sprite()
    {};

    /**
     *
     * @param texture
     * @param pos
     * @param size
     */
    Sprite(SDL_Texture *texture, Vec2i pos, Vec2i size, Vec2d targetSize)
    {
        texture_ = texture;
        sourcePos_ = pos;
        sourceSize_ = size;
        targetSize_ = targetSize;
    }

    /**
     *
     * @return
     */
    SDL_Texture *getTexture()
    {
        return texture_;
    }

    /**
     *
     * @param texture
     */
    void setTexture(SDL_Texture *texture)
    {
        texture_ = texture;
    }

    /**
     *
     * @return
     */
    SDL_Rect getSrcRect()
    {
        return SDL_Rect{sourcePos_.x, sourcePos_.y, sourceSize_.x, sourceSize_.y};
    }

    /**
     *
     * @param pos
     */
    void setSourcePosition(Vec2i pos)
    {
        sourcePos_ = pos;
    }

    /**
     *
     * @param size
     */
    void setSourceSize(Vec2i size)
    {
        sourceSize_ = size;
    }


    void setTargetSize(Vec2d size)
    {
        targetSize_ = size;
    }

    Vec2d getTargetSize()
    {
        return targetSize_;
    }
};


#endif //CHAOS_SPRITE_H
