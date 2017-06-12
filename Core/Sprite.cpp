#include "Sprite.h"

/**
 *
 * @return
 */
SDL_Texture * Sprite::getTexture()
{
    return texture_;
}


/**
 *
 * @return
 */
SDL_Rect Sprite::getSrcRect()
{
    return srcRect_;
}