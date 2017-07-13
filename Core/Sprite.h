#ifndef CHAOS_SPRITE_H
#define CHAOS_SPRITE_H

#include <Core/Vec2i.h>
#include <Core/Vec2d.h>
#include <SDL2/SDL.h>
#include <iostream>

class Sprite
{
    SDL_Texture *texture_;

    SDL_Rect srcRect_;

    int currentFrame = 0;

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
     * @param sourceSize
     * @param targetSize
     */
    Sprite(SDL_Texture *texture, Vec2i pos, Vec2i sourceSize, Vec2d targetSize)
    {
        texture_ = texture;
        sourcePos_ = pos;
        sourceSize_ = sourceSize;
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
    SDL_Rect getSourceRect()
    {
        return SDL_Rect{sourcePos_.x + sourceSize_.x * currentFrame, sourcePos_.y, sourceSize_.x, sourceSize_.y};
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


    /**
     *
     * @param size
     */
    void setTargetSize(Vec2d size)
    {
        targetSize_ = size;
    }

    /**
     *
     * @return
     */
    Vec2d getTargetSize()
    {
        return targetSize_;
    }

    /**
     *
     * @param frame
     */
    void setFrame(int frame)
    {
        currentFrame = frame;
    }
};


#endif //CHAOS_SPRITE_H
