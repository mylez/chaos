#include <iostream>
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Vec2I.h"


/**
 *
 * @param pos
 * @param size
 */
void Graphics::drawRect(Vec2I pos, Vec2I size)
{
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
void Graphics::fillRect(Vec2I pos, Vec2I size)
{
    SDL_Rect rect = {
        offset_.x + (int)(pos.x * scale_.y), offset_.y + (int)(pos.y * scale_.y),
        size.x, size.y
    };

    SDL_RenderFillRect(renderer_, &rect);
}


/**
 *
 * @param offset
 * @param scale
 */
void Graphics::pushTransform(Vec2I offset, Vec2D scale)
{
    offset_ = offset_.add(offset);
    scale_ = scale_.entryMult(scale);
    offsetStack_.push_back(offset);
    scaleStack_.push_back(scale);
}


/**
 *
 */
void Graphics::popTransform()
{
    Vec2I _offset = offsetStack_.back();
    Vec2D _scale = scaleStack_.back();

    offsetStack_.pop_back();
    scaleStack_.pop_back();

    offset_.x -= _offset.x;
    offset_.y -= _offset.y;

    scale_.x /= _scale.x;
    scale_.y /= _scale.y;
}


/**
 *
 * @param texture
 * @param srcPos
 * @param srcSize
 * @param dstPos
 * @param dstSize
 */
void Graphics::copyTexture(SDL_Texture *texture, Vec2I srcPos, Vec2I srcSize, Vec2I dstPos, Vec2I dstSize)
{
    dstPos = transformPosition(dstPos);

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

    //std::cout << srcRect.x << " " << srcRect.y << " " << srcSize.x << " " << srcSize.y << std::endl;
    //std::cout << dstRect.x << " " << dstRect.y << " " << dstSize.x << " " << dstSize.y << std::endl << std::endl;

    SDL_RenderCopy(renderer_, texture, &srcRect, &dstRect);
}


/**
 *
 * @param msg
 * @param fontSize
 * @param pos
 */
void Graphics::drawDebugText(std::string msg, int fontSize, Vec2I pos)
{
    // todo
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
}


/**
 *
 * @param pos
 */
Vec2I Graphics::transformPosition(Vec2I pos)
{
    return Vec2I(
        scale_.x * pos.x + offset_.x,
        scale_.y * pos.y + offset_.y
    );
}


/**
 *
 * @param pos
 */
Vec2I Graphics::getWindowSize()
{
    int w = 0, h = 0;
    SDL_GetWindowSize(window_, &w, &h);
    return Vec2I(w, h);
}