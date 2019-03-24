#include "Headers/BasicHeader.h"
#include "Systems/ArkanoidGame.h"
#include "Systems/ArkanoidGraphics.h"
#include "Systems/ArkanoidInput.h"

int main()
{
    //screenSize in Headers/BasicHeader.h

    Clock clock;    //count time between ticks
    Time deltaTime;

    ArkanoidGame* game = new ArkanoidGame();
    ArkanoidGraphics* graphics = new ArkanoidGraphics();
    ArkanoidInput* input = new ArkanoidInput(game, graphics);

    graphics->init(game);
    game->init(graphics);

    clock.restart();
    while (graphics->isOpen())
    {
        deltaTime = clock.getElapsedTime();
        clock.restart();

        input->handleEvents();
        game->tick(deltaTime);
        graphics->drawAll();
    }

    delete game;
    delete graphics;
    delete input;

    return 0;
}
