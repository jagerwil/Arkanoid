#pragma once
#include "Headers/GraphicsHeader.h"

class ArkanoidGame;
class Widget;
class PlayingWidget;


class ArkanoidGraphics : public RenderWindow
{
protected:
    ArkanoidGame* game;

    PlayingWidget* playingWidget;
    Widget* currentWidget;

    GameState currentState;

public:
    ArkanoidGraphics();
    ~ArkanoidGraphics();
    void init(ArkanoidGame* _game);

    void drawAll();

    void updateGameState(GameState& gameState);
    void updateScore(Uint32 score);
};
