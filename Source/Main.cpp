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

    ArkanoidGraphics* graphics = new ArkanoidGraphics(screenSize);
    ArkanoidGame* game = new ArkanoidGame(graphics);
    ArkanoidInput* input = new ArkanoidInput(game, graphics);

    while (graphics->isOpen())
    {
        deltaTime = clock.getElapsedTime();
        clock.restart();

        input->handleEvents();
        game->tick(deltaTime);
        graphics->draw();
    }

    return 0;
}
