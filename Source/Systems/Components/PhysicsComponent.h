#pragma once
#include "Headers/BasicHeader.h"
#include "Objects/GameField.h"


class PhysicsComponent
{
protected:
    GameField* gameField;

public:
    PhysicsComponent(GameField* gameField);

    void tick(Time deltaTime);
    
protected:
    void moveBalls(Time deltaTime);
    void moveBall(Ball& ball, Uint32 index, Time deltaTime);

    Vector2f checkBallCollision(Ball& ball, Vector2f offset);

    float calculateMovementX(Vector2f coords, float angle, float y);
    float calculateMovementY(Vector2f coords, float angle, float x);
    Vector2f getCollisionCornerCoords(Vector2f coords, Vector2f offset);
    CollisionSide calculateCollisionSide(Ball& ball, Vector2f cornerCoods, Vector2f offset);
};
