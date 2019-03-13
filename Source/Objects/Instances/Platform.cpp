#include "Platform.h"
///USING GLOBAL VARIABLE!


Platform::Platform(Vector2f coords, Vector2f size):
    Object(coords)
{
    setSize(size);
}

void Platform::setX(float x)
{
    float minX = size.x / 2.f + 1.f;
    float maxX = screenSize.x - size.x / 2.f - 1.f;

    if (x < minX)
    {
        x = minX;
    }
    else if (x > maxX)
    {
        x = maxX;
    }

    setPosition(Vector2f{x, coords.y});
}

void Platform::setSize(Vector2f size)
{
    this->size = size;
    sprite.setOrigin({size.x / 2.f, 0});
}

Vector2f Platform::getSize()
{
    return size;
}
