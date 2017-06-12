#ifndef CHAOS_GRAPHICS_H
#define CHAOS_GRAPHICS_H

#include <SDL2/SDL.h>
#include <vector>
#include <SDL_FontCache.h>
#include "vec2i.h"
#include "vec2d.h"
#include "Sprite.h"

class Graphics
{
private:
    const int FONT_LOAD_SIZE = 720;

    SDL_Renderer *renderer_ = NULL;
    SDL_Window *window_ = NULL;
    FC_Font *font_ = NULL;

    vec2i offset_ = vec2i(0, 0);
    vec2d scale_ = vec2d(1, 1);

    std::vector<vec2i> offsetStack_;
    std::vector<vec2d> scaleStack_;

    void loadFontCache();

public:
    Graphics();

    void setColor(int r, int g, int b);
    void setColor(int r, int g, int b, int a);
    void drawSprite(Sprite *sprite, vec2i size, vec2i pos);
    void drawPoint(vec2i pos);
    void drawRect(vec2i pos, vec2i size);
    void drawString(std::string text, vec2i pos);
    void fillRect(vec2i pos, vec2i size);
    void copyTexture(SDL_Texture *texture, vec2i srcPos, vec2i srcSize, vec2i dstPos, vec2i dstSize);

    void pushOffset(vec2i offset);
    void pushTransform(vec2i offset, vec2d scale);
    void popTransform();
    vec2i transformPosition(vec2i pos);
    vec2i transformSize(vec2i size);

    void drawDebugText(std::string msg, int fontSize, vec2i pos);
    vec2i getWindowSize();

    void setWindowAndRenderer(SDL_Window* window, SDL_Renderer *renderer);
};


#endif //CHAOS_GRAPHICS_H
