#pragma once
#include <SFML/System/Time.hpp>
#include "Structures/BasicStructures.h"    ///Unused
using sf::Time;

class ArkanoidGraphics;


class ArkanoidGame
{
public:
    ArkanoidGame(ArkanoidGraphics* graphics);

    void tick(Time deltaTime);

protected:
    ArkanoidGraphics* graphics;
};
