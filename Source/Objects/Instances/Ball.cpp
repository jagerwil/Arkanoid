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
    setSimulatePhysics(true);
}

void Ball::recalculate()
{
    movementVector.x = speed * cos(angleRadian);
    movementVector.y = speed * sin(angleRadian);
}

void Ball::setSpeed(float speed)
{
    this->speed = speed;
    recalculate();
}

void Ball::setRotation(float angle)
{
    this->angle = (float)((int)angle % 360);
    angleRadian = angle / radian;

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

void Ball::setSimulatePhysics(bool bSimulatePhysics)
{
    this->bSimulatePhysics = bSimulatePhysics;
}

Vector2f Ball::getOrigin()
{
    return sprite.getOrigin();
}

float Ball::getSpeed()
{
    return speed;
}

float Ball::getAngle()
{
    return angle;
}

float Ball::getAngleRadian()
{
    return angleRadian;
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

bool Ball::simulatePhysics()
{
    return bSimulatePhysics;
}
