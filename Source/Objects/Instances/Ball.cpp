#include "Ball.h"
#include <cmath>
using std::sin;
using std::cos;


float Ball::radian = 180.f / 3.14159f;

Ball::Ball(Vector2f coords, BallSize size, BallType type):
    Object(coords)
{
    setPosition(coords);
    setSize(size);
    setType(type);

    sprite.setOrigin((float)size, (float)size);
    bitmap.setOrigin((float)size, (float)size);
}

void Ball::recalculate()
{
    movementVector.x = speed * cos(angle / radian);
    movementVector.y = speed * sin(angle / radian);
}

void Ball::setSpeed(float speed)
{
    this->speed = speed;
    recalculate();
}

void Ball::setRotation(float angle)
{
    this->angle = angle;
    recalculate();
}

void Ball::setSize(BallSize size)
{
    this->size = size;
}

void Ball::setType(BallType type)
{
    this->type = type;
}

Vector2f Ball::getMovementVector()
{
    return movementVector;
}

BallSize Ball::getSize()
{
    return size;
}

BallType Ball::getType()
{
    return type;
}

Uint8 Ball::getRadius()
{
    return (Uint8)size;
}
