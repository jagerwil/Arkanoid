#pragma once
#include "Headers/BasicHeader.h"
#include "Objects/Ball.h"


class PhysicsComponent
{
public:
    PhysicsComponent();

    void tick(Time deltaTime);
    void moveBalls(vector<Ball>& balls, Time deltaTime);
    void moveBall(Ball& ball, Time deltaTime);
};
