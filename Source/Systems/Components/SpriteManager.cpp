#include "SpriteManager.h"


Vector2i SpriteManager::smallBallSize = {21, 21};
Vector2i SpriteManager::largeBallSize = {41, 41};

SpriteManager::SpriteManager()
{
    smallBallsTexture.loadFromFile("Textures/small_balls.png");
    largeBallsTexture.loadFromFile("Textures/large_balls.png");
    platformTexture.loadFromFile("Textures/platform.png");
    brickTexture.loadFromFile("Textures/brick.png");

    smallBallsBitmap.loadFromFile("Textures/small_balls_bitmap.png");
    largeBallsBitmap.loadFromFile("Textures/large_balls_bitmap.png");
    brickBitmap.loadFromFile("Textures/brick_bitmap.png");
}

bool SpriteManager::loadPlatformSprite(Platform& platform)
{
    Sprite& sprite = platform.getSprite();

    sprite.setTexture(platformTexture);
    sprite.setTextureRect(IntRect({0, 0}, {120, 20}));

    return true;
}

bool SpriteManager::loadBallSprite(Ball& ball)
{
    Texture* ballTexture;
    Image* ballBitmap;
    Vector2i* ballSize;
    Vector2i startCoords;

    if (ball.getSize() == BallSize::SMALL)
    {
        ballSize = &smallBallSize;
        ballTexture = &smallBallsTexture;
        ballBitmap = &smallBallsBitmap;
    }
    else if (ball.getSize() == BallSize::LARGE)
    {
        ballSize = &largeBallSize;
        ballTexture = &largeBallsTexture;
        ballBitmap = &largeBallsBitmap;
    }
    else return false;

    if (ball.getType() == BallType::COMMON)
    {
        startCoords = {0, 0};
    }
    else if (ball.getType() == BallType::FIRE)
    {
        ///...
    }
    else return false;

    Sprite& sprite = ball.getSprite();

    sprite.setTexture(*ballTexture);
    sprite.setTextureRect(IntRect(startCoords, *ballSize));

    Bitmap& bitmap = ball.getBitmap();

    bitmap.initialize(*ballBitmap);

    return true;
}

bool SpriteManager::loadBrickSprite(Brick& brick, Vector2i brickSize)
{
    Sprite& sprite = brick.getSprite();
    Bitmap& bitmap = brick.getBitmap();

    sprite.setTexture(brickTexture);
    sprite.setTextureRect(IntRect({0, 0}, brickSize));

    bitmap.initialize(brickBitmap);

    return true;
}
