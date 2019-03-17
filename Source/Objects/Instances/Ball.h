#pragma once
#include "Objects/Object.h"


class Ball : public Object
{
protected:
    static float radian /* = 180.f / 3.14159f */;

    BallSize size;
    BallType type;
    Vector2f movementVector;
    float speed;
    float angle;
    bool bSimulatePhysics;
    
public:
    Ball(Vector2f coords, BallSize size = BallSize::SMALL, BallType type = BallType::COMMON);
    void recalculate();

    void setSpeed(float speed);
    void setRotation(float angle);
    void setSize(BallSize size);
    void setType(BallType type);
    void setSimulatePhysics(bool bSimulatePhysics);

    Vector2f getMovementVector();
    BallSize getSize();
    BallType getType();
    Uint8 getRadius();
    bool simulatePhysics();
};
