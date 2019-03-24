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
    Uint32 score;

public:
    ArkanoidGame();
    ~ArkanoidGame();
    void init(ArkanoidGraphics* _graphics);

    void tick(Time deltaTime);

    void inputMovePlatform(float x);
    void inputReleaseBall();

    void setGameState(GameState _gameState);
    void increaseScore();
    GameField* getGameField();
};
