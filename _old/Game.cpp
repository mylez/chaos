#include "Game.h"


void Game::loop()
{
    isRunning_ = true;

    while (isRunning_)
    {
        // poll events
        //
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning_ = false;
            }
        }
        // draw the renderables
        //
        SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);
        SDL_RenderClear(this->renderer);
        for (unsigned long i = 0; i < this->renderables.size(); i++)
        {
            this->renderables.at(i)->render(this->renderer);
        }
        SDL_RenderPresent(this->renderer);
        // ghetto 60 fps
        //
        SDL_Delay(16);
    }
}


Game::Game()
{
    this->window = SDL_CreateWindow("Chaos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 32 * 15, 32 * 10, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    this->world = new World(this->renderer);

    this->renderables.push_back((Renderable *)this->world);
}


Game::~Game()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();

    delete this->world;
}