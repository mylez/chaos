#ifndef CHAOS_SPRITE_H
#define CHAOS_SPRITE_H


class Sprite
{
    SDL_Texture *texture_;
    SDL_Rect srcRect_;
    vec2i pos_, size_;
public:
    Sprite()
    {};

    Sprite(SDL_Texture *texture, vec2i pos, vec2i size)
    {
        texture_ = texture;
        pos_ = pos;
        size_ = size;
    }

    SDL_Texture *getTexture()
    { return texture_; }

    void setTexture(SDL_Texture *texture)
    { texture_ = texture; }

    SDL_Rect getSrcRect()
    { return SDL_Rect{ pos_.x, pos_.y, size_.x, size_.y }; }

    void setSourcePosition(vec2i pos)
    { pos_ = pos; }

    void setSourceSize(vec2i size)
    { size_ = size; }
};


#endif //CHAOS_SPRITE_H
