#include "GameField.h"
#include "Systems/Components/SpriteManager.h"


GameField::GameField():
    platform {Platform(Vector2f{0, 0})}
{
    spriteManager = new SpriteManager;
}

void GameField::movePlatform(float deltaX)
{
    platform.move(Vector2f{deltaX, 0});
}

void GameField::spawnBall(Vector2f coords, BallSize size, BallType type)
{
    balls.push_back(Ball(coords, size, type));
    spriteManager->loadBallSprite(balls[balls.size() - 1]);
}

void GameField::destroyBall(Uint8 index)
{
    balls.erase(balls.begin() + index);
}

void GameField::spawnBrick(Vector2f coords)
{
    bricks.push_back(Brick(coords));
}

void GameField::spawnUpgrade(Vector2f coords, UpgradeType type)
{
    upgrades.push_back(Upgrade(coords, type));
}

vector<Ball>& GameField::getBalls()
{
    return balls;
}

vector<Brick>& GameField::getBricks()
{
    return bricks;
}

vector<Upgrade>& GameField::getUpgrades()
{
    return upgrades;
}

Ball& GameField::getBall(Uint8 index)
{
    return balls[index];
}
