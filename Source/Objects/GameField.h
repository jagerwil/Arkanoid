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

public:
    GameField();

    void movePlatform(float deltaX);

    void spawnBall(Vector2f coords, BallSize size = BallSize::SMALL, 
                   BallType type = BallType::COMMON);
    void destroyBall(Uint8 index);

    void spawnBrick(Vector2f coords);
    void destroyBrick(Uint8 index);

    void spawnUpgrade(Vector2f coords, UpgradeType type);
    void destroyUpgrade(Uint8 index);

    vector<Ball>& getBalls();
    vector<Brick>& getBricks();
    vector<Upgrade>& getUpgrades();
    Ball& getBall(Uint8 index);
};
