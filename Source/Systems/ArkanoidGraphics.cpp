#include "ArkanoidGraphics.h"
using sf::VideoMode;
using sf::Style::Close;


ArkanoidGraphics::ArkanoidGraphics(Vector2i screenSize)
{
    create(VideoMode(screenSize.x, screenSize.y), "Arkanoid", Close);
}

void ArkanoidGraphics::draw()
{
    clear();

    ///...

    display();
}

void ArkanoidGraphics::update()
{
    ///...
}
