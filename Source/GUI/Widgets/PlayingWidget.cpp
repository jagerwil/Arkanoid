#include "PlayingWidget.h"


PlayingWidget::PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics, GameField* gameField):
    Widget(coords, size, graphics),
    gameField {gameField}
{
    backgroundTexture.loadFromFile("Textures/background.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setTextureRect(IntRect(Vector2i{0, 0}, screenSize));

    scoreFont.loadFromFile("Textures/cyrillic_font.ttf");

    scoreText.setPosition(30.f, 20.f);
    scoreText.setFont(scoreFont);
    scoreText.setFillColor(Color::White);
    scoreText.setCharacterSize(30);
    updateScore(0);
}

PlayingWidget::~PlayingWidget()
{
    gameField = nullptr;
}

void PlayingWidget::draw()
{
    graphics->draw(*this);

    graphics->draw(backgroundSprite);
    graphics->draw(scoreText);
    
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

void PlayingWidget::updateScore(Uint32 score)
{
    string scoreString = "Score: " + std::to_string(score);
    scoreText.setString(scoreString);
}
