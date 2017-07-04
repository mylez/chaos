#ifndef CHAOS_SPRITESHEET_H
#define CHAOS_SPRITESHEET_H

#include "Sprite.h"

class SpriteSheet
{
    SDL_Texture *texture_ = nullptr;

public:

    Vec2i
        sheetSize,
        spriteSize,
        sourceSize;


    /**
     *
     * @param texture
     * @param sheetSize
     * @param spriteSize
     */
    SpriteSheet(SDL_Texture *texture, Vec2i sheetSize, Vec2i spriteSize):
        texture_(texture),
        sheetSize(sheetSize),
        spriteSize(spriteSize)
    {
        SDL_QueryTexture(texture, NULL, NULL, &sourceSize.x, &sourceSize.y);
    }


    /**
     *
     * @param i
     * @return
     */
    Sprite getSprite(int i)
    {
        return getSprite(i % sheetSize.x, i / sheetSize.y);
    }


    /**
     *
     * @param x
     * @param y
     * @return
     */
    Sprite getSprite(int x, int y)
    {
        Sprite sprite;
        sprite.setTexture(texture_);
        sprite.setSourcePosition(spriteSize.hadamard(Vec2i(x, y)));
        sprite.setSourceSize(spriteSize);
        //sprite.setTargetSize(spriteSize);
        //...

        return sprite;
    }


};


#endif //CHAOS_SPRITESHEET_H
