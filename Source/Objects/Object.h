#pragma once
#include "Headers/GraphicsHeader.h"


class Object
{
protected:
    Vector2f coords;

    Sprite sprite;
    Sprite bitmap;

public:
    Object(Vector2f coords);

    void move(Vector2f offset);
    virtual void setPosition(Vector2f coords);

    Sprite& getSprite();
    Sprite& getBitmap();
    Vector2f getPosition();
};

typedef Object Brick;
