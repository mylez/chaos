#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Game.h"


/**
 * todo - make this loop more complicated
 *
 */
void Game::loop()
{
    Uint32
        timeElapsed = 0,
        timeCurrent = 0,
        timePrevious = SDL_GetTicks(),

        fpsCheck_curr = 0,
        fpsCheck_prev = 0;

    isRunning_ = true;

    // todo - get rid of this stupid fps meter and put it somewhere proper
    int cycles = 0;
    char fpsMsg[128];

    while (isRunning_)
    {
        timeCurrent = SDL_GetTicks();
        timeElapsed = timeCurrent - timePrevious;
        timePrevious = timeCurrent;

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);
        pollInputEvents();

        gameState_->update(((double)timeElapsed) / 1000);

        if (cycles++ % 25 == 0)
        {
            fpsCheck_curr = SDL_GetTicks();
            double fps = 25 * (1000 / (double) (fpsCheck_curr - fpsCheck_prev));
            snprintf(fpsMsg, 128, "fps: %.3f", fps);
            fpsCheck_prev = fpsCheck_curr;
        }

        graphics_.drawString(fpsMsg, vec2i(10, 10));
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
        //gameState_->handleInputEvent(&event);
        if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q))
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
    //gameState_ = new GameState();

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);

    window_ = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               displayMode.w / 2, displayMode.h / 2,
                               SDL_WINDOW_MAXIMIZED | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_FULLSCREEN);

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
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


void Game::setGameState(GameState *gameState)
{
    //gameState_->willExit();
    //gameState->willEnter(&assetLibrary_);
    gameState_ = gameState;
}
