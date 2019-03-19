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
    void init(ArkanoidGraphics* _graphics);

    void tick(Time deltaTime);

    void movePlatform(float x);
    void releaseBall();

    void setGameState(GameState _gameState);
    GameField* getGameField();
};
