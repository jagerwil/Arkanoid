#include "ArkanoidGraphics.h"
#include "ArkanoidGame.h"
#include "GUI/Widgets/PlayingWidget.h"
using sf::VideoMode;
using sf::Style::Close;


ArkanoidGraphics::ArkanoidGraphics(Vector2i screenSize)
{
    create(VideoMode(screenSize.x, screenSize.y), "Arkanoid", Close);
}

void ArkanoidGraphics::drawAll()
{
    clear();
    currentWidget->draw();
    display();
}

void ArkanoidGraphics::update()
{
    ///...
}

void ArkanoidGraphics::updateGameState(GameState& gameState)
{
    if (currentState == gameState)
        return;

    currentState = gameState;
    currentWidget = nullptr;

    switch (gameState)
    {
    case GameState::START_GAME:
        ///...
        break;

    case GameState::PLAYING:
        playing = new PlayingWidget(Vector2f{0, 0}, Vector2f{1366, 768}, this);
        currentWidget = playing;
        break;

    case GameState::END_GAME:
        ///...
        break;
    }
}

vector<BallData> ArkanoidGraphics::getBallsData()
{
    return game->getBallsData();
}

void ArkanoidGraphics::init(ArkanoidGame* game)
{
    this->game = game;
}
