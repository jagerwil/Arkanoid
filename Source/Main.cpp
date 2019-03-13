#include "Headers/BasicHeader.h"
#include "Systems/ArkanoidGame.h"
#include "Systems/ArkanoidGraphics.h"
#include "Systems/ArkanoidInput.h"
///USING GLOBAL VARIABLE!!!

int main()
{
    ///screenSize = {1366, 768};

    Clock clock;
    Time deltaTime;

    ArkanoidGame* game = new ArkanoidGame();
    ArkanoidGraphics* graphics = new ArkanoidGraphics(screenSize);
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

    return 0;
}
