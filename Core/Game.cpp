#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <deque>
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
    int cycles = 0,
        fpsBarWidth = 0,
        timeSleeping = 0,
        timePlaceholder = 0,
        avgBarWidth = 0;

    char fpsMsg[128];

    std::deque<int> barWidths;

    int numCycles = 10;

    for (int i = 0; i < numCycles; i++) barWidths.push_back(0);

    while (isRunning_)
    {
        timeCurrent = SDL_GetTicks();
        timeElapsed = timeCurrent - timePrevious;
        timePrevious = timeCurrent;

        SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
        SDL_RenderClear(renderer_);

        gameState_->performUpdate(((double) timeElapsed) / 1000);

        if (cycles++ % numCycles == 0)
        {
            fpsCheck_curr = SDL_GetTicks();
            double fps = numCycles * (1000 / (double) (fpsCheck_curr - fpsCheck_prev));
            snprintf(fpsMsg, 128, "fps: %.3f", fps);
            fpsCheck_prev = fpsCheck_curr;
            fpsBarWidth = (int) (200 * timeSleeping / 16.0);
            if (fpsBarWidth > 200) fpsBarWidth -= fpsBarWidth % 200;

            barWidths.push_back(fpsBarWidth);
            barWidths.pop_front();

            avgBarWidth = 0;
            for (int i = 0; i < numCycles; i++) avgBarWidth += barWidths[i];
            avgBarWidth = avgBarWidth / numCycles;
        }


        graphics_.setColor(50, 200, 10);
        graphics_.drawRect(Vec2i(7, 7), Vec2i(200, 22));
        if (avgBarWidth <= 200) graphics_.fillRect(Vec2i(7, 7), Vec2i(200 - avgBarWidth, 22));
        graphics_.setColor(0, 0, 0);
        for (int i = 200 / 17; i < 200 - 200 / 17; i += 200 / 17)
        {
            graphics_.drawRect(Vec2i(7, 9).add(Vec2i(i, 0)), Vec2i(1, 18));
        }
        graphics_.drawString(fpsMsg, Vec2i(10, 10));


        timePlaceholder = SDL_GetTicks();
        SDL_RenderPresent(renderer_);
        timeSleeping = SDL_GetTicks() - timePlaceholder;
    }

    // deinit the gamestate that was running
    // before game loop was exited
    gameState_->performDeinit();
}


/**
 *
 */
Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    SDL_GetDisplayDPI(0, &dispDDPI, &dispHDPI, &dispVDPI);

    std::cout << "disp ddpi: " << dispDDPI << ", "
              << "hdpi: " << dispVDPI << ", "
              << "vdpi: " << dispDDPI << std::endl;

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);

    window_ = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               960, 640,
                               //displayMode.w / 2, displayMode.h / 2,
                               SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

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
    gameState->performDeinit();
    gameState_ = gameState;
    gameState_->game = this;
    gameState_->performInit(this);
    //gameState->willEnter(&assetLibrary_);
}

Vec2i Game::getMousePosition()
{
    Vec2i mouse_pos;
    SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
    return mouse_pos;
}