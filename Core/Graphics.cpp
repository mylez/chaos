#include <iostream>
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Vec2I.h"


/**
 *
 * @param pos
 * @param size
 */
void Graphics::fillRect(Vec2I pos, Vec2I size)
{
    SDL_Rect rect = {pos.x, pos.y, size.x, size.y};
    SDL_RenderFillRect(renderer_, &rect);
}


/**
 *
 * @param offset
 * @param scale
 */
void Graphics::pushTransform(Vec2I offset, Vec2D scale)
{
    offset_.push_back(offset);
    scale_.push_back(scale);
}


/**
 *
 */
void Graphics::popTransform()
{
    offset_.pop_back();
    scale_.pop_back();
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

}


/**
 *
 * @param msg
 * @param fontSize
 * @param pos
 */
void Graphics::drawDebugText(std::string msg, int fontSize, Vec2I pos)
{

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
    Vec2I sumOffset;

    for (unsigned long i = 0; i < offset_.size(); i++)
    {
        sumOffset.x += offset_.at(i).x;
        sumOffset.y += offset_.at(i).y;
    }

    return Vec2I(
        pos.x + sumOffset.x,
        pos.y + sumOffset.y
    );
}