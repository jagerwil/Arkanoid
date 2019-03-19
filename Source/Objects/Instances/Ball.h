#pragma once
#include "Objects/Object.h"


class Ball : public Object
{
protected:
    BallSize size;
    BallType type;
    Vector2f movementVector;
    float speed;
    float angle;
    float angleRadian;
    bool bSimulatePhysics;
    
public:
    Ball(Vector2f coords, BallSize size = BallSize::SMALL, BallType type = BallType::COMMON);
    void recalculate();

    void setSpeed(float _speed);
    //Set rotation in degrees
    void setRotation(float _angle);
    void setSize(BallSize _size);
    void setType(BallType _type);
    void setSimulatePhysics(bool _bSimulatePhysics);

    Vector2f getOrigin();
    float getSpeed();
    //Rotation in radian
    float getAngleRadian();
    //Rotation in degrees
    float getAngle();
    Vector2f getMovementVector();
    BallSize getSize();
    BallType getType();
    Uint8 getRadius();
    bool simulatePhysics();
};
