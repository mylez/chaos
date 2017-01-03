#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"
#include "SceneGameState.h"


/**
 * todo - make this loop more complicated
 *
 */
void Game::loop()
{
    Uint32
        timeElapsed = 0,
        timeCurrent = 0,
        timePrevious = SDL_GetTicks();

    isRunning_ = true;

    // todo - get rid of this stupid fps meter and put it somewhere proper
    TTF_Font *font = TTF_OpenFont("media/fonts/Bitstream-Vera-Sans-Mono/VeraMono.ttf", 12);
    int h, w, cycles = 0;
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Shit...", SDL_Color{255, 255, 255, 255});
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer_, textSurface);

    while (isRunning_)
    {
        timeCurrent = SDL_GetTicks();
        timeElapsed = timeCurrent - timePrevious;
        timePrevious = timeCurrent;

        pollInputEvents();
        gameState_->update((double) timeElapsed);

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);

        gameState_->render(&graphics_);

        if (cycles++ % 10 == 0)
        {
            Uint32 fpsCheck_curr,
                fpsCheck_prev;
            fpsCheck_curr = SDL_GetTicks();
            double fps = 10 * (1000 / (double)(fpsCheck_curr - fpsCheck_prev));
            char thing[128];
            snprintf(thing, 128, "fps: %d", (int)fps);
            textSurface = TTF_RenderText_Solid(font, thing, SDL_Color{255, 255, 255, 255});
            textTexture = SDL_CreateTextureFromSurface(renderer_, textSurface);
            TTF_SizeText(font, thing, &h, &w);
            fpsCheck_prev = fpsCheck_curr;
        }

        SDL_Rect fpsTextRect{10, 10, h, w};
        SDL_RenderCopy(renderer_, textTexture, NULL, &fpsTextRect);
        SDL_RenderPresent(renderer_);
    }
}


/**
 *
 */
void Game::pollInputEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        gameState_->handleInputEvent(&event);
        if (event.type == SDL_QUIT)
        {
            isRunning_ = false;
        }
    }
}


/**
 *
 */
Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    gameState_ = new SceneGameState();
    window_ = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500,
                               SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer_ = SDL_CreateRenderer(window_, -1,  SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    std::cout << "fucker ass " << renderer_ << "\n\n";

    graphics_.setWindowAndRenderer(window_, renderer_);
    assetLibrary_.setRenderer(renderer_);

    SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
}


/**
 *
 */
Game::~Game()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

