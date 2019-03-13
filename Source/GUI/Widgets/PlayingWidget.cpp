#include "PlayingWidget.h"


PlayingWidget::PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics, GameField* gameField):
    Widget(coords, size, graphics),
    gameField {gameField}
{
    ///...
}

void PlayingWidget::draw()
{
    graphics->draw(*this);

    vector<Ball>& balls = gameField->getBalls();

    for (Ball& ball : balls)
    {
        graphics->draw(ball.getSprite());
    }

    Platform& platform = gameField->getPlatform();
    graphics->draw(platform.getSprite());

    ///...
}
