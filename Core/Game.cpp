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
        timeStart = 0,
        timePrevious = SDL_GetTicks();

    isRunning_ = true;

    while (isRunning_)
    {
        timeStart = SDL_GetTicks();
        timeElapsed = timeStart - timePrevious;
        timePrevious = timeStart;

        pollInputEvents();

        gameState_->update((double) timeElapsed);

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);
        gameState_->render(renderer_);
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
            std::cout << "warning: hard quit" << std::endl;
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
    assetLibrary_.setRenderer(renderer_);
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

