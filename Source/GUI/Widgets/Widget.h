#pragma once
#include "Headers/GraphicsHeader.h"
#include "Systems/ArkanoidGraphics.h"


class Widget : public RectangleShape
{
protected:
    ArkanoidGraphics* graphics;

public:
    Widget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics);
    ~Widget();

    virtual void draw();
};
