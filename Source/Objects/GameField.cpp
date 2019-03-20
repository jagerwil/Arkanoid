#include "GameField.h"
#include "Systems/Components/SpriteManager.h"
#include <cmath>
using std::floor;
using std::make_pair;


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
    ball.setSpeed(400.f);
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

void GameField::destroyBrick(Vector2i relativeCoords)
{
    int index = getBrickIndex(relativeCoords);
    bricks.erase(index);

    Vector2i coords = {relativeCoords.x * brickSize.x + (int)bricksOffset.x,
                       relativeCoords.y * brickSize.y + (int)bricksOffset.y};

    Bitmap bitmap;
    bitmap.initialize(brickSize);
    fieldBitmap.copyPartial(bitmap, Vector2i{0, 0}, coords, brickSize);
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

map<int, Brick>& GameField::getBricks()
{
    return bricks;
}

Vector2i GameField::getBrickSize()
{
    return brickSize;
}

Vector2f GameField::getBricksOffset()
{
    return bricksOffset;
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
    vector<Color> colors = {Color::Red, Color{255, 127, 0}, Color::Yellow, Color{0, 230, 0}, Color::White};

    for (int y = 0; y < bricksFieldSize.y; ++y)
    {
        int index = y % colors.size();
        Color color = colors[index];

        for (int x = 0; x < bricksFieldSize.x; ++x)
        {
            spawnBrick(Vector2i{x, y}, color);
        }
    }
}

void GameField::spawnBrick(Vector2i relativeCoords, Color& color)
{
    Vector2f coords = {(float)relativeCoords.x * brickSize.x + bricksOffset.x,
                       (float)relativeCoords.y * brickSize.y + bricksOffset.y};

    int index = getBrickIndex(relativeCoords);

    bricks.insert(make_pair(index, Brick(coords)));
    Brick& brick = bricks[index];

    brick.setSize({(float)brickSize.x, (float)brickSize.y});
    spriteManager->loadBrickSprite(brick, brickSize);

    Vector2i bitmapCoords = {(int)floor(coords.x), (int)floor(coords.y)};
    fieldBitmap.copyPartial(brick.getBitmap(), Vector2i{0, 0}, bitmapCoords, brickSize);

    brick.setColor(color);
}

int GameField::getBrickIndex(Vector2i relativeCoords)
{
    return relativeCoords.y * bricksFieldSize.x + relativeCoords.x;
}
