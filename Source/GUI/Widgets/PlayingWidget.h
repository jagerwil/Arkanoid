#pragma once
#include "Widget.h"
#include "Components/GameField.h"


class PlayingWidget : public Widget
{
protected:
    GameField* gameField;

    Texture backgroundTexture;
    Sprite backgroundSprite;

    Font scoreFont;
    Text scoreText;

public:
    PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics, GameField* gameField);
    ~PlayingWidget();

    void draw() override;
    void updateScore(Uint32 score);
};
