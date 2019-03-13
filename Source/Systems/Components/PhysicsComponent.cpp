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
    ///...
}

void PhysicsComponent::moveBalls(Time deltaTime)
{
    vector<Ball>& balls = gameField->getBalls();

    for (Ball& ball : balls)
    {
        moveBall(ball, deltaTime);
    }
}

void PhysicsComponent::moveBall(Ball& ball, Time deltaTime)
{
    Vector2f moveVector = ball.getMovementVector();
    Vector2f offset = moveVector * deltaTime.asSeconds();

    ball.move(offset);
}
