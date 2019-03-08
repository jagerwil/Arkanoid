#pragma once
#include <SFML/Graphics.hpp>
using sf::RenderWindow;
using sf::Vector2i;
using sf::Event;


class ArkanoidGraphics : public RenderWindow
{
public:
    ArkanoidGraphics(Vector2i screenSize);

    void draw();
    void update();
};
