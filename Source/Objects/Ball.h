#pragma once
#include "Headers/BasicHeader.h"
#include <SFML/Graphics/Transformable.hpp>
using sf::Transformable;


class Ball
{
protected:
    static float radian /* = 180.f / 3.14159f */;

    BallSize size;
    Vector2f coords;
    float speed;
    float angle;
    Vector2f movementVector;

public:
    Ball(Vector2f coords, BallSize size);
    void recalculate();
    void move(Vector2f offset);

    void setPosition(Vector2f coords);
    void setSpeed(float speed);
    void setRotation(float angle);
    void setSize(BallSize size);

    Vector2f getPosition();
    Vector2f getMovementVector();
    BallSize getSize();
    Uint8 getRadius();
};
