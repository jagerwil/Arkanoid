#include "PhysicsComponent.h"
#include <cmath>
using std::round;


PhysicsComponent::PhysicsComponent(GameField* gameField):
    gameField {gameField}
{
    ///...
}

void PhysicsComponent::tick(Time deltaTime)
{
    moveBalls(deltaTime);
}

void PhysicsComponent::moveBalls(Time deltaTime)
{
    vector<Ball>& balls = gameField->getBalls();

    for (Uint32 i = 0; i < balls.size(); ++i)
    {
        Ball& ball = balls[i];
        if (ball.simulatePhysics())
        {
            moveBall(ball, i, deltaTime);
        }
    }
}

void PhysicsComponent::moveBall(Ball& ball, Uint32 index, Time deltaTime)
{
    Vector2f moveVector = ball.getMovementVector();
    Vector2f offset = moveVector * deltaTime.asSeconds();

    ball.move(offset);

    if (ball.getPosition().y < 0 - (float)ball.getRadius() - 2)
    {
        gameField->destroyBall(index);
        ///DEBUG
        gameField->spawnAttachedBall();
    }
    else
    {
        Vector2f coords = ball.getPosition() - ball.getOrigin();
        Vector2i bitmapCoords = {(int)round(coords.x), (int)round(coords.y)};

        Vector2i bitmapSize = {(int)ball.getRadius() * 2 + 1, (int)ball.getRadius() * 2 + 1};

        Bitmap partialBitmap;
        partialBitmap.initialize(bitmapSize);
        partialBitmap.copyPartial(gameField->getBitmap(), bitmapCoords, Vector2i{0, 0}, bitmapSize);
        vector<Vector2i> points = getCollisionPoints(ball.getBitmap(), partialBitmap);
    }
}
