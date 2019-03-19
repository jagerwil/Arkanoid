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

    void inputMovePlatform(float x);
    void inputReleaseBall();

    void setGameState(GameState _gameState);
    GameField* getGameField();
};
