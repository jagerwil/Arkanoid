#include "ArkanoidGame.h"
#include "ArkanoidGraphics.h"
#include "Components/PhysicsComponent.h"


ArkanoidGame::ArkanoidGame()
{
    physics = new PhysicsComponent();
    
    balls.push_back(Ball(Vector2f{700.f, 500.f}, BallSize::SMALL));
    balls[0].setSpeed(50.f);
    balls[0].setRotation(-90.f);
}

void ArkanoidGame::init(ArkanoidGraphics * graphics)
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
        physics->moveBalls(balls, deltaTime);
        break;

    case GameState::END_GAME:
        ///...
        break;
    }
}

void ArkanoidGame::removeBall(Uint32 index)
{
    balls.erase(balls.begin() + index);
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

vector<Ball>& ArkanoidGame::getBalls()
{
    return balls;
}

vector<BallData> ArkanoidGame::getBallsData()
{
    vector<BallData> ballsData;

    for (Ball& ball : balls)
    {
        ballsData.push_back(BallData(ball.getPosition(), ball.getRadius()));
    }

    return ballsData;
}
