#pragma once
#include "Headers/BasicHeader.h"
#include "Objects/Ball.h"

class ArkanoidGraphics;
class PhysicsComponent;


class ArkanoidGame
{
protected:
    ArkanoidGraphics* graphics;
    PhysicsComponent* physics;

    GameState gameState;
    vector<Ball> balls;

public:
    ArkanoidGame();
    void init(ArkanoidGraphics* graphics);

    void tick(Time deltaTime);
    void removeBall(Uint32 index);

    void setGameState(GameState gameState);
    vector<Ball>& getBalls();
    vector<BallData> getBallsData();
};
