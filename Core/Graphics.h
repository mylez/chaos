#ifndef CHAOS_GRAPHICS_H
#define CHAOS_GRAPHICS_H

#include <SDL2/SDL.h>
#include <vector>
#include <SDL_FontCache.h>
#include "Vec2i.h"
#include "Vec2d.h"

#include <Core/Color.h>

class Graphics
{
private:
    const int FONT_LOAD_SIZE = 720;

    SDL_Renderer *renderer_ = NULL;
    SDL_Window *window_ = NULL;
    FC_Font *font_ = NULL;

    Vec2i offset_ = Vec2i(0, 0);
    Vec2d scale_ = Vec2d(1, 1);

    std::vector<Vec2i> offsetStack_;
    std::vector<Vec2d> scaleStack_;

    void loadFontCache();

public:
    Graphics();

    void setColor(int r, int g, int b);
    void setColor(int r, int g, int b, int a);
    void setColor(Color c);
    // void drawSprite(Sprite *sprite, Vec2i size, Vec2i pos);
    void drawPoint(Vec2i pos);
    void drawRect(Vec2i pos, Vec2i size);
    void drawString(std::string text, Vec2i pos);
    void fillRect(Vec2i pos, Vec2i size);
    void copyTexture(SDL_Texture *texture, Vec2i srcPos, Vec2i srcSize, Vec2i dstPos, Vec2i dstSize);

    void pushOffset(Vec2i offset);
    void pushTransform(Vec2i offset, Vec2d scale);
    void popTransform();
    Vec2i transformPosition(Vec2i pos);
    Vec2i transformSize(Vec2i size);

    void drawDebugText(std::string msg, int fontSize, Vec2i pos);
    Vec2i getWindowSize();

    void setWindowAndRenderer(SDL_Window* window, SDL_Renderer *renderer);
};


#endif //CHAOS_GRAPHICS_H
