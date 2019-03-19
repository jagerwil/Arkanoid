#include "PhysicsComponent.h"
#include <cmath>
using std::round;
using std::ceil;
using std::floor;
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

void PhysicsComponent::moveBall(Ball& ball, Uint32 ballIndex, Time deltaTime)
{
    Vector2f moveVector = ball.getMovementVector();
    Vector2f offset = moveVector * deltaTime.asSeconds();
    Platform& platform = gameField->getPlatform();

    checkBallCollisions(ball, ballIndex, platform, offset);
}

Vector2f PhysicsComponent::checkBallCollisionWithBricks(Ball& ball, Vector2f offset)
{
    Vector2f coords = ball.getPosition() + offset - ball.getOrigin();
    Vector2i bitmapCoords = {(int)floor(coords.x), (int)floor(coords.y)};

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

    system("cls");
    cout << "ball coords: " << ball.getPosition().x << ' ' << ball.getPosition().y << endl;

    Vector2f cornerCoords = {(float)points[0].x, (float)points[0].y};
    cornerCoords += ball.getPosition();
    cornerCoords -= ball.getOrigin();
    cornerCoords += offset;

    cornerCoords = getCollisionCornerCoords(cornerCoords, offset);
    CollisionSide collisionSide = calculateCollisionSide(ball, cornerCoords, offset);
    offset = changeBallDirection(ball, cornerCoords, offset, collisionSide);

    ///DEBUG
    Vector2i brickCoords = calculateBrickRelativeCoords(cornerCoords);
    gameField->destroyBrick(brickCoords);
    
    return offset;
}

Vector2f PhysicsComponent::checkBallCollisionWithPlatform(Ball& ball, Vector2f offset)
{
    if (ball.getMovementVector().y <= 0)
    {
        return offset;
    }

    Platform& platform = gameField->getPlatform();

    int platformCoordX = (int)platform.getPosition().x;
    int platformSizeX = (int)platform.getSize().x;

    if (ball.getPosition().x - ball.getRadius() > platformCoordX - platformSizeX
        && ball.getPosition().x + ball.getRadius() < platformCoordX + platformSizeX)
    {
        offset = changeBallDirection(ball, platform.getPosition(), offset, CollisionSide::TOP);
    }

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
    float speed = (x - coords.x) / cos(angle);
    float y = speed * sin(angle) + coords.y;

    return y;
}

void PhysicsComponent::checkBallCollisions(Ball& ball, Uint32 ballIndex, Platform& platform, Vector2f offset)
{
    bool hasOffsetChanged = false;

    if (ball.getPosition().y > screenSize.y + (float)ball.getRadius() + 1)
    {
        gameField->destroyBall(ballIndex);
        ///DEBUG
        gameField->spawnAttachedBall();
        return;
    }

    if (ball.getPosition().x + offset.x > screenSize.x - (float)ball.getRadius())
    {
        offset = changeBallDirection(ball, Vector2f{(float)screenSize.x, 0},
                                     offset, CollisionSide::RIGHT);

        hasOffsetChanged = true;
    }
    else if (ball.getPosition().x + offset.x < (float)ball.getRadius())
    {
        offset = changeBallDirection(ball, Vector2f{0, 0},
                                     offset, CollisionSide::LEFT);

        hasOffsetChanged = true;
    }

    if (ball.getPosition().y + offset.y < (float)ball.getRadius())
    {
        offset = changeBallDirection(ball, Vector2f{0, 0},
                                     offset, CollisionSide::TOP);

        hasOffsetChanged = true;
    }

    if (!hasOffsetChanged)
    {
        Vector2f offsetBefore = offset;
        if (ball.getPosition().y + (float)ball.getRadius() > platform.getPosition().y)
        {
            offset = checkBallCollisionWithPlatform(ball, offset);
        }
        else
        {
            offset = checkBallCollisionWithBricks(ball, offset);
        }

        if (round(offsetBefore.x * 100) != round(offset.x * 100)
            || round(offsetBefore.y * 100) != round(offset.y * 100))
        {
            hasOffsetChanged = true;
        }
    }

    if (hasOffsetChanged)
    {
        checkBallCollisions(ball, ballIndex, platform, offset);
    }
    else
    {
        ball.move(offset);
    }
}

Vector2f PhysicsComponent::getCollisionCornerCoords(Vector2f coords, Vector2f offset)
{
    cout << "coords: " << coords.x << ' ' << coords.y << endl;

    Vector2f cornerCoords = coords - gameField->getBricksOffset();
    Vector2i brickSize = gameField->getBrickSize();

    int modX = (int)floor(cornerCoords.x) % brickSize.x;
    int modY = (int)floor(cornerCoords.y) % brickSize.y;

    cout << "Corner coords before: " << cornerCoords.x << ' ' << cornerCoords.y << endl;

    cornerCoords.x -= modX;
    cornerCoords.y -= modY;

    cout << "Corner coords after: " << cornerCoords.x << ' ' << cornerCoords.y << endl;

    ///DEBUG
    bool isLeft = true;
    bool isTop = true;

    if (offset.x < 0.f)
    {
        cornerCoords.x += brickSize.x - 2;
        isLeft = false;

    }

    if (offset.y < 0.f)
    {
        cornerCoords.y += brickSize.y - 2;
        isTop = false;
    }

    if (isLeft) cout << "left/";
    else cout << "right/";

    if (isTop) cout << "top" << endl;
    else cout << "bottom" << endl;

    cout << "Offset: " << offset.x << ' ' << offset.y << endl;

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

Vector2f PhysicsComponent::changeBallDirection(Ball& ball, Vector2f cornerCoords, Vector2f offset, CollisionSide side)
{
    float collisionPointDistance;

    cout << "Side: ";
    switch (side)
    {
    case CollisionSide::LEFT:
        cout << "left";
        break;
    case CollisionSide::RIGHT:
        cout << "right";
        break;

    case CollisionSide::TOP:
        cout << "top";
        break;
    case CollisionSide::BOTTOM:
        cout << "bottom";
        break;
    }

    cout << endl;

    switch (side)
    {
    case CollisionSide::LEFT:
    case CollisionSide::RIGHT:
        collisionPointDistance = abs(cornerCoords.x - ball.getPosition().x) - (float)ball.getRadius();
        offset.x = collisionPointDistance - offset.x;
        ball.setRotation(180.f - ball.getAngle());
        break;

    case CollisionSide::TOP:
    case CollisionSide::BOTTOM:
        collisionPointDistance = abs(cornerCoords.y - ball.getPosition().y) - (float)ball.getRadius();
        offset.y = collisionPointDistance - offset.y;
        ball.setRotation(-ball.getAngle());
        break;
    }

    return offset;
}

Vector2i PhysicsComponent::calculateBrickRelativeCoords(Vector2f cornerCoords)
{
    Vector2f brickRelativeCoordsF = cornerCoords - gameField->getBricksOffset();
    brickRelativeCoordsF.x = ceil(brickRelativeCoordsF.x);
    brickRelativeCoordsF.y = ceil(brickRelativeCoordsF.y);

    cout << "Coords - offset: " << brickRelativeCoordsF.x << ' ' << brickRelativeCoordsF.y << endl;

    Vector2i brickRelativeCoords = {(int)brickRelativeCoordsF.x,
                                    (int)brickRelativeCoordsF.y};

    Vector2i brickSize = gameField->getBrickSize();

    brickRelativeCoords.x /= brickSize.x;
    brickRelativeCoords.y /= brickSize.y;

    cout << "Relative coords: " << brickRelativeCoords.x << ' ' << brickRelativeCoords.y << endl;

    return brickRelativeCoords;
}
