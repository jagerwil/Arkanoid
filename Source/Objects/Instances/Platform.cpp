#include "Platform.h"
#include "Ball.h"


Platform::Platform(Vector2f coords, Vector2f size):
    Object(coords)
{
    setSize(size);
    bBallAttached = false;
}

Platform::~Platform()
{
    ball = nullptr;
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

    Vector2f newCoords = Vector2f{x, coords.y};
    setPosition(newCoords);

    if (bBallAttached)
    {
        ball->setPosition(newCoords + ballOffset);
    }
}

void Platform::setSize(Vector2f _size)
{
    Object::setSize(_size);
    sprite.setOrigin({size.x / 2.f, 0});
}

void Platform::attachBall(Ball* _ball)
{
    if (!bBallAttached)
    {
        _ball->setSimulatePhysics(false);
        ball = _ball;

        ballOffset = {0, -(float)ball->getRadius() - 1};
        ball->setPosition(coords + ballOffset);

        bBallAttached = true;
    }
}

void Platform::unAttachBall()
{
    if (bBallAttached)
    {
        ball->setSimulatePhysics(true);

        ball = nullptr;
        bBallAttached = false;
    }
}

bool Platform::ballAttached()
{
    return bBallAttached;
}
