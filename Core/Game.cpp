#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include "SceneGameState.h"


void Game::loop()
{
    Uint32
        time_elapsed = 0,
        time_frameStart = 0,
        time_framePrevious = SDL_GetTicks();

    int cycle = 0,
        delay = 0;

    isRunning_ = true;

    while (isRunning_)
    {
        cycle ++;

        time_frameStart = SDL_GetTicks();
        time_elapsed = time_frameStart - time_framePrevious;
        time_framePrevious = time_frameStart;

        pollEvents();

        gameState_->update((double) time_elapsed);

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);
        gameState_->render(renderer_);
        SDL_RenderPresent(renderer_);

        delay = 16 - ((int)SDL_GetTicks() - (int)time_frameStart);
        delay = delay > 0 ? delay : 0;

        if (++cycle % 60 == 0)
        {
            std::cout << "delay: " << delay << "\n\n";
        }

        SDL_Delay((Uint32) delay);
    }
}


void Game::pollEvents()
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


Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    gameState_ = new SceneGameState();
    window_ = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500,
                               SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    assetLibrary_.setRenderer(renderer_);
}


Game::~Game()
{
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);

    IMG_Quit();
    SDL_Quit();
}

