#pragma once
#include "Widget.h"
#include "Objects/GameField.h"


class PlayingWidget : public Widget
{
protected:
    GameField* gameField;

public:
    PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics, GameField* gameField);

    void draw() override;
};
