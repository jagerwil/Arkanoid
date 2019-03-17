#pragma once
#include "Headers/BasicHeader.h"
#include "Objects/Instances/Platform.h"
#include "Objects/Instances/Ball.h"
#include "Objects/Instances/Upgrade.h"

class SpriteManager;


class GameField
{
protected:
    SpriteManager* spriteManager;

    Platform platform;
    vector<Ball> balls;
    vector<Brick> bricks;
    vector<Upgrade> upgrades;

    Vector2i brickSize;

public:
    GameField();

    void spawnBall(Vector2f coords, BallSize size = BallSize::SMALL, 
                   BallType type = BallType::COMMON);
    void destroyBall(Uint32 index);

    void spawnBrick(Vector2f coords);
    void destroyBrick(Uint32 index);

    void spawnUpgrade(Vector2f coords, UpgradeType type);
    void destroyUpgrade(Uint32 index);

    void movePlatform(float x);
    void spawnAttachedBall();
    void releaseBall();

    vector<Ball>& getBalls();
    Ball& getBall(Uint32 index);

    vector<Brick>& getBricks();
    vector<Upgrade>& getUpgrades();
    Platform& getPlatform();

protected:
    void spawnBricks();
};
