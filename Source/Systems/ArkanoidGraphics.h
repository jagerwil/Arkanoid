#pragma once
#include "Headers/GraphicsHeader.h"

class ArkanoidGame;
class Widget;
class PlayingWidget;


class ArkanoidGraphics : public RenderWindow
{
protected:
    ArkanoidGame* game;
    Widget* currentWidget;

    PlayingWidget* playing;

    GameState currentState;

public:
    ArkanoidGraphics(Vector2i screenSize);

    void drawAll();
    void update();
    void updateGameState(GameState& gameState);

    vector<BallData> getBallsData();

    void init(ArkanoidGame* game);
};
