#include "Object.h"


Object::Object(Vector2f coords)
{
    setPosition(coords);
}

void Object::move(Vector2f offset)
{
    setPosition(coords + offset);
}

void Object::setPosition(Vector2f coords)
{
    this->coords = coords;

    sprite.setPosition(coords);
    bitmap.setPosition(coords);
}

Sprite& Object::getSprite()
{
    return sprite;
}

Sprite& Object::getBitmap()
{
    return bitmap;
}

Vector2f Object::getPosition()
{
    return coords;
}
