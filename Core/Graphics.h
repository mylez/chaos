#ifndef CHAOS_GRAPHICS_H
#define CHAOS_GRAPHICS_H

#include <SDL2/SDL.h>
#include <vector>
#include "Vec2I.h"
#include "Vec2D.h"

class Graphics
{
private:
    SDL_Renderer *renderer_;
    SDL_Window *window_;

    std::vector<Vec2I> offset_;
    std::vector<Vec2D> scale_;

public:
    void pushTransform(Vec2I offset, Vec2D scale);
    void popTransform();
    Vec2I transformPosition(Vec2I pos);
    void setWindowAndRenderer(SDL_Window* window, SDL_Renderer *renderer);
    void setColor(int r, int g, int b, int a);
    void fillRect(Vec2I pos, Vec2I size);
    void copyTexture(SDL_Texture *texture, Vec2I srcPos, Vec2I srcSize, Vec2I dstPos, Vec2I dstSize);
    void drawDebugText(std::string msg, int fontSize, Vec2I pos);
};


#endif //CHAOS_GRAPHICS_H
