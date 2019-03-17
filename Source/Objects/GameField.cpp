#include "GameField.h"
#include "Systems/Components/SpriteManager.h"
#include <cmath>
using std::floor;


GameField::GameField():
    platform {Platform(Vector2f{100, 680}, Vector2f{120, 20})}
{
    spriteManager = new SpriteManager;
    spriteManager->loadPlatformSprite(platform);

    brickSize = Vector2i{100, 30};
    bricksOffset = {33, 90};
    bricksFieldSize = {13, 13};

    fieldBitmap.initialize(screenSize);

    spawnBricks();
    spawnAttachedBall();
}

void GameField::movePlatform(float x)
{
    platform.setX(x);
}

void GameField::spawnAttachedBall()
{
    spawnBall(Vector2f{0.f, 0.f});

    Ball& ball = getBall(balls.size() - 1);
    ball.setSpeed(200.f);
    ball.setRotation(-45.f);

    platform.attachBall(&ball);
}

void GameField::releaseBall()
{
    platform.unAttachBall();
}

void GameField::spawnBall(Vector2f coords, BallSize size, BallType type)
{
    balls.push_back(Ball(coords, size, type));
    spriteManager->loadBallSprite(balls[balls.size() - 1]);
}

void GameField::destroyBall(Uint32 index)
{
    balls.erase(balls.begin() + index);
}

void GameField::spawnBrick(Vector2f coords)
{
    bricks.push_back(Brick(coords));
    Brick& brick = bricks[bricks.size() - 1];

    brick.setSize({(float)brickSize.x, (float)brickSize.y});
    spriteManager->loadBrickSprite(brick, brickSize);

    Vector2i bitmapCoords = {(int)floor(coords.x), (int)floor(coords.y)};
    fieldBitmap.copyPartial(brick.getBitmap(), Vector2i{0, 0}, bitmapCoords, brickSize);
}

void GameField::spawnUpgrade(Vector2f coords, UpgradeType type)
{
    upgrades.push_back(Upgrade(coords, type));
}

vector<Ball>& GameField::getBalls()
{
    return balls;
}

Uint32 GameField::getBallsCount()
{
    return balls.size();
}

Ball& GameField::getBall(Uint32 index)
{
    return balls[index];
}

Bitmap& GameField::getBitmap()
{
    return fieldBitmap;
}

vector<Brick>& GameField::getBricks()
{
    return bricks;
}

vector<Upgrade>& GameField::getUpgrades()
{
    return upgrades;
}

Platform& GameField::getPlatform()
{
    return platform;
}

void GameField::spawnBricks()
{
    for (int x = 0; x < bricksFieldSize.x; ++x)
    {
        for (int y = 0; y < bricksFieldSize.y; ++y)
        {
            Vector2f coords = bricksOffset + Vector2f{(float)x * brickSize.x, (float)y * brickSize.y};
            spawnBrick(coords);
        }
    }
}
