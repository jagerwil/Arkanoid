#include "ArkanoidInput.h"
#include "ArkanoidGame.h"
#include "ArkanoidGraphics.h"
using sf::Keyboard;
using sf::Event;
using sf::Mouse;


ArkanoidInput::ArkanoidInput(ArkanoidGame* game, ArkanoidGraphics* graphics)
{
    this->game = game;
    this->graphics = graphics;
}

ArkanoidInput::~ArkanoidInput()
{
    game = nullptr;
    graphics = nullptr;
}

void ArkanoidInput::handleEvents()
{
    Event event;
    while (graphics->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            graphics->close();
        }

        if (event.type == Event::MouseMoved
            || event.type == Event::MouseButtonPressed
            || event.type == Event::MouseButtonReleased)
        {
            inputMouse(event);
        }
        else if (event.type == Event::KeyPressed
                 || event.type == Event::KeyReleased)
        {
            inputKeyboard(event);
        }
    }
}

void ArkanoidInput::inputKeyboard(Event& event)
{
    if (event.type == Event::KeyPressed)
    {
        ///...
    }
    else if (event.type == Event::KeyReleased)
    {
        ///...
    }
}

void ArkanoidInput::inputMouse(Event& event)
{
    if (event.type == Event::MouseMoved)
    {
        Vector2i mouseCoords = Mouse::getPosition(*graphics);
        game->inputMovePlatform((float)mouseCoords.x);
    }
    if (event.type == Event::MouseButtonPressed)
    {
        if (event.key.code == Mouse::Left)
        {
            game->inputReleaseBall();
        }
    }
    else if (event.type == Event::MouseButtonReleased)
    {
        ///...
    }
}
