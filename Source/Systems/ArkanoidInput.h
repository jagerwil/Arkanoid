#pragma once
#include <SFML/Window/Event.hpp>
using sf::Event;

class ArkanoidGame;
class ArkanoidGraphics;


class ArkanoidInput
{
protected:
    ArkanoidGame* game;
    ArkanoidGraphics* graphics;

public:
    ArkanoidInput(ArkanoidGame* game, ArkanoidGraphics* graphics);
    ~ArkanoidInput();

    void handleEvents();
    void inputKeyboard(Event& event);
    void inputMouse(Event& event);
};
