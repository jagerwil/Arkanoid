#pragma once
#include <SFML/Window/Event.hpp>
using sf::Event;

class ArkanoidGame;
class ArkanoidGraphics;


class ArkanoidInput
{
public:
    ArkanoidInput(ArkanoidGame* game, ArkanoidGraphics* graphics);

    void handleEvents();
    void inputKeyboard(Event& event);
    void inputMouse(Event& event);

protected:
    ArkanoidGame* game;
    ArkanoidGraphics* graphics;
};
