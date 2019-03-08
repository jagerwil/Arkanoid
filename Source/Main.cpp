#include <SFML/System/Clock.hpp>
#include "Systems/ArkanoidInput.h"
#include "Systems/ArkanoidGame.h"
#include "Systems/ArkanoidGraphics.h"
using sf::Vector2i;
using sf::Clock;
using sf::Time;


int main()
{
    Vector2i screenSize = {1366, 768};
    Clock clock;
    Time deltaTime;

    ArkanoidGame* game = new ArkanoidGame();
    ArkanoidGraphics* graphics = new ArkanoidGraphics(screenSize);
    game->init(graphics);
    graphics->init(game);
    ArkanoidInput* input = new ArkanoidInput(game, graphics);

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
