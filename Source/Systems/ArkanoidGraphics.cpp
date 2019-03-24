#include "ArkanoidGraphics.h"
#include "ArkanoidGame.h"
#include "GUI/Widgets/PlayingWidget.h"
using sf::VideoMode;
using sf::Style::Close;


ArkanoidGraphics::ArkanoidGraphics()
{
    create(VideoMode(screenSize.x, screenSize.y), "Arkanoid", Close);
}

ArkanoidGraphics::~ArkanoidGraphics()
{
    game = nullptr;
    currentWidget = nullptr;

    if (playingWidget != nullptr)
    {
        delete playingWidget;
    }
}

void ArkanoidGraphics::init(ArkanoidGame* _game)
{
    game = _game;
}

void ArkanoidGraphics::drawAll()
{
    clear();
    currentWidget->draw();
    display();
}

void ArkanoidGraphics::updateGameState(GameState& gameState)
{
    if (currentState == gameState)
    {
        return;
    }

    currentState = gameState;
    currentWidget = nullptr;

    switch (gameState)
    {
    case GameState::START_GAME:
        ///...
        break;

    case GameState::PLAYING:
        playingWidget = new PlayingWidget(Vector2f{0, 0}, (Vector2f)getSize(), this, game->getGameField());
        currentWidget = playingWidget;
        break;

    case GameState::END_GAME:
        ///...
        break;
    }
}

void ArkanoidGraphics::updateScore(Uint32 score)
{
    playingWidget->updateScore(score);
}
