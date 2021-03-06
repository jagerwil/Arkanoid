#pragma once
#include "Headers/BasicHeader.h"
#include "GameField.h"

class ArkanoidGame;


class PhysicsComponent
{
protected:
    GameField* gameField;
    ArkanoidGame* game;

public:
    PhysicsComponent(ArkanoidGame* _game, GameField* _gameField);
    ~PhysicsComponent();

    void tick(Time deltaTime);
    
protected:
    void moveBalls(Time deltaTime);
    void moveBall(Ball& ball, Uint32 ballIndex, Time deltaTime);

    void checkBallCollisions(Ball& ball, Uint32 ballIndex, Platform& platform, Vector2f offset);

    Vector2f checkBallCollisionWithBricks(Ball& ball, Vector2f offset);
    Vector2f checkBallCollisionWithPlatform(Ball& ball, Vector2f offset);

    Vector2f getCollisionCornerCoords(Vector2f coords, Vector2f offset);
    CollisionSide calculateCollisionSide(Ball& ball, Vector2f cornerCoods, 
                                         Vector2f offset);

    Vector2f changeBallDirection(Ball& ball, Vector2f cornerCoords, 
                                 Vector2f offset, CollisionSide side);
    Vector2i calculateBrickRelativeCoords(Vector2f cornerCoords);

    float calculateMovementX(Vector2f coords, float angle, float y);
    float calculateMovementY(Vector2f coords, float angle, float x);
};
