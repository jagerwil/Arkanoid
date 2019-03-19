#include "Ball.h"
#include <cmath>
using std::sin;
using std::cos;
///DEBUG
#include "Headers/DebugHeader.h"


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

void Ball::setSpeed(float _speed)
{
    speed = _speed;
    recalculate();
}

void Ball::setRotation(float _angle)
{
    angle = (float)((int)_angle % 360);

    if (angle > 180.f)
    {
        angle -= 360.f;
    }
    ///DEBUG
    ///system("cls");
    cout << "angle: " << angle << endl;
    
    angleRadian = angle / radian;

    recalculate();
}

void Ball::setSize(BallSize _size)
{
    size = _size;
}

void Ball::setType(BallType _type)
{
    type = _type;
}

void Ball::setSimulatePhysics(bool _bSimulatePhysics)
{
    bSimulatePhysics = _bSimulatePhysics;
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
