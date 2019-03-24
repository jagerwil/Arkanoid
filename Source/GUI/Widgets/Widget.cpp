#include "Widget.h"


Widget::Widget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics)
{
    setPosition(coords);
    setSize(size);
    this->graphics = graphics;
}

Widget::~Widget()
{
    graphics = nullptr;
}

void Widget::draw()
{
    graphics->draw(*this);
}
