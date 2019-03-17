#pragma once
#include "Headers/BasicHeader.h"

class ArkanoidGraphics;
class PhysicsComponent;
class GameField;


class ArkanoidGame
{
protected:
    ArkanoidGraphics* graphics;
    PhysicsComponent* physics;
    GameField* gameField;

    GameState gameState;

public:
    ArkanoidGame();
    void init(ArkanoidGraphics* graphics);

    void tick(Time deltaTime);

    void movePlatform(float x);
    void spawnAttachedBall();
    void releaseBall();

    void setGameState(GameState gameState);
    GameField* getGameField();
};
