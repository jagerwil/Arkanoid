#include "ArkanoidGame.h"
#include "ArkanoidGraphics.h"
#include "Components/PhysicsComponent.h"


ArkanoidGame::ArkanoidGame()
{
    gameField = nullptr;
    physics = nullptr;
}

void ArkanoidGame::init(ArkanoidGraphics* graphics)
{
    this->graphics = graphics;
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

void ArkanoidGame::movePlatform(float x)
{
    if (gameState == GameState::PLAYING)
    {
        gameField->movePlatform(x);
    }
}

void ArkanoidGame::spawnAttachedBall()
{
    if (gameState == GameState::PLAYING)
    {
        gameField->spawnAttachedBall();
    }
}

void ArkanoidGame::releaseBall()
{
    if (gameState == GameState::PLAYING)
    {
        gameField->releaseBall();
    }
}

void ArkanoidGame::setGameState(GameState gameState)
{
    this->gameState = gameState;

    switch (gameState)
    {
    case GameState::START_GAME:
        if (gameField != nullptr)
        {
            delete gameField;
            gameField = nullptr;

            delete physics;
            physics = nullptr;
        }
        break;

    case GameState::PLAYING:
        if (gameField == nullptr)
        {
            gameField = new GameField();
            physics = new PhysicsComponent(gameField);
        }
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
