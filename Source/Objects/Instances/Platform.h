#pragma once
#include "Objects/Object.h"


class Ball;

class Platform : public Object
{
protected:
    Ball* ball;
    Vector2f ballOffset;
    bool bBallAttached;

public:
    Platform(Vector2f coords, Vector2f size);
    ~Platform();

    void attachBall(Ball* _ball);
    void unAttachBall();

    void setX(float x);
    void setSize(Vector2f _size) override;

    bool ballAttached();
};
