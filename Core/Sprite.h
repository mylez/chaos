#ifndef CHAOS_SPRITE_H
#define CHAOS_SPRITE_H

#include <Core/Vec2i.h>
#include <SDL2/SDL.h>

class Sprite
{
    SDL_Texture *texture_;
    SDL_Rect srcRect_;
    Vec2i pos_, size_;
public:
    Sprite()
    {};

    /**
     *
     * @param texture
     * @param pos
     * @param size
     */
    Sprite(SDL_Texture *texture, Vec2i pos, Vec2i size)
    {
        texture_ = texture;
        pos_ = pos;
        size_ = size;
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
        return SDL_Rect{pos_.x, pos_.y, size_.x, size_.y};
    }

    /**
     *
     * @param pos
     */
    void setSourcePosition(Vec2i pos)
    {
        pos_ = pos;
    }

    /**
     *
     * @param size
     */
    void setSourceSize(Vec2i size)
    {
        size_ = size;
    }
};


#endif //CHAOS_SPRITE_H
