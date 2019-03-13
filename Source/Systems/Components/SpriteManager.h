#pragma once
#include "Headers/GraphicsHeader.h"
#include "Objects/GameField.h"


class SpriteManager
{
protected:
    static Vector2i smallBallSize;
    static Vector2i largeBallSize;

    Texture smallBalls;
    Texture largeBalls;

    Texture smallBallsBitmap;
    Texture largeBallsBitmap;

public:
    SpriteManager();
    bool loadBallSprite(Ball& ball);
};
