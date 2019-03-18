#pragma once
#include "Headers/GraphicsHeader.h"
#include "Objects/GameField.h"


class SpriteManager
{
protected:
    static Vector2i smallBallSize;
    static Vector2i largeBallSize;

    Texture smallBallsTexture;
    Texture largeBallsTexture;
    Texture platformTexture;
    Texture brickTexture;

    Image smallBallsBitmap;
    Image largeBallsBitmap;
    Image platformBitmap;
    Image brickBitmap;

public:
    SpriteManager();

    bool loadPlatformSprite(Platform& platform);
    bool loadBallSprite(Ball& ball);
    bool loadBrickSprite(Brick& brick, Vector2i brickSize);
};
