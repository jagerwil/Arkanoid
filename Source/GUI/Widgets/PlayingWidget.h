#pragma once
#include "Widget.h"
#include "Objects/Ball.h"


class PlayingWidget : public Widget
{
public:
    PlayingWidget(Vector2f coords, Vector2f size, ArkanoidGraphics* graphics);

    void draw() override;
};
