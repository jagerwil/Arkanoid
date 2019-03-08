#include "PhysicsComponent.h"
//+DEBUG
#include "Headers/DebugHeader.h"
//-DEBUG
#include <cmath>
using std::round;



PhysicsComponent::PhysicsComponent()
{
    ///...
}

void PhysicsComponent::tick(Time deltaTime)
{
    ///...
}

void PhysicsComponent::moveBalls(vector<Ball>& balls, Time deltaTime)
{
    //Reference on vector

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

    ///DEBUG
    Vector2f position = ball.getPosition();
    cout << "New ball coords: " << position.x << ", " << position.y << endl;
}
