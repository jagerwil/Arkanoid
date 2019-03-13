#include "SpriteManager.h"


Vector2i SpriteManager::smallBallSize = {21, 21};
Vector2i SpriteManager::largeBallSize = {41, 41};

SpriteManager::SpriteManager()
{
    smallBalls.loadFromFile("Textures/small_balls.png");
    largeBalls.loadFromFile("Textures/large_balls.png");

    smallBallsBitmap.loadFromFile("Textures/small_balls_bitmap.png");
    largeBallsBitmap.loadFromFile("Textures/large_balls_bitmap.png");
}

bool SpriteManager::loadBallSprite(Ball& ball)
{
    Texture* ballTexture;
    Texture* ballBitmap;
    Vector2i* ballSize;
    Vector2i startCoords;

    if (ball.getSize() == BallSize::SMALL)
    {
        ballSize = &smallBallSize;
        ballTexture = &smallBalls;
        ballBitmap = &smallBallsBitmap;
    }
    else if (ball.getSize() == BallSize::LARGE)
    {
        ballSize = &largeBallSize;
        ballTexture = &largeBalls;
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
    Sprite& bitmap = ball.getBitmap();
    
    sprite.setTexture(*ballTexture);
    sprite.setTextureRect(sf::IntRect(startCoords, *ballSize));

    bitmap.setTexture(*ballBitmap);
    bitmap.setTextureRect(sf::IntRect({0, 0}, *ballSize));

    return true;
}
