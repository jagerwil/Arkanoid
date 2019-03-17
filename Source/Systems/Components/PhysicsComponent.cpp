#include "PhysicsComponent.h"
#include <cmath>
using std::round;
///DEBUG
#include "Headers/DebugHeader.h"


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
        gameField->spawnAttachedBall();
        cout << "Ball destroyed" << endl;
    }
}
