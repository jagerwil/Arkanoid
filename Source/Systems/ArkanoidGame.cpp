#include "ArkanoidGame.h"
#include "ArkanoidGraphics.h"
#include "Components/PhysicsComponent.h"
#include "Objects/GameField.h"


ArkanoidGame::ArkanoidGame()
{
    gameField = new GameField();
    physics = new PhysicsComponent(gameField);
}

void ArkanoidGame::init(ArkanoidGraphics* graphics)
{
    this->graphics = graphics;

    gameField->spawnBall(Vector2f{700.f, 500.f});
    Ball& ball = gameField->getBall(0);
    ball.setSpeed(50.f);
    ball.setRotation(-90.f);

    setGameState(GameState::PLAYING);
}

void ArkanoidGame::tick(Time deltaTime)
{
    switch (gameState)
    {
    case GameState::START_GAME:
        ///...
        break;

    case GameState::PLAYING:
        physics->moveBalls(deltaTime);
        break;

    case GameState::END_GAME:
        ///...
        break;
    }
}

void ArkanoidGame::setGameState(GameState gameState)
{
    this->gameState = gameState;

    switch (gameState)
    {
    case GameState::START_GAME:
        ///...
        break;

    case GameState::PLAYING:
        ///...
        break;

    case GameState::END_GAME:
        ///...
        break;
    }

    graphics->updateGameState(gameState);
}

GameField* ArkanoidGame::getGameField()
{
    return gameField;
}
