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
    void moveBalls(Time deltaTime);
    void moveBall(Ball& ball, Uint32 index, Time deltaTime);
};
