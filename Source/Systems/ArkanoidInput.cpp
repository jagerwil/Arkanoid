#include "ArkanoidInput.h"
#include "ArkanoidGame.h"
#include "ArkanoidGraphics.h"
using sf::Keyboard;


ArkanoidInput::ArkanoidInput(ArkanoidGame* game, ArkanoidGraphics* graphics)
{
    this->game = game;
    this->graphics = graphics;
}

void ArkanoidInput::handleEvents()
{
    sf::Event event;
    while (graphics->pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            graphics->close();
        }
        if (event.type == Event::KeyPressed
            || event.type == Event::KeyReleased)
        {
            inputKeyboard(event);
        }
        else if (event.type == Event::MouseMoved
                 || event.type == Event::MouseButtonPressed
                 || event.type == Event::MouseButtonReleased)
        {
            inputMouse(event);
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
        ///...
    }
    if (event.type == Event::MouseButtonPressed)
    {
        ///...
    }
    else if (event.type == Event::MouseButtonReleased)
    {
        ///...
    }
}
