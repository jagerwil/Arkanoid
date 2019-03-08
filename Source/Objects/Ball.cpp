#include "Ball.h"
#include <cmath>
using std::sin;
using std::cos;


float Ball::radian = 180.f / 3.14159f;

Ball::Ball(Vector2f coords, BallSize size)
{
    setPosition(coords);
    setSize(size);
}

void Ball::recalculate()
{
    movementVector.x = speed * cos(angle / radian);
    movementVector.y = speed * sin(angle / radian);
}

void Ball::move(Vector2f offset)
{
    setPosition(coords + offset);
}

void Ball::setPosition(Vector2f coords)
{
    this->coords = coords;
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

Vector2f Ball::getPosition()
{
    return coords;
}

Vector2f Ball::getMovementVector()
{
    return movementVector;
}

BallSize Ball::getSize()
{
    return size;
}

Uint8 Ball::getRadius()
{
    return (Uint8)size;
}
