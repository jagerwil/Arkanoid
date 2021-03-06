#pragma once
#include "Headers/GraphicsHeader.h"
#include "Datatypes/Bitmap.h"


class Object
{
protected:
    Vector2f coords;
    Vector2f size;

    Sprite sprite;
    Bitmap bitmap;

public:
    Object();
    Object(Vector2f coords);

    void move(Vector2f offset);
    virtual void setPosition(Vector2f _coords);
    virtual void setSize(Vector2f _size);
    void setColor(Color color);

    Sprite& getSprite();
    Bitmap& getBitmap();
    Vector2f getPosition();
    Vector2f getSize();
};

typedef Object Brick;
