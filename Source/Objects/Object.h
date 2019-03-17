#pragma once
#include "Headers/GraphicsHeader.h"


class Object
{
protected:
    Vector2f coords;
    Vector2f size;

    Sprite sprite;
    Sprite bitmap;

public:
    Object(Vector2f coords);

    void move(Vector2f offset);
    virtual void setPosition(Vector2f coords);
    virtual void setSize(Vector2f size);

    Sprite& getSprite();
    Sprite& getBitmap();
    Vector2f getPosition();
    Vector2f getSize();
};

typedef Object Brick;
