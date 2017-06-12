#include <iostream>
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "SDL_FontCache.h"
#include "Err.h"


/**
 *
 * @param pos
 * @param size
 */
void Graphics::drawRect(vec2i pos, vec2i size)
{
    pos = transformPosition(pos);
    size = transformSize(size);
    
    SDL_Rect rect = {
        pos.x, pos.y,
        size.x, size.y
    };

    SDL_RenderDrawRect(renderer_, &rect);
}


/**
 *
 * @param pos
 * @param size
 */
void Graphics::fillRect(vec2i pos, vec2i size)
{
    pos = transformPosition(pos);
    size = transformSize(size);

    SDL_Rect rect = {
        pos.x, pos.y,
        size.x, size.y
    };

    SDL_RenderFillRect(renderer_, &rect);
}


/**
 *
 * @param offset
 * @param scale
 */
void Graphics::pushTransform(vec2i offset, vec2d scale)
{
    offset_ = offset_.add(offset);
    scale_ = scale_.entryMult(scale);
    offsetStack_.push_back(offset);
    scaleStack_.push_back(scale);
}


/**
 *
 * @param offset
 * @param scale
 */
void Graphics::pushOffset(vec2i offset)
{
    vec2d scale = vec2d(1, 1);
    offset_ = offset_.add(offset);
    offsetStack_.push_back(offset);
    scaleStack_.push_back(scale);
}


/**
 *
 */
void Graphics::popTransform()
{
    vec2i _offset = offsetStack_.back();
    vec2d _scale = scaleStack_.back();

    offsetStack_.pop_back();
    scaleStack_.pop_back();

    offset_.x -= _offset.x;
    offset_.y -= _offset.y;

    scale_ = vec2d(1, 1);
    for (unsigned long int i = 0; i < scaleStack_.size(); i++)
    {
        scale_ = scale_.entryMult(scaleStack_.at(i));
    }
}


/**
 *
 * @param texture
 * @param srcPos
 * @param srcSize
 * @param dstPos
 * @param dstSize
 */
void Graphics::copyTexture(SDL_Texture *texture, vec2i srcPos, vec2i srcSize, vec2i dstPos, vec2i dstSize)
{
    dstPos = transformPosition(dstPos);
    dstSize = transformSize(dstSize);
    SDL_Rect
        srcRect = {
            srcPos.x,
            srcPos.y,
            srcSize.x,
            srcSize.y
        },
        dstRect = {
            dstPos.x,
            dstPos.y,
            dstSize.x,
            dstSize.y
        };

    SDL_RenderCopy(renderer_, texture, &srcRect, &dstRect);
}


/**
 *
 * @param msg
 * @param fontSize
 * @param pos
 */
void Graphics::drawDebugText(std::string msg, int fontSize, vec2i pos)
{
    // todo
}


/**
 *
 * @param r
 * @param g
 * @param b
 */
void Graphics::setColor(int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer_, r, g, b, 255);
}


/**
 *
 * @param r
 * @param g
 * @param b
 * @param a
 */
void Graphics::setColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}


/**
 *
 * @param window
 * @param renderer
 */
void Graphics::setWindowAndRenderer(SDL_Window *window, SDL_Renderer *renderer)
{
    renderer_ = renderer;
    window_ = window;

    loadFontCache(); // todo - find better place for this
}


/**
 *
 * @param pos
 */
vec2i Graphics::transformPosition(vec2i pos)
{
    return vec2i(
        (int)ceil(scale_.x * pos.x) + offset_.x,
        (int)ceil(scale_.y * pos.y) + offset_.y
    );
}


/**
 *
 * @param size
 * @return
 */
vec2i Graphics::transformSize(vec2i size)
{
    return vec2i(
        (int)ceil(size.x * scale_.x),
        (int)ceil(size.y * scale_.y)
    );
}


/**
 *
 * @param pos
 */
vec2i Graphics::getWindowSize()
{
    int w = 0, h = 0;
    SDL_GetWindowSize(window_, &w, &h);
    return vec2i(w, h);
}


void Graphics::drawString(std::string text, vec2i pos)
{
    pos = transformPosition(pos);

    FC_Draw(font_, renderer_, pos.x, pos.y, "%s", text.c_str());
    //SDL_Rect box = FC_MakeRect(pos.x, pos.y, 0, 0);
    //double scale = (double)fontSize / (double)168;
    //FC_DrawBoxScale(font_, renderer_, box, FC_MakeScale(scale, scale), "%s", text.c_str());
}


void Graphics::drawPoint(vec2i pos)
{

}

Graphics::Graphics()
{

}

void Graphics::loadFontCache()
{
    font_ = FC_CreateFont();
    FC_LoadFont(font_, renderer_, "media/fonts/vera-sans-mono/VeraMono.ttf", 14, FC_MakeColor(255, 255, 255, 255),
                TTF_STYLE_NORMAL);
}


/**
 *
 * @param sprite
 * @param size
 * @param pos
 *
void Graphics::drawSprite(Sprite *sprite, vec2i size, vec2i pos)
{
    vec2i
        dstPos = transformPosition(pos).add(vec2i(0, -size.y)),
        dstSize = transformSize(size);

    SDL_Rect
        srcRect = sprite->getSrcRect(),
        dstRect = {
            (int)floor(dstPos.x),
            (int)floor(dstPos.y),
            (int)floor(abs(dstSize.x)),
            (int)floor(abs(dstSize.y))
        };

    SDL_RenderCopy(renderer_, sprite->getTexture(), &srcRect, &dstRect);
}
*/