#include "PlayingWidget.h"
#include "SFML/Graphics/CircleShape.hpp"
using sf::CircleShape;
using sf::Color;


PlayingWidget::PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics):
    Widget(coords, size, graphics)
{
    ///...
}

void PlayingWidget::draw()
{
    graphics->draw(*this);

    vector<BallData> ballsData = graphics->getBallsData();
    for (auto ballData : ballsData)
    {
        CircleShape shape;
        shape.setPosition(ballData.coords);
        shape.setRadius(ballData.radius);
        shape.setFillColor(Color::Green);
        graphics->draw(shape);
    }

    ///...
}
