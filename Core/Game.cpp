#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include "SceneGameState.h"


void Game::loop()
{
    this->isRunning = true;

    while (this->isRunning)
    {
        this->pollEvents();
        SDL_Delay(100);
    }
}


void Game::pollEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        this->gameState->handleInputEvent(&event);

        if (event.type == SDL_QUIT)
        {
            this->isRunning = false;
        }
    }
}


Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    this->gameState = new SceneGameState();

    this->window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}


Game::~Game()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    IMG_Quit();
    SDL_Quit();
}

