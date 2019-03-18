#include "PhysicsComponent.h"
#include <cmath>
using std::round;
using std::abs;
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

    if (ball.getPosition().y < 0 - (float)ball.getRadius() - 2)
    {
        gameField->destroyBall(index);
        ///DEBUG
        gameField->spawnAttachedBall();
    }
    else
    {
        offset = checkBallCollision(ball, offset);
    }

    ball.move(offset);
}

Vector2f PhysicsComponent::checkBallCollision(Ball& ball, Vector2f offset)
{
    Vector2f coords = ball.getPosition() + offset - ball.getOrigin();
    Vector2i bitmapCoords = {(int)round(coords.x), (int)round(coords.y)};

    Vector2i bitmapSize = {(int)ball.getRadius() * 2 + 1, 
                           (int)ball.getRadius() * 2 + 1};

    Bitmap partialBitmap;
    partialBitmap.initialize(bitmapSize);
    partialBitmap.copyPartial(gameField->getBitmap(), bitmapCoords, 
                              Vector2i{0, 0}, bitmapSize);

    vector<Vector2i> points = getCollisionPoints(ball.getBitmap(), partialBitmap);

    if (points.size() == 0)
    {
        return offset;
    }


    Vector2f cornerCoords = {(float)points[0].x, (float)points[0].y};
    cornerCoords += ball.getPosition();
    cornerCoords -= ball.getOrigin();

    cornerCoords = getCollisionCornerCoords(cornerCoords, offset);
    CollisionSide collisionSide = calculateCollisionSide(ball, cornerCoords, offset);

    Vector2f collisionPointCoords = cornerCoords;
    float collisionPointDistance;

    switch (collisionSide)
    {
    case CollisionSide::LEFT:
    case CollisionSide::RIGHT:
        collisionPointDistance = abs(cornerCoords.x - ball.getPosition().x) - (float)ball.getRadius();
        offset.x = collisionPointDistance - offset.x;
        break;

    case CollisionSide::TOP:
    case CollisionSide::BOTTOM:
        collisionPointDistance = abs(cornerCoords.y - ball.getPosition().y) - (float)ball.getRadius();
        offset.y = collisionPointDistance - offset.y;
        break;
    }

    ball.setRotation(-ball.getAngle());

    ///DEBUG
    cout << points.size() << endl;

    return offset;
}

float PhysicsComponent::calculateMovementX(Vector2f coords, float angle, float y)
{
    float speed = (y - coords.y) / sin(angle);
    float x = speed * cos(angle) + coords.x;

    return x;
}

float PhysicsComponent::calculateMovementY(Vector2f coords, float angle, float x)
{
    float speed = (x - coords.x) / sin(angle);
    float y = speed * cos(angle) + coords.y;

    return y;
}

Vector2f PhysicsComponent::getCollisionCornerCoords(Vector2f coords, Vector2f offset)
{
    Vector2f cornerCoords = coords - gameField->getBricksOffset();
    Vector2i brickSize = gameField->getBrickSize();

    int modX = (int)cornerCoords.x % brickSize.x;
    int modY = (int)cornerCoords.y % brickSize.y;

    cornerCoords.x -= modX;
    cornerCoords.y -= modY;

    if (offset.x < 0)
    {
        cornerCoords.x += brickSize.x - 1;
    }

    if (offset.y < 0)
    {
        cornerCoords.y += brickSize.y - 1;
    }

    cornerCoords += gameField->getBricksOffset();

    return cornerCoords;
}

CollisionSide PhysicsComponent::calculateCollisionSide(Ball& ball, Vector2f cornerCoords, Vector2f offset)
{
    float relativeX = calculateMovementX(ball.getPosition(), ball.getAngleRadian(), cornerCoords.y);

    CollisionSide side;
    
    if (offset.y < 0)
    {
        if (offset.x < 0)
        {
            if (relativeX <= cornerCoords.x)
            {
                side = CollisionSide::BOTTOM;
            }
            else
            {
                side = CollisionSide::RIGHT;
            }
        }
        else
        {
            if (relativeX <= cornerCoords.x)
            {
                side = CollisionSide::LEFT;
            }
            else
            {
                side = CollisionSide::BOTTOM;
            }
        }
    }
    else
    {
        if (offset.x < 0)
        {
            if (relativeX <= cornerCoords.x)
            {
                side = CollisionSide::TOP;
            }
            else
            {
                side = CollisionSide::RIGHT;
            }
        }
        else
        {
            if (relativeX <= cornerCoords.x)
            {
                side = CollisionSide::LEFT;
            }
            else
            {
                side = CollisionSide::TOP;
            }
        }
    }

    return side;
}
