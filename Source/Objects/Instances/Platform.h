#pragma once
#include "Objects/Object.h"


class Platform : public Object
{
protected:
    Vector2f size;

public:
    Platform(Vector2f coords, Vector2f size);

    void setX(float x);
    void setSize(Vector2f size);
    Vector2f getSize();
};
