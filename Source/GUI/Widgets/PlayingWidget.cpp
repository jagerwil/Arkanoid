#include "PlayingWidget.h"


PlayingWidget::PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics, GameField* gameField):
    Widget(coords, size, graphics),
    gameField {gameField}
{
    backgroundTexture.loadFromFile("Textures/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(IntRect(Vector2i{0, 0}, screenSize));
}

void PlayingWidget::draw()
{
    graphics->draw(*this);

    graphics->draw(backgroundSprite);
    
    map<int, Brick>& bricks = gameField->getBricks();
    for (auto& brick : bricks)
    {
        graphics->draw(brick.second.getSprite());
    }
    

    vector<Ball>& balls = gameField->getBalls();
    for (Ball& ball : balls)
    {
        graphics->draw(ball.getSprite());
    }

    Platform& platform = gameField->getPlatform();
    graphics->draw(platform.getSprite());

    ///...
}
