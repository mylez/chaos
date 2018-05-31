#include <iostream>
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Sprite.h"
#include <SDL2/SDL2_gfxPrimitives.h>


/**
 *
 * @param pos
 * @param size
 */
void Graphics::drawRect(Vec2i pos, Vec2i size)
{
    pos = transformPosition(pos);
    size = transformScale(size);

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
void Graphics::fillRect(Vec2i pos, Vec2i size)
{
    pos = transformPosition(pos);
    size = transformScale(size);

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
void Graphics::pushTransform(Vec2i offset, Vec2d scale)
{
    offset_ = offset_.add(offset);
    scale_ = scale_.hadamard(scale);
    offsetStack_.push_back(offset);
    scaleStack_.push_back(scale);
}


/**
 *
 * @param offset
 * @param scale
 */
void Graphics::pushOffset(Vec2i offset)
{
    Vec2d scale = Vec2d(1, 1);
    offset_ = offset_.add(offset);
    offsetStack_.push_back(offset);
    scaleStack_.push_back(scale);
}


/**
 *
 */
void Graphics::popTransform()
{
    Vec2i _offset = offsetStack_.back();
    Vec2d _scale = scaleStack_.back();

    offsetStack_.pop_back();
    scaleStack_.pop_back();

    offset_.x -= _offset.x;
    offset_.y -= _offset.y;

    scale_ = Vec2d(1, 1);
    for (unsigned long int i = 0; i < scaleStack_.size(); i++)
    {
        scale_ = scale_.hadamard(scaleStack_.at(i));
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
void Graphics::copyTexture(SDL_Texture *texture, Vec2i srcPos, Vec2i srcSize, Vec2i dstPos, Vec2i dstSize)
{
    dstPos = transformPosition(dstPos);
    dstSize = transformScale(dstSize);
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
void Graphics::drawDebugText(std::string msg, int fontSize, Vec2i pos)
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
Vec2i Graphics::transformPosition(Vec2i pos)
{
    return Vec2i(
        (int) ceil(scale_.x * pos.x) + offset_.x,
        (int) ceil(scale_.y * pos.y) + offset_.y
    );
}


/**
 *
 * @param size
 * @return
 */
Vec2i Graphics::transformScale(Vec2i size)
{
    return Vec2i(
        (int) ceil(size.x * scale_.x),
        (int) ceil(size.y * scale_.y)
    );
}


/**
 *
 * @param pos
 */
Vec2i Graphics::getWindowSize()
{
    int w = 0, h = 0;
    SDL_GetWindowSize(window_, &w, &h);
    return Vec2i(w, h);
}


void Graphics::drawString(std::string text, Vec2i pos)
{
    pos = transformPosition(pos);

    FC_Draw(font_, renderer_, pos.x, pos.y, "%s", text.c_str());
    //SDL_Rect box = FC_MakeRect(pos.x, pos.y, 0, 0);
    //double scale = (double)fontSize / (double)168;
    //FC_DrawBoxScale(font_, renderer_, box, FC_MakeScale(scale, scale), "%s", text.c_str());
}

void Graphics::drawLine(Vec2i a, Vec2i b)
{
    SDL_RenderDrawLine(renderer_, a.x, a.y, b.x, b.y);
}


void Graphics::drawPoint(Vec2i pos)
{}

Graphics::Graphics()
{}


void Graphics::loadFontCache()
{
    font_ = FC_CreateFont();
    FC_LoadFont(font_, renderer_, "media/fonts/vera-sans-mono/VeraMono.ttf", 14, FC_MakeColor(255, 255, 255, 255),
                TTF_STYLE_NORMAL);
}


/**
 *
 * @param c
 */
void Graphics::setColor(Color c)
{
    color_ = c;
    setColor(c.r, c.g, c.b, c.a);
}


/**
 *
 * @param sprite
 * @param size
 * @param pos
 */
void Graphics::drawSprite(Sprite *sprite, Vec2i size, Vec2i pos)
{
    //Vec2i dstPos = transformPosition(pos).add(Vec2i(0, size.y));
    //Vec2i dstSize = transformScale(size);
    SDL_Rect
        srcRect = sprite->getSourceRect(),
        dstRect = {
        pos.x,
        pos.y,// - size.y / 2,
        size.x,
        size.y
    };

    SDL_RenderCopy(renderer_, sprite->getTexture(), &srcRect, &dstRect);
}

void Graphics::drawTriangle(Vec2i a, Vec2i b, Vec2i c)
{
    trigonRGBA(renderer_,
               a.x, a.y,
               b.x, b.y,
               c.x, c.y,
               color_.r,
               color_.g,
               color_.b,
               color_.a
    );
}

void Graphics::fillTriangle(Vec2i a, Vec2i b, Vec2i c)
{
    filledTrigonRGBA(renderer_,
               a.x, a.y,
               b.x, b.y,
               c.x, c.y,
               color_.r,
               color_.g,
               color_.b,
               color_.a
    );
}
