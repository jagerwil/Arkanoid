#include "Object.h"


Object::Object()
{ }

Object::Object(Vector2f coords)
{
    setPosition(coords);
}

void Object::move(Vector2f offset)
{
    setPosition(coords + offset);
}

void Object::setPosition(Vector2f _coords)
{
    coords = _coords;

    sprite.setPosition(coords);
}

void Object::setSize(Vector2f _size)
{
    size = _size;
}

Sprite& Object::getSprite()
{
    return sprite;
}

Bitmap& Object::getBitmap()
{
    return bitmap;
}

Vector2f Object::getPosition()
{
    return coords;
}

Vector2f Object::getSize()
{
    return size;
}
